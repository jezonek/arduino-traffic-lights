#define OFF LOW
#define ON HIGH
#define PIN_RED 8
#define PIN_YELLOW 9
#define PIN_GREEN 10
#define PIN_BUTTON 7

//This short program emulates behaviour of traffic lights with button for pedestrian, for requesting green light;

//Tested on Arduino Uno with connections:
//Red LED connected with 330Ohm resistor to pin 8;
//Yellow LED connected with 330Ohm resistor to pin 9;
//Green LED connected with 330Ohm resistor to pin 10;
//Button connected between ground and pin 7;

int DELAY_TIME = 300;

void changeLightsRedToGreen(){
  digitalWrite(PIN_RED, OFF);
  digitalWrite(PIN_YELLOW, ON);
  delay(1000);
  digitalWrite(PIN_YELLOW, OFF);
  digitalWrite(PIN_GREEN, ON);
  }

void changeLightsGreenToRed(){
  digitalWrite(PIN_GREEN, OFF);
  digitalWrite(PIN_YELLOW, ON);
  delay(1000);
  digitalWrite(PIN_YELLOW, OFF);
  digitalWrite(PIN_RED, ON);
  }

  


void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  
  digitalWrite(PIN_RED, OFF);
  digitalWrite(PIN_YELLOW, OFF);
  digitalWrite(PIN_GREEN, OFF);

  delay(500);
  
  digitalWrite(PIN_RED, OFF);
  digitalWrite(PIN_YELLOW, OFF);
  digitalWrite(PIN_GREEN, OFF);

  digitalWrite(PIN_RED, ON);
}

void loop() {
  Serial.println(digitalRead(PIN_BUTTON));
  if (digitalRead(PIN_BUTTON) == LOW){
    changeLightsRedToGreen();
    delay(5000);
    changeLightsGreenToRed();}
}
