#ifndef __WEEOS_H__
#define __WEEOS_H__
#include <stdint.h>
#include <stm32l476xx.h>

#define NUM_TASKS 3
#define STACK_SIZE 100
#define xPSR (STACK_SIZE-1)
#define PC (STACK_SIZE-2)

void wee_os_launch(uint32_t quanta);
void wee_os_init(void);

uint8_t wee_os_addthreads(void(*task0)(void),
			  void(*task1)(void),
			  void(*task2)(void));


#endif
