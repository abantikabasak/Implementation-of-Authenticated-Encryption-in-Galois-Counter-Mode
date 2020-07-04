#include<stdio.h>
#include<stdlib.h>
//char *calculate(int);
/*int main()
{
	int i;
	unsigned char *len_init;
	len_init=(char *)malloc(16*sizeof(unsigned char));
	int len_iv=48;
	len_init=calculate(len_iv);
	printf("LEN_INIT:\n");
	for(i=0;i<16;i++)
	printf("%x ",len_init[i]);
}*/

char *calculate(int len_iv)
{
	int i;
	unsigned char *len_init,text;
	len_init=(char *)malloc(16*sizeof(unsigned char));
	int temp;
	temp=len_iv*8;
	//text=(char)temp;
	//printf("Temp:%x ",temp);
	if(temp<256)
	{
		for(i=0;i<15;i++)	len_init[i]=0x00;
		len_init[15]=(char)temp;
	}
	
	else if(temp>=256)
	{
		for(i=0;i<14;i++)	len_init[i]=0x00;
		len_init[14]=0x01;
		len_init[15]=(char)(temp-256);
	}
	
	//for(i=0;i<14;i++)	len_init[i]=0x00;
	return (char *)len_init;
}
