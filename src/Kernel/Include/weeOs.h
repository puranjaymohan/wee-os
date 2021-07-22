/* SPDX-License-Identifier: MIT */
#ifndef __WEEOS_H__
#define __WEEOS_H__
#include <stdint.h>
#include <sched.h>

#ifdef stm32l476rg
#include <stm32l476xx.h>
#endif

#ifdef MK64F12
#include <MK64F12.h>
#endif

#ifdef lm3s811
#include <lm3s811.h>
#endif

#ifdef TM4C123GH6PM
#include <TM4C123.h>
#endif

#define MAX_TASKS 10
#define STACK_SIZE 100
#define xPSR (STACK_SIZE - 1)
#define PC (STACK_SIZE - 2)

typedef struct task_prop{
	void (*task)(void);
	char *name;
#ifdef weighted_round_robin
	uint32_t weight;
#endif
} task_prop;

/*System Calls*/
#define wee_os_yield() wee_os_system_call(1, 0)
#define wee_os_kill() wee_os_system_call(2, 0)
#define wee_os_addthread(task_property) wee_os_system_call(3, task_property)

void wee_os_launch(uint32_t quanta);
void wee_os_init(void);
void __attribute__((noinline)) wee_os_system_call(uint32_t syscall_no,
						  task_prop *task_property);

#endif
