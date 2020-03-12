
#include <Servo.h>


Servo myservo;

int MV = 70;


void setup()
{

  Serial.begin(9600);

  myservo.attach(9);
 
    pinMode(2, OUTPUT);
    pinMode(3 , OUTPUT);
    pinMode(4 , OUTPUT);
    pinMode(5 , OUTPUT);
    
    //ENA pwm 
    pinMode(6, OUTPUT);
    //ENB pwm 
    pinMode(11, OUTPUT);

}


void iniit()
{
  Serial.println("iniiiit");
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  digitalWrite(6, LOW);
  digitalWrite(11, LOW);

}

void vitess(int x)
{
  analogWrite(6, x);
  analogWrite(11, x);
}

void go(int x)
{
  Serial.println("Gooooo");

  vitess(x);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void back()
{
  vitess(255);
  Serial.println("  baaaaaaack");
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);        
}

void loop()
{
  if (Serial.available() > 0)
  {
    char  data = Serial.read(); // reading the data received from the bluetooth module

    switch (data)
            {
              
              case '1': iniit() ; go(255);                     break;
              case '2': iniit() ; back() ;                  break;
              case '3': MV += 10; myservo.write(MV);        break;
              case '4': MV -= 10; myservo.write(MV);        break;   
              case '0': iniit() ;                           break;

              
              default : break;
            }      
            
      Serial.print("data = ");
      Serial.println(data);
      Serial.print("MV = ");
      Serial.println(MV);
  }
     delay(100);
}
