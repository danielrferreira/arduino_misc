//This is a simple drawning in a 128x64 OLED display

#include <U8glib.h>
 
U8GLIB_SH1106_128X64  tela_led(U8G_I2C_OPT_NONE); 


void u8g_prepare() {
  tela_led.setFont(u8g_font_6x10);
  tela_led.setFontRefHeightExtendedText();
  tela_led.setDefaultForegroundColor();
  tela_led.setFontPosTop();
}

void draw(){
  u8g_prepare();

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

  tela_led.drawPixel(50,9); //smoke
  tela_led.drawPixel(50,8); //smoke
  tela_led.drawPixel(51,7); //smoke
  tela_led.drawPixel(52,6); //smoke
  tela_led.drawPixel(52,5); //smoke

  tela_led.drawPixel(52,9); //smoke
  tela_led.drawPixel(52,8); //smoke
  tela_led.drawPixel(53,7); //smoke
  tela_led.drawPixel(54,6); //smoke
  tela_led.drawPixel(54,5); //smoke

  tela_led.drawCircle(90,18,5); //sun

  tela_led.drawLine(81,18,83,18); //sun light -
  tela_led.drawLine(83,11,85,13); //sun light
  tela_led.drawLine(90,9,90,11); //sun light
  tela_led.drawLine(95,13,97,11); //sun light
  tela_led.drawLine(97,18,99,18); //sun light
  tela_led.drawLine(95,23,97,25); //sun light
  tela_led.drawLine(90,25,90,27); //sun light
  tela_led.drawLine(85,23,83,25); //sun light

}



void setup() {

}

void loop() {
  tela_led.firstPage();  
  do {
    draw();
  } while( tela_led.nextPage() );
}
