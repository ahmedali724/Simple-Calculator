/*
 ============================================================================
 Name        : LCD_program.c
 Author      : Ahmed Ali
 Date        : 20 Aug 2023
 ============================================================================
 */

#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "GPIO_Interface.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

void LCD_SendCommand(uint8 uint8_command) {
	/* set RS pin to low...RS low => command  */
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, PIN_LOW);
	/* set RW pin to low...RW low => write  */
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	/* send the command to data pin in LCD */
	GPIO_SetPortValue(LCD_DATA_PORT, uint8_command);
	/* set enable pin to high then low to generate pulse */
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_HIGH);
	_delay_ms(2);
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_LOW);
}

void LCD_SendData(uint8 uint8_data) {
	/* set RS pin to high...RS high => data  */
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, PIN_HIGH);
	/* set RW pin to low...RW low => write  */
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	/* send the command to data pin in LCD */
	GPIO_SetPortValue(LCD_DATA_PORT, uint8_data);
	/* set enable pin to high then low to generate pulse */
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_HIGH);
	_delay_ms(2);
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_LOW);
}

void LCD_Init(void) {
	/* set the PORTA output for the data of LCD */
	GPIO_SetPortDirection(LCD_DATA_PORT, OUTPUT);
	/* set the pin 0,1,2 in PORTB output for control of LCD */
	GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
	GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
	GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);
	/* wait for 40ms */
	_delay_ms(40);
	/* set LCD configuration to 2 lines and 5*8 font size */
	LCD_SendCommand(LCD_TWO_LINE_EIGHT_BIT_MODE);
	/* turn on the LCD and disable showing a cursor */
	LCD_SendCommand(LCD_CURSOR_OFF);
	/* clear display */
	LCD_SendCommand(LCD_CLEAR_DISPLAY);
}

void LCD_DisplayString(const uint8 *uint8_str) {
	uint8 i = 0;
	/* loop until reach the last char of sting */
	while (uint8_str[i] != '\0') {
		/* send char by char of the string to the LCD */
		LCD_SendData(uint8_str[i]);
		/* increment the counter to the next char */
		i++;
	}
}

void LCD_NumberToString(sint32 data) {
	/* string to hold the ASCII result */
	char str[16];
	/* use itoa C function to convert the data to its corresponding ASCII value*/
	itoa(data, str, 10);
	/* display the string */
	LCD_DisplayString(str);
}

void LCD_MoveCursor(uint8 row, uint8 column) {
	/* variable to know which address in the LCD will to cursor moved to */
	uint8 LCD_address = 0;
	/* check which row is chosen */
	switch (row) {
	case 0:
		LCD_address = column;
		break;
	case 1:
		/* the first address in the second line is 0x40 then add it to the LCD address */
		LCD_address = column + 0x40;
		break;
	}
	/* move the LCD cursor to the specific address location */
	LCD_SendCommand(LCD_CURSOR_POSITION | LCD_address);
}

void LCD_ClearScreen(void) {
	/* send the clear screen command to the LCD */
	LCD_SendCommand(LCD_CLEAR_DISPLAY);
}

void LCD_displayStringRowColumn(uint8 row, uint8 column, const uint8 *Str) {
	/* go to to the required LCD position */
	LCD_MoveCursor(row, column);
	/* display the string */
	LCD_DisplayString(Str);
}
