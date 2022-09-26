String x;
#define LED_BUILTIN  13

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); //turn on
}

void loop() {
  while(Serial.available()){
    // read the incoming byte:
    x = Serial.readString();
    light_controll(x);
    Serial.print(x);
  }
}

void light_controll(String status) {
  if (x == "ON") {
    digitalWrite(LED_BUILTIN, HIGH); //turn on
  } else {
    digitalWrite(LED_BUILTIN, LOW); //turn off
  }
}
