#include "vex.h"
using namespace vex;
double inchesConversion = 30*(7/3);
double degConversion = 7;
double angleTarget = 0;

//drive encoder functions
double getDriveFL(){
  return FLWheel.rotation(deg);
}
double getDriveTL(){
  return TLWheel.rotation(deg);
}
double getDriveBL(){
  return BLWheel.rotation(deg);
}
double getDriveFR(){
  return FRWheel.rotation(deg);
}
double getDriveTR(){
  return TRWheel.rotation(deg);
}
double getDriveBR(){
  return BRWheel.rotation(deg);
} 
double getDriveL(){
  double averageValue = (getDriveFL() + getDriveTL() + getDriveBL())/3;
  return averageValue;
}
double getDriveR(){
  double averageValue = (getDriveFR() + getDriveTR() + getDriveBR())/3;
  return averageValue;
}
double getDrive(){
  double averageValue = (getDriveL() + getDriveR())/2;
  return averageValue;
}

void driveReset(){
  FLWheel.resetRotation();
  TLWheel.resetRotation();
  BLWheel.resetRotation();
  FRWheel.resetRotation();
  TRWheel.resetRotation();
  BRWheel.resetRotation();
}

//getDriveHeat
double getHeatFL(){
  return FLWheel.temperature(pct);
}
double getHeatTL(){
  return TLWheel.temperature(pct);
}
double getHeatBL(){
  return BLWheel.temperature(pct);
}
double getHeatFR(){
  return FRWheel.temperature(pct);
}
double getHeatTR(){
  return TRWheel.temperature(pct);
}
double getHeatBR(){
  return BRWheel.temperature(pct);
}

//set drive commands
void setDriveFL(double speed){
  FLWheel.spin(fwd, 0.12*speed, volt);
}
void setDriveTL(double speed){
  TLWheel.spin(fwd, 0.12*speed, volt);
}
void setDriveBL(double speed){
  BLWheel.spin(fwd, 0.12*speed, volt);
}
void setDriveFR(double speed){
  FRWheel.spin(fwd, 0.12*speed, volt);
}
void setDriveTR(double speed){
  TRWheel.spin(fwd, 0.12*speed, volt);
}
void setDriveBR(double speed){
  BRWheel.spin(fwd, 0.12*speed, volt);
}
void setDriveFull(double flSpeed, double tlSpeed, double blSpeed, double frSpeed, double trSpeed, double brSpeed){
  setDriveFL(flSpeed);
  setDriveTL(tlSpeed);
  setDriveBL(blSpeed);
  setDriveFR(frSpeed);
  setDriveTR(trSpeed);
  setDriveBR(brSpeed);
}
void setDrive(double lSpeed, double rSpeed){
  setDriveFull(lSpeed, lSpeed, lSpeed, rSpeed, rSpeed, rSpeed);
}

//drive stop commands
void driveBrake(){
  FLWheel.stop(hold);
  TLWheel.stop(hold);
  BLWheel.stop(hold);
  FRWheel.stop(hold);
  TRWheel.stop(hold);
  BRWheel.stop(hold);
}
void driveCoast(){
  FLWheel.stop(coast);
  TLWheel.stop(coast);
  BLWheel.stop(coast);
  FRWheel.stop(coast);
  TRWheel.stop(coast);
  BRWheel.stop(coast);
}

//drive time
void goTime(double lSpeed, double rSpeed, double timeValue){
  setDrive(lSpeed, rSpeed);
  wait(timeValue, msec);
  driveBrake();
}

//PID
void goP(int dir, double speed, double dist, double pStop, double maxError) {
  driveReset();
  //calibrateInertial();
  double speedP = speed/100;
  double pStopVal = pStop*inchesConversion;
  double maxErrorP = maxError*inchesConversion;
  double error;
  double targetVal = dist*inchesConversion;
  double kP = 100/targetVal;
  double kP2 = 7;
  double driftError = 0;
  double pVal = speed;
  double finalPower = speed;
  while (fabs(getDrive()) < (fabs(targetVal) - maxErrorP)){
    if (fabs(getDrive()) < pStopVal){
      error = targetVal - fabs(getDrive());
      pVal = error*kP*speedP;
    }
    finalPower = pVal*dir;
    driftError = ((angleTarget - getInertialYaw())*finalPower*kP2)/100;
    setDrive((pVal + driftError)*dir, (pVal - driftError)*dir);
    wait(10, msec);
  }
  driveBrake();
}


void turnEncoder(int dir, double speed, double dist){
  double degreeDist = dist*degConversion;
  FLWheel.startRotateFor(-1*degreeDist*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  TLWheel.startRotateFor(-1*degreeDist*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  BLWheel.startRotateFor(-1*degreeDist*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  FRWheel.startRotateFor(degreeDist*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  TRWheel.startRotateFor(degreeDist*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BRWheel.startRotateFor(degreeDist*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while(FLWheel.isSpinning() || FRWheel.isSpinning()){
    wait(1, msec);
  }
  driveBrake();
}

double getInertialYaw(){
  return InertialSensor.rotation(deg);
}

void calibrateInertial(){
  InertialSensor.calibrate();
}

void resetAngle(){
  InertialSensor.resetRotation();
  InertialSensor.resetHeading();
}

/*void turnInertial(int dir, double speed, double dist, double pStop, double maxError){
  //calibrateInertial();
  angleTarget = dist;
  double error = dist;
  double actualError = dist;
  double kP = 1/dist;
  double finalPower = speed;
  while(fabs(actualError) > maxError){
    actualError = dist - (getInertialYaw());
    if (actualError > pStop){
      error = dist - (getInertialYaw());
      finalPower = error*kP*speed;
    }
    setDrive(-1*dir*finalPower, dir*finalPower);
  }
  driveBrake();
  
}*/

void turnInertial(int dir, double speed, double dist, double pStop, double maxError){
  //calibrateInertial();
  double initialDist = getInertialYaw();
  double totalDist = dist - getInertialYaw();
  double distTraveled = 0;
  double error = totalDist;
  double actualError = totalDist;
  double kP = 1/totalDist;
  double finalPower = speed;
  while(fabs(actualError) > maxError){
    actualError = totalDist - distTraveled;
    if (actualError > pStop){
      error = totalDist - distTraveled;
      finalPower = error*kP*speed;
    }
    setDrive(-1*dir*finalPower, dir*finalPower);
    distTraveled = getInertialYaw() - initialDist;
  }
  driveBrake();
  angleTarget = dist;
}

int turnP(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth){
  driveReset();
  double speedP = speed/100;
  double targetVal = dist*degConversion;
  double speedStartDeg = speedStart*degConversion;
  double speedCutDeg = speedCut*degConversion;
  double kP = 100/targetVal;
  double kPSlow = slowFactor/100;
  double error = 1;
  double pVal = initSpeed;
  double speedSmooth;
  if (smooth){
    speedSmooth = speedStartDeg;
  }
  else{
    speedSmooth = 0;
  }
  while ((fabs(getDriveL()) < targetVal) && (fabs(getDriveR()) < targetVal)){
    if (((fabs(getDriveL()) <= speedCutDeg) || (fabs(getDriveR()) <= speedCutDeg)) && ((fabs(getDriveL()) > speedStartDeg) || (fabs(getDriveR()) > speedStartDeg))){
      error = (((targetVal + speedSmooth) - (fabs(getDriveL())*kPSlow)) + ((targetVal + speedSmooth) - (fabs(getDriveR())*kPSlow)))/2;
      pVal = kP*error*speedP;
    }
    setDrive(-1*pVal*dir, pVal*dir);
  }
  driveBrake();
  return 0;
}