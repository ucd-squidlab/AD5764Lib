#include "Arduino.h"
#include "SPI.h"
#include "AD5764.h"

//DAC symbols

//Defines for the input shift regsiter bit map, designed to be OR'd together to create a valid input for the AD5764

//Read/Write bit (R, W)
#define READ  1 << 7
#define WRITE 0

//Register select bits (REG0, REG1, REG2)
#define FUNCTION_REG  0 << 3
#define DATA_REG      2 << 3
#define COURSE_REG    3 << 3
#define FINE_REG      4 << 3
#define OFFSET_REG    5 << 3

//Course gain options
#define COURSE_GAIN_0 0
#define COURSE_GAIN_1 1
#define COURSE_GAIN_2 2

//Function select bits (A2, A1, A0, if function register is selected) 
#define NOP 0
#define LOCAL_GROUND_OFFSET_ADJUST 1
#define CLEAR_DATA  4
#define LOAD_DATA   5

//converts a decimal value into a value between 0-65535, so it can be used by the DAC
<<<<<<< HEAD
#define VREFIN 5.0
#define CONVERT_VALUE2DAC(vout) ((uint16_t)(16384.0 * ((vout/VREFIN) + 2)))
=======
#define VREFIN 5
#define CONVERT_VALUE2DAC(vout) (int(-16384 * (((float)vout / VREFIN) + 2)))
>>>>>>> 5f4d724bdcf1b54da456365aaea0e5a6aa6ad7fd

AD5764::AD5764() { }
AD5764::~AD5764() { }

void AD5764::SetupAD5764(int cs, int ldac, int clr) {
	//assign pin values to class members
	_cs = cs;
	_ldac = ldac;
	_clr = clr;

	//setup SPI communication with DAC
	SPI.begin(_cs);
	
	//set bit order for DAC
	SPI.setBitOrder(_cs, MSBFIRST);
	
	//set clock divider for DAC
	//SPI.setClockDivider(_cs, SPI_CLOCK_DIV64);
	
	//set data mode for dac
	SPI.setDataMode(_cs, SPI_MODE1);

	//set pin modes for LDAC and CLR pins
	pinMode(_ldac, OUTPUT);
	pinMode(_clr, OUTPUT);

	//write pin values 
	//on the eval board, there is a jumper that can be used to ground the LDAC pin, so this would be unnecessary 
	digitalWrite(_ldac, LOW);    //we will not use LDAC, so it will be driven high, dac will automatically respoind with rising edge of the chip select signal

	//the DAC has a startup reset method, which will automatically clear the DAC on start
	digitalWrite(_clr, HIGH);    //not going to clear the DAC, must be driven high
}

//sets the output on the specified DAC channel
<<<<<<< HEAD
//the data word is a value between 0-65535 in Binary encoding

// void AD5764::SetDataRegister(float vout, int dac_channel) {
// 	//to set the data register in the DAC, we use the following bits:
// 	//WRITE | DATA_REG | DAC_Address | data

// 	uint16_t data = CONVERT_VALUE2DAC(vout);

// 	//make an array of bytes to send in MSB first order
// 	uint8_t data_array[3];
// 	data_array[0] = WRITE | DATA_REG | dac_channel;
// 	data_array[1] = (data & 0xFF00) >> 8;
// 	data_array[2] = (data & 0x00FF);

// 	//transfer the data to the DAC
// 	SPI.transfer(_cs, data_array, 3);
// }

void AD5764::SetDataRegister(uint16_t vout, int dac_channel) {
	//to set the data register in the DAC, we use the following bits:
	//WRITE | DATA_REG | DAC_Address | data

=======
//the data word is a value between 0-65535 in 2's complement encoding
void AD5764::SetDataRegister(float value, int dac_channel) {
	//to set the data register in the DAC, we use the following bits:
	//WRITE | DATA_REG | DAC_Address | data

	//convert the passed decimal value into a value between 0-65535
	short data = CONVERT_VALUE2DAC(value);

>>>>>>> 5f4d724bdcf1b54da456365aaea0e5a6aa6ad7fd
	//make an array of bytes to send in MSB first order
	uint8_t data_array[3];
	data_array[0] = WRITE | DATA_REG | dac_channel;
	data_array[1] = (vout & 0xFF00) >> 8;
	data_array[2] = (vout & 0x00FF);

	//transfer the data to the DAC
	SPI.transfer(_cs, data_array, 3);	
}