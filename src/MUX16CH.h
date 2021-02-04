#ifndef MUX16CH_H
#define MUX16CH_H

#include <math.h>
#include <Arduino.h>


class MUX16CH
{
  public:
         MUX16CH(int cpins, int s0, int s1, int s2, int s3);
    void selectChannel(int Channel);
    int Npins;
  private:
    int controlPins[4];

};



#endif
