#include <ShiftRegisterQ.h>

ShiftRegisterQ shiftR(1,2,3,true,4);
//ShiftRegisterQ pantalla2(13,12,11,false,10);

void setup(){

  Serial.begin(9600);
  String Datos = "24.22";
  shiftR.setPins(7,8,9);
  shiftR.print(&Datos);

//String Datos2 = "24.36";
 // pantalla2.print(&Datos2);


}
void loop(){
  
}