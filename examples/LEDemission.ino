/* 
 * Filename: LEDemission.ino
 * Author: Mattia Devangelio <mattdev6@gmail.com>
 * Description: Example script of the MUX 74HC4067 control.
 */

// The script reports an easy example demostrating the working of 
// the MUX channel selection process by using the library MUX.h.
// In the used configuration, a number N of LEDs are connected 
// to N channels of the MUX to provide evidence of the performed channel selection.

#include "MUX.h"

MUX mux(4, 12, 13, 14, 15); //set the Number of control pins and the digital pins

int N=pow(2, mux.Npins); //Number of selected channels

void setup()
{
  Serial.begin(115200); 
}

void loop()
{
  //ascending channel selection 
  for(int ch=0; ch<N; ch++)
  { 
    mux.selectChannel(ch);
    delay(50); //set a pause between one selection and the next
  }
  
  //descending channel selection
  for(int ch=N-2; ch>0; ch--)
  {
    mux.selectChannel(ch);
    delay(50); //set a pause between one selection and the next
  }
}
