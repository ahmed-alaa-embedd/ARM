/***************************/
/*Author : ahmed alaa	*/
/*date : 19/8/2020 		*/
/*version : v02			*/
/***************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_VoidInit()
{
	#define SCB_AIRCR		*((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_VoidSetPriority(u8 Copy_u8PeripheralIdx ,u8 Copy_u8Priority)
{
	if(Copy_u8PeripheralIdx<60)
	{
		NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority;
	}

	else
	{
		/*Reprot Error*/
	}
}

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else
	{
		/*Return error*/
	}
}


void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else
	{
		/*Return error*/
	}
}


void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else
	{
		/*Return error*/
	}
}

void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<=31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber ); // faster than SET_BIT as it use OR
	}
	
	else
	{
		/*Return error*/
	}
}


u8 MNVIC_U8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 LocalResult=0;
	
	if(Copy_u8IntNumber<=31)
	{
		LocalResult = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -= 32;
		LocalResult = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	
	else
	{
		/*Return error*/
	}
	return LocalResult;
}

/*void MNVIC_VoidSetPriority(s8 copy_s8IntId,u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u8 copy_u32Group)
{
	u8 Local_u8priority = copy_u8SubPriority|(copy_u32Group<<((copy_u32Group - 0x05FA0300)/256));
	//core peripheral*/



	/*external peripheral*/
/*
	if(copy_s8IntId >= 0)
	{
		IPR[copy_s8IntId] = Local_u8priority<<4;
	}
	SCB_AIRCR = copy_u32Group ;
}
*/
