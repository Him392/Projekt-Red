
#include <Wire.h>
#include <PS2X_lib.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include "QGPMaker_MotorShield.h"

QGPMaker_MotorShield AFMS = QGPMaker_MotorShield();
PS2X ps2x;
QGPMaker_Servo *Servo0 = AFMS.getServo(0);
QGPMaker_Servo *Servo1 = AFMS.getServo(1);
QGPMaker_Servo *Servo2 = AFMS.getServo(2);
QGPMaker_DCMotor *DCMotor_1 = AFMS.getMotor(1);
QGPMaker_DCMotor *DCMotor_2 = AFMS.getMotor(2);
QGPMaker_DCMotor *DCMotor_3 = AFMS.getMotor(3);
QGPMaker_DCMotor *DCMotor_4 = AFMS.getMotor(4);

void setup(){
  AFMS.begin(50);

  int error = 0;
  do{
    error = ps2x.config_gamepad(13,11,10,12, true, true);
    if(error == 0){
      break;
    }else{
      delay(100);
    }
  }while(1);
  for(size_t i = 0; i < 50; i++)
  {
        ps2x.read_gamepad(false, 0);
        delay(10);
  }

  Servo0->writeServo(0);
}

void loop(){
  ps2x.read_gamepad(false, 0);
  delay(3);
  Servo0->writeServo(ps2x.Analog(PSS_RY));Servo1->writeServo(ps2x.Analog(PSS_LX));Servo2->writeServo(ps2x.Analog(PSS_LY));// 前进
  if (ps2x.Button(PSB_PAD_UP)) {
    DCMotor_1->setSpeed(255);
    DCMotor_1->run(FORWARD);
    DCMotor_2->setSpeed(200);
    DCMotor_2->run(FORWARD);

  }
  if (ps2x.Button(PSB_PAD_DOWN)) {
    DCMotor_1->setSpeed(155);
    DCMotor_1->run(BACKWARD);
    DCMotor_2->setSpeed(100);
    DCMotor_2->run(BACKWARD);

  }
  if (ps2x.Button(PSB_PAD_LEFT)) {
    DCMotor_1->setSpeed(200);
    DCMotor_1->run(BACKWARD);
    DCMotor_2->setSpeed(200);
    DCMotor_2->run(FORWARD);

  }
  if (ps2x.Button(PSB_PAD_RIGHT)) {
    DCMotor_1->setSpeed(200);
    DCMotor_1->run(FORWARD);
    DCMotor_2->setSpeed(200);
    DCMotor_2->run(BACKWARD);

  }
  if (ps2x.ButtonReleased(PSB_PAD_RIGHT)) {
    DCMotor_1->setSpeed(0);
    DCMotor_1->run(RELEASE);
    DCMotor_2->setSpeed(0);
    DCMotor_2->run(RELEASE);

  }
  if (ps2x.ButtonReleased(PSB_PAD_UP)) {
    DCMotor_1->setSpeed(0);
    DCMotor_1->run(RELEASE);
    DCMotor_2->setSpeed(0);
    DCMotor_2->run(RELEASE);

  }
  if (ps2x.ButtonReleased(PSB_PAD_DOWN)) {
    DCMotor_1->setSpeed(0);
    DCMotor_1->run(RELEASE);
    DCMotor_2->setSpeed(0);
    DCMotor_2->run(RELEASE);

  }
  if (ps2x.ButtonReleased(PSB_PAD_LEFT)) {
    DCMotor_1->setSpeed(0);
    DCMotor_1->run(RELEASE);
    DCMotor_2->setSpeed(0);
    DCMotor_2->run(RELEASE);

  }
  if (ps2x.Button(PSB_R2)) {
    DCMotor_3->setSpeed(200);
    DCMotor_3->run(FORWARD);
    DCMotor_4->setSpeed(200);
    DCMotor_4->run(FORWARD);

  }
  if (ps2x.ButtonReleased(PSB_R2)) {
    DCMotor_3->setSpeed(0);
    DCMotor_3->run(RELEASE);
    DCMotor_4->setSpeed(0);
    DCMotor_4->run(RELEASE);

  }

}