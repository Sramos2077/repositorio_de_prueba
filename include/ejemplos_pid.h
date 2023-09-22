#include"componentes.h"
void inertialpid(int pulgadas){
  //--Constants--//
  double kp = 0.001;
  double ki = 0.001;
  double kd = 0.001;

  //--Variables--//
  int desiredValue = pulgadas;
  int currentvalue;
  int error;
  int previouserror = 0;
  int totalerror = 0;
  int derivative;

  //--PID Loop--//
  while(1){
    currentvalue = DrivetrainInertial.value(vex::voltageUnits::volt);

    // Proportional
    error = desiredValue - currentvalue;

    // Derivative
    derivative = error - previouserror;
    previouserror = error;

    // Integral
    totalerror += error;

    // Compute the output
    double output = kp * error + kd * derivative + ki * totalerror;

    // Apply the output to the drivetrain
    Drivetrain.drive(output, vex::velocityUnits::pct);
  wait(20, msec);
  }
}