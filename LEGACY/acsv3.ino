#include <TimerOne.h> // TODO: replace with IntervalTimer
//#include <avdweb_SAMDtimer.h> //get up on out of here
#include <StarshotACS0.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>
int permission = 0; // clock
//int output=0;
int count = 0;
int pinset = LOW;
int ACSmode = 1;
int Xtorqorder = 1;
int Ytorqorder = 1;
int Ztorqorder = 1;
float current1;
float current2;
float current3;
float Res_torquer = 100.0; // unused

int yout1 = 5; //output to hbridges 
int yout2 = 6; //output to hbridges 
int zout1 = 9; //output to hbridges 
int zout2 = 10; //output to hbridges 
int xout1 = 7; //output to hbridges 
int xout2 = 8; //output to hbridges 
int xPWMpin = 2; //output to hbridges 
int yPWMpin = 3; //output to hbridges 
int zPWMpin = 4; //output to hbridges 
int LEDpin = 13; //testing pin
int STBYpin = 21; //output to hbridges 
int STBZpin = 20; //output to hbridges 

static StarshotACS0ModelClass rtObj; // from simulink, matlab library

Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

void setupIMU() { //we have another function in the code
  lsm.begin();
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G); // can change settings in flight software
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_12GAUSS);
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
  //lsm.begin();
}
void setup() {
  //
  Serial.begin(9600);
  while (!Serial); //CODE WILL ONLY RUN IF SERIAL MONITOR IS OPEN!!!!!!
  Serial.println("STARTING ACS SETUP");
  Timer1.initialize(10000); // synchronize time with calculations
  Timer1.attachInterrupt(myISR);
  //LED Pins

  //H-bridge standby pins
  pinMode(STBYpin, OUTPUT);  
  pinMode(STBZpin, OUTPUT);

  //Pins for X-Torquer
  pinMode(xPWMpin, OUTPUT);
  pinMode(xout1, OUTPUT);
  pinMode(xout2, OUTPUT);

  //Pins for Y-Torquer
  pinMode(yPWMpin, OUTPUT);
  pinMode(yout1, OUTPUT);
  pinMode(yout2, OUTPUT);

  //Pins for Z-Torquer
  pinMode(zout1, OUTPUT);
  pinMode(zout2, OUTPUT);
  pinMode(zPWMpin, OUTPUT);

  rtObj.initialize();
  Serial.println("Setting up IMU");
  setupIMU();
  Serial.println("IMU SETUP COMPLETE");
  Serial.println("SETUP COMPLETE");
}

void myISR(void) {
  if (pinset == HIGH) {
    pinset = LOW;
  }
  else {
    pinset = HIGH;
  }
  permission = 1; // clock - activate simulation
}

//SAMDtimer mytimer=SAMDtimer(4,myISR,1e6); //outdated

void ACSwrite(int torqorder,  float current,  int out1,  int out2, int PWMpin) {
  if (current == 0.0) {
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
  }

  if (torqorder == 0) { // Lauren took this out of the final flight version, as of 12/3/2020
                        // TODO - add it back
    if (current > 0) {
      digitalWrite(out1, HIGH);
      digitalWrite(out2, LOW);
      analogWrite(PWMpin, current);
    }
    if (current < 0) {
      digitalWrite(out1, LOW);
      digitalWrite(out2, HIGH);
      analogWrite(PWMpin, current);
    }
  }
  if (torqorder == 1) {
    if (current > 0) {
      digitalWrite(out1, LOW);
      digitalWrite(out2, HIGH);
      analogWrite(PWMpin, current);
    }
    if (current < 0) {
      digitalWrite(out1, HIGH);
      digitalWrite(out2, LOW);
      analogWrite(PWMpin, current);
    }
  }

}

void ACSmodeselect() {
}

void runsim() {
  if (permission == 1) {

    sensors_event_t accel, mag, gyro, temp;
    lsm.getEvent(&accel, &mag, &gyro, &temp);

    rtObj.rtU.angularvelocity[0] = gyro.gyro.x * 3.14159 / 180.0; //these must be changed to accomodate the new IMU model
    rtObj.rtU.angularvelocity[1] = gyro.gyro.y * 3.14159 / 180.0;
    rtObj.rtU.angularvelocity[2] = gyro.gyro.z * 3.14159 / 180.0;
    rtObj.rtU.Bfield_body[0] = mag.magnetic.x;
    rtObj.rtU.Bfield_body[1] = mag.magnetic.y;
    rtObj.rtU.Bfield_body[2] = mag.magnetic.z;
    rtObj.step();
    count = count + 1;
    //rtObj.rtY.detuble;
    //rtObj.rtY.point;

    if (ACSmode == 0) { //detumble
      current1 = rtObj.rtY.detuble[0];
      current2 = rtObj.rtY.detuble[1];
      current3 = rtObj.rtY.detuble[2];
    }
    if (ACSmode == 1) { //normal acs operations, i.e. point
      current1 = rtObj.rtY.point[0];
      current2 = rtObj.rtY.point[1];
      current3 = rtObj.rtY.point[2];
    }

//    Serial.println("Run Count");
//    Serial.println(count);
//    Serial.println("Angular Velocity p");
//    Serial.println(rtObj.rtU.angularvelocity[0]);
//    Serial.println("Angular Velocity q");
//    Serial.println(rtObj.rtU.angularvelocity[1]);
//    Serial.println("Angular Velocity r");
//    Serial.println(rtObj.rtU.angularvelocity[2]);
    //Serial.println("Bfield_body");
    //Serial.println(rtObj.rtU.Bfield_body[0]);
    //Serial.println(rtObj.rtU.Bfield_body[1]);
    //Serial.println(rtObj.rtU.Bfield_body[2]);
    permission = 0;
  }
}

unsigned long t = 0;
unsigned long told = 0;

void loop() {
  told = t;
  t = millis();
//  delay(5000);
//  Serial.println("Setting up RUNSIM");
//  //permission = 0; done by myISR function
//  Serial.println("Permission set to 1. 3 Seconds for RUNSIM!");
//  delay(3000);
  runsim();
  //digitalWrite(LEDpin, pinset);
//  current1=255.0; // this is just for testing I believe
 // digitalWrite(xPWMpin, HIGH); // sets pin to 5V. why need this if doing analogWrite() in ACSwrite()?
  digitalWrite(STBYpin, HIGH);
 // digitalWrite(yPWMpin, HIGH);
  digitalWrite(STBZpin, HIGH);
 // digitalWrite(zPWMpin, HIGH);
  ACSwrite(Xtorqorder, current1, xout1, xout2, xPWMpin);
  ACSwrite(Ytorqorder, current2, yout1, yout2, yPWMpin); //previously current1 for testing I think
  ACSwrite(Ztorqorder, current3, zout1, zout2, zPWMpin); //previously current1 for testing I think
//  if(t-told > 500){
  Serial.print("Current Value 1: ");
  Serial.println(current1);  
  Serial.print("Current Value 2: ");
  Serial.println(current2);  
  Serial.print("Current Value 3: ");
  Serial.println(current3);  
//  }
//  Serial.print("Ztorqorder Value: ");
//  Serial.println(Ztorqorder);

}

// to check: 
// 1. run simulation and see what current values display on scope - DONE (~ 0.0005)
// 2. ammeter to magnetorquers to measure current - most impt
// 3. software readout - DONE (~0.0000000024)
// ~ 0.01A
// find breaking points
