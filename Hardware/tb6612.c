#include "tb6612.h"

void Global_TIM_Init(void)
{
    HAL_TIM_Base_Start(&htim4);   
}

void motor_Init(void)
{
    //开启pwm通道
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);    //打开通道4
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
}

void Set_Speed(int speed)
{
    if(speed>0)
    {
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
        //__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,speed);
        speed = (speed > 3600) ? 3600 :speed;
        TIM1->CCR4 = speed;
    }else{
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
        speed = -speed;
        speed = (speed > 3600) ? 3600 :speed;
        //__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,speed);
        TIM1->CCR4 = speed;
	}
}