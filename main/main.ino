
// note, for full build, define pins used as outputs in void setup()

#include <LiquidCrystal.h>
#include <Keypad.h>

int relayfiretime = 2000; //in ms 

#define Relay1 22                 //relay pins
#define Relay2 24
#define Relay3 26
#define Relay4 28
#define Relay5 30
#define Relay6 32
#define Relay7 34
#define Relay8 36
#define Relay9 23
#define Relay10 25
#define Relay11 27
#define Relay12 29
#define Relay13 31
#define Relay14 33
#define Relay15 35
#define Relay16 37
#define Relay17 38
#define Relay18 40
#define Relay19 42
#define Relay20 44
#define Relay21 46
#define Relay22 48
#define Relay23 50
#define Relay24 52
           
#define contrelaypin 9    //pin for continuity relay/light
#define contlightpin 11
#define armlightpin 10     //pin for arm light
#define disabledlightpin 12   //pin for diabled light/not armed or cont mode light

#define LCDRSpin 14    //lcd pins
#define LCDEpin 15
#define LCDD4 16
#define LCDD5 17
#define LCDD6 18
#define LCDD7 19 

#define KR0 A7        //keypad pins 
#define KR1 A6        // KR= rows KC= columns
#define KR2 A5
#define KR3 A4
#define KC0 A3
#define KC1 A2
#define KC2 A1
#define KC3 A0
 
char keypressed;                 //where codes stored

char confcode[]= {'*'};          //code to confirm fire
char cancelcode[]= {'0'};        //code to cancel 
char lolcode[]={'6','7','8','9'};   //easter egg :)
char code[]= {'1','2','3','4'};  //arm code

char code0[]= {'1'};
char code1[]= {'2'};   //codes for determining which queue number is pressed (DO NOT CHANGE)
char code2[]= {'3'};
char code3[]= {'4'};
char code4[]= {'5'};
char code5[]= {'6'};
char code6[]= {'7'};
char code7[]= {'8'};
char code8[]= {'9'};
char code9[]= {'1','0'};
char code10[]= {'1','1'};
char code11[]= {'1','2'};
char code12[]= {'1','3'};
char code13[]= {'1','4'};
char code14[]= {'1','5'};
char code15[]= {'1','6'};
char code16[]= {'1','7'};
char code17[]= {'1','8'};
char code18[]= {'1','9'};
char code19[]= {'2','0'};
char code20[]= {'2','1'};
char code21[]= {'2','2'};
char code22[]= {'2','3'};
char code23[]= {'2','4'};

short a=0,i=0,s=0,j=0;          // passcode var. (DO NOT CHANGE)
short aa=0,ii=0,jj=0;
short a0=0,i0=0,j0=0;           // var for relay getcode (DO NOT CHANGE)
short a1=0,i1=0,j1=0;
short a2=0,i2=0,j2=0;
short a3=0,i3=0,j3=0;    
short a4=0,i4=0,j4=0;
short a5=0,i5=0,j5=0;
short a6=0,i6=0,j6=0;
short a7=0,i7=0,j7=0;
short a8=0,i8=0,j8=0;
short a9=0,i9=0,j9=0;
short a10=0,i10=0,j10=0;
short a11=0,i11=0,j11=0;
short a12=0,i12=0,j12=0;
short a13=0,i13=0,j13=0;
short a14=0,i14=0,j14=0;
short a15=0,i15=0,j15=0;
short a16=0,i16=0,j16=0;
short a17=0,i17=0,j17=0;
short a18=0,i18=0,j18=0;
short a19=0,i19=0,j19=0;
short a20=0,i20=0,j20=0;
short a21=0,i21=0,j21=0;
short a22=0,i22=0,j22=0;
short a23=0,i23=0,j23=0;

short c=0,b=0;      
short c0=0,b0=0;
short x = 0;

const byte numRows= 4;          //number of rows on the keypad
const byte numCols= 4;          //number of columns on the keypad

char keymap[numRows][numCols]= //keypad config
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {KR0, KR1, KR2, KR3}; //rows 0 to 3
byte colPins[numCols]= {KC0, KC1, KC2, KC3}; //Columns 0 to 3

LiquidCrystal lcd(LCDRSpin, LCDEpin,LCDD4, LCDD5, LCDD6, LCDD7);
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);



