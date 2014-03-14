#include <NewPing.h>

const int motor1Pin = 5;
const int motor2Pin = 6;
const int motor3Pin = 9;
const int motor4Pin = 10;

int left = 0;
int front = 0;
int right = 0;


#define TRIG1 4
#define ECHO1 3
#define TRIG2 8
#define ECHO2 7
#define TRIG3 13
#define ECHO3 12
#define MAX 200


NewPing sonar1(TRIG1,ECHO1,MAX);
NewPing sonar2(TRIG2,ECHO2,MAX);
NewPing sonar3(TRIG3,ECHO3,MAX);

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  //Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  left = sonar1.ping()/US_ROUNDTRIP_CM; // left sensor
  front = sonar2.ping()/US_ROUNDTRIP_CM; // front sensor
  right = sonar3.ping()/US_ROUNDTRIP_CM; // right sensor
 /* Serial.print("Left: "); //prints the distance for sensor one
  Serial.print(left);
  Serial.println("cm");
  Serial.print("Front: "); //prints the distance for sensor two
  Serial.print(front);
  Serial.println("cm");
  Serial.print("Right: "); //prints the distance for sensor two
  Serial.print(right);
  Serial.println("cm"); */

  if(front < 10 && front !=0)
  {
    analogWrite(motor1Pin, 0);//left motor stop
    analogWrite(motor2Pin, 0);
    analogWrite(motor3Pin, 0);//right motor stop
    analogWrite(motor4Pin, 0);
    delay(1000);
  } 
  if(left < 10 && left != 0)
  {
    digitalWrite(motor1Pin, LOW); // left motor forward
    digitalWrite(motor2Pin,HIGH);
    digitalWrite(motor3Pin,LOW); // right motor backward
    digitalWrite(motor4Pin, HIGH); 
  }
  if(left > 10 && left != 0)
  {
    digitalWrite(motor1Pin, LOW); // left motor backward
    digitalWrite(motor2Pin,HIGH);
    digitalWrite(motor3Pin,LOW); // right motor forward
    digitalWrite(motor4Pin, HIGH);
  }

  else
  {
    analogWrite(motor1Pin, 0); // left motor forward
    analogWrite(motor2Pin,255);
    analogWrite(motor3Pin,255); // right motor forward
    analogWrite(motor4Pin, 0); 
  }
}









