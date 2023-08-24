/*
 ============================================================================
 Name        : KeyPad_config.h
 Author      : Ahmed Ali
 Date        : 21 Aug 2023
 ============================================================================
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/* define PORTB for keypad row and PORTD for keypad column */
#define KPD_ROW_PORT PORT_B
#define KPD_COL_PORT PORT_D
/* value to check if no button is pressed */
#define KPD_NO_PRESSED_KEY 0xFF
/* define pins from PIN2 to PIN5 in PORTD for keypad columns */
#define KPD_COL_0 PIN2
#define KPD_COL_1 PIN3
#define KPD_COL_2 PIN4
#define KPD_COL_3 PIN5
/* define pins from PIN4 to PIN7 in PORTB for keypad rows */
#define KPD_ROW_0 PIN4
#define KPD_ROW_1 PIN5
#define KPD_ROW_2 PIN6
#define KPD_ROW_3 PIN7
/* define number of columns and rows */
#define COL_NUM 4
#define ROW_NUM 4
/* the values of the keypad with (COL_NUM * ROW_NUM) */
#define KPD_ARR_VAL {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'C', '0', '=', '+'}}

#endif /* KEYPAD_CONFIG_H_ */
