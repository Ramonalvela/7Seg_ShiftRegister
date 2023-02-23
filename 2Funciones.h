void saludo() {
  Datos = "HOLA";
  shiftR.print(&Datos);
  delay(500);
  Datos = "18.02";
  shiftR.print(&Datos);
  delay(500);
}

void leerPot() {
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
}

void ImprimirPantalla() {
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
}

void ImprimirSerial() {
  Serial.print("Promedio A0  ");
  Serial.print(prom_a0);
  Serial.print("  Promedio A1  ");
  Serial.println(prom_a1);
  //Serial.println("--------------------------------------------------String de salida");
  Serial.println(Datos);
  //Serial.println("--------------------------------------------------String de salida");
}