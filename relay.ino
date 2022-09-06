#define button 2
#define relay 13
#define c_clock 8
#define c_latch 9
#define c_data 10

const int p_display[4]={4,5,6,7};
int segmento[10]={252,96,218,242,102,182,190,224,254,246};
int t_action, reaction, best=9999;

bool aux;
void setup() {

pinMode(button, INPUT_PULLUP);

pinMode(p_display[0], OUTPUT);
pinMode(p_display[1], OUTPUT);
pinMode(p_display[2], OUTPUT);
pinMode(p_display[3], OUTPUT);

pinMode(c_clock,OUTPUT);
pinMode(c_latch,OUTPUT);
pinMode(c_data,OUTPUT);

pinMode(relay,OUTPUT);

randomSeed(A5);
attachInterrupt(digitalPinToInterrupt(button),gather,FALLING);
Serial.begin(9600);
}

void loop() {
for (int i=0; i<5; i++){
  reaction =0;
  erase();
  action();
  int amount = reaction - t_action;
  Serial.println(amount);
  if(amount>9999){
    amount = 9999;
  }
  if(amount<best){
    best=amount;
  }
  for(int i=0; i<20; i++){
    show(amount);
    delay(5);
  }
}
activate();
digitalWrite(c_latch, LOW);
shiftOut(c_data, c_clock, LSBFIRST, 2);
digitalWrite(c_latch, HIGH);
delay(3000);
for(int i=0;i<=100;i++){
  show(best);
  delay(5);
}
}

void erase(){
  for(int i=3; i>0;i--){
    digitalWrite(p_display[i], HIGH);
}
}

void activate(){
  for(int i=3; i>0;i--){
    digitalWrite(p_display[i], LOW); 
}
}

void gather(){
int wait = 0;
if(millis()-wait>600 and aux==true){
reaction = millis();
wait = millis();
digitalWrite(relay,LOW);
}
}


void action(){
  aux=false;
  int timer = random(1000,10000);
  delay(timer);
  aux=true;
  digitalWrite(relay, HIGH);
  t_action = millis();
  while(reaction==0){
    delay(50);
  }
}

void show(int answer){
  String text = String(answer);
  int l_digit = text.length();
  for(int i=0; i<l_digit; i++){
    String digit = text.substring(i, i+1);
    switch(digit.toInt()){
      case 0:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[0]);
      digitalWrite(c_latch, HIGH);
      delay(30);
      

      break;
      case 1:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[1]);
      digitalWrite(c_latch, HIGH);
      delay(30);
      
      break;
      case 2:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[2]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      break;
      case 3:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[3]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      break;
      case 4:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[4]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      case 5:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[5]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      case 6:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[6]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      case 7:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[7]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      case 8:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[8]);
      digitalWrite(c_latch, HIGH);
      delay(30);

      case 9:
      erase();
      digitalWrite(p_display[i], LOW);
      digitalWrite(c_latch, LOW);
      shiftOut(c_data, c_clock, LSBFIRST, segmento[9]);
      digitalWrite(c_latch, HIGH);
      delay(30);
      break;
    }
  }
}
