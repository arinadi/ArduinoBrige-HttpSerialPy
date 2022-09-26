String rx;
#define LED_BUILTIN  13
#define TRIG  2
#define ECHO  4

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(TRIG, OUTPUT);//define arduino pin
  pinMode(ECHO, INPUT);//define arduino pin
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    // read the incoming byte:
    rx = Serial.readString();
    commander();
  }
}

void commander() {
  lightControll();
  getDistance();
}

void lightControll() {
  if (rx == "LON") {
    digitalWrite(LED_BUILTIN, HIGH); //turn on
    Serial.print("ON");
  }
  if (rx == "LOFF") {
    digitalWrite(LED_BUILTIN, LOW); //turn off
    Serial.print("OFF");
  }
}

void getDistance() {
  if (rx == "GDCM" || rx == "GDIN") {
    //pulse output
    digitalWrite(TRIG, LOW);
    delayMicroseconds(4);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    long t = pulseIn(ECHO, HIGH);//input pulse and save it veriable

    if (rx == "GDCM") {
      long cm = t / 29 / 2; //time convert distance
      Serial.print(cm);
    }
    if (rx == "GDIN") {
      long inches = t / 74 / 2; //time convert distance
      Serial.print(inches);
    }
    //  String inch = " inches t";
    //  String CM = " cm";

    //  Serial.print(inches +inch);//print serial monitor inches
    //  Serial.println(cm +CM);//print serial monitor cm
    //  Serial.println();//print space
  }
}
