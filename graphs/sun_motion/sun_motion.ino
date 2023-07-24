//Sun Motion
#include <U8glib.h>
 
U8GLIB_SH1106_128X64  tela_led(U8G_I2C_OPT_NONE); 

int count = 0;

void u8g_prepare() {
  tela_led.setFont(u8g_font_6x10);
  tela_led.setFontRefHeightExtendedText();
  tela_led.setDefaultForegroundColor();
  tela_led.setFontPosTop();
}

//Static Sun with a x,y center
void sun(int xs,int ys){
  tela_led.drawCircle(xs,ys,5); //sun
  
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

//Motion: Go down, and then come back up
void sun_motion(int b){
  if (b<32){
    sun(110+b,15+b);
  }
  else {
    sun(110+64-b,15+64-b);
  }
}

void draw(){
  u8g_prepare();
  sun_motion(count);

}



void setup() {

}

void loop() {
  tela_led.firstPage();  
  do {
    draw();
  } while( tela_led.nextPage() );
  count++;
  if (count>=64) {
    count=0;
  }
}
