/*
 ============================================================================
 Name        : GPIO_Private.h
 Author      : Ahmed Ali
 Date        : 17 Aug 2023
 ============================================================================
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define DDRA  *((volatile uint8*)0x3A)
#define PORTA *((volatile uint8*)0x3B)
#define PINA  *((volatile uint8*)0x39)

#define DDRB  *((volatile uint8*)0x37)
#define PORTB *((volatile uint8*)0x38)
#define PINB  *((volatile uint8*)0x36)

#define DDRC  *((volatile uint8*)0x34)
#define PORTC *((volatile uint8*)0x35)
#define PINC  *((volatile uint8*)0x33)

#define DDRD  *((volatile uint8*)0x31)
#define PORTD *((volatile uint8*)0x32)
#define PIND  *((volatile uint8*)0x30)

#endif /* GPIO_PRIVATE_H_ */
