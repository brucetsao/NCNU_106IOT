
#include <Wire.h>   // I2C must use
#include <LiquidCrystal_I2C.h>    //lcm 1602/2004 use
#include "DHT.h"
// include above


// -------------- define  following ------------
#define DHTPIN 7     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

//------------create object following -------------
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
     Serial.println("DHTxx test!");
     dht.begin();
     lcd.begin(16,2);     //begin(column,row)            // initialize the lcd 
      lcd.backlight();
     lcd.clear();
     lcd.setCursor( 0, 0 );
     
}

void loop() {
      // put your main code here, to run repeatedly:
        // Reading temperature or humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
      float h = dht.readHumidity();
      // Read temperature as Celsius (the default)
      float t = dht.readTemperature();
      // Read temperature as Fahrenheit (isFahrenheit = true)
      float f = dht.readTemperature(true);
    
      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
      }
      //   display to serial monitor
      Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t \n");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t \n");
    
      lcd.clear();    //clear lcd screen
      lcd.setCursor( 0, 0 );
       lcd.print("H: ");
      lcd.print(h);
      lcd.setCursor( 0, 1 );
       lcd.print("T: ");
      lcd.print(t);
       lcd.print("/");
      lcd.print(f);

      delay(5000) ;
}
