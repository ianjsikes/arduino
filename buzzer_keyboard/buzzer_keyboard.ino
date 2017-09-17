const int buzzerPin = 10;

int btns[] = {2,3,4,5,6};
char scale[] = "cdegaC";
int duration = 50;

int buttonState = 0;

void setup() {
  int j;
  pinMode(buzzerPin, OUTPUT);
  for (j = 0; j < 5; j++) {
    pinMode(btns[j], INPUT);
  }
}

void loop() {
  int i;
  for (i = 4; i >= 0; i--) {
    if (digitalRead(btns[i]) == HIGH) {
      tone(buzzerPin, frequency(scale[i]), duration);
      delay(duration);
      break;
    }
  }
}

int frequency(char note) {
  int i;
  const int numNotes = 8;
  char names[] = {'c','d','e','f','g','a','b','C'};
  int frequencies[] = {262,294,330,349,392,440,494,523};

  for (i=0; i<numNotes; i++) {
    if (names[i] == note) {
      return(frequencies[i]);
    }
  }
  return(0);
}

