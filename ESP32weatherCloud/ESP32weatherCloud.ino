#include <WiFi.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

const char *ssid = "Wi-Fi Network 5.0GHz";
const char *password = "februari094";
String APIKEY = "cfe7422fdd687e61e56ca6f4a889bd59";
String CityID = "1636884";
bool id = false;
WiFiClient client;
char servername[] = "api.openweathermap.org";
String result;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "my.pool.ntp.org", 25200, 60000); // kathmandu is GMT +5.45 so 19620 is the value. Just multiply your GMT with 3600 and you will get your value.

String formattedDate;
String dayStamp;
String timeStamp;

void setup()
{
  Serial.begin(115200);
  Serial.print("Connecting to ");
  WiFi.mode(WIFI_STA);
  Serial.println(ssid);
  WiFi.begin("ABDANSB", "00000000");

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(200);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Connecting.");
  display.display();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
  }

  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connected ");
  display.println("IP Address: ");
  display.println(WiFi.localIP());
  display.display();
  delay(1000);
  display.clearDisplay();
  timeClient.begin();
}

void loop()
{
  timeClient.update();
  if (client.connect(servername, 80))
  {
    client.println("GET /data/2.5/weather?id=" + CityID + "&units=metric&APPID=" + APIKEY);
    client.println("Host: api.openweathermap.org");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();
  }
  else
  {
    Serial.println("connection failed");
    Serial.println();
  }

  while (client.connected() && !client.available())
    delay(1);
  while (client.connected() || client.available())
  {
    char c = client.read();
    result = result + c;
  }

  client.stop();
  result.replace('[', ' ');
  result.replace(']', ' ');

  char jsonArray[result.length() + 1];
  result.toCharArray(jsonArray, sizeof(jsonArray));
  jsonArray[result.length() + 1] = '\0';
  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, jsonArray);

  if (error)
  {
    Serial.print(F("deserializeJson() failed with code "));
    Serial.println(error.c_str());
    return;
  }

  String location = doc["name"];
  String country = doc["sys"]["country"];
  int temperature = doc["main"]["temp"];
  int humidity = doc["main"]["humidity"];
  float pressure = doc["main"]["pressure"];
  int id = doc["id"];
  float Speed = doc["wind"]["speed"];
  int degree = doc["wind"]["deg"];
  float longitude = doc["coord"]["lon"];
  float latitude = doc["coord"]["lat"];

  Serial.println();
  Serial.print("Country: ");
  Serial.println(country);
  Serial.print("Location:");
  Serial.println(location);
  Serial.print("Location ID: ");
  Serial.println(id);
  Serial.printf("Temperature: %d°C\r\n", temperature);
  Serial.printf("Humidity: %d %%\r\n", humidity);
  Serial.printf("Pressure: %.2f hpa\r\n", pressure);
  Serial.printf("Wind speed: %.1f m/s\r\n", Speed);
  Serial.printf("Wind degree: %d°\r\n", degree);
  Serial.printf("Longitude: %.2f\r\n", longitude);
  Serial.printf("Latitude: %.2f\r\n", latitude);

  formattedDate = timeClient.getFormattedTime();
  Serial.println(formattedDate);

  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  Serial.print("DATE: ");
  Serial.println(dayStamp);

  timeStamp = formattedDate.substring(splitT + 1, formattedDate.length() - 1);
  Serial.print("HOUR: ");
  Serial.println(timeStamp);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.print("Location:");
  display.print(country);
  display.print(" ");
  display.println(location);

  display.println();
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  display.print("T: ");
  display.print(temperature);
  display.print((char)247);
  display.print("C     ");
  display.print("H: ");
  display.print(humidity);
  display.println("%  ");
  display.print("Pressure:");
  display.print(pressure);
  display.println("hpa");
  display.print("WS: ");
  display.print(Speed);
  display.print("m/s  ");
  display.print("WA: ");
  display.print(degree);
  display.println((char)247);
  display.print("Lat: ");
  display.print(latitude);
  display.print(" ");
  display.print("Lon: ");
  display.println(longitude);
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);

  display.print("Date: ");
  display.println(dayStamp);
  display.print("Time: ");
  display.println(timeStamp);

  display.display();

  delay(6000);
}
