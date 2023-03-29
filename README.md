# Peripheral And Drivers For AVR Microcontrollers

A repository for drivers built specifically for **AVR Micro-controller** with **layered Architecture** applied.  
This was developed during my time enrolled in Embedded Systems diploma by IMT School.
This repository can be useful to anyone in the process of learning Embedded Systems, and working with AVR.

Please consider referring my work if you would ever use it in any of your own projects.


## List of Existing Drivers 
1. DIO peripheral (MCAL Layer)
2. ADC peripheral (MCAL Layer)
3. Extint/Interrupt peripheral (MCAL Layer)
4. Timer peripheral (MCAL Layer)
5. LCD module (HAL Layer)
6. Keypad module (HAL Layer)
7. ICU(SW/HW) (MCAL Layer)
8. USART (MCAL Layer)
9. SPI (MCAL Layer)
10. NRF24L01 RF Module (HAL Layer)

## How to use
Each driver is encapsualted in a folder, to use any of the drivers you should read the `interface.h` file (fully commented on what every function does). 
It's then as easy as just including the `interface.h` file in your work and compiling the driver implementation files with your object file using the compiler. 

## Contributing 
If you'd like to contribute in building more drivers for AVR Microcontrollers on this repository, feel free to fork and PR you work. Am always open to contributions and growing this work to give back to the community.

<h4 align='center'>Made with :heart:</h4>
