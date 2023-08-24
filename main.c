/*
 ============================================================================
 Name        : main.c
 Author      : Ahmed Ali
 Date        : 21 Aug 2023
 ============================================================================
 */
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	/* declare variable used in main file */
	sint32 num1, num2, result;
	float32 floatResult;
	uint8 i, j, k, floatFlag;
	/* call the function of the KEYPAD initialization */
	KPD_Init();
	/* call the function of the LCD initialization */
	LCD_Init();
	/* print my name on the LCD */
	LCD_DisplayString("***AHMED  ALI***");
	/* move the cursor to the second row of LCD */
	LCD_MoveCursor(1, 0);
	/* print the project name */
	LCD_DisplayString("Mini Calc. Proj.");
	/* wait for 2 second */
	_delay_ms(2000);
	/* clean screen */
	LCD_ClearScreen();
	/* super loop */
	while (1) {
		/* declare the string used in super loop */
		char input[16] = "", num1_str[8] = "", num2_str[8] = "", operator, temp;
		/* at first all number is 0 */
		num1 = 0, num2 = 0;
		/* flag to check if there is a float numbers in division */
		floatFlag = 0;
		i = 0;
		while (1) {
			if (i < 16) {
				/* get input from the KEYPAD */
				temp = KPD_GetPressedKey();
				/* loop until a key is pressed, if key is pressed then the loop will break */
				while (temp == KPD_NO_PRESSED_KEY) {
					temp = KPD_GetPressedKey();
				}
				/* if the clean screen button is pressed in KEYPAD */
				if (temp == 'C') {
					/* clean the LCD screen */
					LCD_ClearScreen();
					/* make the input string empty again */
					strcpy(input, "");
					/* start a loop from first again */
					i = 0;
					continue;
				}
				/* put the value of key pressed in the input string */
				input[i] = temp;
				/* if = button is pressed, then it is the end of operation */
				if (input[i] == '=') {
					/* show = in the LCD */
					LCD_SendData('=');
					/* the null character to indicate the end of string */
					input[i] = '\0';
					/* break the loop */
					break;
				}
				/* if the button pressed is not = of C then send the button value to LCD */
				LCD_SendData(input[i]);
				/* increase the index of input string */
				i++;
			}
		}
		/* reset all counters */
		i = 0, j = 0, k = 0;
		while (input[i] != '\0') {
			/* if the operator char is found in input string */
			if (input[i] == '*' || input[i] == '/' || input[i] == '+'
					|| input[i] == '-') {
				/* then store the operator in the variable */
				operator = input[i];
				/* increase the index of input string */
				i++;
				/* loop to take the second number of the operation and store it in a string */
				while (input[i] != '\0') {
					/* store digit digit of the second number in the second number string */
					num2_str[k] = input[i];
					/* increase the index of second number string */
					k++;
					/* increase the index of input string */
					i++;
				}
				break;
			}
			/* if the operator is not found, then we still in the first number part */
			else {
				/* store digit digit of the first number in the first number string */
				num1_str[j] = input[i];
				/* increase the index of first number string */
				j++;
				/* increase the index of input string */
				i++;
			}
		}
		/* function to convert string to integer to use it in the operation */
		num1 = atoi(num1_str);
		num2 = atoi(num2_str);
		/* switch case to know which operator is chosen */
		switch (operator) {
		case '+':
			/* the + operator is chosen, then add two numbers and store it in result number */
			result = num1 + num2;
			break;
		case '-':
			/* the - operator is chosen, then subtract two numbers and store it in result number */
			result = num1 - num2;
			break;
		case '*':
			/* the * operator is chosen, then multiply two numbers and store it in result number */
			result = num1 * num2;
			break;
		case '/':
			/* the / operator is chosen, then divide two numbers and store it in result number */
			/* if the first number divisible by the second, then there is no floating part */
			if (num1 % num2 == 0) {
				result = num1 / num2;
			} else {
				/* else, there is a floating part and start to calculate it */
				floatResult = (float32) num1 / num2;
				/* take the integer part of the result */
				result = num1 / num2;
				/* make the flag is true */
				floatFlag = 1;
				/* get the first 3 digits of the floating part */
				floatResult = (floatResult - result) * 1000;
			}
			break;
		}
		/* start to print the result of the operation */
		/* check if there is a floating part in the operation */
		if (floatFlag) {
			/* if the integer part of floating is 0, then send it */
			if (result == 0) {
				LCD_SendData('0');
			} else {
				/* if the integer part of floating is not 0, then send the all number */
				LCD_NumberToString(result);
			}
			/* send the dot to the LCD */
			LCD_SendData('.');
			/* print the floating part of the operation */
			LCD_NumberToString((sint32) floatResult);
		} else {
			/* there is no floating part, then send the integer number only */
			LCD_NumberToString(result);
		}
		/* loop to wait for the C button is pressed to clean the screen for new operation */
		temp = KPD_GetPressedKey();
		while (temp != 'C') {
			temp = KPD_GetPressedKey();
		}
		/* the C button is pressed and we will clean the screen */
		LCD_ClearScreen();
	}
}
