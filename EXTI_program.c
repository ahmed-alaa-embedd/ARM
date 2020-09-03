/***************************/
/*Author : ahmed alaa	*/
/*date : 22/8/2020 		*/
/*version : v02			*/
/***************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


#define NULL		(void * )0		//POINTER TO VOID
//global variable
static void (*EXTI0_CallBack) (void)= NULL;



void MEXTI_VoidInit(void)
{
#if EXTI_LINE==EXTI_LINE0
	SET_BIT(EXTI -> IMR , EXTI_LINE0);
#elif EXTI_LINE==EXTI_LINE1
	SET_BIT(EXTI -> IMR , EXTI_LINE1);
#elif EXTI_LINE==EXTI_LINE2
	SET_BIT(EXTI -> IMR , EXTI_LINE2);

#else
#error("Wrong External interrupt line")

#endif

#if EXTI_SENSE_MODE==FALLING_EDGE
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
#elif EXTI_SENSE_MODE==RISING_EDGE
	SET_BIT(EXTI -> RTSR , EXTI_LINE);
#elif EXTI_SENSE_MODE==ON_CHANGE
	SET_BIT(EXTI -> RTSR , EXTI_LINE);
	SET_BIT(EXTI -> FTSR , EXTI_LINE);

#else
#error("Wrong External interrupt Mode")

#endif
}
void MEXTI_VoidSetSignalLatch(u8 Copy_U8EXTILine, u8 Copy_U8EXTISenseMode)
{
	switch(Copy_U8EXTISenseMode)
		{
		case RISING_EDGE	:SET_BIT(EXTI -> RTSR , Copy_U8EXTILine);			/*Rising edge*/ break;
		case FALLING_EDGE	:SET_BIT(EXTI -> FTSR , Copy_U8EXTILine);			/*FALLING edge*/ break;
		case ON_CHANGE		:SET_BIT(EXTI -> RTSR , Copy_U8EXTILine);			/*Rising edge*/
							 SET_BIT(EXTI -> FTSR , Copy_U8EXTILine);			/*Rising edge*/ break;
		}
	SET_BIT(EXTI->IMR ,Copy_U8EXTILine);
}
void MEXTI_VoidEnable(u8 Copy_U8EXTILine)
{
	SET_BIT(EXTI->IMR ,Copy_U8EXTILine);

}
void MEXTI_VoidDisnable(u8 Copy_U8EXTILine)
{
	CLR_BIT(EXTI->IMR ,Copy_U8EXTILine);
}
void MEXTI_VoidSoftwareTrigger(u8 Copy_U8EXTILine)
{

}

void MEXTI_VoidSetCallBack(void (*ptr) (void))
{

	EXTI0_CallBack= ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI->PR , 0);	//clear pending bit
}

