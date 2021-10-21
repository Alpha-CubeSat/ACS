#include <Arduino.h>
#include <avdweb_SAMDtimer.h>
#include <StarshotACS0.h>
#include <Wire.h>
#include <I2C_Anything.h>
int permission=0;
int count=0;
int pinset=LOW;
int ACSmode=0;
int Xtorqorder=1;
int Ytorqorder=1;
int Ztorqorder=1;
double current1;
double current2; 
double current3;
double rxangularvelocity1;
double rxangularvelocity2;
double rxangularvelocity3;
unsigned long t1;
unsigned long t2;
unsigned long dt;
static StarshotACS0ModelClass rtObj;
void setup(){
  // put your setup code here, to run once:    
  Serial.begin(9600);
  while(!Serial);
  Serial.println("STARTING SETUP");
  rtObj.initialize();
  Wire.begin();
  Serial.println("SETUP COMPLETE");    
}

void myISR(struct tc_module *const module_inst){
  //Serial.println("Running ISR");
  //Serial.println(rxangularvelocity1);
  //Serial.println(x);
  if(pinset==HIGH){
    pinset=LOW;
    }
  else{
    pinset=HIGH;
    }
  permission=1;  
}

SAMDtimer mytimer=SAMDtimer(4,myISR,3e4);  

void ACSmodeselect(){
  }

void runsim(){
  if(permission==1){
    //t1=micros();
    Wire.requestFrom(9,48,true);
    //Serial.println(Wire.available());
    //Serial.println(Wire.available());
    if(Wire.available()==48){
      //Serial.println("Receiving");
      I2C_readAnything(rtObj.rtU.w[0]);
      I2C_readAnything(rtObj.rtU.w[1]);
      I2C_readAnything(rtObj.rtU.w[2]);
      I2C_readAnything(rtObj.rtU.Bfield_body[0]);
      I2C_readAnything(rtObj.rtU.Bfield_body[1]);
      I2C_readAnything(rtObj.rtU.Bfield_body[2]);
      //Serial.println("Received");
    }
    rtObj.step();
    //Serial.println(dt);
    count=count+1;
    //Serial.println(count);
    //rtObj.rtY.detuble;
    //rtObj.rtY.point;
      if(ACSmode==0){
        current1=rtObj.rtY.detumble[0];
        current2=rtObj.rtY.detumble[1];
        current3=rtObj.rtY.detumble[2];
      }
      if(ACSmode==1){
        current1=rtObj.rtY.point[0];
        current2=rtObj.rtY.point[1];
        current3=rtObj.rtY.point[2];
      }
//      Serial.println("Execution Time");
//      Serial.println(dt);
//      Serial.println("Run Count");
//      Serial.println(count);
//      Serial.println("Angular Velocity p");
//      Serial.println(rtObj.rtU.angularvelocity[0]);
//      Serial.println("Angular Velocity q");
//      Serial.println(rtObj.rtU.angularvelocity[1]);
//      Serial.println("Angular Velocity r");
//      Serial.println(rtObj.rtU.angularvelocity[2]);
//      Serial.println(rtObj.rtU.Bfield_body[0]);
//      Serial.println(rtObj.rtU.Bfield_body[1]);
//      Serial.println(rtObj.rtU.Bfield_body[2]);
      Wire.beginTransmission(9);
      I2C_writeAnything(current1);
      I2C_writeAnything(current2);
      I2C_writeAnything(current3);
      Wire.endTransmission();
      //Serial.println("Transmission Sent");
      permission=0;
      //t2=micros();
      //dt=t2-t1;
      //Serial.println(dt);
      if (count%1000==0){
        Serial.println("Elapsed Time");
        Serial.println(count/100.0);
//        Serial.println("Execution Time");
//        Serial.println(dt);
        Serial.println("Angular Velocity p");
        Serial.println(rtObj.rtU.w[0]);
        Serial.println("Angular Velocity q");
        Serial.println(rtObj.rtU.w[1]);
        Serial.println("Angular Velocity r");
        Serial.println(rtObj.rtU.w[2]);
    }
    }
  }
  
void loop(){
  runsim();
  //digitalWrite(13,pinset);
  //Serial.println(x);
  //current1=255.0;
  //digitalWrite(STBYpin,HIGH);
  //digitalWrite(22,LOW);
  //digitalWrite(23,HIGH);
  //analogWrite(11,255);
  //ACSwrite(Xtorqorder,current1,xout1,xout2,xPWMpin);
  //ACSwrite(Ytorqorder,current1,yout1,yout2,yPWMpin);
  //ACSwrite(Ztorqorder,current1,zout1,zout2,zPWMpin);
  //Serial.println(rtObj.rtY.detuble[0]);
  // put your main code here, to run repeatedly:
}

  