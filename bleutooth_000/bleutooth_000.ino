
#include <Servo.h>


Servo myservo;
Servo myservo1;
Servo myservo2;


int MD = 0;
int MG = 0;
int MV = 70;
int x = 10;


void setup()
{

  Serial.begin(9600);

  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);


        //test?? 
  
//  myservo.write(180);
//  delay(1000);
//  myservo.write(0);
//
//  myservo1.write(180);

//  delay(1000);
//  myservo1.write(0);
//  delay(1000);
//  
//  myservo1.write(180);
//  myservo.write(180);
//  delay(1000);
//  myservo1.write(0);
//  myservo.write(0);

}

///mysrvo down < 90 < up MG
///mysrvo1 up < 90 < down MD
// myservo2 gauche < 60 < droite

// 1 = up
// 2 = down
// gauche = 4
// droite = 3

void iniit()
{
  MD = 0;
  MG = 0;
  MV = 70;
}

void go()
{
  MG = 140 ;
  MD = 70 ; 
}

void back()
{
  MG = 0 ; 
  MD = 0 ;         
}

void loop()
{


  if (Serial.available() > 0)
  {
    char  data = Serial.read(); // reading the data received from the bluetooth module


    switch (data)
            {
              
              case '1': iniit() ; go(); break;
             
              case '2': iniit() ; back();break;
            
              case '3': MV += 10; break;
              case '4': MV -= 10; break;

              
              case '0': iniit() ; break;

              
              default : break;
      
            }
  
      
      Serial.print("data = ");
       Serial.println(data);
    
        Serial.print("MG = ");
       Serial.println(MG);
  
       Serial.print("MD = ");
       Serial.println(MD);
 
        Serial.print("MV = ");
        Serial.println(MV);
 
    
          myservo.write(MG);
          myservo1.write(MD);
           myservo2.write(MV);
        


  
  }
  
     delay(100);





}
