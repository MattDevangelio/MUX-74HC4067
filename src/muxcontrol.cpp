/* 
 *  Filename: muxcontrol.cpp
 *  Author: Mattia Devangelio <mattdev6@gmail.com>
 *  Description: Control the MUX 74HC4067 Channel selection.
 *  License: Copyright (c) 2021, The library is licensed under the MIT license.
 */

#include "MUX.h"

// Preliminary set-up of the control pins.
// The digital pins are set as Output pins

//   Arguments:
// - N: number of the used control pins
// - S0: 1° control pin
// - S1: 2° control pin
// - S2: 3° control pin
// - S3: 4° control pin

MUX::MUX(int N, int s0, int s1, int s2, int s3)
{
  Npins=N;
  int s[4]={s0,s1,s2,s3};
  for(int i=0; i<sizeof(s); i++)
  {
    controlPins[i]=s[i];
    pinMode(controlPins[i], OUTPUT);
    digitalWrite(controlPins[i], LOW);
  }
}

// The number of the used control pins is specified by the variable N
// The selectable Channels will be from 0 to 2^N-1:
// N=1 --> [Ch=0 : Ch=1]
// N=2 --> [Ch=0 : Ch=3]
// N=3 --> [Ch=0 : Ch=7]
// N=4 --> [Ch=0 : Ch=15]

// The function uses the digital control pins to drive the MUX Channel selection.
// Each selected channel is automatically connected to the common pin (SIG).

void MUX::selectChannel(int Channel)
{
   if(Channel>=0 && Channel<=pow(2,Npins)-1)
   {
      for (int i=0; i<Npins; i++)
      {
        if (Channel & (1<<i))
        digitalWrite(controlPins[i], HIGH);  
        else
        digitalWrite(controlPins[i], LOW); 
       }
    }
}
