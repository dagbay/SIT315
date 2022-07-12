// C++ code
//

int SENSOR_PIN = A0;
int RED_LED = 2;
int WHITE_LED = 3;
int BLUE_LED = 4;

// Setup the board
void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

// This function calculates the output from the
// temp sensor and returns the temperature in celcius.
float GetTemperature() {
  int reading = analogRead(SENSOR_PIN);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  Serial.print((voltage - 0.5) * 100); Serial.println(" °C");
  return ((voltage - 0.5) * 100);
}

// This procedure compares the output of GetTemperature() and lights up
// a specific LED if it matches within the temperature range.
void CurrentLEDTemp(float temp) {
  if (temp <= 20){
    digitalWrite(BLUE_LED, HIGH); 
    digitalWrite(WHITE_LED, LOW);
    digitalWrite(RED_LED, LOW);
    Serial.println("TOO COLD");
  } else if (temp >= 21 && temp <= 30){
    digitalWrite(WHITE_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, LOW);
    Serial.println("WARM");
  } else if (temp >= 31){
    digitalWrite(RED_LED, HIGH); 
    digitalWrite(WHITE_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    Serial.println("TOO HOT");
  }
  
}

void loop()
{
  float temp = GetTemperature();
  CurrentLEDTemp(temp);
}
