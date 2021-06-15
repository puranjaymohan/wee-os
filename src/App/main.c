#include <stdint.h>
#include <weeOs.h>

int t1 = 0;

void task0(void)
{
	while(1) {
	}
}

void task1(void)
{
	while(1) {
	}
}

void task2(void)
{
	while(1) {
	}
}

int main()
{
	wee_os_addthread(task0);
	wee_os_addthread(task1);
	wee_os_addthread(task2);

	wee_os_launch(1);
	while(1);
}
