# Foue Digit Up Down Rest Counter
In this Project embedded c with interrupt in order to code a four digit seven segment.\
initially the display value should start with 0000. Pressing the left button will count down by one, pressing the right button will count up by one, and Pressing the center button should set the count to 0.\

* Displaying Numbers
Just like all LCD, we turn some segments and leave others off to make a pattern, and then all patterns will be stored in the flash memory as .DB statement.\
Each of the segments is connected to a bit of PORTD.\
Segment a is connected to PD0; b is connected to PD1; and so on; g is connected to PD6. On some seven segment displays, the MSB is connected to a decimal point or to a colon.\
To control which digit is lit (as all of the segments are connected common on each of the four digits, use the lower four bits of PORTB. PB0 controls the left most digit; PB3 controls the rightmost digit.
The buttons are connected to PORTE, specifically bits PE0 (right), PE1 (center), PE2 (left).\
There are no external pullups on the board; hence you must enable the internal pull ups.\
Here is the schematic

<img width="642" alt="Screen Shot 2020-06-02 at 10 05 36 AM" src="https://user-images.githubusercontent.com/57555013/83532258-000ed380-a4bc-11ea-8707-141c4d26cf9b.png">

