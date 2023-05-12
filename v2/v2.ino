#include <LiquidCrystal.h>
#include <Keypad.h>

const int Relay1 = 22;                 //relay pins
const int Relay2 = 24;
const int Relay3 = 26;
const int Relay4 = 28;
const int Relay5 = 30;
const int Relay6 = 32;
const int Relay7 = 34;
const int Relay8 = 36;
const int Relay9 = 23;
const int Relay10 = 25;
const int Relay11 = 27;
const int Relay12 = 29;
const int Relay13 = 31;
const int Relay14 = 33;
const int Relay15 = 35;
const int Relay16 = 37;
const int Relay17 = 38;
const int Relay18 = 40;
const int Relay19 = 42;
const int Relay20 = 44;
const int Relay21 = 46;
const int Relay22 = 48;
const int Relay23 = 50;
const int Relay24 = 52;
           
const int contrelaypin = 9;    //pin for continuity relay/light
const int contlightpin = 11;
const int armlightpin = 10;     //pin for arm light
const int disabledlightpin = 12;   //pin for diabled light/not armed or cont mode light

const int LCDRSpin = 14;    //lcd pins
const int LCDEpin = 15;
const int LCDD4 = 16;
const int LCDD5 = 17;
const int LCDD6 = 18;
const int LCDD7 = 19;

const char KR0 = A7;        //keypad pins 
const char KR1 = A6;       // KR= rows KC= columns
const char KR2 = A5;
const char KR3 = A4;
const char KC0 = A3;
const char KC1 = A2;
const char KC2 = A1;
const char KC3 = A0;

const int relayFireTime = 2000;  //ms
const int delayTime = 1000;      //ms
const int totalRelays = 23;
char keypressed;
static bool armed = false;
static bool continuity = false;
void setup() {

}

void loop() {
}
class Display {
public:
  static LiquidCrystal lcd;
  display(int LCDRSpin, int LCDEpin, int LCDD4, int LCDD5, int LCDD6, int LCDD7) {
    static LiquidCrystal lcd(LCDRSpin, LCDEpin, LCDD4, LCDD5, LCDD6, LCDD7);
  };
  startUp() {
    lcd.begin(16, 2);
    lcd.home();
    lcd.print("Firework Control");
    lcd.setCursor(0, 1);
    lcd.print("Board v3.0.3");
    lcd.setCursor(0, 0);
    delay(delayTime);
    lcd.clear();
    lcd.print("Enter Command");
  };
  clear() {
    lcd.clear();
    lcd.setCursor(0, 0);
  };
  print(String text, String text2 = "") {
    clear();
    lcd.print(text);
    if (sizeof(text2) > 0) {
      lcd.setCursor(0, 1);
      lcd.print(text2);
    };
  };
  //default state
  def() {
    clear();
    lcd.print("Enter Command");
  };
};
class ButtonPad {
public:
  static Keypad myKeypad;
  ButtonPad(char KR0, char KR1, char KR2, char KR3, char KC0, char KC1, char KC2, char KC3) {
    char keymap[4][4] =  //keypad config
      {
        { '1', '2', '3', 'A' },
        { '4', '5', '6', 'B' },
        { '7', '8', '9', 'C' },
        { '*', '0', '#', 'D' }
      };
    byte rowPins[4] = { KR0, KR1, KR2, KR3 };  //rows 0 to 3
    byte colPins[4] = { KC0, KC1, KC2, KC3 };  //Columns 0 to 3
   myKeypad = Keypad::Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);
  };
  char getKey() {
    return myKeypad.getKey();
  }
};

class Relay {
public:
  static int pinNumbers[totalRelays];
  Relay(int pins[totalRelays]) {
    pinNumbers[totalRelays] = pins[totalRelays];
    for (int i = 0; i < sizeof(pinNumbers); i++) {
      digitalWrite(pinNumbers[i], HIGH);
    };
  };
  void ignite(Display display, int relayNumber) {
    display.print("Ignition!");
    digitalWrite(pinNumbers[relayNumber], HIGH);
    delay(relayFireTime);
    digitalWrite(pinNumbers[relayNumber], LOW);
    display.def();
    delay(delayTime);
  };
  void fire(ButtonPad buttonPad, Display display, int relayNumber) {
    String message = "Fire";
    String number = String(relayNumber + 1);
    message += number;
    message += "?";
    display.print("Are you sure?", message);
    keypressed = buttonPad.getKey();
    if (keypressed == "#") {
      ignite(display, relayNumber);
    } else if (keypressed == "*") {
      display.print("Canceled");
    }
  };
};