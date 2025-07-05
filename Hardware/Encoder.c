#include "Encoder.h"


void Start_Encoder(void){
		//HAL_TIM_Encoder_Start
		HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
		HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
		
}
//获取编码器的值
int Get_Encoder(void){
		int cnt = 0;
		cnt = __HAL_TIM_GetCounter(&htim3);	//获取计数器的值
		
		return cnt;
}

// 读取编码器速度（单位：RPM）
float Read_Encoder_Speed(void) {
    static int32_t prev_count = 0;
    int32_t curr_count = (int32_t)TIM3->CNT;  // 读取编码器计数值
    int32_t delta = (curr_count - prev_count+5000)%5000;
    prev_count = curr_count;
    
    // 转换为转速（假设编码器1000线，采样周期10ms）
    float rpm = (delta * 60.0f) / (700.0f * 0.01f);  // RPM = (脉冲数/每转) / 时间
    return rpm;
}