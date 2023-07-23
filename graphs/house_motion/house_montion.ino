//This is a simple house drawning in a 128x64 OLED display, adding some motion to the chimmey smoke and sun

#include <U8glib.h>
 
U8GLIB_SH1106_128X64  tela_led(U8G_I2C_OPT_NONE); 

int count = 0;

void u8g_prepare() {
  tela_led.setFont(u8g_font_6x10);
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

  tela_led.drawCircle(37,40,11,U8G_DRAW_LOWER_RIGHT); //window skirts
  tela_led.drawCircle(68,40,11,U8G_DRAW_LOWER_LEFT); //window skirts

  tela_led.drawPixel(21,55); //doorknob
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

void sun(int b){
  tela_led.drawCircle(90-b,18-b,5); //sun
  tela_led.drawLine(81-b,18-b,83-b,18-b); //sun light -
  tela_led.drawLine(83-b,11-b,85-b,13-b); //sun light
  tela_led.drawLine(90-b,9-b,90-b,11-b); //sun light
  tela_led.drawLine(95-b,13-b,97-b,11-b); //sun light
  tela_led.drawLine(97-b,18-b,99-b,18-b); //sun light
  tela_led.drawLine(95-b,23-b,97-b,25-b); //sun light
  tela_led.drawLine(90-b,25-b,90-b,27-b); //sun light
  tela_led.drawLine(85-b,23-b,83-b,25-b); //sun light
}
void draw(){
  u8g_prepare();
  house();
  smoke(count);
  sun(count);
}



void setup() {

}

void loop() {
  tela_led.firstPage();  
  do {
    draw();
  } while( tela_led.nextPage() );
  count++;
  if (count>=8) {
    count=0;
  }
}
