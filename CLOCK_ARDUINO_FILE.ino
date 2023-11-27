#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int h = 12;
int m = 0;
int s = 0;
int flag = 0;
int TIME = 0;
const int hs = A0;
const int ms = A1;
int state1 = 0;
int state2 = 0;
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(hs, INPUT_PULLUP);
  pinMode(ms, INPUT_PULLUP);
}
void loop()
{
  lcd.setCursor(0, 0);
  s = s + 1;
  lcd.print("TIME:" );
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);
  if (flag < 12) lcd.print(" AM");
  if (flag == 12) lcd.print(" PM");
  if (flag > 12) lcd.print(" PM");
  if (flag == 24) flag = 0;
  delay(1000);
  lcd.clear();
  if (s == 60)
  {
    s = 0;
    m = m + 1;
  }
  if (m == 60)
  {
    m = 0;
    h = h + 1;
    flag = flag + 1;
  }
  if (h == 13)
  {
    h = 1;
  }
  lcd.setCursor(0, 1);
  if (h <= 12 && flag < 12)
  {
    lcd.print("GOOD MORNING  ;)");
  }
  if (h == 12 || h == 1 || h == 2 || h == 3 && flag >= 12)
  {
    lcd.print("GOOD AFTERNOON:)");
  }
  if (h == 4 || h == 5 || h == 6 || h == 7 || h == 8 && flag > 12)
  {
    lcd.print("GOOD EVENING  :)");
  }
  if (h >= 9 && flag > 12)
  {
    lcd.print("GOOD NIGHT  :)");
  }
  state1 = digitalRead(hs);
  if (state1 == 0)
  {
    h = h + 1;
    flag = flag + 1;
    if (flag < 12) lcd.print(" AM");
    if (flag == 12) lcd.print(" PM");
    if (flag > 12) lcd.print(" PM");
    if (flag == 24) flag = 0;
    if (h == 13) h = 1;
  }
  state2 = digitalRead(ms);
  if (state2 == 0)
  {
    s = 0;
    m = m + 1;
  }
}