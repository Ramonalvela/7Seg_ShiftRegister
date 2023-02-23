#include <ShiftRegisterQ.h>
#include "1init.h"
#include "2Funciones.h"

void setup() {
  Serial.begin(9600);
  shiftR.setPins(7, 8, 9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  saludo(); 

  // a02 = 0;
  // a16 = 0;
  // prom_a0 = 0;
  // prom_a1 = 0;
  // V0ant = 0;
  // v0nuev = 0;
}


void loop() {
  leerPot();
  ImprimirPantalla();
  ImprimirSerial();

  
  delay(t);
}
