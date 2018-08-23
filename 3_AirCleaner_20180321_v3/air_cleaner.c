#include "air_cleaner.h"
#include <stdio.h>

uint8_t get_abc_co2_level(void);
uint8_t get_abc_lpg_gas_level(void);
uint8_t get_abc_dust_level(void);
uint8_t get_abc_air_quality(uint8_t co2, uint8_t lpg_gas, uint8_t dust);
uint8_t abc_start(uint8_t air_quality);
uint8_t abc_stop(void);
uint8_t abc_timer(time_t star_time, time_t stop_time);
uint8_t abc_display_led(uint8_t air_quality);
uint8_t abc_display_lcd(uint8_t air_quality);

int main(){
	int co2_level=0, lpg_gas_level=0, dust_level=0, air_quality=0;//산소레벨, 가스레벨, 먼지레벨, 공기질 
	struct air_cleaner abc_air_cleaner;//abc 공기청정기 구조체 선언 
	char ch[8];//선택을 위한 변수 
	time_t t1, t2;// start time_t 변수 stop time_t 변수 
	struct tm starttime;//tm 구조체 스타트타임 
	struct tm stoptime;//tm 구조체 스탑타임 
	int year1, year2, mon1, mon2, day1, day2, hour1,hour2, min1, min2;//시간을 받기위한 변 
	
	//구조체 함수 연결 
	abc_air_cleaner.get_co2_level=get_abc_co2_level;
	abc_air_cleaner.get_lpg_gas_level=get_abc_lpg_gas_level;
	abc_air_cleaner.get_dust_level=get_abc_dust_level;
	abc_air_cleaner.get_air_quality=get_abc_air_quality;
	abc_air_cleaner.start=abc_start; 
	abc_air_cleaner.stop=abc_stop;
	abc_air_cleaner.timer=abc_timer;
	abc_air_cleaner.display_led=abc_display_led;
	abc_air_cleaner.display_lcd=abc_display_lcd;
	
		
	while(1){
		
		printf("수행하고자 하는 공기청정기 기능을 입력하세요-->");
		scanf("%s", &ch);
		
		if(strcmp(ch,"?")==0){
			printf("Usage: 1~9 (1: CO2 측정, 2: 가스 측정, 3: 먼지 측정, 4: 공기질 측정, 5: 공기청정기 가동, 6: 공기청정기 동작 중지, 7: 타이머 설정, 8: LED 출력, 9: LCD 출력)\n");
		}else if(strcmp(ch,"1")==0){
			//co2 측정 
			
			co2_level=abc_air_cleaner.get_co2_level();
			printf("co2: %d\n", co2_level);
		}else if(strcmp(ch,"2")==0){
			//가스 측정
			
			lpg_gas_level=abc_air_cleaner.get_lpg_gas_level();
			printf("lpg_gas: %d\n", lpg_gas_level);			
			 
		}else if(strcmp(ch,"3")==0){
			//먼지 측정 
			
			dust_level=abc_air_cleaner.get_dust_level();
			printf("dust: %d\n", dust_level);
			
		}else if(strcmp(ch,"4")==0){
			//공기질 측정 
			
			air_quality=abc_air_cleaner.get_air_quality(co2_level, lpg_gas_level, dust_level);
			printf("air quality: %d\n");
			
		}else if(strcmp(ch,"5")==0){
			//공기청정기 가동
			
			abc_air_cleaner.start(air_quality);
			
		}else if(strcmp(ch,"6")==0){
			//공기청정기 가동 중지 
			
			abc_air_cleaner.stop();
			
		}else if(strcmp(ch,"7")==0){
			//타이머 설정 
			printf("시작 시간을 입력하세요. (형식: 2018-03-20 11:30)\n");
			scanf("%d-%d-%d %d:%d", &year1, &mon1, &day1, &hour1, &min1);
			
			//스타트타임 tm구조체화  
			starttime.tm_year=year1-1900;
			starttime.tm_mon=mon1-1;
			starttime.tm_mday=day1;
			starttime.tm_hour=hour1;
			starttime.tm_min=min1;
			starttime.tm_sec=0;
			starttime.tm_isdst=0;
			
			printf("종료 시간을 입력하세요. (형식: 2018-03-20 12:30)\n"); 
			scanf("%d-%d-%d %d:%d", &year2, &mon2, &day2, &hour2, &min2);
			
			//스탑타임 tm구조체화 
			stoptime.tm_year=year2-1900;
			stoptime.tm_mon=mon2-1;
			stoptime.tm_mday=day2;
			stoptime.tm_hour=hour2;
			stoptime.tm_min=min2;
			stoptime.tm_sec=0;
			stoptime.tm_isdst=0;
			
			//mktime				
			t1=mktime(&starttime);
			t2=mktime(&stoptime);
						
			abc_air_cleaner.timer(t1, t2);
			
		}else if(strcmp(ch,"8")==0){
			//LED 출력
			printf("abc Display information to LED\n");
			//co2 측정 
			co2_level=abc_air_cleaner.get_co2_level();
			printf("-->co2: %d\n", co2_level);
			
			//lpg 측정 
			lpg_gas_level=abc_air_cleaner.get_lpg_gas_level();
			printf("-->lpg_gas: %d\n", lpg_gas_level);	
			
			//dust 측정 
			dust_level=abc_air_cleaner.get_dust_level();
			printf("-->dust: %d\n", dust_level);
			
			//calculate 공기질값  
			air_quality=abc_air_cleaner.get_air_quality(co2_level, lpg_gas_level, dust_level);
			
			//LED 			
			abc_air_cleaner.display_led(air_quality);
			
		}else if(strcmp(ch,"9")==0){
			//LCD 출력
			printf("abc Display information to LCD\n");
			
			//co2 측정 
			co2_level=abc_air_cleaner.get_co2_level();
			printf("-->co2: %d\n", co2_level);
			
			//lpg 측정 
			lpg_gas_level=abc_air_cleaner.get_lpg_gas_level();
			printf("-->lpg_gas: %d\n", lpg_gas_level);	
			
			//dust 측정 
			dust_level=abc_air_cleaner.get_dust_level();
			printf("-->dust: %d\n", dust_level);
			
			//calculate 공기질 
			air_quality=abc_air_cleaner.get_air_quality(co2_level, lpg_gas_level, dust_level);
			
			//lcd 출력 
			abc_air_cleaner.display_lcd(air_quality);
			
		}else if(strcmp(ch,"quit")==0){
			//종료 
			printf("공기청정기 종료! \n");
			return 0;
		}else printf("허용되지 않은 값 입니다.\n");

	} 
	
	return 0;
}


