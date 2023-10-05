#define in1 13
#define in2 12
#define in3 9
#define in4 8
#define enA 11
#define enB 10
#define max_speed 255


//#define TRIG 3  // TRIG PIN connected to Analog pin 3 out
//#define ECHO 2  // ECHO PIN connected to Analog pin 2 in
//int duration = 0;
//int distance = 0;

// int M1_Speed = 250;
// int M2_Speed = 250;
 int t=700 ;
 int h=700 ;

void setup() {

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);


  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
//  pinMode(A2, I/NPUT);

//  pinMode(TRIG, OUTPUT);
//  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {

int sensors[2] = {A0 , A1};

sensors[0] = analogRead(A0);
sensors[1] = analogRead(A1);//left
//sensors[2] = analogRead(/A2);//middle


///ultrasonic code
//  digitalWrite(TRIG, LOW);  //clear trigger pin
//  delayMicroseconds(2);
//  digitalWrite(TRIG, HIGH);  //set trigger pin high for 10 msec
//  delayMicroseconds(10);
//  digitalWrite(TRIG, LOW);
//  duration = pulseIn(ECHO, HIGH);  //read echo pin return sound wave
//  distance = duration * 0.34 / 2;
//  Serial.print("distance : ");
//  Serial.println(distance);

for(int i=2;i>=0;i--){
Serial.print(sensors[i]);
Serial.print(" ");

}
Serial.println();

//
//if (distance >= 200)
//{
//A1 left inx 1
//A0 right inx 0

if (sensors[0] > t && sensors[1] > t){
  forward();
  
}
else if( sensors[0] >t && sensors[1] < t  )
{
  left();
  
}
else if( sensors[0] < t && sensors[1] >t  )
{
  right();
}

//two lines for 90 degree turn
else if(sensors[0] < t && sensors[0] < t )
{
  Stop();
  forward();
  delay(20);
}

}


void Stop() {
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
}

void backward() {
  //backward
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,100);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,99);
}

void forward() {
  //forward
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,110);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,118);
}
void left() {
  //left turn
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,89);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enB,63);
}

void right() {
  //right turn
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,83);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB,91);
}