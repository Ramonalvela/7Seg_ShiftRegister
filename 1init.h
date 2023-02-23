int NumPantallas = 4;  // Cantidad de Display's instalados
String Datos = "";
String DatosAnteriores = "";
ShiftRegisterQ shiftR(7, 8, 9, true, NumPantallas);
// shiftR.setPins(7, 8, 9);// en caso de reasignar los pines
uint16_t veces = 1000;
uint16_t Max = 100;
int8_t t = 1;
