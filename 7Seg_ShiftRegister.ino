#include <ShiftRegisterQ.h>

ShiftRegisterQ shiftR(7,8,9,true,4);
int numero = -9999;
String Datos = "";

void setup(){

  Serial.begin(9600);
 
  shiftR.setPins(7,8,9);
  

  Datos = numero;
  
  shiftR.print(&Datos);



}
void loop(){
  numero = numero + 1;
  Datos = numero;
  shiftR.print(&Datos);
  Serial.println(numero);
  delay(5);
}