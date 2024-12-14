<h3>Small Clock using 4 Digit 7 Segment Display and Real Time Clock Module</h3>

<img src="https://github.com/user-attachments/assets/53cb0418-ca66-46e1-83b4-53dc47f9f369" width="500px">
<img src="https://github.com/user-attachments/assets/c2507271-b54e-4046-8fc4-5398dd562237" width="500px">

# Parts:

#### 4 digit 7 segment display (COMMON_CATHODE in this example. The other one is COMMON_ANODE)
#### 24 wires
#### MH-Real-Time Clock Module + 3 Volt Li(Lithium) Coin Battery
#### arduino nano (any other board should work)
#### 3d printed clock box (optional)


# Connections:

![Screenshot (880)](https://github.com/Y3llow45/small-clock-arduino/assets/68009977/0d6dfb67-5a85-4130-a51f-ee9f318e2c67)

![7segment4digit_schema-2690630837](https://github.com/Y3llow45/small-clock-arduino/assets/68009977/38d3d0b8-1eb8-4c98-892c-7313c0ade956)
# Issues you may encounter: 

## __Messed up digits:__
#### 1)   Try changing COMMON_CATHODE to COMMON_ANODE in the code.<br>
#### 2)   Check if notch or dot is at the right direction (to the left).<br>
#### 3)   Check connections.<br>

## __Unable to upload sketch:__
#### 1)   Make sure you have ThreeWire and RtcDS1302 libraries installed.<br>
#### 2)   Try using different/older bootloader (in case you have chinese arduino).<br>
#### 3)   Press reset button while uploading.<br>
#### 4)   Check if you are using the right port (COM1 is reserved by the system).<br>
#### 5)   Check if you have selected the right board<br>
#### 6)   Try using different cable or program the board using usb to tll programmer<br>
#### 7)   Reinstall arduino ide<br>
#### 8)   Use different arduino board<br>

## __Too dark display:__
#### 1)   Add resistors with lower ohm rating<br>
#### 2)   Add 1 or 2 ms delay in the main loop (it will make the refresh rate lower but it will be brighter)<br>
