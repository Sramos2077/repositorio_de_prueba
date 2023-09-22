#include "componentes.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Avanzar(int dónde, int cuánto, int velocidad)  //base del motor:3
{
  if(dónde == 1)
  {
    Drivetrain.setTurnVelocity(velocidad, pct);
    Drivetrain.driveFor(forward, cuánto, inches);
  }

  else if(dónde == 2)
  {
    Drivetrain.setTurnVelocity(velocidad, pct);
    Drivetrain.driveFor(reverse, cuánto, inches);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void giro (int cuanto,int velocidad){                      // giro para los autonomos
  Drivetrain.setTurnVelocity(velocidad,pct);
  Drivetrain.turnToRotation(cuanto,degrees);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void alto (){                    //alto para la base
  Drivetrain.stop(hold);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lanzador()                    // parte del lanzador
{
  LANZADOR. spin(forward);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void percutor(int grados){
  gatillo.spinFor(forward,grados,degrees);                   // parte del gatillo
  task::sleep(200);
  gatillo.spinFor(reverse,grados,degrees);
  task::sleep (200);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rodillo1 (float segundos){                           //parte del rodillo
rodillo.spinFor(reverse,segundos,sec);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void recolector()
{
  banda.spin(fwd);
}
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}







