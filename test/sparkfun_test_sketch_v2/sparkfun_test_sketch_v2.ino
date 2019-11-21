// This sketch is used to test if the Sparkfun Midi shield is working as it supposed to
// Change the baud rate to 9600 if you want to test using the IDEs serial monitor. 
// Step 1 : Compile the sketch
// Step 2 : Upload the sketch
// Step 3 : When button 1 (D2) is pressed "the number is 1" gets printed on Serial monitor of IDE
// This test is to check if the buttons have been soldered correctly and are working as it is supposed to

// defines for MIDI Shield components only
#define KNOB1  0
#define KNOB2  1

#define BUTTON1  2
#define BUTTON2  3
#define BUTTON3  4

#define STAT1  7
#define STAT2  6


void setup() {

  pinMode(STAT1,OUTPUT);   
  pinMode(STAT2,OUTPUT);

  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  pinMode(BUTTON3,INPUT);

  digitalWrite(BUTTON1,HIGH);
  digitalWrite(BUTTON2,HIGH);
  digitalWrite(BUTTON3,HIGH);

  for(int i = 0;i < 10;i++) // flash MIDI Sheild LED's on startup
  {
    digitalWrite(STAT1,HIGH);  
    digitalWrite(STAT2,LOW);
    delay(30);
    digitalWrite(STAT1,LOW);  
    digitalWrite(STAT2,HIGH);
    delay(30);
  }
  digitalWrite(STAT1,HIGH);   
  digitalWrite(STAT2,HIGH);

  //start serial with midi baudrate 31250
  Serial.begin(9600);     
}

void loop () {

  //*************** MIDI OUT ***************//
  
  if(button(BUTTON1))
  {  
    int i = 1;
    Serial.print("The number is ");
    Serial.println(i);
    while(button(BUTTON1));
  }

  if(button(BUTTON2))
  {  
    int i = 2;
    Serial.print("The number is ");
    Serial.println(i);
    while(button(BUTTON2));
  }

  if(button(BUTTON3))
  {  
    int i = 3;
    Serial.print("The number is ");
    Serial.println(i);
    while(button(BUTTON3));
  }

}

char button(char button_num)
{
  return (!(digitalRead(button_num)));
}
