# AD5764Lib

Arduino library for controlling the *[DAC: AD5764]* chipset using SPI protocol

## **Evaluation Board**: *[EVAL-AD5764EB]*

### Link Pin Configuration (*Documentation: Table 4 [[pg4]], Default - Table 1 [[pg3]]*)

   | Link | Connection [Default] | Abv Description               | Current                                            |
   | ---- | :------------------: | ----------------------------- | -------------------------------------------------- |
   | LK1  |        B [A]         | 5V Digital Power Source       | J2                                                 |
   | LK2  |          C           | DAC Output Short Protection   | 6kΩ Resistor, 10mA current                         |
   | LK3  |       Inserted       | AGNDA to 0V                   | 0V                                                 |
   | LK4  |          B           | 5V Reference Voltage Source   | Board                                              |
   | LK5  |         A/B          | REFAB/CD Source               | External                                           |
   | LK6  |  Inserted [Removed]  | TEMP pin to ADC               | Connected                                          |
   | LK7  |        B [A]         | Digital Supply Voltage        | 5V                                                 |
   | LK8  |          A           | LDAC pin State                | Driven                                             |
   | LK9  |          A           | BIN/2sCOMP pin State          | Binary (to DVcc)                                   |
   | LK10 |       Removed        | CLR pin State w/ LK11 active  | CLR to DVcc w/ 10kΩ                                |
   | LK11 |        A [B]         | Controlled via USB or J21/SMB | J21                                                |
   | LK12 |       Inserted       | AGNDB to 0V                   | 0V                                                 |
   | LK13 |       Inserted       | AGNDC to 0V                   | 0V                                                 |
   | LK14 |       Inserted       | AGNDD to 0V                   | 0V                                                 |

![DAC LINKS](./docs/20190717.EVAL-AD5764(DAC)_Links.jpg)
<sup> Updated: 17 July 2019 </sup>
 
[DAC: AD5764]: https://www.analog.com/media/en/technical-documentation/data-sheets/AD5764.pdf
[EVAL-AD5764EB]: https://www.analog.com/media/en/technical-documentation/evaluation-documentation/106758267AD5764EB_0.pdf
[pg3]: https://www.analog.com/media/en/technical-documentation/evaluation-documentation/106758267AD5764EB_0.pdf#page=3
[pg4]: https://www.analog.com/media/en/technical-documentation/evaluation-documentation/106758267AD5764EB_0.pdf#page=4