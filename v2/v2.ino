#include <LiquidCrystal.h>
#include <Keypad.h>

const int relayFireTime = 2000;  //ms
const int delayTime = 1000;      //ms
const int totalRelays = 23;
char keypressed;
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
  };
  ignite(Display display, int relayNumber) {
    display.print("Ignition!");
    digitalWrite(pinNumbers[relayNumber], HIGH);
    delay(relayFireTime);
    digitalWrite(pinNumbers[relayNumber], LOW);
    display.def();
    delay(delayTime);
  };
  fire(ButtonPad buttonPad, Display display, int relayNumber) {
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