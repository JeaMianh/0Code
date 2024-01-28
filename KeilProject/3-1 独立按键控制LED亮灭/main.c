#include <REGX52.H>
#include <INTRINS.h>

void Delayms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);	
		xms--;
	}
}


void  main()
{
	unsigned char LEDnum = 1;
	while (1)
	{
		if (P3_1 == 0)
		{
			Delayms(20);
			while(P3_1 == 0);
			Delayms(20);
			
			// P2_0 = ~P2_0;
			// P2 默认为 1111 1111
			// P2--; // 第一次执行后为 1111 1110
			
			P2 = ~LEDnum;
			LEDnum <<= 1;
		}

	}
}