//expieremental var


void setup(){

digitalWrite(Relay1,HIGH);
digitalWrite(Relay2,HIGH);
digitalWrite(Relay3,HIGH);
digitalWrite(Relay4,HIGH);
digitalWrite(Relay5,HIGH);
digitalWrite(Relay6,HIGH);
digitalWrite(Relay7,HIGH);
digitalWrite(Relay8,HIGH);
digitalWrite(Relay9,HIGH);
digitalWrite(Relay10,HIGH);
digitalWrite(Relay11,HIGH);
digitalWrite(Relay12,HIGH);
digitalWrite(Relay13,HIGH);
digitalWrite(Relay14,HIGH);
digitalWrite(Relay15,HIGH);
digitalWrite(Relay16,HIGH);
digitalWrite(Relay17,HIGH);
digitalWrite(Relay18,HIGH);
digitalWrite(Relay19,HIGH);
digitalWrite(Relay20,HIGH);
digitalWrite(Relay20,HIGH);
digitalWrite(Relay21,HIGH);
digitalWrite(Relay22,HIGH);
digitalWrite(Relay23,HIGH);
digitalWrite(Relay24,HIGH);

  
pinMode(Relay1,OUTPUT);
pinMode(Relay2,OUTPUT);
pinMode(Relay3,OUTPUT);
pinMode(Relay4,OUTPUT);
pinMode(Relay5,OUTPUT);
pinMode(Relay6,OUTPUT);
pinMode(Relay7,OUTPUT);
pinMode(Relay8,OUTPUT);
pinMode(Relay9,OUTPUT);
pinMode(Relay10,OUTPUT);
pinMode(Relay11,OUTPUT);
pinMode(Relay12,OUTPUT);
pinMode(Relay13,OUTPUT);
pinMode(Relay14,OUTPUT);
pinMode(Relay15,OUTPUT);
pinMode(Relay16,OUTPUT);
pinMode(Relay17,OUTPUT);
pinMode(Relay18,OUTPUT);
pinMode(Relay19,OUTPUT);
pinMode(Relay20,OUTPUT);
pinMode(Relay21,OUTPUT);
pinMode(Relay22,OUTPUT);
pinMode(Relay23,OUTPUT);
pinMode(Relay24,OUTPUT);
pinMode(contrelaypin,OUTPUT);
pinMode(armlightpin,OUTPUT);
pinMode(disabledlightpin,OUTPUT);

  
  lcd.begin(16,2);
  lcd.home();
  lcd.print("Firework Control");
  lcd.setCursor(0,1);
  lcd.print("Board v3.0.3");
  lcd.setCursor(0,0);
  delay(1000);
  lcd.clear();
  lcd.print("Enter Command");                               
}

