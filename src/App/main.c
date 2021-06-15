#include <stdint.h>
#include <weeOs.h>

int c0 = 0;
int c1 = 0;
int c2 = 0;

void task0(void)
{
	while(1) {
		c0++;
	}
}

void task1(void)
{
	while(1) {
		c1++;
	}
}

void task2(void)
{
	while(1) {
		c2++;
	}
}

int main()
{
#ifdef weighted_round_robin
	wee_os_addthread(task0, 1);
	wee_os_addthread(task1, 2);
	wee_os_addthread(task2, 3);
#elif defined round_robin
	wee_os_addthread(task0);
	wee_os_addthread(task1);
	wee_os_addthread(task2);
#endif
	wee_os_launch(1);
	while(1);
}
