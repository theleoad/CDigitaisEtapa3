#include<LiquidCrystal.h>

int va = 0;
int vb = 0;
int vc = 0;
int vd = 0;

int ve = 0;
int vf = 0;
int vg = 0;
int vh = 0;

int v1 = 1;
int v2 = 2;
int v3 = 3;
int v4 = 4;

int contesq = 0;
int contdir = 0;

char sinal;

int ler = 0;

int resultado = 0;

LiquidCrystal lcd(4, 5, 0, 1, 2, 3);


void setup()
{
  pinMode(A0,INPUT);
  
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
 lcd.begin(16, 2);
 
 lcd.setCursor(0,0);
 lcd.print("Soma:1/Subtrai:0");
  
}


int somar(int a, int b){
  int c  = 0;
  c = a + b;
  return c;
}

int subtrair(int a, int b){
  int c = 0;
  c = a - b;
  return c;
}



void loop()
{
  lcd.setCursor(2,1);
  
  ler= digitalRead(A0);
  
  va= digitalRead(6);
  vb= digitalRead(7);
  vc= digitalRead(8);
  vd= digitalRead(9);
  
  ve= digitalRead(10);
  vf= digitalRead(11);
  vg= digitalRead(12);
  vh= digitalRead(13);

  if (ve == 1){
  contesq = contesq + v4;
  }
  
  if (vf == 1){
  contesq = contesq + v3;
  }
  
  if (vg == 1){
  contesq = contesq + v2;
  }
  
  if (vh == 1){
  contesq = contesq + v1;
  }
  
   if (va == 1){
  contdir = contdir + v4;
  }
  
  if (vb == 1){
  contdir = contdir + v3;
  }
  
  if (vc == 1){
  contdir = contdir + v2;
  }
  
  if (vd == 1){
  contdir = contdir + v1;
  } 
  
  
  if (ler == 1){
    resultado = somar(contesq,contdir);
    sinal = '+';
  } else {
    resultado = subtrair(contesq,contdir);
    sinal = '-';
  		 }
  
  	
  lcd.print(contesq);
  lcd.print(sinal);
  lcd.print(contdir);
  lcd.print("=");
  
  lcd.print(resultado);
  lcd.print("      ");
  
  contesq = 0;
  contdir = 0;
  resultado = 0;
  }