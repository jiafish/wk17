#include "pitches.h"

// notes in the melody:
const int btn1 = 9;
const int btn2 = 10; 
const int ledPin =  11;  
long CTime,PTime;
bool check;
int state = 0;
int bstate = 0;
int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_G4,NOTE_G5,NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_F5, NOTE_F5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_C5
};
int melody2[] = {
  NOTE_G4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
 4,4,3,2,5,4,4,4,3,2,6,4,4,4,3,2,5,2,6,4,6,4,5,2,2
};
int noteDurations2[] = {
1,1,2, 1,1,2, 1,1,1,1,1,1,2,

    1,1,2, 1,1,2, 1,1,1,1,4,
};
void setup() {
pinMode(btn1, INPUT);
}




void loop() {
  // no need to repeat the melody.

 if(digitalRead(btn1) == LOW) state = 1;
 if(digitalRead(btn2) == LOW) state = 2;

     if(state == 1){
        for(int TN=0 ; TN < 26 ; TN++ ){
        
            tone(8, melody[TN], 500);
            PTime=millis();
            digitalWrite(ledPin,HIGH);
            check=false;
            while(!check){
              CTime=millis();
              if(CTime-PTime>500) digitalWrite(ledPin,LOW);
              if(CTime-PTime>650) check=true;
               if( digitalRead(btn2) == LOW) {state = 2; check=true;}

              }
             
      }
   }
      
   if(state == 2){
          for(int TN=0;TN<24;TN++){
       
              tone(8, melody2[TN],500);
              PTime=millis();
              digitalWrite(ledPin,HIGH);
              check=false;
              while(!check){
                CTime=millis();
                if(CTime-PTime>500) digitalWrite(ledPin,LOW);
                if(CTime-PTime>650) check=true;
                if( digitalRead(btn1) == LOW ) {state = 1; check=true;}
                }
                 
        }
    }

}
