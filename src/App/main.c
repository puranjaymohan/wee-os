#include <stdint.h>
#include <weeOs.h>

int c0 = 0;
int c1 = 0;
int c2 = 0;

void task0(void)
{
	while(1) {
		c0++;
		wee_os_yield();
	}
}

void task1(void)
{
	while(1) {
		c1++;
		wee_os_yield();
	}
}

void task2(void)
{
	while(1) {
		c2++;
		wee_os_yield();
	}
}

int main()
{
	task_prop task0_data = {.task = task0 , .name="TASK0"};
	task_prop task1_data = {.task = task1 , .name="TASK1"};
	task_prop task2_data = {.task = task2 , .name="TASK2"};
	wee_os_addthread(&task0_data);
	wee_os_addthread(&task1_data);
	wee_os_addthread(&task2_data);
	wee_os_launch(10);
	while(1);
}