void loop()
{
  static int armed = false;
  static int contrelay = 0; 
  keypressed = myKeypad.getKey();               //Constantly waiting for a key to be pressed
  
  if(keypressed == 'A'){                      // A to get arm code menu
    if(armed==false){
    if(contrelay == 0){ 
          lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Enter code");            
            GetCode();                          
           if(a==sizeof(code)) {          
                  armed = true;                   
            lcd.clear();
                   lcd.print("Armed");
                 }
      else if(aa==sizeof(lolcode)) {
            lcd.clear();
            lcd.print("lol, easter egg");
      }
           else{
                  lcd.clear();               
                  lcd.print("Wrong");          
                  }
            delay(2000);
            lcd.clear();
            lcd.print("Enter Command");             //Return to standby mode it's the message do display when waiting
     } else if(contrelay ==1){
      
      lcd.clear();
      lcd.print("Err Cont Mode ON");
      delay(1500);
      lcd.clear();
      lcd.print("Enter Command");
    }
   }
      else if(armed==true){
        lcd.clear();
        lcd.print("Already Armed");
        delay(1000);
        lcd.clear();
        lcd.print("Enter Command");
     
      }
  }
 
  if(keypressed == 'B'){
    if(armed == true){
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Enter Queue #:");
    GetCode0();
       if(a0==sizeof(code0)){           //The GetCode function assign a value to a (it's correct when it has the size of the code array)
         testcode0();    
      }
      else if(a1==sizeof(code1)){   
         testcode1();
      }
      else if(a2==sizeof(code2)){
         testcode2();
      }
      else if(a3==sizeof(code3)){
         testcode3();  
      }
      else if(a4==sizeof(code4)){
        testcode4(); 
      }
       else if(a5==sizeof(code5)){
        testcode5();
      }
      else if(a6==sizeof(code6)){
        testcode6();      
      }
       else if(a7==sizeof(code7)){
        testcode7();
      }
      else if(a8==sizeof(code8)){
        testcode8();     
      }
       else if(a9==sizeof(code9)){
        testcode9();
      }
       else if(a10==sizeof(code10)){
        testcode10();
      }
      else if(a11==sizeof(code11)){
        testcode11();    
      }
       else if(a12==sizeof(code12)){
        testcode12();     
      }
       else if(a13==sizeof(code13)){
        testcode13();
      }
       else if(a14==sizeof(code14)){
        testcode14();          
      }
       else if(a15==sizeof(code15)){
        testcode15();       
      }
       else if(a16==sizeof(code16)){
        testcode16();    
      }
       else if(a17==sizeof(code17)){
        testcode17();   
      }
      else if(a18==sizeof(code18)){
        testcode18();
      }
       else if(a19==sizeof(code19)){
        testcode19();   
      }
       else if(a20==sizeof(code20)){
        testcode20();     
      }
       else if(a21==sizeof(code21)){
        testcode21();
      }
       else if(a22==sizeof(code22)){
        testcode22();
      }
       else if(a23==sizeof(code23)){
         testcode23();  
      }
      else{
             lcd.clear();               
             lcd.print("Not a Queue");          
      }
      delay(1000);
      lcd.clear();
      lcd.print("Enter Command");
      
  }else{ 
    lcd.clear();
      lcd.print("Not Armed");
    delay (1500);
     lcd.clear();
     lcd.print("Enter Command"); 
    } 
  }
  
  if(keypressed=='D'){
    armed=false;
    lcd.clear();
    lcd.print("Not Armed");
    delay(1500);
    lcd.clear();
    lcd.print("Enter Command");
  }


     if(armed==true){      
       digitalWrite(armlightpin,HIGH);
     }                        //arm light
  else if(armed==false){
        digitalWrite(armlightpin,LOW);
     
     }
     if(armed==false && contrelay==0){
        digitalWrite(disabledlightpin,HIGH); 
     }
     else{
      digitalWrite(disabledlightpin,LOW);
    }
  if(keypressed=='C'){
    if(armed==false){
       if(contrelay==0){
         digitalWrite(disabledlightpin,LOW);
         digitalWrite(contrelaypin, HIGH);
         digitalWrite(contlightpin, HIGH);
          contrelay = 1;
              lcd.clear();
              lcd.print("Cont Mode ON");
            delay(1000);
           lcd.clear();
           lcd.print("Enter Command");
         }
       else if(contrelay==1){
           digitalWrite(disabledlightpin,HIGH);
           digitalWrite(contrelaypin, LOW);
           digitalWrite(contlightpin, LOW);
           contrelay = 0;
              lcd.clear();
              lcd.print("Cont Mode OFF");
            delay(1000);
           lcd.clear();
           lcd.print("Enter Command");
           }
      }
    else if(armed==true){
      lcd.clear();
      lcd.print("ERR: Armed");
      delay(1500);
      lcd.clear();
      lcd.print("Enter Command");
    }
  }
 if(keypressed=='1'){
  sequencefire(); 
 }

  
  }

void GetCode(){                  //Getting code sequence
       i=0;                      //All variables set to 0
       a=0;
       j=0; 
       ii=0;
       aa=0;
       
                                     
     while(keypressed != '#'){                                     //The user press # to confirm the code otherwise he can keep typing
           keypressed = myKeypad.getKey();                         
             if(keypressed != NO_KEY && keypressed != '#' ){       //If the char typed isn't # and neither "nothing"
              lcd.setCursor(j,1);                                  //This to write "*" on the LCD whenever a key is pressed it's position is controlled by j
              lcd.print('*');
              j++;
            if(keypressed == code[i]&& i<sizeof(code)){            //if the char typed is correct a and i increments to verify the next caracter
                 a++;                                              
                 i++;
                 }
              else{
                a--;                                               //if the character typed is wrong a decrements and cannot equal the size of code []
               }
              if(keypressed == lolcode[ii]&& ii<sizeof(lolcode)){            //if the char typed is correct a and i increments to verify the next caracter
                 aa++;                                              
                 ii++;
                 }
                else{
                aa--;                                               //if the character typed is wrong a decrements and cannot equal the size of code []
               }
             }
            }
    keypressed = NO_KEY;

}

