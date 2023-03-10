//#include "WString.h"
void saludo() {
  Datos = "HOLA";
  shiftR.print(&Datos);
  delay(500);
  Datos = "22.02";  //Fecha de la ultima Modificacion
  shiftR.print(&Datos);
  delay(500);
}

void ImprimirSerial(double prom_a0, double prom_a1) {
  Serial.print("Promedio A0  ");
  Serial.print(prom_a0);
  Serial.print("  Promedio A1  ");
  Serial.println(prom_a1);
  //Serial.println("--------------------------------------------------String de salida");
  Serial.println(Datos);
  //Serial.println("--------------------------------------------------String de salida");
}

void leerPot() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  double prom_a0 = 0;  //Promedio Potenciometro 0
  double a02 = 0;
  double prom_a1 = 0;
  double a16 = 0;
  double i = 0;
  double V0ant = 0;
  double j = 0;
  double v0nuev = 0;
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

  int val0 = prom_a0;
  int val1 = prom_a1;

  Datos = "";
  if (val1 < 10) {
    Datos = "0";
  }
  Datos += val1;

  Datos += ".";  //si agrego este punto la lungitud excede el alrgo de la pantalla y no funciona como deberia

  if (val0 < 10) {
    Datos += "0";
  }
  Datos += val0;
  ImprimirSerial(prom_a0, prom_a1);
}

void ImprimirPantalla() {
  if (Datos != DatosAnteriores) {
    String Salida = "";
    shiftR.print(&Salida);
    delay(t * 100);
    int LargoDatos = Datos.length();
    if (LargoDatos <= NumPantallas) {
        shiftR.print(&Datos);
    } else {
      bool modo1 = true;

      for (int i = 0; i < LargoDatos; i++) {
        if(modo1){
          Salida += Datos.charAt(i);
          shiftR.print(&Salida);
        }else{
          /*Salida = (Datos.substring(0, 1 + i));
          shiftR.print(&Salida);*/

          shiftR.print(&(Datos.substring(0, 1 + i)));
        }
        delay(t * 200);
      }

    }
  }
  DatosAnteriores = Datos;
}

/*
void OtroModo() {
  if (Datos != DatosAnteriores) {
    String Salida = "";
    shiftR.print(&Salida);
    delay(t * 100);
    int LargoDatos = Datos.length();
    if (LargoDatos <= NumPantallas) 
      shiftR.print(&Datos);
    }
    else {
      for (int i = 0; i < LargoDatos; i++) {
        //Salida = (Datos.substring(i, i + 4));
        Salida = (Datos.substring(0, 1 + i));
        shiftR.print(&Salida);
        delay(t*1500);
      }
      delay(t*100);
    }
    DatosAnteriores = Datos;    
  }
}
*/
