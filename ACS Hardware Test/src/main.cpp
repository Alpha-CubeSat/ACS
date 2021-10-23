/*
TODO: log current, angular velocity, and mag values to SD card
      time how long main loop takes
      get rid of redundant setup/read stuff since we can just use the flight code

Thought: it'd be nice to still used averaged gyro and mag values to reduce sensor noise if possible
        As long as it's only averaged over a few loops not like 20
*/
#include <StarshotACS0.h>
#include <Adafruit_LSM9DS1.h> // has dependencies
#include <Arduino.h>

int ACSmode = 1; // 0 for detumble, 1 for pointing

// check magnetorquer direction
int Xtorqorder = 1; // set to -1 if magnetorquer was installed backwards
int Ytorqorder = 1; // set to -1 if magnetorquer was installed backwards
int Ztorqorder = 1; // set to -1 if magnetorquer was installed backwards

// define pins for magnetorquer drivers // feel free to use flight code instead
int xout1 = 25; //output to hbridges 
int xout2 = 24; //output to hbridges
int yout1 = 8; //output to hbridges 
int yout2 = 7; //output to hbridges 
int zout1 = 28; //output to hbridges 
int zout2 = 29; //output to hbridges  
int xPWMpin = 10; //output to hbridges 
int yPWMpin = 6; //output to hbridges 
int zPWMpin = 30; //output to hbridges 
int STBY_XYpin = 9; //output to hbridges 
int STBY_Zpin = 27; //output to hbridges 

// define pins for IMU

// define ACS object class 
static StarshotACS0ModelClass starshotObj

// define pins for IMU // feel free to use flight code instead
#define LSM9DS1_XGCS 21
#define LSM9DS1_MCS 20

// define IMU
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1(LSM9DS1_XGCS, LSM9DS1_MCS);

void setupIMU(int mode) // lauren, feel free to use the flight code for this
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_16G);
  
  // 2.) Set the magnetometer sensitivity
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_8GAUSS);
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_12GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_16GAUSS);

  // 3.) Setup the gyroscope - the ranging thing based on mode isn't essential, 
  // feel free to ignore and just use a higher range to be safe
  if (mode == 0){
    lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_500DPS); // fine for pointing
  }
  else {
    lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS); // probably better for detumbling
  }
  //lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_2000DPS);
}
void IMUinit { // feel free to use flight code instead
    if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");
}

void magtorqInit() { // feel free to use flight code instead
  // STBY pins
  pinMode(STBY_XYpin, OUTPUT);  
  pinMode(STBY_Zpin, OUTPUT);

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
}
int current2PWM(float current) {
  // Sana has the math, josh will repeat the mapping if she doesn't get back to us
  // returns PWM value
}
void ACSwrite(int torqorder,  float current,  int out1,  int out2, int PWMpin) {
 // this has been tweaked from the old version 
  int PWM = current2PWM(abs(current));
  
  if (PWM == 0) {
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
  }

  else if (torqorder == 0) { // Lauren took this out of the final flight version, as of 12/3/2020
                        // TODO - add it back
    if (current > 0) {
      digitalWrite(out1, HIGH);
      digitalWrite(out2, LOW);
      analogWrite(PWMpin, PWM);
    }
    if (current < 0) {
      digitalWrite(out1, LOW);
      digitalWrite(out2, HIGH);
      analogWrite(PWMpin, PWM);
    }
  }
  else if (torqorder == 1) {
    if (current > 0) {
      digitalWrite(out1, LOW);
      digitalWrite(out2, HIGH);
      analogWrite(PWMpin, PWM);
    }
    if (current < 0) {
      digitalWrite(out1, HIGH);
      digitalWrite(out2, LOW);
      analogWrite(PWMpin, PWM);
    }
  }

void setup() {
  starshotObj.initialize();
  delay(5000); // enough time to make sure air bearing is stable again

  magtorqInit(); //initialize pins for magnetorquer driver
  IMUinit(); //initilize IMU
  setupIMU(ACSmode); // sets IMU ranges 

  // read IMU

  // correct IMU readings
  // basically just define 3 constants (MagXOffset,MagYOffset, and MagZOffset)
  // then after reading new mag values from the imu, correct them by subtracting these offset constants

  // feed gyro + corrected mag values into initial conditions for ACS library
  // (the library initial conditions should be real life measurements)
}

void loop() {
  //run ACS for one time step
  
  // actuate magtorquers via ACSwrite() based on current values output by autocoded ACS function

  //delay(whatever the step size of the library is); // 3 ms for 333hz version

  // read IMU (ideally averaged values)

  // correct IMU mag values for magnetic field offsets

  // update gyro and mag variables for ACS function to use on the next loop
  
}