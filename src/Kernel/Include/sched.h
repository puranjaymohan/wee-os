#ifndef __SCHED_H__
#define __SCHED_H__
#include <weeOs.h>

typedef struct tcb {
	int32_t *sp;
	struct tcb *next_tcb;
	uint8_t pid;
#ifdef weighted_round_robin
	uint32_t weight;
	uint32_t c_weight;
#endif
} tcb;


#endif
