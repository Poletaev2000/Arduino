#include <GyverFilters.h>

GMedian<15, int> testFilter;    

#include <Adafruit_NeoPixel.h>

#define PIN 5   // input pin Neopixel is attached to

#define NUMPIXELS      9 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



int redColor = 0;
int greenColor = 0;
int blueColor = 0;
unsigned long lastflash;
int rpm;

void setup() {
  Serial.begin(9600);  //открыть порт
  attachInterrupt(0,sens,RISING); //подключить прерывание на 2 пин при повышении сигнала
  pinMode(3, OUTPUT);   //3 пин как выход
  digitalWrite(3, HIGH);  //подать 5 вольт на 3 пин

  pixels.begin();
}

void sens() {
  rpm=60/(((float)(micros()-lastflash)/1000000))/2;  //расчет
  lastflash=micros();  //запомнить время последнего оборота
    rpm = testFilter.filtered(rpm);
}
void loop() {
  if ((micros()-lastflash)>1000000){ //если сигнала нет больше секунды
    rpm=0;  //считаем что RPM 0
  }
  Serial.println(rpm);   //вывод в порт
  delay(200);  //задержка для стабильности


   pixels.clear();

   if(rpm <= 200) {
        pixels.setPixelColor(0, pixels.Color(255, 0, 0));
        pixels.setPixelColor(1, pixels.Color(0, 255, 0));
        pixels.setPixelColor(2, pixels.Color(255, 0, 0));
        pixels.setPixelColor(3, pixels.Color(0, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255, 0, 0));
        pixels.setPixelColor(5, pixels.Color(0, 255, 0));
        pixels.setPixelColor(6, pixels.Color(255, 0, 0));
        pixels.setPixelColor(7, pixels.Color(0, 255, 0));
        pixels.setPixelColor(8, pixels.Color(255, 0, 0));

pixels.show();
    delay(300);



        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
        pixels.setPixelColor(1, pixels.Color(255, 0, 0));
        pixels.setPixelColor(2, pixels.Color(0, 255, 0));
        pixels.setPixelColor(3, pixels.Color(255, 0, 0));
        pixels.setPixelColor(4, pixels.Color(0, 255, 0));
        pixels.setPixelColor(5, pixels.Color(255, 0, 0));
        pixels.setPixelColor(6, pixels.Color(0, 255, 0));
        pixels.setPixelColor(7, pixels.Color(255, 0, 0));
        pixels.setPixelColor(8, pixels.Color(0, 255, 0));
pixels.show();
    delay(300);

   }
   
if(rpm > 800 && rpm <= 1200) {
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  
   
        }

if(rpm > 1200 && rpm <= 1600) {
     
 
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));

        }

if(rpm > 1600 && rpm <= 2000) {
 
 
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
 
        }    

if(rpm > 2000 && rpm <= 2200) {
  
  
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
   pixels.setPixelColor(3, pixels.Color(255, 255, 0));
 
  

   
        }  

if(rpm > 2200 && rpm <= 2500) {
     
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
   pixels.setPixelColor(3, pixels.Color(255, 255, 0));
    pixels.setPixelColor(4, pixels.Color(255, 255, 0));
   
        }  

if(rpm > 2500 && rpm <= 2800) {
     
          pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
   pixels.setPixelColor(3, pixels.Color(255, 255, 0));
    pixels.setPixelColor(4, pixels.Color(255, 255, 0));
   pixels.setPixelColor(5, pixels.Color(255, 255, 0));
  
 
        }  

if(rpm > 2800 && rpm <= 3100) {
      
         pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
   pixels.setPixelColor(3, pixels.Color(255, 255, 0));
    pixels.setPixelColor(4, pixels.Color(255, 255, 0));
   pixels.setPixelColor(5, pixels.Color(255, 255, 0));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
    
        
 
        }  

if(rpm > 3100 && rpm <= 3400) {
      
         pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
   pixels.setPixelColor(3, pixels.Color(255, 255, 0));
    pixels.setPixelColor(4, pixels.Color(255, 255, 0));
   pixels.setPixelColor(5, pixels.Color(255, 255, 0));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
   pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  
  
}

if(rpm > 3400 && rpm <= 3800) {
       
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
   pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
   pixels.setPixelColor(3, pixels.Color(255, 255, 0));
    pixels.setPixelColor(4, pixels.Color(255, 255, 0));
   pixels.setPixelColor(5, pixels.Color(255, 255, 0));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
   pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    pixels.setPixelColor(8, pixels.Color(0, 0, 255));
 
        }  

if(rpm > 3800) {
       
        pixels.setPixelColor(0, pixels.Color(255, 0, 0));
   pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
   pixels.setPixelColor(3, pixels.Color(255, 0, 0));
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));
   pixels.setPixelColor(5, pixels.Color(255, 0, 0));
    pixels.setPixelColor(6, pixels.Color(255, 0, 0));
   pixels.setPixelColor(7, pixels.Color(255, 0, 0));
    pixels.setPixelColor(8, pixels.Color(255, 0, 0));
    
pixels.show();
    delay(300);


pixels.clear();
pixels.show();
    delay(300);
  
        }  



        
  pixels.show();
    delay(20);

}
