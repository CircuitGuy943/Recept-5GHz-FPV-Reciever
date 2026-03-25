
I happened to have a 4.3" TFT display left over from dissassembling my old screen from my Ender 3 and I also had an ongoing project of a flight controller, with FPV functionality and I had an amazing idea, I present to you:

# **Recept!**

Recept is a 5.8GHz video signal reciever board running with an RX5808 as the reciever module and the combined power of an RP2040 and TW8819 decoder chip to quickly decode and output the video signal to a parallel RGB interface (3x8, 40 pin) for a generic 4.3" TFT display. It runs primarilly off of a fully integrated LiPo battery of dimensions and size 903759 / 2500mAh but it also provides the possibily of running off of USB C both for general use or charging the battery automatically using the built in BQ21088 charging chip from TI.

Power the backlight for the display there is an MT3608 24V boost converter paired with another buck/boost converter for the generic 5V rail (LDO wasn't suitable as the RX module power draw is quite high). However for the 1.8V and 3.3V rails, simple LD1117s were used for their low ripple, stable output and low power requirements of the TW8819 and RP2040 ICs. The PCB comes in the preferable dimensions for mounting a generic 4.3" TFT on the back with mounting points for a metal case that also came with my display. It also includes the main power switch (everything but charging) mounted next to the USB C port on the bottom of the board. On the left side you will also find the SMA connector for the 5.8GHz antenna and 8 LEDs, these LEDs are directly controlled by the RP2040 in response to the RSSI signal from the reciever, to give you an easy indication of the signal strength. Besides that there are also several power LEDs and GPIO LED on the other side of the board for general power and functionality debugging in addition to headers near to the SMA connector for more GPIOs/Power/RP2040 debugging. The board also has a keepout zone design to allow double sided tape mounting of the 903759 LiPo battery (on the other side of the display) where it can be easilly soldered to the pads for the battery connection.

There is also a really sleekly designed friction fit case (your mileage may vary with tolerances) designed to house the TFT display and battery mounted on the PCB all in one. It's designed to be easy to print, no supports and pretty much as simple as it gets to assemble. And if that wasn't enough for your preferences of beautiful design, a silkscreen pattern also embosses the board on both sides (although what use this is as you can't even see it in the case, don't ask me) to give a super cool aesthetic.

To use this you simply need the PCB, the display is attached to it using the metal bracket/casing it came in and the battery can either be stuck on with double sided tape or if you're putting it in the case it can even be left loose as it'll be contained. The device then fits into the bottom section of the case and the top section then just simply friction fits over it and sits in place. The configuration code can then bu uploaded using Arduino IDE via the USB C cable onto the RP2040 to configure the TW8819 and allow it to show video on the TFT display.

## Features:
- USB C power supply programming port for the RP2040
- 1s LiPo integration with built in charging
- 4.3" 40 pin TFT display support
- 5.8GHz video band
- Channel switch ability
- RSSI support
- No screw assembly

## PCB
This is the PCB, with L1 to L4 Layers, silkscreen for both layers and an all layers view

<img src=Pictures/Finish/PCB_L1.png alt="PCB Layer 1" width="300"/> <img src=Pictures/Finish/PCB_L2.png alt="PCB Layer 2" width="300"/> <img src=Pictures/Finish/PCB_L3.png alt="PCB Layer 3" width="300"/> 
<img src=Pictures/Finish/PCB_L4.png alt="PCB Layer 4" width="300"/> <img src=Pictures/Finish/PCB_Silkscreen_Top.png alt="PCB Slikscreen Top" width="300"/> <img src=Pictures/Finish/PCB_Silkscreen_Bottom.png alt="PCB Silkscreen Bottom" width="300"/> 


And here is the schematic

<img src=Pictures/Finish/top_schem.png alt="Schematic" width="800"/>
<img src=Pictures/Finish/bottom_schem.png alt="Schematic" width="800"/>

## Case and 3D renders
Here are also some 3D renders done in fusion to show off the case and it's functionality :)

<img src=Pictures/Renders/render1.png alt="Case render 1" width="300"/> <img src=Pictures/Renders/render2.png alt="Case render 2" width="300"/> <img src=Pictures/Renders/render3.png alt="Case render 3" width="300"/> 
<img src=Pictures/Renders/render4.png alt="Case render 4" width="300"/> <img src=Pictures/Renders/render5.png alt="Case render 5" width="300"/> <img src=Pictures/Renders/render6.png alt="Case render 6" width="300"/>
<img src=Pictures/Renders/render7.png alt="Case render 7" width="300"/> <img src=Pictures/Renders/render8.png alt="Case render 8" width="300"/> <img src=Pictures/Renders/render9.png alt="Case render 9" width="300"/> 

And last but not least this is a render of the PCB itself:

<img src=Pictures/Renders/render10.png alt="PCB render" width="300"/>

## Firmware Overview
I've included some basic firmware (**untested**) that should get the TFT display working out of the box with a quick upload from arduino IDE

## BOM:
The BOM list for the actual PCB components is in the BOM folder section and here is also a BOM list for all the other components I plan to buy for this:


- PCB             $198.94		
- Antenna         $7.77      https://www.aliexpress.com/item/1005006153683653.html		
- 90 degree SMA   $4.51      https://www.aliexpress.com/item/1005005665998117.html						
- RX5808 module   $33.54     https://www.ebay.co.uk/itm/264574341923						                (This module is not cheaper on AliExpress)
- Battery         $9.39      https://www.ebay.co.uk/itm/396305473532?var=665862385939						(I don't feel safe buying batteries off Ali)
											
Total			      $246.38		

<img width="1083" height="141" alt="image" src="https://github.com/user-attachments/assets/e6ed5a2c-47a3-496e-8e86-db1041965be2" />


