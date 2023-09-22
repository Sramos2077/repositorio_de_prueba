/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "funciones.h"
#include "PID.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // Initializing Robot Configuration. DO NOT REMOVE!
DrivetrainInertial.calibrate();
  grupoA.setVelocity(100,pct);
   grupoA.setMaxTorque(100,pct);
   grupoB.setVelocity(100,pct);
    grupoB.setMaxTorque(100,pct);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      LANZADOR.setVelocity(100,pct);
       LANZADOR.setMaxTorque(100,pct);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        banda.setVelocity(100,pct);
         banda.setMaxTorque(100,pct);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       
          gatillo.setVelocity(100,pct);
           gatillo.setMaxTorque(100,pct);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            rodillo.setVelocity(100,pct);
            rodillo.setMaxTorque(100,pct);
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

PID();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
   grupoA.setVelocity(100,pct);
   grupoA.setMaxTorque(100,pct);
   grupoB.setVelocity(100,pct);
   grupoB.setMaxTorque(100,pct);
   grupoA.stop(hold);
   grupoB.stop(hold);
   banda.setVelocity(100,pct);
   banda.setMaxTorque(100,pct);
   banda.stop(hold);
   lanzador1.setVelocity(100,pct);
   lanzador1.setMaxTorque(100,pct);
   lanzador2.setVelocity(100,pct);
   lanzador2.setMaxTorque(100,pct);
   gatillo.setVelocity(100,pct);
   gatillo.setMaxTorque(100,pct);
   gatillo.stop(hold);

  // User control code here, inside the loop
 int x=1;
   int y=1;
  while (1) {
    if(control.Axis2.value()>10 || control.Axis2.value()< -10){
      grupoB.spin(reverse,control.Axis2.value(),percent);
    }
    else  if(control.Axis2.value()<10 || control.Axis2.value() > -10){
      grupoB.stop(hold);
    }
    grupoA.spin(reverse,control.Axis3.value(),pct);
    if(control.ButtonX.pressing() && x==1){ //si ( control.botonA. presionado ())
    banda.spin(forward);
    task::sleep(300);
    x=2;
    }
    else if(control.ButtonY.pressing()&& x==2){//si ( control.botonB. presionado ())
    banda.spin(reverse);
     task::sleep (300);
    x=1;
    }

    else if(control.ButtonA.pressing()){
      banda.stop(hold);
    }
   /* if(control.ButtonL1.pressing()){
      gatillo.spin(forward);
    
    }
    else if (control.ButtonL2.pressing() ) {
      gatillo.spin (reverse);
      
    }
    */
     
    if(control.ButtonL1.pressing()){
      gatillo.setVelocity(100,pct);
      gatillo.setMaxTorque(100,pct);

      gatillo.setTimeout(3,sec);
      gatillo.spinFor(forward,93,degrees);
      task:: sleep (100); 
      gatillo.spinFor(reverse,93,degrees);
      task::sleep(100);
    }
  
   if(control.ButtonA.pressing() && y==1){ //si ( control.botonA. presionado ())
    rodillo.spin(forward, 80,pct);
          task:: sleep (300); 

    y=2;
    }
    else if(control.ButtonA.pressing()&& y==2){//si ( control.botonB. presionado ())
     rodillo.stop();
           task:: sleep (300); 

    y=1;
    }

  
  if (control.ButtonR1.pressing() && x==1){
    LANZADOR.spin( forward, 80,pct);
    x=2;
  }
  else if (control.ButtonR2.pressing()&& x==2){
  LANZADOR.stop();
  task::sleep(300);
  x=1;
  }
  if (control.ButtonUp.pressing()&& y==1){
    LANZADOR.spin(fwd,100,pct);
    task::sleep(300);
    y=2;
  }
  else if (control.ButtonR1.pressing() && y==2){
    LANZADOR.spin(fwd,80,pct);
    task::sleep(300);
    y=1;
  }
  }
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
