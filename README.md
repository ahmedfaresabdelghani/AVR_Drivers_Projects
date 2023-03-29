# Peripheral And Drivers For AVR Microcontrollers

A repository for drivers built specifically for **AVR Micro-controller** with **layered Architecture** applied.  
This was developed during my time enrolled in Embedded Systems diploma .
This repository can be useful to anyone in the process of learning Embedded Systems, and working with AVR.

Please consider referring my work if you would ever use it in any of your own projects.


## COTS

The components that are typically found on a software development shelf for embedded systems include:

- MCAL (Microcontroller Abstraction Layer): As mentioned earlier, the MCAL provides a low-level interface between the microcontroller hardware and the higher-level software. It includes drivers and functions for handling peripherals such as timers, GPIOs, and communication interfaces.

- HAL (Hardware Abstraction Layer): The HAL provides an interface between the hardware and the operating system or application software. It includes functions and drivers that abstract hardware details, such as timers, interrupts, and communication interfaces, and provides a standardized interface for software to interact with the hardware.

- APP (Application Software): The APP is the main software component that runs on the microcontroller and provides the functionality of the embedded system. It interacts with the MCAL and HAL to control the hardware and perform tasks such as data processing, communication, and control.

- RTOS (Real-Time Operating System): An RTOS is a software layer that provides a scheduling and task management system for the embedded system. It allows for the execution of multiple tasks in a predictable and deterministic manner, enabling real-time response to external events.

- BSP (Board Support Package): The BSP provides low-level software components and drivers specific to the hardware platform, such as the microcontroller and peripherals, and allows for easy integration of the hardware with the software.

These components are usually provided by the microcontroller manufacturer or third-party vendors and can be combined and customized to suit the requirements of a particular embedded system project.



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

## Author
- [@AhmedFares->linkedin](https://www.linkedin.com/in/ahmed-fares-42ab14220)

<h4 align='center'>Made with :heart:</h4>
