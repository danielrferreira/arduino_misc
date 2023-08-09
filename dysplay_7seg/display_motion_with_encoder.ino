//This code uses a 7 segments dysplay and an encoder

#include <TM1637Display.h>

#define CLK1 6
#define DIO 5

#define CLK2 2
#define DT 3

TM1637Display tela = TM1637Display(CLK1,DIO);

int current_state;
int last_state;

int wait_time = 200;

void updateEncoder(){
  current_state = digitalRead(CLK2);
  if (current_state != last_state && current_state == 1){
    if (digitalRead(DT) != current_state){
      wait_time+=10;
    }
    else {
      wait_time-=10;
    }
    Serial.print("Speed = ");
    Serial.println(wait_time);
  }
  if (wait_time<=0){
    wait_time=100;
  }
  last_state = current_state;
}

const uint8_t blank[] = {0, 0, 0, 0};
const uint8_t all[] = {127, 127, 127, 127};
const uint8_t circle[] = {57, 9, 9, 15};


//0-1 1-2 2-4 3-8 4-16 5-32 6-64 A-128
const uint8_t turn_A1[] = {1, 0, 0, 0};
const uint8_t turn_B1[] = {2, 0, 0, 0};
const uint8_t turn_C1[] = {4, 0, 0, 0};
const uint8_t turn_D1[] = {8, 0, 0, 0};
const uint8_t turn_E1[] = {16, 0, 0, 0};
const uint8_t turn_F1[] = {32, 0, 0, 0};
const uint8_t turn_G1[] = {64, 0, 0, 0};

const uint8_t turn_A2[] = {0, 1, 0, 0};
const uint8_t turn_B2[] = {0, 2, 0, 0};
const uint8_t turn_C2[] = {0, 4, 0, 0};
const uint8_t turn_D2[] = {0, 8, 0, 0};
const uint8_t turn_E2[] = {0, 16, 0, 0};
const uint8_t turn_F2[] = {0, 32, 0, 0};
const uint8_t turn_G2[] = {0, 64, 0, 0};

const uint8_t turn_A3[] = {0, 0, 1, 0};
const uint8_t turn_B3[] = {0, 0, 2, 0};
const uint8_t turn_C3[] = {0, 0, 4, 0};
const uint8_t turn_D3[] = {0, 0, 8, 0};
const uint8_t turn_E3[] = {0, 0, 16, 0};
const uint8_t turn_F3[] = {0, 0, 32, 0};
const uint8_t turn_G3[] = {0, 0, 64, 0};

const uint8_t turn_A4[] = {0, 0, 0, 1};
const uint8_t turn_B4[] = {0, 0, 0, 2};
const uint8_t turn_C4[] = {0, 0, 0, 4};
const uint8_t turn_D4[] = {0, 0, 0, 8};
const uint8_t turn_E4[] = {0, 0, 0, 16};
const uint8_t turn_F4[] = {0, 0, 0, 32};
const uint8_t turn_G4[] = {0, 0, 0, 64};


void setup() {
  
  pinMode(CLK2,INPUT);
  pinMode(DT,INPUT);

  Serial.begin(9600);
  
  last_state = digitalRead(CLK2);
  
  attachInterrupt(digitalPinToInterrupt(CLK2), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT), updateEncoder, CHANGE);

  tela.clear();
  tela.setBrightness(7);
  delay(1000);
  tela.setSegments(all);
  delay(1000);
  tela.setSegments(blank);
  delay(1000);
  tela.setSegments(circle);
  delay(1000);
  tela.setSegments(blank);

  tela.setSegments(turn_A1);
  delay(wait_time);
  tela.setSegments(turn_A2);
  delay(wait_time);
  tela.setSegments(turn_A3);
  delay(wait_time);
  tela.setSegments(turn_A4);
  delay(wait_time);
  tela.setSegments(turn_B4);
  delay(wait_time);
  tela.setSegments(turn_C4);
  delay(wait_time);
  tela.setSegments(turn_D4);
  delay(wait_time);
  tela.setSegments(turn_D3);
  delay(wait_time);
  tela.setSegments(turn_D2);
  delay(wait_time);
  tela.setSegments(turn_D1);
  delay(wait_time);
  tela.setSegments(turn_E1);
  delay(wait_time);
  tela.setSegments(turn_F1);
  delay(wait_time);
}

void loop() {
  
  tela.setSegments(turn_A1);
  delay(wait_time);
  tela.setSegments(turn_B1);
  delay(wait_time);
  tela.setSegments(turn_G1);
  delay(wait_time);
  tela.setSegments(turn_E1);
  delay(wait_time);
  tela.setSegments(turn_D1);
  delay(wait_time);
  tela.setSegments(turn_C1);
  delay(wait_time);
  tela.setSegments(turn_G1);
  delay(wait_time);
  tela.setSegments(turn_F1);
  delay(wait_time);
  tela.setSegments(turn_A1);
  delay(wait_time);

  tela.setSegments(turn_A2);
  delay(wait_time);
  tela.setSegments(turn_B2);
  delay(wait_time);
  tela.setSegments(turn_G2);
  delay(wait_time);
  tela.setSegments(turn_E2);
  delay(wait_time);
  tela.setSegments(turn_D2);
  delay(wait_time);
  tela.setSegments(turn_C2);
  delay(wait_time);
  tela.setSegments(turn_G2);
  delay(wait_time);
  tela.setSegments(turn_F2);
  delay(wait_time);
  tela.setSegments(turn_A2);
  delay(wait_time);

  tela.setSegments(turn_A3);
  delay(wait_time);
  tela.setSegments(turn_B3);
  delay(wait_time);
  tela.setSegments(turn_G3);
  delay(wait_time);
  tela.setSegments(turn_E3);
  delay(wait_time);
  tela.setSegments(turn_D3);
  delay(wait_time);
  tela.setSegments(turn_C3);
  delay(wait_time);
  tela.setSegments(turn_G3);
  delay(wait_time);
  tela.setSegments(turn_F3);
  delay(wait_time);
  tela.setSegments(turn_A3);
  delay(wait_time);

  tela.setSegments(turn_A4);
  delay(wait_time);
  tela.setSegments(turn_B4);
  delay(wait_time);
  tela.setSegments(turn_G4);
  delay(wait_time);
  tela.setSegments(turn_E4);
  delay(wait_time);
  tela.setSegments(turn_D4);
  delay(wait_time);
  tela.setSegments(turn_C4);
  delay(wait_time);
  tela.setSegments(turn_G4);
  delay(wait_time);
  tela.setSegments(turn_F4);
  delay(wait_time);
  tela.setSegments(turn_A4);
  delay(wait_time);

  tela.setSegments(turn_B4);
  delay(wait_time);
  tela.setSegments(turn_C4);
  delay(wait_time);
  tela.setSegments(turn_D4);
  delay(wait_time);
  tela.setSegments(turn_D3);
  delay(wait_time);
  tela.setSegments(turn_D2);
  delay(wait_time);
  tela.setSegments(turn_D1);
  delay(wait_time);
  tela.setSegments(turn_E1);
  delay(wait_time);
  tela.setSegments(turn_F1);
}
