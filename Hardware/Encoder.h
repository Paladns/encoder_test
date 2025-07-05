#ifndef __ENCODER_H
#define __ENCODER_H

#include "main.h"
//#include "usart.h"
#include "tim.h"

//自己定义
void Start_Encoder(void);
//获取编码器的值
int Get_Encoder(void);
float Read_Encoder_Speed(void);

#endif