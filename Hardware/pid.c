#include "pid.h"

// PID计算函数
float PID_Update(PID_Controller *pid, float target, float current, float dt) {
    float error = target - current;
    
    // P项
    float P = pid->Kp * error;
    
    // I项（积分抗饱和）
    pid->integral += error * dt;
    if (pid->integral > 1000) pid->integral = 1000;  // 限制积分上限
    if (pid->integral < -1000) pid->integral = -1000;
    float I = pid->Ki * pid->integral;
    
    // D项
    float D = pid->Kd * (error - pid->prev_error) / dt;
    pid->prev_error = error;
    
    // 输出总和
    pid->output = P + I + D;
    return pid->output;
}

// 初始化PID控制器
void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->integral = 0;
    pid->prev_error = 0;
    pid->output = 0;
}