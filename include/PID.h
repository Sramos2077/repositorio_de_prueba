#include "vex.h"
#include "componentes.h"
int PID(){

/////////////////generador de voltaje///////////////
double kp=0.0;
double Ki=0.0;
double Kd=0.0;

///////////////////////////////parte matematica y logica/////////////////////////////////////7
int vd=100; //valor deseado
int va=10; //valor actual
int e;     //error
int ea=5;  //error actual
int et=100; // error total
int error_anterior;
int derivada;

while (1){
////////////////////////////////proporcional/////////////////////////////////////////////

e=vd-va;      //el error es igual valor desado - valor actual;

////////////////////////////////derivada/////////////////////////////////////////////

derivada= e-error_anterior;  //derivada = error - error anterior;


//////////////////////////////integral/////////////////////////////////////////////

et+=e;   //error total += error


error_anterior=e;

wait(20,sec);

double volttotal = kp * e +Ki * derivada + Kd * error_anterior;

banda.spin(fwd,volttotal,volt);
Brain.Screen.print("encoder del motor %d",banda.voltage(voltageUnits::volt));
/*

 int bandavolts = banda.voltage(volt);
Brain.Screen.clearScreen();
Brain.Screen.print("encoder del motor %d",banda.voltage(voltageUnits::volt));
banda.spinFor(fwd, 20, degrees);


}
*/




}

