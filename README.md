### small clock using 4 digit 7 segment display and real time module

# Parts:
#### 4 digit 7 segment display (COMMON_CATHODE in this example. The other one is COMMON_ANODE)<br>
#### 24 wires<br>
#### MH-Real-Time Clock Module + 3 Volt Li(Lithium) Coin Battery<br>
#### arduino nano (any other board should work)<br>
#### 3d printed clock box (optional)

# Connections:

![Screenshot (880)](https://github.com/Y3llow45/small-clock-arduino/assets/68009977/0d6dfb67-5a85-4130-a51f-ee9f318e2c67)

# Issues you may encounter: 

### __Messed up digits:__
#### *1)   Try changing COMMON_CATHODE to COMMON_ANODE in the code.*<br>
#### *2)   Check if notch or dot is at the right direction (to the left).*<br>
#### *3)   Check connections.*<br>

### __Unable to upload sketch:__
#### *1)   Make sure you have ThreeWire and RtcDS1302 libraries installed.*<br>
#### *2)   Try using different/older bootloader (in case you have chinese arduino).*<br>
#### *3)   Press reset button while uplaoding.*<br>
#### *4)   Check if you are using the right port (should be anything other than COM1).*<br>
