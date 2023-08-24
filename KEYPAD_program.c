/*
 ============================================================================
 Name        : KeyPad_program.c
 Author      : Ahmed Ali
 Date        : 21 Aug 2023
 ============================================================================
 */

#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"

uint8 KPD_GetPressedKey(void) {
	/* value of the pressed key and initial has value of no pressed key */
	uint8 pressedKey = KPD_NO_PRESSED_KEY;
	/* value of the counters for loops */
	uint8 colCounter, rowCounter;
	/* flag to check if the pin pressed or not */
	uint8 pinState;
	/* array for keypad values with specific column and row number */
	static uint8 kpdArr[ROW_NUM][COL_NUM] = KPD_ARR_VAL;
	/* array for keypad columns with specific column number */
	static uint8 kpdColArr[COL_NUM] = { KPD_COL_0, KPD_COL_1, KPD_COL_2,
	KPD_COL_3 };
	/* array for keypad rows with specific row number */
	static uint8 kpdRowArr[ROW_NUM] = { KPD_ROW_0, KPD_ROW_1, KPD_ROW_2,
	KPD_ROW_3 };
	/* start loops to check the pins state */
	for (colCounter = 0; colCounter < COL_NUM; ++colCounter) {
		/* activate current column to check it */
		GPIO_SetPinValue(KPD_COL_PORT, kpdColArr[colCounter], PIN_LOW);
		for (rowCounter = 0; rowCounter < ROW_NUM; ++rowCounter) {
			/* read the value of the current row */
			GPIO_GetPinValue(KPD_ROW_PORT, kpdRowArr[rowCounter], &pinState);
			/* if the value is 0 that mean the key is pressed */
			if (pinState == PIN_LOW) {
				/* get the value of the key with column and row number of loop */
				pressedKey = kpdArr[rowCounter][colCounter];
				/* wait until the key is released */
				while (pinState == PIN_LOW) {
					/* get the same value until the key is released */
					GPIO_GetPinValue(KPD_ROW_PORT, kpdRowArr[rowCounter],
							&pinState);
				}
				/* return the value of pressed key in the keypad */
				return pressedKey;
			}
		}
		/* deactivate current column to check the next column in the next loop */
		GPIO_SetPinValue(KPD_COL_PORT, kpdColArr[colCounter], PIN_HIGH);
	}
	/* return the value 0xFF which mean that no key is pressed */
	return pressedKey;
}

void KPD_Init(void) {
	/* set the PORTD output for the columns of KEYPAD */
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_0, OUTPUT);
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_1, OUTPUT);
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_2, OUTPUT);
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_3, OUTPUT);
	/* set the PORTB output for the rows of KEYPAD */
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_0, INPUT);
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_1, INPUT);
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_2, INPUT);
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_3, INPUT);
	/* set all pins of KEYPAD columns high */
	GPIO_SetPortValue(KPD_COL_PORT, 0x3C);
	/* set all pins of KEYPAD rows with internal pull-up resistor */
	GPIO_SetPortValue(KPD_ROW_PORT, 0xF0);
}
