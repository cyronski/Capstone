#define SMP A0
#define RP 2
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2);
int percentage;

int MT = 1000;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor (0,0);
  lcd.print("Soil Moisture:");
  pinMode(SMP, INPUT);
  pinMode(RP, OUTPUT);
  digitalWrite(RP, LOW);
}

void loop () {
  int ML = analogRead(SMP);
  delay(1000);
  percentage = map(ML, 0, 1023, 0, 100); // corrected mapping
  lcd.setCursor(0, 1);
  lcd.print(percentage);
  if (ML<MT){
    digitalWrite(RP, HIGH);
    Serial.println("DRY");
    delay(1000);
  }
  else if(ML<MT)
    digitalWrite(RP, LOW);
    Serial.println("WET");
    delay(1000);
  }
