#include <Servo.h>
Servo sonar_servo;
int servo_pos = 0; //dynamic servo position variable
int pos0 = 0;      //pos0 to pos180 variable stores servo position at those angles
int pos45 = 0;
int pos90 = 0;
int pos135 = 0;
int pos180 = 0;
int echo = 3;
int trig = 4;
int distant;       //distance of object from sonar
int duration;      //duration of soundwave from sonar
int min_dist0180;      //minimum distance from sonar, use if checks on pos0, pos180 etc to further sort to use in motor function
int min_dist45135;
int min_dist90;

void setup() {
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 Serial.begin(9600);
  sonar_servo.attach(6);
}

void loop() {

   //servo motion and distance calculation from postition 0 to 180
  
  for (servo_pos = 0; servo_pos <= 180; servo_pos += 45) {

  sonar_servo.write(servo_pos);
  delay(80);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo, HIGH);
  distant = duration*0.034/2;

  if (servo_pos == 0){
    pos0 = distant;
  }
  if (servo_pos == 45) {
    pos45 = distant;
  }
  if (servo_pos == 90) {
    pos90 = distant;
  }
  if (servo_pos == 135) {
    pos135 = distant;
  }
  if (servo_pos == 180) {
    pos180 = distant;
  }

  Serial.print("Pos: ");
  Serial.print(servo_pos);
  Serial.println(" ");
 Serial.print("Distance: ");
 Serial.print(distant);
 Serial.print("\t");
 Serial.print("Pos0: ");
 Serial.print(pos0);
 Serial.print("\t");
 Serial.print("Pos45: ");
 Serial.print(pos45);
 Serial.print("\t");
 Serial.print("Pos90: ");
 Serial.print(pos90);
 Serial.print("\t");
 Serial.print("Pos135: ");
 Serial.print(pos135);
 Serial.print("\t");
 Serial.print("Pos180: ");
 Serial.print(pos180);
 Serial.println(" ");
 }

 //servo position and distance calculation from 180 to 0
 
 for (servo_pos = 180; servo_pos >= 0; servo_pos -= 45) {
  sonar_servo.write(servo_pos);
  delay(80);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo, HIGH);
  distant = duration*0.034/2;
  
  if (servo_pos == 0){
    pos0 = distant;
  }
  if (servo_pos == 45) {
    pos45 = distant;
  }
  if (servo_pos == 90) {
    pos90 = distant;
  }
  if (servo_pos == 135) {
    pos135 = distant;
  }
  if (servo_pos == 180) {
    pos180 = distant;
  }

  Serial.print("Pos: ");
  Serial.print(servo_pos);
  Serial.println(" ");
 Serial.print("Distance: ");
 Serial.print(distant);
 Serial.print("\t");
 Serial.print("Pos0: ");
 Serial.print(pos0);
 Serial.print("\t");
 Serial.print("Pos45: ");
 Serial.print(pos45);
 Serial.print("\t");
 Serial.print("Pos90: ");
 Serial.print(pos90);
 Serial.print("\t");
 Serial.print("Pos135: ");
 Serial.print(pos135);
 Serial.print("\t");
 Serial.print("Pos180: ");
 Serial.print(pos180);
 Serial.println(" ");

 min_dist0180 = min(pos0, pos180);
 min_dist45135 = min(pos45, pos135);
 min_dist90 = min(pos90, 15);           //setting 15cm as the upper limit
 
 }
}
