### small clock using 4 digit 7 segment display and real time module

# Parts:

#### 4 digit 7 segment display (COMMON_CATHODE in this example. The other one is COMMON_ANODE)
#### 24 wires
#### MH-Real-Time Clock Module + 3 Volt Li(Lithium) Coin Battery
#### arduino nano (any other board should work)
#### 3d printed clock box (optional)


# Connections:

![Screenshot (880)](https://github.com/Y3llow45/small-clock-arduino/assets/68009977/0d6dfb67-5a85-4130-a51f-ee9f318e2c67)

# Issues you may encounter: 

## __Messed up digits:__
#### *1)   Try changing COMMON_CATHODE to COMMON_ANODE in the code.*<br>
#### *2)   Check if notch or dot is at the right direction (to the left).*<br>
#### *3)   Check connections.*<br>

## __Unable to upload sketch:__
#### *1)   Make sure you have ThreeWire and RtcDS1302 libraries installed.*<br>
#### *2)   Try using different/older bootloader (in case you have chinese arduino).*<br>
#### *3)   Press reset button while uplaoding.*<br>
#### *4)   Check if you are using the right port (should be anything other than COM1).*<br>
#### *5)   Check if you have selected the right board*<br>
#### *6)   Try using different cable or program the board using usb to tll programmer*<br>
#### *7)   Reinstall arduino ide*<br>
#### *8)   Use different arduino board*<br>

## __Too dark display:__
#### *1)   Remove or add resistors with lower ohm rating*<br>
#### *2)   Add 1 or 2 ms delay in the main loop (it will make the refresh rate lower but it will be brighter)*<br>
