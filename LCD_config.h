/*
 ============================================================================
 Name        : LCD_config.h
 Author      : Ahmed Ali
 Date        : 20 Aug 2023
 ============================================================================
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_DATA_PORT PORT_A

#define LCD_CTRL_PORT PORT_B
#define LCD_RS_PIN    PIN0
#define LCD_RW_PIN    PIN1
#define LCD_EN_PIN    PIN2

#define LCD_CLEAR_DISPLAY 0x01
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_POSITION 0x80
#define LCD_TWO_LINE_EIGHT_BIT_MODE 0x38

#endif /* LCD_CONFIG_H_ */
