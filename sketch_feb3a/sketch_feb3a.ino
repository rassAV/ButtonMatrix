#define p2 2 // 1 строка
#define p3 3 // 2 строка
#define p4 4 // 1 столбец
#define p5 5 // 2 столбец

bool status = true;
bool pressed = false;
int buttons = 0;

void setup() {
  pinMode(p4, INPUT_PULLUP);
  pinMode(p5, INPUT_PULLUP);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  Serial.begin(9600);
  Serial.println("\nSTART");
}

void loop() {
  if (status) {
    status = false;
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
  } else {
    status = true;
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
  }

  if (status && digitalRead(p4) == LOW) {
    buttons = buttons * 10 + 3;
    pressed = true;
  }
  if (!status && digitalRead(p4) == LOW) {
    buttons = buttons * 10 + 1;
    pressed = true;
  }
  if (status && digitalRead(p5) == LOW) {
    buttons = buttons * 10 + 4;
    pressed = true;
  }
  if (!status && digitalRead(p5) == LOW) {
    buttons = buttons * 10 + 2;
    pressed = true;
  }
  if (pressed && !status) {
    Serial.print("btn pressed ");
    Serial.println(buttons);
    buttons = 0;
    pressed = false;
  }
  delay(50);
}
