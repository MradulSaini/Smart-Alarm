#include <LiquidCrystal.h>//Please replace the single quote characters ('') with the parenthesis character (<>)

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int trigPin = 8;
const int echoPin = 9;
long duration;
int distanceCm, distanceInch;

const int led = 12;// the PWM pin the LED is attached to
const int led1=10;
const int buzzer=11;
int brightness = 0;    // how bright the LED is

void setup() {
  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(led1, OUTPUT);

}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
analogWrite(led,23);
analogWrite(led1,100);
if(distanceCm<=15)
{
  digitalWrite(led,HIGH);
  digitalWrite(led1,LOW);
  digitalWrite(buzzer,HIGH);
}
else
{
  digitalWrite(led,LOW);
  digitalWrite(led1,HIGH);
  digitalWrite(buzzer,LOW);
}
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm);
  // Prints the distance value from the sensor
  lcd.print(" cm  ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print(" in  ");
delay(10);
}
