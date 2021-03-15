const int ledPin = 13; //Define the LED Pin to be D13
const int ldrPin = A0; //Define the LDR pin to be A0
const int buzzPin = 9; //Define the Buzzer pin to be D9

void setup() {
  // put your setup code here, to run once:
  //Define the pins as input and output
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  //Begin serial communication for debugging
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int ldr = analogRead(ldrPin);

  if (ldr <= 200)
  {
    //LED will blink and buzzer will sound when it is dark
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(800);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
    delay(800);

    Serial.println("It is dark");
  }
  else
  {
    //The buzzer and LED will be off when there is enough light.
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
    Serial.println("It is not dark");
  }
}
