#include <stdint.h>
#include <weeOs.h>
#include <stm32l4xx_hal_gpio.h>
#include <stm32l4xx_hal_rcc.h>
#include <stm32l4xx_hal.h>

int c0 = 0;
int c1 = 0;
int c2 = 0;

extern volatile uint64_t Tick;

int quanta = 10;

GPIO_InitTypeDef init;

void delay(uint64_t delay)
{
	volatile uint64_t iTick = Tick;
	uint64_t count = delay/quanta;
	while((Tick-iTick) <= count);
}
void task0(void)
{
	while(1) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		c0++;
		delay(1000);

	}
}

void task1(void)
{
	while(1) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
		c1++;
		delay(1000);
	}
}

void task2(void)
{
	while(1) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
		c2++;
		delay(1000);
	}
}

int main()
{

	__HAL_RCC_GPIOA_CLK_ENABLE();
	init.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	init.Mode = GPIO_MODE_OUTPUT_PP;
	init.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &init);

	task_prop task0_data = {.task = task0 , .name="TASK0"};
	task_prop task1_data = {.task = task1 , .name="TASK1"};
	task_prop task2_data = {.task = task2 , .name="TASK2"};
	wee_os_addthread(&task0_data);
	wee_os_addthread(&task1_data);
	wee_os_addthread(&task2_data);
	wee_os_launch(quanta);
	while(1);
}
