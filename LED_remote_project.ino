#include <IRremote.h>

int IRpin = 2;
IRrecv IR(IRpin);
decode_results results;

int button;
void setup(){
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop(){
  while(IR.decode(&results) == 0){
  }
 
  IR.resume();
  if(results.value==0xFF6897){
    button=1;
  }
  if(results.value==0xFF9867){
    button=2;
  }
  if(results.value==0xFFB04F){
    button=3;
  }
  if(results.value==0xFF30CF){
    button=4;
  }
  if(results.value==0xFF18E7){
    button=5;
  }
  if(results.value==0xFF7A85){
    button=6;
  }
  if(results.value==0xFF10EF){
    button=7;
  }
  if(results.value==0xFF38C7){
    button=8;
  }
  if(results.value==0xFF5AA5){
    button=9;
  }
  if(results.value==0xFF4AB5){
    button=0;
  }
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Serial.println(button);
  for(int b=3; b<button+3; b++)
  {
    digitalWrite(b,HIGH);
    delay(50);
    
  }
  
}
