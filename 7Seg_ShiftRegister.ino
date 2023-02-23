#include <ShiftRegisterQ.h>
#include "1init.h"
#include "2Funciones.h"
//22/02/2023
void setup() {
  Serial.begin(9600);
  Serial.println("------------------INICIO------------------");
  saludo();
  Datos = "15.600.547";
  ImprimirPantalla();
 // OtroModo();
}


void loop() {
  leerPot();
  ImprimirPantalla();


  delay(t);
}
