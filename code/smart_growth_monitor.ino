#define BLYNK_TEMPLATE_ID "TMPL3DPRT_KsX" 
#define BLYNK_TEMPLATE_NAME "microgreen" 
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_TOKEN" 
#include <WiFi.h> 
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h> 
#include <DHT.h> 
#include <Wire.h> 
#include <BH1750.h> 
char ssid[] = "foo"; char pass[] = "1234567890"; 
#define DHTPIN 4 
#define DHTTYPE DHT22 DHT dht(DHTPIN, DHTTYPE); 
#define SOIL_PIN 34 BH1750 lightMeter; 
BlynkTimer timer; 
void sendSensorData() { int soilValue = analogRead(SOIL_PIN); int moisture = map(soilValue, 4095, 0, 0, 100); 
float lux = lightMeter.readLightLevel(); float temp = dht.readTemperature(); float hum = dht.readHumidity(); 
Blynk.virtualWrite(V1, moisture); Blynk.virtualWrite(V2, lux); Blynk.virtualWrite(V4, (int)temp); Blynk.virtualWrite(V5, (int)hum); 
String advice = ""; 
// Soil Moisture if (moisture < 20) advice += "Soil Too Dry  
&& moisture <= 50) advice += "Soil Best  
| "; else if (moisture >= 45 
| "; else if ((moisture >= 20 && moisture < 45) 
|| (moisture > 50 && moisture <= 70)) advice += "Soil Good | "; else advice += "Soil Too 
Wet  
| "; 
// Temperature if (temp < 15) advice += "Temp Too Low  
temp <= 30) advice += "Temp Best  
| "; else if (temp >= 28 && 
| "; else if ((temp > 15 && temp < 28) || (temp > 30 
&& temp <= 35)) advice += "Temp Good | "; else advice += "Temp Too High  
| "; 
// Humidity if (hum < 40) advice += "Humidity Too Low | "; else if (hum >= 60 && hum <= 
70) advice += "Humidity Best  
| "; else if ((hum >= 40 && hum < 60) || (hum > 70 && 
hum <= 90)) advice += "Humidity Good | "; else advice += "Humidity Too High | "; 
// Light if (lux < 20000) advice += "Light Too Low 
81000) advice += "Light Best 
"; else if (lux >= 40500 && lux <= 
"; else if ((lux >= 20000 && lux < 40500) || (lux > 81000 
&& lux < 90000)) advice += "Light Good"; else advice += "Light Too High 
Blynk.virtualWrite(V3, advice); 
"; 
// Debug Serial.println("---- Sensor Readings ----"); Serial.print("Soil Moisture: "); 
Serial.println(moisture); Serial.print("Light: "); Serial.println(lux); Serial.print("Temp: "); 
Serial.println(temp); Serial.print("Humidity: "); Serial.println(hum); Serial.print("Advice: "); 
Serial.println(advice); Serial.println("-------------------------"); } 
void setup() { Serial.begin(115200); Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
dht.begin(); Wire.begin(); lightMeter.begin(); 
timer.setInterval(7000L, sendSensorData); } 
void loop() { Blynk.run(); timer.run(); } 
