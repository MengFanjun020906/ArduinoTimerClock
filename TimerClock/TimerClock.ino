#include <MsTimer2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
unsigned char hour,hour_h,hour_l,minit,minit_h,minit_l,sec,sec_h,sec_l;
LiquidCrystal_I2C lcd(0x27,16,2); //配置LCD地址及行列

void flashInter()
{
sec++;
if(sec == 60) {minit++;sec = 0; }
if(minit == 60)
{
  hour++;
  minit=0;
 if(hour == 24) hour = 0;
}
}
void setup()
{
 hour = 22;
 minit = 59;
 sec = 55;
 lcd.init(); //初始化LCD
 lcd.backlight(); //打开背光
lcd.setCursor(2,0);
 lcd.print("the time is");
lcd.setCursor(6,1);
 lcd.print(":");
 lcd.setCursor(9,1);
 lcd.print(":");
MsTimer2::set(1000,flashInter);
 MsTimer2::start();
 Serial.begin(9600);
}


void loop()
{
hour_h = hour/10;
hour_l = hour%10;
minit_h = minit/10;
minit_l = minit%10;
sec_h = sec/10;
sec_l = sec%10;
lcd.setCursor(4,1);
lcd.print(hour_h);
lcd.print(hour_l);
lcd.setCursor(7,1);
lcd.print(minit_h);
lcd.print(minit_l);
lcd.setCursor(10,1);
lcd.print(sec_h);
lcd.print(sec_l);
Serial.println(sec);
}
