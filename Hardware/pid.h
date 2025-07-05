#ifndef __PID_H
#define __PID_H

#include "main.h"

// PID结构体定义
typedef struct {
    float Kp, Ki, Kd;  // PID参数
    float integral;     // 积分项累计
    float prev_error;   // 上一次误差（用于微分）
    float output;       // 输出值（PWM占空比）
} PID_Controller;

float PID_Update(PID_Controller *pid, float target, float current, float dt);

void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd);

#endif // !__PID_H