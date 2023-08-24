/*
 ============================================================================
 Name        : GPIO_Prog.c
 Author      : Ahmed Ali
 Date        : 17 Aug 2023
 ============================================================================
 */

#include "GPIO_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"

/* Setting Pin Direction */
void GPIO_SetPinDirection(uint8 uint8_port, uint8 uint8_pin,
		uint8 uint8_direction) {
	if (uint8_direction == INPUT) {
		switch (uint8_port) {
		case PORT_A:
			CLEAR_BIT(DDRA, uint8_pin);
			break;
		case PORT_B:
			CLEAR_BIT(DDRB, uint8_pin);
			break;
		case PORT_C:
			CLEAR_BIT(DDRC, uint8_pin);
			break;
		case PORT_D:
			CLEAR_BIT(DDRD, uint8_pin);
			break;
		}
	} else if (uint8_direction == OUTPUT) {
		switch (uint8_port) {
		case PORT_A:
			SET_BIT(DDRA, uint8_pin);
			break;
		case PORT_B:
			SET_BIT(DDRB, uint8_pin);
			break;
		case PORT_C:
			SET_BIT(DDRC, uint8_pin);
			break;
		case PORT_D:
			SET_BIT(DDRD, uint8_pin);
			break;
		}
	}
}

/* Setting Pin Value */
void GPIO_SetPinValue(uint8 uint8_port, uint8 uint8_pin, uint8 uint8_value) {
	if (uint8_value == PIN_LOW) {
		switch (uint8_port) {
		case PORT_A:
			CLEAR_BIT(PORTA, uint8_pin);
			break;
		case PORT_B:
			CLEAR_BIT(PORTB, uint8_pin);
			break;
		case PORT_C:
			CLEAR_BIT(PORTC, uint8_pin);
			break;
		case PORT_D:
			CLEAR_BIT(PORTD, uint8_pin);
			break;
		}
	} else if (uint8_value == PIN_HIGH) {
		switch (uint8_port) {
		case PORT_A:
			SET_BIT(PORTA, uint8_pin);
			break;
		case PORT_B:
			SET_BIT(PORTB, uint8_pin);
			break;
		case PORT_C:
			SET_BIT(PORTC, uint8_pin);
			break;
		case PORT_D:
			SET_BIT(PORTD, uint8_pin);
			break;
		}
	}
}

/* Getting Pin Value */
void GPIO_GetPinValue(uint8 uint8_port, uint8 uint8_pin, uint8 *p_uint8_data) {
	switch (uint8_port) {
	case PORT_A:
		*p_uint8_data = GET_BIT(PINA, uint8_pin);
		break;
	case PORT_B:
		*p_uint8_data = GET_BIT(PINB, uint8_pin);
		break;
	case PORT_C:
		*p_uint8_data = GET_BIT(PINC, uint8_pin);
		break;
	case PORT_D:
		*p_uint8_data = GET_BIT(PIND, uint8_pin);
		break;
	}
}

/* Setting Port Direction */
void GPIO_SetPortDirection(uint8 uint8_port, uint8 uint8_direction) {
	if (uint8_direction == INPUT) {
		switch (uint8_port) {
		case PORT_A:
			DDRA = 0x00;
			break;
		case PORT_B:
			DDRB = 0x00;
			break;
		case PORT_C:
			DDRC = 0x00;
			break;
		case PORT_D:
			DDRD = 0x00;
			break;
		}
	} else if (uint8_direction == OUTPUT) {
		switch (uint8_port) {
		case PORT_A:
			DDRA = 0xFF;
			break;
		case PORT_B:
			DDRB = 0xFF;
			break;
		case PORT_C:
			DDRC = 0xFF;
			break;
		case PORT_D:
			DDRD = 0xFF;
			break;
		}
	}
}

/* Setting Port Value */
void GPIO_SetPortValue(uint8 uint8_port, uint8 uint8_value) {
	switch (uint8_port) {
	case PORT_A:
		PORTA = uint8_value;
		break;
	case PORT_B:
		PORTB = uint8_value;
		break;
	case PORT_C:
		PORTC = uint8_value;
		break;
	case PORT_D:
		PORTD = uint8_value;
		break;
	}
}

/* Getting Port Value */
void GPIO_GetPortValue(uint8 uint8_port, uint8 *p_uint8_data) {
	switch (uint8_port) {
	case PORT_A:
		*p_uint8_data = PINA;
		break;
	case PORT_B:
		*p_uint8_data = PINB;
		break;
	case PORT_C:
		*p_uint8_data = PINC;
		break;
	case PORT_D:
		*p_uint8_data = PIND;
		break;
	}
}
