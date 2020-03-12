
#include <Servo.h>


Servo myservo;
Servo myservo1;
Servo myservo2;


int MD = 90;
int MG = 90;
int MV = 70;
int x = 10;


void setup() 
{
  
Serial.begin(9600);

myservo.attach(9);
myservo1.attach(10);
myservo2.attach(11);


 
}

///mysrvo down < 90 < up MG
///mysrvo1 up < 90 < down MD 
// myservo2 gauche < 60 < droite 

// 1 = up 
// 2 = down 
// gauche = 4 
// droite = 3

void loop() 
{

//
//
// if(Serial.available()>0)
//   {     
//      char data= Serial.read(); // reading the data received from the bluetooth module
//      
//      
//      switch(data)
//      {
//        //case '1': if (MG < 90) MG = 90; if (MD > 90) MD = 90; else { MG += x ; MD -= x ;} break; 
//        case '1' : MG = 100 ; MD = 100; break;
//        case '2' : MD = 80 ; MG = 80 ; break;
//        //case '2': if (MG > 90) MG = 90; if (MD < 90) MD = 90; else { MG -= x ; MD += x ;} ;break; 
//        
//        case '3': MV += 10; break; 
//        case '4': MV -= 10; break; 
//       
//        default : break;
//      
//      }
//      
// //      Les extrimite :
// 
//// 
////      if (MG >= 180)
////          MG = 180;
////      if (MG <= 0)
////            MG = 0;
////
////       if (MD >= 180)
////          MD = 180;
////       if (MD <= 0)
////           MD = 0;
//           
//       if (MV <= 10)
//        MV = 10;
//       else if (MV >= 110 )
//        MV = 110;
//      
//      Serial.print("data = ");
//      Serial.println(data);
//      
//      Serial.print("MG = ");
//      Serial.println(MG);
//      
//      Serial.print("MD = ");
//      Serial.println(MD);
//
//      Serial.print("MV = ");
//      Serial.println(MV);
//      
//      myservo.write(MG);
//      myservo1.write(MD);
//      myservo2.write(MV);
//   }
//   
//   delay(50);

myservo.write(60);



}
