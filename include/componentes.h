#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;
motor leftMotorA = motor(PORT17, ratio6_1, false);
motor leftMotorB = motor(PORT18, ratio6_1, true);
motor leftMotorC = motor(PORT16, ratio6_1, true);
motor leftMotorD = motor(PORT19, ratio6_1, false);
motor_group grupoA = motor_group(leftMotorA, leftMotorB, leftMotorC,leftMotorD); // grupo izquierda

motor rightMotorA = motor(PORT7, ratio6_1, true);
motor rightMotorB = motor(PORT8, ratio6_1, false);
motor rightMotorC = motor(PORT5, ratio6_1, false);
motor rightMotorD = motor(PORT9, ratio6_1, true);
motor_group grupoB = motor_group(rightMotorA, rightMotorB, rightMotorC,rightMotorD); // grupo derecho
motor lanzador1 = motor(PORT20, ratio36_1, false);
motor lanzador2 = motor(PORT10, ratio36_1, false);
motor_group LANZADOR = motor_group(lanzador1, lanzador2);

inertial DrivetrainInertial = inertial(PORT14);
smartdrive Drivetrain = smartdrive(grupoA, grupoB, DrivetrainInertial, 299.24,320, 40, mm, 0.6666666666666666);
motor gatillo = motor(PORT2, ratio36_1, false);

motor rodillo = motor(PORT11, ratio36_1, false);

motor banda = motor(PORT1, ratio6_1, false);

controller control = controller(primary);
