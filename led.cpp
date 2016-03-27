#include <wiringPi.h>
int main(void)
{
	if( wiringPiSetupGpio() == -1 ) return 1;
	
	pinMode( 17, OUTPUT);
	while(1){
		digitalWrite(17, 1);
		delay(1000);
		digitalWrite(17, 0);
		delay(1000);
	}
	return 0;
}
