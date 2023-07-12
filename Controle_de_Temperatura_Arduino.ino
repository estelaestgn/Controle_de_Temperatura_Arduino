// C++ code
//
#include <TMP36.h>

#define sensor A0;
#define led 13;
#define motor 12;
#define buzzer 8;

void setup()
{
  TMP36 myTMP36(sensor, HIGH);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  float celsius = myTMP36.getTempC();
  Serial.print("Temperatura em ºC: ");
  Serial.println(celsius);
  delay(1000);
  
  if(celsius >= 30)
  {
    digitalWrite(motor, HIGH);
    Serial.print("Temperatura igual ou acima de 30ºC");
    Serial.print("Ventilador acionado");
    delay(1000);
  }
  if(celsius > 50)
  {
	digitalWrite(led, HIGH);
  	digitalWrite(buzzer, HIGH);
    Serial.print("Temperatura acima de 50ºC");
    Serial.print("EMERGÊNCIA!!!");
    delay(1000);
  }
}