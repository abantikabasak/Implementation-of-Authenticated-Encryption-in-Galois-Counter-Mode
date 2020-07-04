#include<stdio.h>
#include<stdlib.h>
char *calculate(int);
int main()
{
	int i;
	unsigned char *len_init;
	len_init=(char *)malloc(8*sizeof(unsigned char));
	int len_iv=64;
	len_init=calculate(len_iv);
	printf("LEN_INIT:\n");
	for(i=0;i<8;i++)
	printf("%x ",len_init[i]);
}

char *calculate(int len_iv)
{
	int i;
	unsigned char *len_init,text;
	len_init=(char *)malloc(8*sizeof(unsigned char));
	int temp;
	temp=len_iv*8;
	text=(char)temp;
	printf("Temp: %d %x ",temp,temp);
	if(temp<256)
	{
		for(i=0;i<7;i++)	len_init[i]=0x00;
		len_init[7]=(char)temp;
	}
	
	else if(temp>=256&&temp<=504)
	{
		for(i=0;i<6;i++)	len_init[i]=0x00;
		len_init[6]=0x01;
		len_init[7]=(char)(temp-256);
	}
	
	else if(temp>504)
	{
		for(i=0;i<6;i++)	len_init[i]=0x00;
		len_init[6]=0x02;
		len_init[7]=(char)(temp-256);
	}
	
	//for(i=0;i<14;i++)	len_init[i]=0x00;
	return (char *)len_init;
}
