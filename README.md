# ITSP

# Introduction

The project aims to build an 8x8x8 cube out of LEDs and to control each LED individually using Arduino. The basic idea is to show static or moving patterns on the cube; moving alphabets is one of them. </br>
The cube's potential can be stretched to cover 3D plotting, music controlled patterns, and basic games like Snake in 3D.
All these patterns can further be moved and rotated to see them from any and every perspective.

# Working Principle

Each horizontal layer is to be controlled by Mosfets, and every row of the layers by shift registers. </br>
All the 64 pillars of the cube have been designated as the negative terminal for the LEDs to be connected to. Each horizontal row consisting of 8 of such pillars further connects to the corresponding shift register. These 8 shift registers keep shifting the data within one layer.  </br>
The horizontal rows of each layer are shorted, being the positive terminal for the LEDs to be connected to. And each of that horizontal layer is connected to the corresponding mosfet. Each of these mosfets turn on and off one by one so that the data now shifts to the upper layer, and the LEDs of that layer glow.

# The Code

# Problems faced

The major problems faced were mainly in building the structure and the wiring.
1. Straightening of the wires for the sturdy structure of the cube.
2. Soldering of the LEDs onto these wires.
3. Holding the layers together for the cube to stand straight.
4. The layers getting internally shorted.

# Solutions

1. Initially the drill didn't prove to be useful for the straightening of the wires, as it kept coming off while it rotated. Afterwards we had to attach a wooden piece to the drill and entangle the wire through a hole in it, which made the wire hold in place and got us perfectly straightened wires. 

2. The solder used to hold the LEDs kept coming off and hence they lost the connection. To tackle this, we took a single strands of a multi-stranded wire and literally sewed it looping through all the LEDs, shorting them.

3. The layers(vertical) were fixed on a thermocol sheet and then a single-stranded wire was used to bind the layers together so that it could stand as well as shorting the horizontal rows of every layer.

4. Had to debug each and every layer, and at times each LED too.
