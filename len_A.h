#include<stdio.h>
#include<stdlib.h>
char *calculatelenA(int);


char *calculatelenA(int len_iv)
{
	int i;
	unsigned char *len_init,text;
	len_init=(char *)malloc(8*sizeof(unsigned char));
	int temp;
	temp=len_iv*8;
	//text=(char)temp;
	//printf("Temp:%x ",temp);
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
