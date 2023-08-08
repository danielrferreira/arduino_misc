//This animation for a 128x64 OLED Display shows a house, tree, su, moon and stars during the day
#include <U8glib.h>
#define CLK2 2
#define DT 3

int current_state;
int last_state;

U8GLIB_SH1106_128X64  tela_led(U8G_I2C_OPT_NONE); 

int count = 0;

void u8g_prepare() {
  tela_led.setFont(u8g_font_gdr20n);
  tela_led.setFontRefHeightExtendedText();
  tela_led.setDefaultForegroundColor();
  tela_led.setFontPosTop();
}

void house(){
  tela_led.drawLine(1,63,120,63); //floor
  tela_led.drawFrame(10,29,65,35); //house
  tela_led.drawFrame(37,40,32,15); //window
  tela_led.drawFrame(15,46,9,18); //door
  tela_led.drawLine(28,30,28,62); //side
  tela_led.drawLine(10,29,19,14); //roof
  tela_led.drawLine(28,29,19,14); //roof
  tela_led.drawLine(20,14,47,14); //roof
  tela_led.drawLine(55,14,64,14); //roof
  tela_led.drawLine(65,14,74,28); //roof

  tela_led.drawLine(48,17,48,11); //chimmey
  tela_led.drawLine(49,11,53,11); //chimmey
  tela_led.drawLine(54,11,54,17); //chimmey

  tela_led.drawCircle(19,37,4); //circle window
  tela_led.drawLine(19,35,19,39); //circle window
  tela_led.drawLine(17,37,21,37); //circle window

  tela_led.drawDisc(37,40,11,U8G_DRAW_LOWER_RIGHT); //window skirts
  tela_led.drawDisc(68,40,11,U8G_DRAW_LOWER_LEFT); //window skirts

  tela_led.drawPixel(21,55); //doorknob
}

void tree(int xt,int yt){
  
  tela_led.drawLine(xt-2,yt-1,xt-2,yt-15); //Tree 
  tela_led.drawLine(xt+2,yt-1,xt+2,yt-15); //Tree 

  tela_led.drawTriangle(xt-8,yt-15,xt+8,yt-15,xt,yt-50); //Bush
  tela_led.drawTriangle(xt-9,yt-25,xt+9,yt-25,xt,yt-35); //Bush
  tela_led.drawTriangle(xt-8,yt-35,xt+8,yt-35,xt,yt-42); //Bush
}

void smoke(int a){
  
  tela_led.drawLine(50,9,50,8); //smoke bottom static
  tela_led.drawLine(52,9,52,8); //smoke bottom static

  // Smoke Base Montion
  if (a<=2){
    tela_led.drawPixel(51-a,7); //smoke base
    tela_led.drawPixel(53-a,7); //smoke base
  }
  else if (a==3){
    tela_led.drawPixel(51-2,7); //smoke base
    tela_led.drawPixel(53-2,7); //smoke base
  }
  else if (a<=6){
    tela_led.drawPixel(51-6+a,7); //smoke base
    tela_led.drawPixel(53-6+a,7); //smoke base
  }
  else {
    tela_led.drawPixel(51,7); //smoke base
    tela_led.drawPixel(53,7); //smoke base
  }
  // End of Smoke Base Montion

  // Upper Smoke Montion
  if (a<=4){
    tela_led.drawLine(52-a,5,52-a,6); //smoke upper
    tela_led.drawLine(54-a,5,54-a,6); //smoke upper
  }
  else {
    tela_led.drawLine(52-8+a,5,52-8+a,6); //smoke upper
    tela_led.drawLine(54-8+a,5,54-8+a,6); //smoke upper
  }
  // End of Upper Smoke Montion
}

void sun(int xs,int ys){
  tela_led.drawDisc(xs,ys,5); //sun
  
  tela_led.drawPixel(xs,ys-9); // SL N
  tela_led.drawPixel(xs,ys-8); // SL N
  tela_led.drawPixel(xs,ys-7); // SL N

  tela_led.drawPixel(xs+5,ys-5); // SL NE
  tela_led.drawPixel(xs+6,ys-6); // SL NE

  tela_led.drawPixel(xs+7,ys); // SL E
  tela_led.drawPixel(xs+8,ys); // SL E
  tela_led.drawPixel(xs+9,ys); // SL E

  tela_led.drawPixel(xs+5,ys+5); // SL SE
  tela_led.drawPixel(xs+6,ys+6); // SL SE

  tela_led.drawPixel(xs,ys+7); // SL S
  tela_led.drawPixel(xs,ys+8); // SL S
  tela_led.drawPixel(xs,ys+9); // SL S

  tela_led.drawPixel(xs-5,ys+5); // SL SW
  tela_led.drawPixel(xs-6,ys+6); // SL SW

  tela_led.drawPixel(xs-9,ys); // SL W
  tela_led.drawPixel(xs-8,ys); // SL W
  tela_led.drawPixel(xs-7,ys); // SL W

  tela_led.drawPixel(xs-5,ys-5); // SL NW
  tela_led.drawPixel(xs-6,ys-6); // SL NW
}

void moon(int xm,int ym){
  tela_led.drawDisc(xm,ym,5); //moon
  tela_led.setColorIndex(0); //
  tela_led.drawDisc(xm+2,ym-2,4);
  tela_led.setColorIndex(1);

}

