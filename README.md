# ESP8266 Bots

## Before Running Code 

### 1. Install NodeMCU Library
Starting with 1.6.4, Arduino allows installation of third-party platform packages using Boards Manager. We have packages available for Windows, Mac OS, and Linux (32 and 64 bit).

- Install the current upstream Arduino IDE at the 1.8 level or later. The current version is at the [Arduino website](http://www.arduino.cc/en/main/software).
- Start Arduino and open Preferences window.
- Enter ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` into *Additional Board Manager URLs* field. You can add multiple URLs, separating them with commas.
- Open Boards Manager from Tools > Board menu and install *esp8266* platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).


### 2. Select Node MCU 1.0 from Boards Manager

### 3. Select Proper COM Port


## Pin Mapping for NodeMCU on Arduino IDE

|   Hardware Pin Number	| Pin Number Mapped to in Arduino IDE   	|   	
|---	|---	|
|   D0	|   16	|   
|   D1	|   5	|   	
|   D2	|   4	|
|   D3	|   0	|   
|   D4	|   2	|   	
|   D5	|   14	|  
|   D6	|   12	|   
|   D7	|   13	|   	
|   D8	|   15	|
|   D9	|   3	|   	
|   D10	|   1	|      

<b>For Eg:</b> DigitalWrite on Pin 16 declared in the code gives output on D0 of Hardware   