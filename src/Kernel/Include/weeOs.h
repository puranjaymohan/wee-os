#ifndef __WEEOS_H__
#define __WEEOS_H__
#include <stdint.h>

#ifdef stm32l476rg
#include <stm32l476xx.h>
#endif

#ifdef MK64F12
#include <MK64F12.h>
#endif

#define MAX_TASKS 10
#define STACK_SIZE 100
#define xPSR (STACK_SIZE-1)
#define PC (STACK_SIZE-2)

void wee_os_launch(uint32_t quanta);
void wee_os_init(void);

uint8_t wee_os_addthread(void(*task)(void)
#ifdef weighted_round_robin
			,uint32_t weight
#endif
			);


#endif
