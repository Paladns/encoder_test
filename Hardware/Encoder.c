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