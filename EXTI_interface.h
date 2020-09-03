/***************************/
/*Author : ahmed alaa	*/
/*date : 22/8/2020 		*/
/*version : v02			*/
/***************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_VoidInit(void);
void MEXTI_VoidSetSignalLatch(u8 Copy_U8EXTILine, u8 Copy_U8EXTISenseMode);
void MEXTI_VoidEnable(u8 Copy_U8EXTILine);
void MEXTI_VoidDisnable(u8 Copy_U8EXTILine);
void MEXTI_VoidSoftwareTrigger(u8 Copy_U8EXTILine);

void MEXTI_VoidSetCallBack(void (*ptr) (void));


#define EXTI_LINE0		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2
#define EXTI_LINE3		3
#define EXTI_LINE4		4
#define EXTI_LINE5		5
#define EXTI_LINE6		6
#define EXTI_LINE7		7
#define EXTI_LINE8		8
#define EXTI_LINE9		9
#define EXTI_LINE10		10
#define EXTI_LINE11		11
#define EXTI_LINE12		12
#define EXTI_LINE13		13
#define EXTI_LINE14		14
#define EXTI_LINE15		15

#define RISING_EDGE		1	/* no start by 0 bec its already initalized by 0 ,increment by 2 for noise*/
#define FALLING_EDGE	3
#define ON_CHANGE		5



#endif
