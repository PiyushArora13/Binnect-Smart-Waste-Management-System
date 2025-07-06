#define BLYNK_TEMPLATE_ID           "xxxxxxxxxxxxx"
#define BLYNK_TEMPLATE_NAME         "xxxxxxxxxxxxxxx"
#define BLYNK_AUTH_TOKEN            "xxxxxxxxxxxxxx"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "xxxxxxxxxxxxxxxxxxx";  // Paste your Blynk Auth Token here
char ssid[] = "xxxxxxxxxxxxxxxxxxx";   // Your WiFi Name
char pass[] = "xxxxxxxxxxxxxxxxxxx"; // Your WiFi Password

#define TRIG_PIN D1
#define ECHO_PIN D0
#define MAX_DISTANCE 200



BlynkTimer timer;

void sendData() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration * 0.034 / 2;
    if (distance == 0 || distance > MAX_DISTANCE) distance = MAX_DISTANCE;
    
    Blynk.virtualWrite(V4, distance);
    
    // Send notification through DataStream
    if (distance < 11) {
        Blynk.virtualWrite(V5, "Overflow");
    } else {
        Blynk.virtualWrite(V5, "Safe");
    }
}

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    timer.setInterval(1000L, sendData);
}

void loop() {
    Blynk.run();
    timer.run();
}