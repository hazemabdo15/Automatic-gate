#include <Servo.h> 
#define servo 3
#define ledpin 13
#define buzzerpin 11
#define enterlrd A0
#define exitlrd A1 
int counter = 0;
int enterflag = 0;
int exitflag = 0;
int Close = 0;
int Open = 90;
Servo ser; 
void setup(){
 pinMode(ledpin,OUTPUT);
 pinMode(buzzerpin,OUTPUT);
 pinMode(enterlrd,INPUT);
 pinMode(exitlrd,INPUT);
 Serial.begin(9600);
 ser.attach(servo); 
}

void loop(){
   ser.write(Close);
   int enterstatus = analogRead(enterlrd);
   int exitstatus = analogRead(exitlrd);
   if(enterstatus < 20){
     enterflag =  1; }
   if(enterflag == 1){
      counter++;
      if(counter <= 5){
      ser.write(Open);
      delay(1000);
      ser.write(Close);}
      Serial.println(counter);
      enterflag = 0;
     }
     
   if(exitstatus < 10){
     exitflag = 1 ;}
     if(exitflag == 1){
      counter--;
      if (counter >= 0 ){ 
      ser.write(Open); //open the gate
      delay(1000);
      ser.write(Close);}
      if(counter < 0 ){
          counter = 0;  
   }
      Serial.println(counter);
      exitflag = 0;
     }
    
   if(counter > 5){
    counter = 5;
    Serial.println(counter);
    for(int i = 0;i<5;i++){
    tone(buzzerpin,100);
    digitalWrite(ledpin,HIGH);
    delay(100);
    noTone(buzzerpin);
    digitalWrite(ledpin,LOW);
    delay(100);
   }
   }
   delay(500);
}
