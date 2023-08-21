// This code turns frequencies from different colors and ligths a RGB led with the same color from your ambient.
int OutPut= 6;//naming pin 6 of uno as output
unsigned int frequency = 0;

int S0 = 2;
int S1 = 3;
int S2 = 4;
int S3 = 5;

int red_pin = 11;
int green_pin = 10;
int blue_pin = 9;

int R_freq;
int G_freq;
int B_freq;

void color_RGB(int red_value, int green_value, int blue_value){
  analogWrite(red_pin, red_value);
  analogWrite(green_pin, green_value);
  analogWrite(blue_pin, blue_value);
}

double freq_to_RGB (double freq, double min, double max){
  if (freq < min){
    freq = min;
  }
  if (freq > max){
    freq = max;
  }
  return (1-((freq-min)/(max-min)))*255;
}

void setup() {
// set up the LCD’s number of columns and rows
  pinMode(red_pin,OUTPUT);
  pinMode(green_pin,OUTPUT);
  pinMode(blue_pin,OUTPUT);
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);//PINS 2, 3,4,5 as OUTPUT
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OutPut, INPUT);//PIN 10 as input

//setting frequency selection to 20% - HIGH HIGH = 100% - HIGH LOW = 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);

}

void loop(){
  
  Serial.print ("R=");// printing name
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);// setting for Red color sensor
  frequency = pulseIn(OutPut, LOW);// reading frequency
  R_freq = freq_to_RGB(frequency,90,500);
  // Serial.print (frequency);// printing Red color frequency
  Serial.print (R_freq);
  Serial.print (" ");
  
  delay(100);

  Serial.print ("G=");// printing name
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);// setting for Green color sensor
  frequency = pulseIn(OutPut, LOW);// reading frequency
  G_freq = freq_to_RGB(frequency,190,500);
  // Serial.print (frequency);// printing Green color frequency
  Serial.print (G_freq);
  Serial.print (" ");
  
  delay(100);

  Serial.print("B=");//printing name
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);//setting for Blue color sensor
  frequency = pulseIn(OutPut, LOW);//reading frequency
  B_freq = freq_to_RGB(frequency,320,900);
  // Serial.print(frequency);//printing Blue color frequency
  Serial.print(B_freq);
  Serial.print(" ");
  
  delay(100);

  Serial.println("****************************");
  color_RGB(R_freq,G_freq,B_freq);
  delay(1000);

}
