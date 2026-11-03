#include <X_general.h>
#include "rtc.h"
#include "stdio.h"
#include "string.h"
#include "stepper.h"

X_StatusTypeDef rtc_status;


X_time_t mytime;
uint8_t myflag=0;


int main(void){

	X_Clock_Init_72MHz();
	X_System_Init();

	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= ~(GPIO_CRL_MODE2|GPIO_CRL_CNF2);
	GPIOB->CRL |= GPIO_CRL_CNF2_0;



	RCC->APB1ENR |= (RCC_APB1ENR_BKPEN|RCC_APB1ENR_PWREN);

	PWR->CR |= PWR_CR_DBP;


	if(GPIOB->IDR & GPIO_IDR_IDR2){
		myflag=1;
		rtc_status= RTC_Init();

	}

	RTC_Init2();

	RTC_Alarm_init();

	stepper_init();



	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);

	DBGMCU->CR &= ~DBGMCU_CR_DBG_SLEEP;
	DBGMCU->CR &= ~DBGMCU_CR_DBG_STOP;
	DBGMCU->CR &= ~DBGMCU_CR_DBG_STANDBY;

	//stop
	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
	PWR->CR &= ~PWR_CR_PDDS;
	PWR->CR |= PWR_CR_LPDS;



	while(1){




		__DSB();
	    __WFI();
		__ISB();

		X_Clock_Init_72MHz_AfterStop();
		stepper_start(1,0,100,__DIR_CW);
		while(TIM1->CR1 & TIM_CR1_CEN){}




	}
}

