volatile uint8_t timeOff = 20;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, dec, FALLING);
  attachInterrupt(1, inc, FALLING);
}

void loop() {
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(timeOff);
}

void dec()
{
  timeOff--;
}

void inc()
{
  timeOff++;
}
