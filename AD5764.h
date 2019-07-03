#ifndef AD5764_H_
#define AD5764_H_

//DAC channels (A0, A1, A2, for data, course, gain, fine gain, or offset registers selected)
#define DAC_A   0
#define DAC_B   1
#define DAC_C   2
#define DAC_D   3
#define DAC_ALL 4

class AD5764 {
  public:
  AD5764();
  ~AD5764();

  //setup SPI communication and pins used with the AD5764
  //cs: chip select pin, ldac: load dac pin, clr: clear pin 
  void SetupAD5764(int cs, int ldac, int clr);

  //set the output of the DAC on one of the 4 DAC channels
  void SetDataRegister(float value, int dac_channel);

  private:
  int _cs, _ldac, _clr;
};

#endif