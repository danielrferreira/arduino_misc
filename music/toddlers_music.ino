//This project needs a 4x4 pinpad, a buzzer and RGB LED (Optional)

//I created for my son, so it is mostly musics that a toddler will enjoy, :)

//Depending on what you press in the pinpad, the buzzer will play a different tune, including Down By The Bay, Wheels on The Bus and Blaze and the Monster Machines

#include <Key.h>
#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;

//Pinpad Pins
byte row_pin[rows] = {5,4,3,2};
byte col_pin[cols] = {6,7,12,13};

//RGB LED Pins, this is optional.
int red_pin = 11;
int green_pin = 10;
int blue_pin = 9;


//Buzzer Pin
int caixa = 8;

char teclas[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// 
Keypad teclado = Keypad(makeKeymap(teclas), row_pin, col_pin, rows, cols);

//Function to change the color of the led
void RGB_color(int red, int green, int blue){
  analogWrite(red_pin,red);
  analogWrite(green_pin,green);
  analogWrite(blue_pin,blue);
}

//Musical Notes Frequencies
double C{261.63},Db{277.18},D{293.66},Eb{311.13},E{329.63},F{349.23},Gb{369.99},G{392},Ab{415.3},A{440},Bb{466.16},B{493.88};

int speed = 200;

//This function creates the musical notes, with a math library we could make it simpler, without all the IF's.
void nota(double freq, int octave, double duration){
  double real_duration = ((duration*1000)/(speed/60));
  if (octave==-2){
    tone(caixa, freq/4, real_duration);
    delay(real_duration);
    noTone(caixa);
    return;
  }
  if (octave==-1){
    tone(caixa, freq/2, real_duration);
    delay(real_duration);
    noTone(caixa);
    return;
  }
  if (octave==1) {
    tone(caixa, freq, real_duration);
    delay(real_duration);
    noTone(caixa);
    return;
  }
  if (octave==2){
    tone(caixa, freq*2, real_duration);
    delay(real_duration);
    noTone(caixa);
    return;
  }
  if (octave==3){
    tone(caixa, freq*4, real_duration);
    delay(real_duration);
    noTone(caixa);
    return;
  }
  if (octave==4){
    tone(caixa, freq*8, real_duration);
    delay(real_duration);
    noTone(caixa);
    return;
  }
  Serial.println("N/A");
}

// Silence
void pausa(double duration){
  delay(((duration*1000)/(speed/60)));
}

// Do Re Mi Fa (C,D,E,F)
void teste(){
  
  Serial.println("Teste - Dó Ré Mi Fá");
  RGB_color(125,125,125);
  speed = 120;

  pausa(0.5);
  nota(C,1,0.5);
  nota(D,1,0.5);
  nota(E,1,0.5);
  nota(F,1,0.75);
  pausa(0.25);
  nota(F,1,0.5);
  nota(F,1,0.5);
  
  pausa(0.5);
  nota(C,1,0.5);
  nota(D,1,0.5);
  nota(C,1,0.5);
  nota(D,1,0.75);
  pausa(0.25);
  nota(D,1,0.5);
  nota(D,1,0.5);
  
  pausa(0.5);
  nota(C,1,0.5);
  nota(G,1,0.5);
  nota(F,1,0.5);
  nota(E,1,0.75);
  pausa(0.25);
  nota(E,1,0.5);
  nota(E,1,0.5);
  
  pausa(0.5);
  nota(C,1,0.5);
  nota(D,1,0.5);
  nota(E,1,0.5);
  nota(F,1,0.75);
  pausa(0.25);
  nota(F,1,0.5);
  nota(F,1,0.5);

  RGB_color(0,0,0);
}

//Down By the Bay
void dbtb(){
  Serial.println("Down by the bay");
  RGB_color(0,125,0);
  speed = 180;
  
  Serial.println("Down by the...");
  nota(D,1,1);
  nota(E,1,1);
  nota(D,1,1);

  Serial.println("bay...");
  nota(G,1,4);

  Serial.println("Where the watermeolons...");
  pausa(1);
  nota(D,1,0.5);
  nota(D,1,0.5);
  nota(E,1,0.5);
  nota(E,1,0.5);
  nota(D,1,0.5);
  nota(D,1,0.5);

  Serial.println("Grow...");
  nota(Gb,1,4);

  Serial.println("Back to my...");
  pausa(1);
  nota(D,1,1);
  nota(E,1,1);
  nota(D,1,1);

  Serial.println("Home...");
  nota(Gb,1,4);

  Serial.println("I dare not..."); 
  pausa(1);
  nota(D,1,1);
  nota(E,1,1);
  nota(Gb,1,1);

  Serial.println("Go...");
  nota(G,1,4);

  Serial.println("For if I...");
  pausa(1);
  nota(G,1,1);
  nota(Gb,1,1);
  nota(F,1,1);

  Serial.println("Do...");
  nota(E,1,4);

  Serial.println("My mother will...");
  pausa(1);
  nota(G,1,1);
  nota(Gb,1,0.5);
  nota(Gb,1,0.5);
  nota(E,1,1);

  Serial.println("Say...");
  nota(D,1,4);

  Serial.println("Did you...");
  pausa(2);
  nota(G,1,1.5);
  nota(A,1,0.5);

  Serial.println("Ever see a goose...");
  nota(B,1,0.5);
  nota(Bb,1,0.5);
  nota(B,1,0.5);
  nota(Bb,1,0.5);
  nota(B,1,2);

  Serial.println("Kissing a moose...");
  nota(B,1,0.5);
  nota(B,1,1);
  nota(Bb,1,0.5);
  nota(B,1,2);

  Serial.println("Down by...");
  nota(C,2,1);
  nota(B,1,2);
  nota(A,1,1);

  Serial.println("The bay.!");
  nota(G,1,1);

  RGB_color(0,0,0);
}

//Wheels of the Bus
void wotb(){
  Serial.println("Wheels on the Bus");
  RGB_color(125,0,0);
  speed = 120;

  Serial.println("The...");
  nota(Bb,-1,1);

  Serial.println("wheels on the bus go...");
  nota(Eb,1,1);
  nota(Eb,1,0.75);
  nota(F,1,0.25);
  nota(G,1,1);
  nota(Ab,1,1);

  Serial.println("round and round,...");
  nota(C,2,1);
  nota(Bb,1,1);
  nota(G,1,2);

  Serial.println("round and round,...");
  nota(Bb,1,1);
  nota(Ab,1,1);
  nota(F,1,2); 

  Serial.println("round and round, The...");
  nota(C,2,1);
  nota(Bb,1,1);
  nota(G,1,1);
  nota(Bb,-1,1);

  Serial.println("wheels on the bus go...");
  nota(Eb,1,1);
  nota(Eb,1,0.75);
  nota(F,1,0.25);
  nota(G,1,1);
  nota(Bb,1,1);

  Serial.println("round and round,...");
  nota(C,2,1);
  nota(Bb,1,1);
  nota(G,1,2);

  Serial.println("All around the...");
  nota(Bb,1,1);
  nota(Bb,1,1);
  nota(Ab,1,1);
  nota(F,1,1);

  Serial.println("Town!");
  nota(Eb,1,3);
  
  RGB_color(0,0,0);
}

//Blaze and the Monster Machines
void batmm(){
  Serial.println("Blaze and the Monster Machines");
  RGB_color(0,0,125);
  speed = 185;

  Serial.println("On your mark, get...");
  nota(B,-1,1);
  nota(B,-1,1);
  nota(B,-1,1);
  nota(B,-1,1);

  Serial.println("ready to race...");
  nota(C,1,0.5);
  nota(C,1,0.5);
  nota(C,1,1);
  nota(C,1,2);

  Serial.println("1, 2, 3, Let's...");
  nota(Db,1,1);
  nota(Db,1,1);
  nota(Db,1,1);
  nota(Db,1,1);

  Serial.println("Blaze!!!! So");
  nota(D,1,2);
  pausa(1);
  nota(G,-1,1);

  Serial.println("Buckle your seatbelt We are...");
  nota(E,1,0.5);
  nota(E,1,0.5);
  nota(D,1,1);
  nota(C,1,1);
  nota(E,1,0.5);
  nota(G,-1,0.5);

  Serial.println("gonna scream and yell...");
  nota(D,1,0.5);
  nota(D,1,0.5);
  nota(C,1,1);
  nota(B,-1,1);
  nota(D,1,0.5);
  nota(G,-1,0.5);

  Serial.println("Blaze goes saving the...");
  nota(B,-1,1);
  nota(B,-1,1);
  nota(B,-1,0.5);
  nota(B,-1,0.5);
  nota(A,-1,1);

  Serial.println("day...");
  pausa(4);

  Serial.println("Gimme, gimme, gimme some...");
  nota(G,1,0.5);
  nota(G,1,0.5);
  nota(G,1,0.5);
  nota(G,1,0.5);
  nota(G,1,0.5);
  nota(G,1,0.5);
  nota(G,1,1);

  Serial.println("speed...");
  nota(Gb,1,4);

  for(int i=0; i<3;i++){
    Serial.println("Blaze and the Monster...Machines");
    nota(G,1,1);
    nota(C,1,0.5);
    nota(C,1,0.5);
    nota(C,1,1);
    nota(D,1,0.75);
    nota(D,1,1.5);
    nota(G,-1,2.5);
  }

  RGB_color(0,0,0);
}

//Random request from my son, he wanted a firetruck sound
void bomb(){
  for(int i=0; i<10;i++){
    RGB_color(0,125,0);
    nota(F,1,2);
    RGB_color(0,0,125);
    nota(C,1,2);
  }
  RGB_color(0,0,0);
}

void setup() {
  pinMode(red_pin,OUTPUT);
  pinMode(green_pin,OUTPUT);
  pinMode(blue_pin,OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  char resultado;
  Serial.println("Olá, bem vindo, por favor escolha uma música:");
  Serial.println("1 - Teste: Dó Ré Mi Fá");
  Serial.println("2 - Down by the bay");
  Serial.println("3 - Wheels on the Bus");
  Serial.println("A - Blaze and the Monster Machines");
  Serial.println("B - Bombeiro Song");
  while (!(resultado = teclado.getKey())){
  }
  if (resultado=='1'){
    teste();
    return;
  }
  if (resultado=='2'){
    dbtb();
    return;
  }
  if (resultado=='3'){
    wotb();
    return;
  }
  if (resultado=='A'){
    batmm();
    return;
  }
  if (resultado=='B'){
    bomb();
    return;
  }

}
