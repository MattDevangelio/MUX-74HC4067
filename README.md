### MUX/DEMUX 74HC4067
Library for 74HC4067 Mux/Demux Control

<a href="https://github.com/MattDevangelio/MattDevangelio.github.io/blob/main/files/documents/MUX/mux.jpeg"><img src="https://github.com/MattDevangelio/MattDevangelio.github.io/blob/main/files/documents/MUX/mux.jpeg" alt="MUX-pic" border="0" width="50%" height="50%"></a>

The CD74HC4067 is a high-speed CMOS Logic 16-Channel Analog Multiplexer/Demultiplexer that features 16 channels of selectable inputs/outputs. 
The routing of common signal to independent I/O is set by digitally controlling 4 select lines, which can be set either H or L into one of 16 binary combinations. The chip allows to connect up to 16 analog sources to 4 pins on the microcontroller:

````cpp
S0
S1
S2
S3
````
### Include header file
````cpp
#include "MUX.h"
````
### Define class
````cpp
MUX mux;
````
### Main function
````cpp
void MUX(int N, int s0, int s1, int s2, int s3);
````
Executed:
````cpp
MUX mux(4, 12, 13, 14, 15);
````
### Selection function
````cpp
void selectChannel(int Channel);
````
Executed:
````cpp
mux.selectChannel(ch);
````

The reported picture shows the SparkFun Analog/Digital MUX Breakout used for all the performed Multiplexing/Demultiplexing tests.

See the example code related to the analog signals multiacquisiton [here](examples/analogReading.ino). The following image shows two voltage signals properly read from two sensors connected to the MUX Channels `C6` and `C12`.

<a href="https://MattDevangelio.github.io/files/documents/MUX/Serial_multiacquisition.png"><img src="https://MattDevangelio.github.io/files/documents/MUX/Serial_multiacquisition.png" alt="Serial-pic" border="0" width="80%" height="80%"></a>

