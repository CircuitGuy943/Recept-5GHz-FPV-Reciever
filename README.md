
I happened to have a 4.3" TFT display left over from dissassembling my old screen from my Ender 3 and I also had an ongoing project of a flight controller, with FPV functionality and I had an amazing idea, I present to you:

# **Recept!**

Recept is a 5.8GHz video signal reciever board running with an RX5808 as the reciever module and the combined power of an RP2040 and TW8819 decoder chip to quickly decode and output the video signal to a parallel RGB interface (3x8, 40 pin) for a generic 4.3" TFT display. It runs primarilly off of a fully integrated LiPo battery of dimensions and size 903759 / 2500mAh but it also provides the possibily of running off of USB C both for general use or charging the battery automatically using the built in BQ21088 charging chip from TI.

Power the backlight for the display there is an MT3608 24V boost converter paired with another buck/boost converter for the generic 5V rail (LDO wasn't suitable as the RX module power draw is quite high). However for the 1.8V and 3.3V rails, simple LD1117s were used for their low ripple, stable output and low power requirements of the TW8819 and RP2040 ICs. The PCB comes in the preferable dimensions for mounting a generic 4.3" TFT on the back with mounting points for a metal case that also came with my display. It also includes the main power switch (everything but charging) mounted next to the USB C port on the bottom of the board. On the left side you will also find the SMA connector for the 5.8GHz antenna and 8 LEDs, these LEDs are directly controlled by the RP2040 in response to the RSSI signal from the reciever, to give you an easy indication of the signal strength. Besides that there are also several power LEDs and GPIO LED on the other side of the board for general power and functionality debugging in addition to headers near to the SMA connector for more GPIOs/Power/RP2040 debugging. The board also has a keepout zone design to allow double sided tape mounting of the 903759 LiPo battery (on the other side of the display) where it can be easilly soldered to the pads for the battery connection.

There is also a really sleekly designed friction fit case (your mileage may vary with tolerances) designed to house the TFT display and battery mounted on the PCB all in one. It's designed to be easy to print, no supports and pretty much as simple as it gets to assemble. And if that wasn't enough for your preferences of beautiful design, a silkscreen pattern also embosses the board on both sides (although what use this is as you can't even see it in the case, don't ask me) to give a super cool aesthetic.

## Features:
- USB C power supply programming port for the RP2040
- 1s LiPo integration with built in charging
- 4.3" 40 pin TFT display support

## PCB
And this is my PCB. Very difficult to include everything in two layers but I managed to do it to save cost, and ommitted the use of an via in pads, the USB traces are length matched but the signals for the display don't need any trace/impedance matching as they don't run fast enough.

<img src=Pictures/PCB_FRONT.png alt="PCB View" width="300"/> <img src=Pictures/PCB_BACK.png alt="PCB Rendered View" width="300"/> 

And the Schematic:

<img src=Pictures/SCHEMATIC.png alt="Schematic" width="800"/>

And here are some 3D views as well:

<img src=Pictures/3D_VIEW_1.png alt="Schematic" width="800"/>
<img src=Pictures/3D_VIEW_2.png alt="Schematic" width="800"/>

## Firmware Overview
I've included some basic firmware (**untested**) to get the TFT working but other than that it should function like a normal devboard hosting an ESP32

## BOM:
I have also included a .csv with the BOM list but here it is anyways.

 - 1x	CH340C	
 - 3x	Diode	
 - 2x	2N3904	
 - 2x	USB_C_Receptacle_USB2.0_16P	
 - 2x	5.7K	
 - 4x	5.1K	
 - 1x	47K	
 - 4x	1K	
 - 1x	1uF	
 - 3x	0.1uF
 - 4x	10uF
 - 6x	10K
 - 4x	27R
 - 1x	396K
 - 2x	100R
 - 1x	10K
 - 1x	MT3608
 - 1x	LD1117S33TR_SOT223
 - 1x	22R
 - 1x	ESP32-S3-WROOM-1
 - 2x	22uF
 - 1x	22uH
 - 2x	RED Led
 - 1x	GREEN Led
 - 2x	SW_Push
 - 1x	Conn_01x40_Socket
 - 1x	CAT4104
 - 1x	1.8K
 - 2x	Conn_01x14_Pin
 - 2x	Conn_01x04_Pin
 - 2x	Conn_01x09_Pin
(All parts for one devboard only)
