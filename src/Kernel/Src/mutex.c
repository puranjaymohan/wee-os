// SPDX-License-Identifier: MIT
#include <mutex.h>
#include <stdint.h>
#include <weeOs.h>
int spin_lock_aquire(mutex *lock)
{
	uint8_t locked = 1;

	do {
		if (!__LDREXB(lock)) {
			if (!__STREXB(1, lock)) {
				__CLREX();
				locked = 0;
			}
		}
	} while (locked);

	return 0;
}

void spin_lock_release(mutex *lock)
{
	__DMB();
	*lock = 0;
}
