# Mini Project: Simple Calculator using ATmega32 Microcontroller

This project involves creating a basic calculator using the ATmega32 microcontroller. The calculator can perform addition, subtraction, multiplication, and division operations. The project utilizes drivers for GPIO, a 16x2 LCD, and a keypad for user interaction. Each line of code is thoroughly commented to explain its functionality.

## Software Requirements
- Eclipse IDE (for code development)
- AVR GCC Compiler (for compiling the code)
- AVR Dude (for flashing the microcontroller)
- Proteus (for simulation)

## How to Use in Proteus Simulation
1. Open the Proteus simulation file included in the project.
2. Simulate the circuit to interact with the virtual keypad and LCD.
3. Follow the on-screen instructions to input numbers and perform calculations.

![image](https://github.com/ahmedali724/Simple-Calculator/assets/111287464/51e90912-6176-4990-a471-0f996ad12fc4)

## Code Structure
- **main.c**: The main program file containing the calculator logic and user interface.
- **LCD_config.h**, **LCD_interface.h** and **LCD_program.c**: LCD driver for initializing and controlling the 16x2 LCD display.
- **KEYPAD_config.h**, **KEYPAD_interface.h** and **KEYPAD_program.c**: Keypad driver for reading user input from the keypad.
- **GPIO_Private.h**, **GPIO_Interface.h** and **GPIO_Prog.c**: GPIO driver to specify the output and input pins.

## Comments
Comments have been provided throughout the code to explain each step's purpose and functionality.
