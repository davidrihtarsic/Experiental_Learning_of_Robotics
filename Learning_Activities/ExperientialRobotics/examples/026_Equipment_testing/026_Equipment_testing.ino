bool test_tipk = 1;
int l=1;

void setup() {
  for (int i = 0; i < 8; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  PORTD=1;
}

void loop() {
  char tipka_a4_is_pressed = !digitalRead(A4); 
  char tipka_a5_is_pressed = !digitalRead(A5); 
  if (tipka_a4_is_pressed) l = l >> 1;
  if (tipka_a5_is_pressed) l = l << 1;
  if (tipka_a4_is_pressed && tipka_a5_is_pressed) test_tipk = !test_tipk;
  if (test_tipk){
    if (l < 1) l = 128;
    if (l > 255) l = 1;
    PORTD = l; 
  }else{
    PORTD = analogRead(A0) >> 2;
  }
  delay(200);
}
