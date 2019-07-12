# AD5764Lib

Arduino library for the AD5764 DAC.

## *EVAL|AD5764EB Board*
### Link Pin Settings (*Documentation: Table 4 [pg4], Default - Table 1 [pg3]*): 03 July 2019

  | Link | Connection (Default) | Abv Description               | Current                    |
  | ---- | :------------------: | ----------------------------- | -------------------------- |
  | LK1  |        B (A)         | 5V Digital Power Source       | J2                         |
  | LK2  |          C           | DAC Output Short Protection   | 6kΩ Resistor, 10mA current |
  | LK3  |       Inserted       | AGNDA to 0V                   | 0V                         |
  | LK4  |          B           | 5V Reference Voltage Source   | Board                      |
  | LK5  |         A/B          | REFAB/CD Source               | External                   |
  | LK6  |  Inserted (Removed)  | TEMP pin to ADC               | Connected                  |
  | LK7  |        B (A)         | Digital Supply Voltage        | 5V                         |
  | LK8  |          A           | LDAC pin State                | Driven                     |
  | LK9  |          A           | BIN/2sCOMP pin State          | Binary (to DVcc)           |
  | LK10 |       Removed        | CLR pin State w/ LK11 active  | CLR to DVcc w/ 10kΩ        |
  | LK11 |        A (B)         | Controlled via USB or J21/SMB | J21                        |
  | LK12 |       Inserted       | AGNDB to 0V                   | 0V                         |
  | LK13 |       Inserted       | AGNDC to 0V                   | 0V                         |
  | LK14 |       Inserted       | AGNDD to 0V                   | 0V                         |
