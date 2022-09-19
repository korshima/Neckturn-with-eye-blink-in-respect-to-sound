#include <Servo.h>
int servoPin = 9;
int servoPin2 = 6;
int servoPin3 =3;  //New servo
int servoPos = 10;
int servoPos2 = 170;
int servoPos3 = 30;  //New servo
Servo myservo;    //Eyeballs movements right and left.
Servo myservo2;  // eyelid servo for up and down
Servo myservo3;   //Neck New servo
const int ledpin = 12;
const int ledpin2 = 11;
const int soundpin = A2;  // Left sound sound sensor
const int soundpin2 = A3;    // Right sound sound sensor
const float threshold = 545;
const float threshold2 = 527.5;
float soundsens;
float soundsens2;

void setup() {
 Serial.begin(9600);
 pinMode (ledpin, OUTPUT);
 pinMode (soundpin, INPUT);
 myservo.attach(servoPin);
 myservo2.attach(servoPin2);
 myservo3.attach(servoPin3);
 
}

void blinkk(){
   myservo2.write(40);
   delay (200); 
   myservo2.write(170);
   delay (200);
  }
void neckturnright(){     // Turn the neck right
   myservo3.write(80);  //135
   delay (200); 
   
  }

  void neckturnleft(){    // Turn the neck left
   myservo3.write(30);
   delay (200); 
 
  }
void believe(){
  if (soundsens>=threshold){
  digitalWrite(ledpin, HIGH);
  myservo.write(servoPos);
   myservo3.write(servoPos3);
  blinkk();
  //neckturnleft();
  delay(500); 
 }

 else if  (soundsens2>=threshold2){
  digitalWrite(ledpin2, HIGH);
  myservo.write(servoPos2);
   myservo3.write(servoPos2);
  blinkk();
 // neckturnright();
  delay (500); 
 
 }
 else {
  digitalWrite(ledpin, LOW);
  digitalWrite(ledpin2, LOW);
  myservo.write(90);
 }
  }

  
void loop(){
  digitalWrite(ledpin, LOW);
  digitalWrite(ledpin2, LOW);
  myservo.write(90);
  soundsens = analogRead(soundpin);  // Left sound sensor reading from soundpins2 analog pin.
  Serial.println ( soundsens);
  soundsens2 = analogRead(soundpin2); // Right sound sensor reading from soundpins2 analog pin.
  Serial.println ( soundsens2);
  
//if (soundsens && soundsens2 >= 0){

  believe();

}
