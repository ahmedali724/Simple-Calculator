/*
 ============================================================================
 Name        : LCD_interface.h
 Author      : Ahmed Ali
 Date        : 20 Aug 2023
 ============================================================================
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_SendCommand(uint8 uint8_command);

void LCD_SendData(uint8 uint8_data);

void LCD_Init(void);

void LCD_DisplayString(const uint8 *uint8_str);

void LCD_NumberToString(sint32 data);

void LCD_MoveCursor(uint8 row, uint8 column);

void LCD_ClearScreen(void);

void LCD_displayStringRowColumn(uint8 row, uint8 column, const uint8 *Str);

#endif /* LCD_INTERFACE_H_ */
