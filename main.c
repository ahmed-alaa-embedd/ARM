/*
 * main.c
 *
 *  Created on: 24 Aug 2020
 *      Author: ahmed alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STk_interface.h"

volatile u8 U8StartFlag=0;
volatile u32 U32FramData[50]={0};
volatile u8 U8EdgeCounter=0;
volatile u8 U8Data=0;

void VoidPlay(void)
{
	switch(U8Data)
	{
	case 70 : MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH); break;
	case 69 : MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW); break;
	}
}

void VoidTakeAction (void)
{
	u8 i=0;
	U8Data=0;
	if((U32FramData[0]>=10000) && (U32FramData[0]<=14000))
	{
		for(i=0;i<8;i++)
		{
			if((U32FramData[17+i]>=2000) && (U32FramData[17+i]<=2300))
			{
				SET_BIT(U8Data,i);
			}

			else
			{
				CLR_BIT(U8Data,i);
			}
		}
	}
	else
	{
		/*invalid frame*/
	}
	U8StartFlag		= 0;
	U32FramData[0]	= 0;
	U8EdgeCounter	= 0;
}

void VoidGetFrame (void)
{
	if(U8StartFlag == 0)
	{
		//Start timer
		// high ticks which is bigger than time of any bit send to ensure no overflow
		MSTK_VoidSetIntervalSingle(1000000,VoidTakeAction);
		U8StartFlag=1;
	}
	else
	{
		U32FramData[U8EdgeCounter]=MSTK_U32GetElapsedTime();
		MSTK_VoidSetIntervalSingle(1000000,VoidTakeAction);
		U8EdgeCounter++;
	}
}


void main()
{
	/*initiat clock*/
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA

	/*PIN mode*/
	MGPIO_VoidSetPinDirection(GPIOA , PIN0 , INPUT_FLOATING); //no pull up or down
	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP);


	/*EXTI Initialization*/
	MEXTI_VoidSetCallBack(VoidGetFrame);
	MEXTI_VoidInit();

	/*Initialise MNVIC EXTI0*/
	MNVIC_VoidInit();
	MNVIC_VoidEnableInterrupt(6); //EXTI0

	/*Initialise SYSTICk*/
	MSTK_VoidInit();	// clk=AHB/8 = 1MHz




	while(1)
	{

	}
}

