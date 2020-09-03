/***************************/
/*Author : ahmed alaa	*/
/*date : 22/8/2020 		*/
/*version : v02			*/
/***************************/



#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef struct 			/* old type*/
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
	
}EXTI_Type ;		/*New type*/

#define EXTI	((volatile EXTI_Type*)0x40010400)	//we cant D-reference as it is pointer
													//so we use -> as D-reference
													//EXTI ->IMR = 0;  prefer to use
													//equal to *(EXTI.IMR)=0;




#endif 