void stars100 (){
  tela_led.drawPixel(5,52);
  tela_led.drawPixel(2,37);
  tela_led.drawPixel(4,30);
  tela_led.drawPixel(8,10);
  tela_led.drawPixel(10,43);
  tela_led.drawPixel(20,4);
  tela_led.drawPixel(26,11);
  tela_led.drawPixel(29,4);
  tela_led.drawPixel(37,8);
  tela_led.drawPixel(43,7);
  tela_led.drawPixel(61,10);
  tela_led.drawPixel(63,2);
  tela_led.drawPixel(70,16);
  tela_led.drawPixel(73,11);
  tela_led.drawPixel(75,4);
  tela_led.drawPixel(89,7);
  tela_led.drawPixel(76,43);
  tela_led.drawPixel(80,22);
  tela_led.drawPixel(109,11);
  tela_led.drawPixel(117,10);
  tela_led.drawPixel(100,55);
  tela_led.drawPixel(98,45);
  tela_led.drawPixel(110,44);
  tela_led.drawPixel(104,49);
  tela_led.drawPixel(101,23);
  tela_led.drawPixel(97,12);
  tela_led.drawPixel(111,22);
  tela_led.drawPixel(106,34);
  tela_led.drawPixel(115,56);
  tela_led.drawPixel(120,32);
  tela_led.drawPixel(111,60);
  tela_led.drawPixel(106,49);
}

void stars75 (){
  tela_led.drawPixel(5,52);
  tela_led.drawPixel(2,37); 
  tela_led.drawPixel(8,10);
  tela_led.drawPixel(10,43);
  tela_led.drawPixel(20,4);
  tela_led.drawPixel(29,4);
  tela_led.drawPixel(37,8);
  tela_led.drawPixel(43,7);
  tela_led.drawPixel(61,10);
  tela_led.drawPixel(70,16);
  tela_led.drawPixel(73,11);
  tela_led.drawPixel(89,7);
  tela_led.drawPixel(80,22);
  tela_led.drawPixel(109,11);
  tela_led.drawPixel(117,10);
  tela_led.drawPixel(98,45);
  tela_led.drawPixel(110,44);
  tela_led.drawPixel(104,49);
  tela_led.drawPixel(97,12);
  tela_led.drawPixel(111,22);
  tela_led.drawPixel(106,34);
  tela_led.drawPixel(120,32);
  tela_led.drawPixel(111,60);
  tela_led.drawPixel(106,49);
}

void stars50 (){
  tela_led.drawPixel(2,37); 
  tela_led.drawPixel(8,10);
  tela_led.drawPixel(20,4);
  tela_led.drawPixel(29,4);
  tela_led.drawPixel(43,7);
  tela_led.drawPixel(61,10);
  tela_led.drawPixel(70,16);
  tela_led.drawPixel(89,7);
  tela_led.drawPixel(80,22);
  tela_led.drawPixel(109,11);
  tela_led.drawPixel(98,45);
  tela_led.drawPixel(110,44);
  tela_led.drawPixel(97,12);
  tela_led.drawPixel(106,34);
  tela_led.drawPixel(111,60);
  tela_led.drawPixel(106,49);
}

void stars25 (){
  tela_led.drawPixel(2,37); 
  tela_led.drawPixel(20,4);
  tela_led.drawPixel(29,4);
  tela_led.drawPixel(61,10);
  tela_led.drawPixel(80,22);
  tela_led.drawPixel(98,45);
  tela_led.drawPixel(97,12);
  tela_led.drawPixel(111,60);
}

void stars_fade_in (int g){
  switch (g>>3){
    case 0: stars25(); break;
    case 1: stars50(); break;
    case 2: stars75(); break;
    case 3: stars100(); break;
  }
}

void stars_fade_out (int h){
  switch (h>>3){
    case 0: stars100(); break;
    case 1: stars75(); break;
    case 2: stars50(); break;
    case 3: stars25(); break;
  }
}

void sun_up (int b){
  sun(141-b,46-b);
}

void sun_down (int c){
  sun(110+c,15+c);
}

void moon_up (int d){
  moon(141-d,46-d);
  stars_fade_in(d);
}

void moon_down (int e){
  moon(110+e,15+e);
  stars_fade_out(e);
}

void sun_moon_motion(int f){
  switch(f >> 5){
    case 0: sun_up(f&31); break;
    case 1: sun_down(f&31); break;
    case 2: moon_up(f&31); break;
    case 3: moon_down(f&31); break;
  }
}

void draw(){
  u8g_prepare();
  house();
  tree(90,63);
  sun_moon_motion(count);
  smoke(count&7);
}

void updateEncoder(){
  current_state = digitalRead(CLK2);
  if (current_state != last_state && current_state == 1){
    if (digitalRead(DT) != current_state){
      count--;
    }
    else {
      count++;
    }
  }
  last_state = current_state;
}
void setup() {
  
  pinMode(CLK2,INPUT);
  pinMode(DT,INPUT);

  last_state = digitalRead(CLK2);
  
  attachInterrupt(digitalPinToInterrupt(CLK2), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT), updateEncoder, CHANGE);
}

void loop() {
  tela_led.firstPage();  
  do {
    draw();
  } while( tela_led.nextPage() );
  if (count>=128) {
    count=0;
  }
  if (count<=0) {
    count=0;
  }
}
