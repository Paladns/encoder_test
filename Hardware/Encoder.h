#ifndef __ENCODER_H
#define __ENCODER_H

#include "main.h"
//#include "usart.h"
#include "tim.h"

//�Լ�����
void Start_Encoder(void);
//��ȡ��������ֵ
int Get_Encoder(void);
float Read_Encoder_Speed(void);

#endif