/* SPDX-License-Identifier: MIT */
#ifndef __SYSTEMCALL_H__
#define __SYSTEMCALL_H__
extern char active_tasks[MAX_TASKS];

void wee_os_syscall_yield(void);
void wee_os_syscall_kill(void);
uint8_t wee_os_add_thread(task_prop *task_property);
#endif
