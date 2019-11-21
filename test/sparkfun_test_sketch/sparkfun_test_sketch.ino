//This sketch is used to test if the Sparkfun Midi shield is working as it supposed to
//Change the baud rate to 9200 if you want to test using the IDEs serial monitor. 
// Baud rate for Midi is set at 31250 as industry standard hence to use the MIDI out pins this is the rate which needs to be set
// When baud rate other than 31250 is used, the 

// defines for MIDI Shield components only
#define KNOB1  0
#define KNOB2  1

#define BUTTON1  2
#define BUTTON2  3
#define BUTTON3  4

#define STAT1  7
#define STAT2  6

#define OFF 1
#define ON 2
#define WAIT 3

byte incomingByte;
byte note;
byte velocity;
int pot;

byte byte1;
byte byte2;
byte byte3;

int action=2; //1 =note off ; 2=note on ; 3= wait



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
  Serial.begin(31250);     
}

void loop () {

  //*************** MIDI OUT ***************//

  //pot = analogRead(0);
  //note = pot/8;  // convert value to value 0-127
  
  note = 50;
  
  if(button(BUTTON1) || button(BUTTON2) || button(BUTTON3))
  {  
    Midi_Send("hello",0x02,0x01);
    while(button(BUTTON1) || button(BUTTON2) || button(BUTTON3));
  }

  //*************** MIDI LOOPBACK ******************//
  if(Serial.available() > 0)
  {
    byte1 = Serial.read();
    byte2 = Serial.read();
    byte3 = Serial.read();

    Midi_Send(byte1, byte2, byte3);
  }
}

void Midi_Send(char cmd, byte data1, byte data2) {
  Serial.write(cmd);
  Serial.write(data1);
  Serial.write(data2);
}

char button(char button_num)
{
  return (!(digitalRead(button_num)));
}
