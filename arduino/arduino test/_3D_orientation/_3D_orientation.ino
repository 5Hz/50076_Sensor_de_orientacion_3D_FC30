/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por: Ezequías Calvillo                                        **
**                                                               **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el sensor de orientación FC30                    **
**                                                               **
** Este sensor indica de una manera sencilla la dirección        **
** en que está orientado:                                        **
** (portrait up/down, landscape left/right o face-up/down)       **
**                                                               **
*******************************************************************
Tabla de la verdad del sensor:

Pines
LC-PC-SIG-Posición
-0--0--0--FACE UP
-0--0--1--FACE DOWN
-0--1--0--PORTRAIT UP
-0--1--1--PORTRAIT DOWN
-1--0--0--LANDSCAPE LEFT
-1--0--1--LANDSCAPE RIGHT
-1--1--0--No aplica
-1--1--1--No aplica
*******************************************************************
*/

//Declaración de pines
const int SIG = 10;
const int PD = 11;
const int LC = 12;
const int PC = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(PD, OUTPUT);
  digitalWrite(PD, HIGH);
  //Pone los pines Landscape, Portrait y Sign como entradas 
  pinMode(LC, INPUT);
  pinMode(PC, INPUT);
  pinMode(SIG, INPUT);
}

void loop()
{
  //Lee los valores de cada pin
  boolean lc = digitalRead(LC);
  boolean pc = digitalRead(PC);
  boolean sig = digitalRead(SIG);
  //Tabla de la verdad para conocer la orientación
  if(sig ==0 && lc==0 && pc==0) Serial.println("face UP");
  if(sig ==1 && lc==0 && pc==0) Serial.println("face DOWN");
  if(sig ==0 && lc==0 && pc==1) Serial.println("Portrait UP");
  if(sig ==1 && lc==0 && pc==1) Serial.println("Portrait DOWN");
  if(sig ==1 && lc==1 && pc==0) Serial.println("Landscape LEFT");
  if(sig ==0 && lc==1 && pc==0) Serial.println("landscape RIGHT");
  //Pequeño retraso
  delay(200);
}

