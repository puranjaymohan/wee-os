/* SPDX-License-Identifier: MIT */

#ifndef __MUTEX_H__
#define __MUTEX_H__
#include <stdint.h>
#define LOCKED 1
#define UNLOCKED 0

typedef uint8_t mutex;

int spin_lock_aquire(mutex *lock);
void spin_lock_release(mutex *lock);
#endif
