#include <Wire.h>
#include <TimeLib.h>
#include <Servo.h>
#include <EEPROM.h>
#include <DS1307RTC.h>

Servo myservo;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int pos1 =0; // set time for alarm 1
int h1=22;
int m1=42;
int s1=0;
int hour1;
int minute1;
int second1;

int pos2 =0;  // set time for alarm 2
int h2=22;
int m2=42;
int s2=30;
int hour2;
int minute2;
int second2;

int pos3 =0;  // set time for alarm 3
int h3=22;
int m3=42;
int s3=40;
int hour3;
int minute3;
int second3;

int pos4 =0; // set time for alarm 4
int h4=22;
int m4=42;
int s4=30;
int hour4;
int minute4;
int second4;

int pos5 =0;  // set time for alarm 5
int h5=22;
int m5=43;
int s5=00;
int hour5;
int minute5;
int second5;

char data;

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  /*Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");*/
}

void loop() {

  if (Serial.available()) 
  {
    data = Serial.read();
  }
 
 tmElements_t tm;

  if (RTC.read(tm)) {
   // pos1 = EEPROM.read(0);
    //Serial.print("Ok, Time = ");
  hour1=tm.Hour;
  minute1=tm.Minute;
  second1=tm.Second;
  hour2=tm.Hour;
  minute2=tm.Minute;
  second2=tm.Second;
  hour3=tm.Hour;
  minute3=tm.Minute;
  second3=tm.Second;
  hour4=tm.Hour;
  minute4=tm.Minute;
  second4=tm.Second;
  hour5=tm.Hour;
  minute5=tm.Minute;
  second5=tm.Second;
  Serial.print(hour1);
  Serial.print(" ");
  Serial.print(minute1);
  Serial.print(" ");
  Serial.print(second1);
 
  if(hour1==h1 && minute1==m1 && s1==second1||data==1)
  {
  myservo.attach(10);
  Serial.print("done");
  delay(500);
  myservo.write(180);
  delay(500);
  }

  if(hour2==h2 && minute2==m2 && s2==second2||data==2)
  {
  myservo2.attach(9);
  Serial.print("done");
  delay(500);
  myservo2.write(-180);
  delay(500);
  }
    
  if(hour3==h3 && minute3==m3 && s3==second3||data==3)
  {
  Serial.print("done");
  myservo3.attach(6);
  delay(500);
  myservo3.write(-180);
  delay(500);
   
  }
  
  if(hour4==h4 && minute4==m4 && s4==second4||data==4)
  {
  Serial.print("done");
  myservo4.attach(5);
  delay(500);
  myservo4.write(-180);
  delay(500);
    
  }
  if(hour5==h5 && minute5==m5 && s5==second5||data==5)
  {
  Serial.print("done");
  myservo5.attach(3);
  delay(500);
  myservo5.write(-180);
  delay(500);
   
  }
  if(data=='1')
  {
  myservo.attach(10);
  Serial.print("done");
  delay(500);
  myservo.write(180);
  delay(1000);
 data=0;
  }

  if(data=='2')
  {
  myservo2.attach(9);
  Serial.print("done");
  delay(500);
  myservo2.write(-180);
  delay(1000);
  data=0;
  }
    
  if(data=='3')
  {
  Serial.print("done");
  myservo3.attach(6);
  delay(500);
  myservo3.write(-180);
  delay(1000);
    data=0;
  }
  
  if(data=='4')
  {
  Serial.print("done");
  myservo4.attach(5);
  delay(500);
  myservo4.write(-180);
  delay(1000);
     data=0;
  }
  if(data=='5')
  {
  Serial.print("done");
  myservo5.attach(3);
  delay(500);
  myservo5.write(-180);
  delay(1000);
   data=0;
  }

 else
 {
  myservo.detach();
  myservo2.detach();
  myservo3.detach();
  myservo4.detach();
  myservo5.detach();
 }
  
  Serial.println();
  }  
    
   else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);

}
