#ifndef __TB6612_H
#define __TB6612_H
#include "main.h"
//#include "usart.h"
#include "tim.h"

void Global_TIM_Init(void);
void motor_Init(void);
void Set_Speed(int speed);

#endif // !__TB6612_H
