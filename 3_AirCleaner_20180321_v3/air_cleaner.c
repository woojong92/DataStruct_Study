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
	int co2_level=0, lpg_gas_level=0, dust_level=0, air_quality=0;//��ҷ���, ��������, ��������, ������ 
	struct air_cleaner abc_air_cleaner;//abc ����û���� ����ü ���� 
	char ch[8];//������ ���� ���� 
	time_t t1, t2;// start time_t ���� stop time_t ���� 
	struct tm starttime;//tm ����ü ��ŸƮŸ�� 
	struct tm stoptime;//tm ����ü ��žŸ�� 
	int year1, year2, mon1, mon2, day1, day2, hour1,hour2, min1, min2;//�ð��� �ޱ����� �� 
	
	//����ü �Լ� ���� 
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
		
		printf("�����ϰ��� �ϴ� ����û���� ����� �Է��ϼ���-->");
		scanf("%s", &ch);
		
		if(strcmp(ch,"?")==0){
			printf("Usage: 1~9 (1: CO2 ����, 2: ���� ����, 3: ���� ����, 4: ������ ����, 5: ����û���� ����, 6: ����û���� ���� ����, 7: Ÿ�̸� ����, 8: LED ���, 9: LCD ���)\n");
		}else if(strcmp(ch,"1")==0){
			//co2 ���� 
			
			co2_level=abc_air_cleaner.get_co2_level();
			printf("co2: %d\n", co2_level);
		}else if(strcmp(ch,"2")==0){
			//���� ����
			
			lpg_gas_level=abc_air_cleaner.get_lpg_gas_level();
			printf("lpg_gas: %d\n", lpg_gas_level);			
			 
		}else if(strcmp(ch,"3")==0){
			//���� ���� 
			
			dust_level=abc_air_cleaner.get_dust_level();
			printf("dust: %d\n", dust_level);
			
		}else if(strcmp(ch,"4")==0){
			//������ ���� 
			
			air_quality=abc_air_cleaner.get_air_quality(co2_level, lpg_gas_level, dust_level);
			printf("air quality: %d\n");
			
		}else if(strcmp(ch,"5")==0){
			//����û���� ����
			
			abc_air_cleaner.start(air_quality);
			
		}else if(strcmp(ch,"6")==0){
			//����û���� ���� ���� 
			
			abc_air_cleaner.stop();
			
		}else if(strcmp(ch,"7")==0){
			//Ÿ�̸� ���� 
			printf("���� �ð��� �Է��ϼ���. (����: 2018-03-20 11:30)\n");
			scanf("%d-%d-%d %d:%d", &year1, &mon1, &day1, &hour1, &min1);
			
			//��ŸƮŸ�� tm����üȭ  
			starttime.tm_year=year1-1900;
			starttime.tm_mon=mon1-1;
			starttime.tm_mday=day1;
			starttime.tm_hour=hour1;
			starttime.tm_min=min1;
			starttime.tm_sec=0;
			starttime.tm_isdst=0;
			
			printf("���� �ð��� �Է��ϼ���. (����: 2018-03-20 12:30)\n"); 
			scanf("%d-%d-%d %d:%d", &year2, &mon2, &day2, &hour2, &min2);
			
			//��žŸ�� tm����üȭ 
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
			//LED ���
			printf("abc Display information to LED\n");
			//co2 ���� 
			co2_level=abc_air_cleaner.get_co2_level();
			printf("-->co2: %d\n", co2_level);
			
			//lpg ���� 
			lpg_gas_level=abc_air_cleaner.get_lpg_gas_level();
			printf("-->lpg_gas: %d\n", lpg_gas_level);	
			
			//dust ���� 
			dust_level=abc_air_cleaner.get_dust_level();
			printf("-->dust: %d\n", dust_level);
			
			//calculate ��������  
			air_quality=abc_air_cleaner.get_air_quality(co2_level, lpg_gas_level, dust_level);
			
			//LED 			
			abc_air_cleaner.display_led(air_quality);
			
		}else if(strcmp(ch,"9")==0){
			//LCD ���
			printf("abc Display information to LCD\n");
			
			//co2 ���� 
			co2_level=abc_air_cleaner.get_co2_level();
			printf("-->co2: %d\n", co2_level);
			
			//lpg ���� 
			lpg_gas_level=abc_air_cleaner.get_lpg_gas_level();
			printf("-->lpg_gas: %d\n", lpg_gas_level);	
			
			//dust ���� 
			dust_level=abc_air_cleaner.get_dust_level();
			printf("-->dust: %d\n", dust_level);
			
			//calculate ������ 
			air_quality=abc_air_cleaner.get_air_quality(co2_level, lpg_gas_level, dust_level);
			
			//lcd ��� 
			abc_air_cleaner.display_lcd(air_quality);
			
		}else if(strcmp(ch,"quit")==0){
			//���� 
			printf("����û���� ����! \n");
			return 0;
		}else printf("������ ���� �� �Դϴ�.\n");

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
	
	struct tm *tmstarttime;//starttime�� ���� tm����ü ������ 
	struct tm *tmstoptime;//stoptime�� ���� tm����ü ������ 
	
	printf("set timer\n");
	//��ŸƮŸ�� ����Ÿ��ȭ 
	tmstarttime=localtime(&start_time);
	
	//��ŸƮŸ�� �� �� 
	printf("-->abc start time: %d-%d-%d %d:%d \n",
		tmstarttime->tm_year+1900,
		tmstarttime->tm_mon+1,
		tmstarttime->tm_mday,
		tmstarttime->tm_hour,
		tmstarttime->tm_min);	
	
	//��žŸ�� ����Ÿ��ȭ 
	tmstoptime=localtime(&stop_time);
	
	//��ž���� ��� 
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
