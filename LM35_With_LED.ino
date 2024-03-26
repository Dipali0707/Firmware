const int ledPin = 13;  //LED connected to digital pin 13 
const int sensorPin = A0;  //LM35 sensor connected to A0 analog pin

unsigned long Counter = 0;

void setup() {
  pinMode(sensorPin, INPUT);  //Sets LM35 as input
  pinMode(ledPin, OUTPUT);  //Sets LED as output
}

void loop() {
  int sensorValue= analogRead(sensorPin);  //Read temperature from LM35 sensor
  float voltage= sensorValue*(5.0/1023.0);  //Conversion of sensorvalue to voltage
  float temperature= voltage*100.0;  //Conversion of voltage to temperature in Celsius
  //Check for temperature value
  if(temperature<30){  
    blinkLED(250);  //LED blinks every 250ms
  } else {
    blinkLED(500);  //LED blinks every 500ms
  }
}

void blinkLED(unsigned long interval) {
  if (Counter % (interval *2) < interval) {  //Toggle LED based on interval
    digitalWrite(ledPin, HIGH);  //Turn LED on
  }else {
    digitalWrite(ledPin, LOW);  //Turn LED off
  }
  Counter++;  //Increment loop counter
  delay(1); //Helps to stabilize the data readings
}
