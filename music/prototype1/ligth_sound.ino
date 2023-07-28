//Photo resistor sending the frequency to buzzer, encoder sets the delay
#define sensor A0
#define caixa 9
#define SW1 13
#define CLK1 2
#define DT 3

int freq = 30;
unsigned int delay_time = 50;

int current_state;
int last_state;

void setup() {
  pinMode(sensor,INPUT);
  pinMode(CLK1,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW1,INPUT);
  pinMode(caixa,OUTPUT); 
  last_state=digitalRead(CLK1);
  attachInterrupt(digitalPinToInterrupt(CLK1), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT), updateEncoder, CHANGE);
  Serial.begin(9600);
}

void updateEncoder(){
  current_state=digitalRead(CLK1);
  if (current_state!=last_state && current_state==1){
    if (current_state==digitalRead(DT)){
      delay_time++;
    }
    else {
      delay_time--;
    }
  }
  last_state=current_state;
  if (delay_time<=0){
    delay_time==30;
  }
}

void loop() {
  if (digitalRead(SW1)==HIGH){
    freq = analogRead(sensor);
    tone(caixa,freq*3,delay_time);
    delay(delay_time);
    noTone(caixa);
  }
}
