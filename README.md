# Arduino based MIDI device

## Introduction
Arduino based midi device is a WIP project which is designed with the intention of performing the following tasks:
- Connecting 2 keyboards which have standard MIDI ports (5 pin)
- Act as a HUB to process MIDI signals (eg. Split keyboards, control multiple instruments using split keyboards, velocity based layered instruments)
- Add expression pedal functionality to the keyboards
- Able to change the configurations easily using a GUI based front end (possibly using Python)

## Need for this device
The idea for this device springs from my attmpt to solve for some of the limitation in my current keyboard setup. I currently have 2 keyboards (Roland JD Xi and an older Roland E-09). JD Xi has mini keys (37 keys) but an very versatile and effective synthesizer sound engine (wave based with enhanced sound design capability) while E09 is a traditional entry level arranger (61 key of standard size) which has very good sample based instruments (Piano, orchestra etc). 

While JD xi lacks any pedal inputs, the E-09 has sustain pedal inputs. Both keyboards lack expression pedal inputs. Both keyboards have tranditional 5 pin MIDI ports however, Roland has fixed the channels on both keyboards making it very difficult to connect the 2 keyboards without a PC or iPad (using midi processors apps)

## Hardware

Compenents
Arduino UNO
Test position 

On Nektar NXp - Switch set to 1

Pin 8 - Tip - 5 Volt
Pin 4 - Ring - A0
Outer pin on top - Sleeve - GND


