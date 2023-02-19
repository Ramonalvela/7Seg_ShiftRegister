void saludo() {

  shiftR.print(&Datos);
  delay(1000);
  Datos = "14.02";
  shiftR.print(&Datos);
  delay(1000);
}