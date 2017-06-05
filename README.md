# ITSP

# Introduction

The project aims to build an 8x8x8 cube out of LEDs and to control each LED individually using Arduino. The basic idea is to show static or moving patterns on the cube; moving alphabets is one of them. </br>
The cube's potential can be stretched to cover 3D plotting, music controlled patterns, and basic games like Snake in 3D.
All these patterns can further be moved and rotated to see them from any and every perspective.

# Working Principle

Each horizontal layer is to be controlled by Mosfets, and every row of the layers by shift registers. </br>
All the 64 pillars of the cube have been designated as the negative terminal for the LEDs to be connected to. Each horizontal row consisting of 8 of such pillars further connects to the corresponding shift register. These 8 shift registers keep shifting the data within one layer.  </br>
The horizontal rows of each layer are shorted, being the positive terminal for the LEDs to be connected to. And each of that horizontal layer is connected to the corresponding mosfet. Each of these mosfets turn on and off one by one so that the data now shifts to the upper layer, and the LEDs of that layer glow. </br>
As an example, if we want to brighten up an LED at position (1,1,1), i.e. at one of the vertex of cube and the rest being off, we will give high potential to Mosfet of layer 1 for short time (say *x*). During this *x* time unit, we shift data through the shift register to give potential to the negative terminal. The working of Shift Registers is explained later. The data that we pass through the Mosfet is all highs except a low. Since the postive as well as the negative terminals of all LEDs except one, of layer 1, is at high. So all the LEDs of layer 1 will be off except for one. The clock frequency of Shift Register is much higher than inverse of *x*, i.e. the shifting of data takes place much much faster than the duration for which the layer is given high potential. </br>
From layer 2 onwards, the data passed is always high. As the two terminals have the same potential, no LED of that layer should glow. This goes on in a loop, i.e. after layer 8, layer 1 is again given high voltage and the data corresponding to layer 1 is shifted at a very fast rate. </br>

#Working of Shift Register

Shift Register can be used to get multiple output from a single data pin, clock pin and latch pin, thus enabling us to use it in our benefit. The datasheet of the Shift Register 74HC595 is here. We use eight Shift Registers in series so that it gives us 64 outputs using only 3 pins, the data pin, clock pin and latch pin. The pin number ( ) of one Shift Register is connected to the data pin of the next Shift Register. The clock and the latch pins are common to all the Shift Registers. </br>
An interesting thing to observe is that if we want the first LED of a layer to be on, we have to pass 63 highs, and the last one should be low, since the first part of data goes to the last Shift Register and the last part of data goes to the first Shift Register. As a simple analogy, when a snake enters a hole, the head reaches the end of it while the tail is still at the entrance. </br>

#Working of Mosfet (and transistor as a Switch)
The schematic connection is shown here. The Mosfet has three pin, the gate, the source and the drain. </br>
INCOMPLETE


# The Code of Alphabet display

# # Initialisation
All the alphabets and the corresponding high/low values for displaying it in an 8x8 sheet has been defined using as many as 26 8x8 arrays. Also a variable having all LEDs off is also defined. 

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
