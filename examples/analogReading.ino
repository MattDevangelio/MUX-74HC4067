/* 
 *  Filename: analogReading.ino
 *  Author: Mattia Devangelio <mattdev6@gmail.com>
 *  Description: Example script of the MUX 74HC4067 control.
 */

// The present example performs multiacquisition of Analog signals 
// from sensors connected between one analog input pin of the ESP32 
// Board and one Channel pin of the MUX. The supply voltage of 3.3V
// is demultiplexed by the SIG pin to each Channel pin of the MUX.

// (Both analog and digital pins refer to ESP32 Boards)

#include "MUX.h"

MUX mux(4, 12, 13, 14, 15); //set the Number of control pins and the digital pins

int N=pow(2, mux.Npins); //Number of selected channels

// The number of signals to be read simultaneosly is between 0 and N.

const int inpin=A0; //set the analog input pin

void setup()
{
  Serial.begin(115200); 
  pinMode(inpin,OUTPUT);
}

void loop()
{
  float reading[N]={};
  for(int ch=0; ch<N; ch++)
  {
    mux.selectChannel(ch);
    pinMode(inpin,INPUT);
    int x=analogRead(inpin);
    reading[ch]=(float)x;
    delay(1); 
  }

  //print on Serial monitor of all voltage readings
  for(int i=0; i<N; i++)
  {
    Serial.print(reading[i]*(3.3/4095.0)); //print value in Volts
    if(i<N-1)
    Serial.print('\t');
  }
  Serial.println(); 
}
