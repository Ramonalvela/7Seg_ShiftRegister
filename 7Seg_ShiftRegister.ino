#include <ShiftRegisterQ.h>

ShiftRegisterQ shiftR(1,2,3,true,4);


void setup(){

  Serial.begin(9600);
  String Datos = "HOLA";
  shiftR.setPins(7,8,9);
  shiftR.print(&Datos);




}
void loop(){
  
}