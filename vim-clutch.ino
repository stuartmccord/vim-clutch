#include <TrinketKeyboard.h>

#define PIN_CLUTCH 0

boolean lastStatus = LOW;

void setup() {
  pinMode(PIN_CLUTCH, INPUT);
  digitalWrite(PIN_CLUTCH, LOW);

  TrinketKeyboard.begin();
}

void loop() {
  int keyCode;
  boolean newStatus;

  TrinketKeyboard.poll();

  newStatus = digitalRead(PIN_CLUTCH);

  if (newStatus != lastStatus) {
    if (newStatus == HIGH) {
      keyCode = KEYCODE_I;
    } else {
      keyCode = KEYCODE_ESC;
    }

    TrinketKeyboard.pressKey(0, keyCode);
    TrinketKeyboard.pressKey(0, 0);
  }
  
  lastStatus = newStatus;

}
