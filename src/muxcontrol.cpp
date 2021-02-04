#include "MUX16CH.h"

// The function uses 4 digital control Pins of the
// used board to drive the MUX Channel selection.
// The selected channel is then automatically connected 
// to the common pin (SIG).

// Preliminar set-up of the control pins, 
// set digital pins to select the MUX Channels

MUX16CH::MUX16CH(int N, int s0, int s1, int s2, int s3)
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

// The number of the used control pins is specified by the integer variable Np
// The selectable Channels will be from 0 to 2^(Np)-1:
// Np=1 --> [Ch=0 : Ch=1]
// Np=2 --> [Ch=0 : Ch=3]
// Np=3 --> [Ch=0 : Ch=7]
// Np=4 --> [Ch=0 : Ch=15]
void MUX16CH::selectChannel(int Channel)
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
