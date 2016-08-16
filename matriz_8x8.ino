#include <LedControl.h>

int DIN = 12;//definir DIN
int CS =  11;//Definir CS
int CLK = 10;//Definir CLK

byte T[8] ={0x00, 0x7E, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00,};
byte A[8] ={0x00, 0x3C, 0x7E, 0x66, 0x7E, 0x66, 0x66, 0x00,};
byte L[8] ={0x00, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x3C, 0x00,};
byte O[8] ={0x00, 0x18, 0x3C, 0x66, 0x66, 0x3C, 0x18, 0x00,};
byte S[8] ={0x3C, 0x7E, 0x72, 0x38, 0x1C, 0x4E, 0x7E, 0x3C,};

LedControl lc = LedControl(DIN, CLK, CS, 0);
int Tiempo = 2000; //Tiempo de espera entre letra y letra

void setup()
{
  lc.shutdown(0, false); //Modo ahorro de energia desactivado
  lc.setIntensity(0, 7); // Definir el nivel de brillo 0 a 15
  lc.clearDisplay(0); // Limpiar la matriz 
}
void printByte(byte character [])//Funcion para mandar el array
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}
void loop()
{
  printByte(T);//Imprimir la letra T
  delay(Tiempo);//Esperar 2 segundos
  printByte(A);//Imprimir la letra A
  delay(Tiempo);//Esperar 2 segundos
  printByte(L);//Imprimir la letra L
  delay(Tiempo);//Esperar 2 segundos
  printByte(O);//Imprimir la letra O
  delay(Tiempo);//Esperar 2 segundos
  printByte(S);//Imprimir la letra S
  delay(Tiempo);//Esperar 2 segundos
}



