#ifndef MUX_H
#define MUX_H

#include <math.h>
#include <Arduino.h>

class MUX
{
  public:
         MUX(int cpins, int s0, int s1, int s2, int s3);
    void selectChannel(int Channel);
    int Npins;
  private:
    int controlPins[4];
};

#endif
