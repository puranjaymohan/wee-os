/* SPDX-License-Identifier: MIT */
#ifndef __SCHED_H__
#define __SCHED_H__
#include <stdint.h>
#include <weeOs.h>
typedef struct tcb {
	int32_t *sp;
	struct tcb *next_tcb;
	uint8_t pid;
	char *name;
#ifdef weighted_round_robin
	uint32_t weight;
	uint32_t c_weight;
#endif
} tcb;

#endif
