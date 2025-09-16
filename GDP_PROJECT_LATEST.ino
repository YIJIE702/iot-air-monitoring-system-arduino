#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>




//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 20, 4);
char auth[] = "6ND5luabF8m7SIPUUd5x0fC05KRhcnRJ";//Enter your Auth token
char ssid[] = "vivo 2006";//Enter your WIFI name
char pass[] = "12345678";//Enter your WIFI password

// Define component pins
#define led D0
#define mq135 A0
#define trig D5
#define echo D6
DHT dht(D4, DHT11); //(sensor pin,sensor type)
BlynkTimer timer;
int pinValue = 0;

void setup() {
  pinMode(mq135, INPUT);  
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Air Monitoring");
  lcd.setCursor(4, 1);
  lcd.print("System");
  delay(3000);
  lcd.clear();

//Call the functions
  timer.setInterval(100L, gassensor);
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(100L, ultrasonic);
}

//Get buttons values
BLYNK_WRITE(V0) {
  pinValue = param.asInt();
}

//Get the MQ135 sensor values
void gassensor() {
  int value = analogRead(mq135);
  Serial.print("\nGas value: "); 
  Serial.println(value);
  value = map(value, 0, 1024, 0, 100);
  if(pinValue == 1){
  if (value < 5) {
    Blynk.notify("Good air quality level.");
    lcd.setCursor(0,1); 
    lcd.print("GOOD AQ LEVEL"); 
    digitalWrite(led, LOW);
    Blynk.virtualWrite(V5,0); //LED ON
  } 
  else if (value >= 5 && value <= 40) {
    Blynk.notify("Average air quality level detected.");
    lcd.setCursor(0,1); 
    lcd.print("AVERAGE AQ LEVEL");  
    digitalWrite(led, LOW);
    Blynk.virtualWrite(V5,0); //LED ON
  }
  else if (value > 40) {
    Blynk.notify("Warning! Danger air quality level detected");
    lcd.setCursor(0,1); 
    lcd.print("DANGER AQ LEVEL");
    digitalWrite(led, HIGH);
    Blynk.virtualWrite(V5,1); //LED ON
  }
  Blynk.virtualWrite(V1, value);
  lcd.setCursor(0, 0);
  lcd.print("Gas:");
  lcd.print(" ");
  lcd.print(value);
  }
  else{
       digitalWrite(led,LOW); 
       lcd.clear();
  }
}

//Get the DHT11 sensor values
void DHT11sensor() {
  float h = dht.readHumidity();       // Read temperature as Percentage (the default) 
  float t = dht.readTemperature();    // Read temperature as Celsius (the default)  

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");  
  Serial.print(h);  
  Serial.print("\nTemperature: ");  
  Serial.print(t);  
  Serial.print("*C ");
  
  if(pinValue == 1){
  lcd.setCursor(0, 2);
  lcd.print("T: ");
  lcd.print(t);
  lcd.print("*C");
  lcd.setCursor(10, 2);
  lcd.print("H: ");
  lcd.print(h);
  lcd.print("%"); 
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
  }
  else{
       digitalWrite(led,LOW); 
       lcd.clear();
  }
}


//Get the ultrasonic sensor values
void ultrasonic() {
  digitalWrite(trig, LOW);        // Clears the trigPin
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);       // Sets the trigPin on HIGH state for 10 micro seconds 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds 
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.print("\nDistance:");  
  Serial.println(cm); 
  if(pinValue == 1){
  lcd.setCursor(0, 3);
  lcd.print("Distance:");
  lcd.print(cm);
  lcd.print("  ");
  Blynk.virtualWrite(V4, cm);
  }
  else{
       digitalWrite(led,LOW); 
       lcd.clear();
  }
}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