void GetCode0(){                  //Getting code sequence
       i0=0;a0=0;j0=0;
       i1=0;a1=0;
       i2=0;a2=0;
       i3=0;a3=0;
       i4=0;a4=0;
       i5=0;a5=0;
       i6=0;a6=0;
     i7=0;a7=0;
       i8=0;a8=0;
       i9=0;a9=0;
       i10=0;a10=0;
       i11=0;a11=0;
       i12=0;a12=0;
       i13=0;a13=0;
       i14=0;a14=0;
       i15=0;a15=0;
       i16=0;a16=0;
       i17=0;a17=0;
       i18=0;a18=0;
       i19=0;a19=0;
       i20=0;a20=0;
       i21=0;a21=0;
       i22=0;a22=0;
       i23=0;a23=0;
  
     while(keypressed != '#'){                                     //The user press # to confirm the code otherwise he can keep typing
           keypressed = myKeypad.getKey();                         
             if(keypressed != NO_KEY && keypressed != '#' ){       //If the char typed isn't # and neither "nothing"
              lcd.setCursor(j0,1);                                  //This to write "*" on the LCD whenever a key is pressed it's position is controlled by j
              lcd.print(keypressed);
              j0++;
            if(keypressed == code0[i0]&& i0<sizeof(code0)){            //if the char typed is correct a and i increments to verify the next caracter
                 a0++;                                              
                 i0++;
                 
            } else {
              a0--;
            }
            if(keypressed == code1[i1]&& i1<sizeof(code1)){
                 a1++;
                 i1++;
              
            }else{
                                                               //if the character typed is wrong a decrements and cannot equal the size of code []
                  a1--;
              }
            if(keypressed == code2[i2]&&i2<sizeof(code2)){
                 a2++;
                 i2++;
               }else{
                 a2--;
               }
            if(keypressed == code3[i3]&&i3<sizeof(code3)){
                 a3++;
                 i3++;
               }else{
                 a3--;
               }
             
             if(keypressed == code4[i4]&&i4<sizeof(code4)){
                 a4++;
                 i4++;
               }else{
                 a4--;
               }
             
             if(keypressed == code5[i5]&&i5<sizeof(code5)){
                 a5++;
                 i5++;
               }else{
                 a5--;
               }
             if(keypressed == code6[i6]&&i6<sizeof(code6)){
                 a6++;
                 i6++;
               }else{
                 a6--;
               }
             if(keypressed == code7[i7]&&i7<sizeof(code7)){
                 a7++;
                 i7++;
               }else{
                 a7--;
               }
             
             if(keypressed == code8[i8]&&i8<sizeof(code8)){
                 a8++;
                 i8++;
               }else{
                 a8--;
               }
             
             if(keypressed == code9[i9]&&i9<sizeof(code9)){
                 a9++;
                 i9++;
               }else{
                 a9--;
               }
             
             if(keypressed == code10[i10]&&i10<sizeof(code10)){
                 a10++;
                 i10++;
               }else{
                 a10--;
               }
             
             if(keypressed == code11[i11]&&i11<sizeof(code11)){
                 a11++;
                 i11++;
               }else{
                 a11--;
               }
             
             if(keypressed == code12[i12]&&i12<sizeof(code12)){
                 a12++;
                 i12++;
               }else{
                 a12--;
               }
               
             if(keypressed == code13[i13]&&i13<sizeof(code13)){
                 a13++;
                 i13++;
               }else{
                 a13--;
               }
             
             if(keypressed == code14[i14]&&i14<sizeof(code14)){
                 a14++;
                 i14++;
               }else{
                 a14--;
               }
             
             if(keypressed == code15[i15]&&i15<sizeof(code15)){
                 a15++;
                 i15++;
               }else{
                 a15--;
               }
             
             if(keypressed == code16[i16]&&i16<sizeof(code16)){
                 a16++;
                 i16++;
               }else{
                 a16--;
               }
             
             if(keypressed == code17[i17]&&i17<sizeof(code17)){
                 a17++;
                 i17++;
               }else{
                 a17--;
               }
             
             if(keypressed == code18[i18]&&i18<sizeof(code18)){
                 a18++;
                 i18++;
               }else{
                 a18--;
               }
             
             if(keypressed == code19[i19]&&i19<sizeof(code19)){
                 a19++;
                 i19++;
               }else{
                 a19--;
               }
             
             if(keypressed == code20[i20]&&i20<sizeof(code20)){
                 a20++;
                 i20++;
               }else{
                 a20--;
               }
             
             if(keypressed == code21[i21]&&i21<sizeof(code21)){
                 a21++;
                 i21++;
               }else{
                 a21--;
               }
             
             if(keypressed == code22[i22]&&i22<sizeof(code22)){
                 a22++;
                 i22++;
               }else{
                 a22--;
               }
             
             if(keypressed == code23[i23]&&i23<sizeof(code23)){
                 a23++;
                 i23++;
               }else{
                 a23--;
               }
             

             }
            }
    keypressed = NO_KEY;

}




