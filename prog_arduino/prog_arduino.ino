#include <HX711.h>     //Leitura amplificadores HX711


int sck = 2;
int dout_0 = 3;
int dout_1 = 4;

double reading_0;
double reading_1;

float erro_max = 80000; //Leitura erro_max vezes maior

HX711 HX_0;
HX711 HX_1;

void setup()
{
  Serial.begin(9600);
  
  pinMode(sck, INPUT);
  pinMode(dout_0, INPUT);
  pinMode(dout_1, INPUT);
  
  HX_0.begin(dout_0, sck);
  
  HX_1.begin(dout_1, sck);
  
  reading_0 = HX_0.get_units();
  reading_1 = HX_1.get_units();
  
}

void loop()
{
  double second_0 = HX_0.get_units();
  double second_1 = HX_1.get_units();
  
  if(abs(second_0) < erro_max){
    reading_0 = second_0;
  }
  
  if(abs(second_1) < erro_max){
    reading_1 = second_1;
  }
      
  Serial.print(reading_0 + reading_1);
  Serial.println(" ");
}



















