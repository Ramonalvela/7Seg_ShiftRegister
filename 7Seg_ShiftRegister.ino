#include <ShiftRegisterQ.h>
#include "1init.h"
#include "2Funciones.h"





void setup() {
  shiftR.setPins(7, 8, 9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  Serial.begin(9600);

  a02 = 0;
  a16 = 0;
  prom_a0 = 0;
  prom_a1 = 0;
  V0ant = 0;
  v0nuev = 0;
}


void loop() {

  prom_a0 = 0;
  prom_a1 = 0;
  for (i = 1; i <= veces; i = i + 1) {
    a02 = map(analogRead(A0), 0, 1010, 0, Max);
    prom_a0 = (a02 + prom_a0);
  }
  prom_a0 = (prom_a0 / veces);
  prom_a0 = (long)(prom_a0);

  for (j = 1; j <= veces; j = j + 1) {
    a16 = map(analogRead(A1), 0, 1010, 0, Max);
    prom_a1 = (a16 + prom_a1);
  }
  prom_a1 = (prom_a1 / veces);
  prom_a1 = (long)(prom_a1);

  Serial.print("Promedio A0  ");
  Serial.print(prom_a0);
  Serial.print("  Promedio A1  ");
  Serial.println(prom_a1);

  int val0 = prom_a0;
  int val1 = prom_a1;
  Datos = "";
  if (val1 < 10) {
    Datos = "0";
  }
  Datos += val1;

  Datos += ".";

  if (val0 < 10) {
    Datos += "0";
  }
  Datos += val0;

  shiftR.print(&Datos);


  //Serial.println("--------------------------------------------------String de salida");
  Serial.println(Datos);
  //Serial.println("--------------------------------------------------String de salida");
  delay(t);
}