void firer0(){                                 //seperate functions responsible for firing relays
 digitalWrite(Relay1,LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ignition!!");
   delay(relayfiretime);
   digitalWrite(Relay1, HIGH);
   delay(500); 
  lcd.clear();
  lcd.print("Enter Command");
   
 
}

void firer1(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay2,LOW); 
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay2,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}

void firer2(){
 lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay3,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay3,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer3(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay4,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay4,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer4(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay5,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay5,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer5(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay6,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay6,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer6(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay7,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay7,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer7(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay8,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay8,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer8(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay9,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay9,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer9(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay10,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay10,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer10(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay11,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay11,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer11(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay12,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay12,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer12(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay13,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay13,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer13(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay14,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay14,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer14(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay15,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay15,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer15(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay16,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay16,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer16(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay17,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay17,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer17(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay18,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay18,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer18(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay19,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay19,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer19(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay20,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay20,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer20(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay21,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay21,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer21(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay22,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay22,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer22(){
  lcd.clear();
  lcd.setCursor(0,0);
 digitalWrite(Relay23,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay23,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}
void firer23(){
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(Relay24,LOW);
  lcd.print("Ignition!!");
  delay(relayfiretime);
  digitalWrite(Relay24,HIGH);
  delay(500);
  lcd.clear();
  lcd.print("Enter Command");
}

void testcode0(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #1 ?");
        for(i=0;true;){
          
         keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer0();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}

void testcode1(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #2 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer1();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}

void testcode2(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #3 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer2();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}

void testcode3(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #4 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer3();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode4(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #5 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer4();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode5(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #6 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer5();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode6(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #7 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer6();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode7(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #8 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer7();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode8(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #9 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer8();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode9(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #10 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer9();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode10(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #11 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer10();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode11(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #12 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer11();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode12(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #13 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer12();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode13(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #14 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer13();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode14(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #15 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer14();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode15(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #16 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer15();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode16(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #17 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer16();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode17(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #18 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer17();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode18(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #19 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer18();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode19(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #20 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer19();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode20(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #21 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer20();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode21(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #22 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer21();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode22(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #23 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer22();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}
void testcode23(){
lcd.clear();
        lcd.print("Are You Sure?");
        lcd.setCursor(0,1);
        lcd.print("fire #24 ?");
        for(i=0;true;){
          
        keypressed = myKeypad.getKey();
          if(keypressed == '#'){
              firer23();
              delay(500);
              break;
         }
          else if(keypressed == '*'){
                lcd.clear();
              lcd.setCursor(0,0); 
              lcd.print("Canceled"); 
              delay(1000);
               break;
         }
        } 


}

//experimental code v4.0.0

void sequencefire(){
lcd.print("Starting Que?");
       jj0=0; 
                             
     while(keypressed != '#'){                                     
           keypressed = myKeypad.getKey();                         
             if(keypressed != NO_KEY && keypressed != '#' ){       
              lcd.setCursor(jj0,1);                                  
              lcd.print('keypressed');
              jj0++;
              
             }
            }
    keypressed = NO_KEY;



}
