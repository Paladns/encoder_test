#include "Encoder.h"


void Start_Encoder(void){
		//HAL_TIM_Encoder_Start
		HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
		HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
		
}
//��ȡ��������ֵ
int Get_Encoder(void){
		int cnt = 0;
		cnt = __HAL_TIM_GetCounter(&htim3);	//��ȡ��������ֵ
		
		return cnt;
}

// ��ȡ�������ٶȣ���λ��RPM��
float Read_Encoder_Speed(void) {
    static int32_t prev_count = 0;
    int32_t curr_count = (int32_t)TIM3->CNT;  // ��ȡ����������ֵ
    int32_t delta = (curr_count - prev_count+5000)%5000;
    prev_count = curr_count;
    
    // ת��Ϊת�٣����������1000�ߣ���������10ms��
    float rpm = (delta * 60.0f) / (700.0f * 0.01f);  // RPM = (������/ÿת) / ʱ��
    return rpm;
}