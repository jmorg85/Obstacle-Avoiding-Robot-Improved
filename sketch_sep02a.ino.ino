#include <AFMotor.h>

long forward_distance, left_distance, right_distance;
int trig_pin = 9;
int echo_pin = 10;
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
   motor1.setSpeed(200);
 motor2.setSpeed(200);
}

void loop() {
     forward_distance = find_distance(9, 10);
     
 if (forward_distance <= 25)
 {
 stop_motor();
 delay(1000);
   motor1.setSpeed(200);
  motor2.setSpeed(200);
 move_backward();
 delay(500);
 stop_motor();
 delay(1000);
 motor1.setSpeed(200);
  motor2.setSpeed(200);
 move_left();
 delay(500);
 left_distance = find_distance(9, 10);
 Serial.print("The left distance is ");
 Serial.print(left_distance);
 Serial.println("cm");
 stop_motor();
 delay(1000);
 motor1.setSpeed(200);
  motor2.setSpeed(200);
 move_right();
 delay(1000);
 right_distance = find_distance(9, 10);
 Serial.print("The right distance is ");
 Serial.print(right_distance);
 Serial.println("cm");
 stop_motor();
 delay(1000);
 motor1.setSpeed(200);
  motor2.setSpeed(200);
 move_left();
 delay(500);
 
 }

 else{
   move_forward();
 }

}

void move_forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void move_backward(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void move_right(){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void move_left(){
  motor1.run(BACKWARD);
  motor2.run(FORWARD); 
}

void stop_motor(){
  motor1.setSpeed(0);
  motor2.setSpeed(0);
}

long find_distance(int trig_pin, int echo_pin)
{
 long distance, duration; 
  digitalWrite(trig_pin, LOW);
   delayMicroseconds(2);
 digitalWrite(trig_pin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig_pin, LOW);
 duration = pulseIn(echo_pin, HIGH);
 distance = (duration/2)/29.1;
 Serial.print(distance);
 Serial.println("cm");
 return distance;
}