//abc co2 level func
uint8_t get_abc_co2_level(void){
	//initialized abc co2 snesor
	printf("measuring Co2 level..\n");
	//get co2 level from abc
	return 48;//co2 level
}

//abc lqg gas level func
uint8_t get_abc_lpg_gas_level(void){
	//initialized abc lqg gas snesor
	printf("measuring LPG gas level..\n");
	//get lpg level from abc
	return 35;//lpg gas level
}

//abc dust level func
uint8_t get_abc_dust_level(void){
	//initialized abc dust snesor
	printf("measuring Dust level..\n");
	//get dust level from abc
	return 63;//co2 level
}

//abc air quality func
uint8_t get_abc_air_quality(uint8_t co2, uint8_t lpg_gas, uint8_t dust){
	
	//calculate Air Quality
	//printf("%d %d %d\n", co2, lpg_gas, dust);
	
	printf("Calculate Air Quality\n");

	//get air_qulity
	return (co2+lpg_gas+dust)/3;//air_qulity 
}

//abc start func
uint8_t abc_start(uint8_t air_quality){
	//star abc
	printf("abc Started: current level - %d\n", air_quality);
	return 0;
}

//abc stop func
uint8_t abc_stop(void){
	printf("abc Stopped\n");
	return 0;
}

//abc timer func
uint8_t abc_timer(time_t start_time, time_t stop_time){
	
	struct tm *tmstarttime;//starttime을 위한 tm구조체 포인터 
	struct tm *tmstoptime;//stoptime을 위한 tm구조체 포인터 
	
	printf("set timer\n");
	//스타트타임 로컬타임화 
	tmstarttime=localtime(&start_time);
	
	//스타트타임 출 려 
	printf("-->abc start time: %d-%d-%d %d:%d \n",
		tmstarttime->tm_year+1900,
		tmstarttime->tm_mon+1,
		tmstarttime->tm_mday,
		tmstarttime->tm_hour,
		tmstarttime->tm_min);	
	
	//스탑타임 로컬타임화 
	tmstoptime=localtime(&stop_time);
	
	//스탑다임 출력 
	printf("-->abc stop time: %d-%d-%d %d:%d \n",
		tmstoptime->tm_year+1900,
		tmstoptime->tm_mon+1,
		tmstoptime->tm_mday,
		tmstoptime->tm_hour,
		tmstoptime->tm_min);	
	
	return 0;
}

//abc display func
uint8_t abc_display_led(uint8_t air_quality){
	printf("-->Air Quality: %d\n", air_quality); 
	
	return 0;
}

//
uint8_t abc_display_lcd(uint8_t air_quality){
	printf("-->Air Quality: %d\n", air_quality);
	return 0;
}
