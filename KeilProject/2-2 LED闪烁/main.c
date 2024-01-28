#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	for (;xms>0;xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	 // 1111 1111
	for (P2 = 0xFF; P2 <= 0xff00; P2 >>= 1)
	{
		if ( P2 = 0xff00 )
			P2 = 0xff;
		Delay(200);
	}
}
