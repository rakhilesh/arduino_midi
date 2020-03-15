
/*
  Midi Expression and routing tool v1.0

  This sketch is written to allow 2 functions :
  a. Expression pedal (default channel 4, Volume Control CC7)
  b. Input loop back (default state)
  c. Changing output channel Ch4 - > others (all messages except expression) - Button 1 + Key on the keyboard
  d. Changing expression channel Default CH4 -> Others - Button 2 + Key on the keyboard

  Next version plan : 
  Software : Allow changing Dual and Split channels, Assigning CC11 to Exp or other parameters like delay to expression
  Hardware : Adding a 2 potentiometers to Cricuit
  
 */
#include <Control_Surface.h>
#include <MIDI.h>
HardwareSerialMIDI_Interface midi={9600};

#define BUTTON1  2
#define BUTTON2  3
#define BUTTON3  4

#define STAT1  7 //LED 1
#define STAT2  6 //LED 2

#define EXP A0 //Analog 0 where Exp pedal is connected

void setup() {
  // put your setup code here, to run once:

  pinMode(STAT1,OUTPUT);   
  pinMode(STAT2,OUTPUT);

  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  pinMode(BUTTON3,INPUT);

  digitalWrite(BUTTON1,HIGH);
  digitalWrite(BUTTON2,HIGH);
  digitalWrite(BUTTON3,HIGH);

  //Change this to 31250 to send from Midi ports

  Serial.begin(9600);

  // Listen to all Chennels - While E09 can send through 4 by default when using split/dual other channels are used
  // In ver 1 we intend to read from all Channels but only send to a specific channel as set using the buttons

  MIDI.begin(MIDI_CHANNEL_OMNI); //THis also creates Soft thru

}

void loop() {
  // put your main code here, to run repeatedly:
  if(MIDI.read()) //Is there a midi message coming in
  {
    if(button(BUTTON1))
    {
      switch(MIDI.getData1())
      {
        case midi::
          
      }
      
    }
  }
  MIDI.
  

}
