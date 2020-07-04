#include<stdio.h>


void conversion(unsigned char inter[16])
{
	int i;
	
for(i=0;i<32;i++)
	{
		switch(inter[i])
		{
		
			case '0':
				x[4*i]=0;
				x[4*i+1]=0;
				x[4*i+2]=0;
				x[4*i+3]=0;
				break;
			case '1':
				x[4*i]=0;
				x[4*i+1]=0;
				x[4*i+2]=0;
				x[4*i+3]=1;
				break;
			case '2':
				x[4*i]=0;
				x[4*i+1]=0;
				x[4*i+2]=1;
				x[4*i+3]=0;
				break;
			case '3':
				x[4*i]=0;
				x[4*i+1]=0;
				x[4*i+2]=1;
				x[4*i+3]=1;
				break;
			case '4':
				x[4*i]=0;
				x[4*i+1]=1;
				x[4*i+2]=0;
				x[4*i+3]=0;
				break;
			case '5':
				x[4*i]=0;
				x[4*i+1]=1;
				x[4*i+2]=0;
				x[4*i+3]=1;
				break;
			case '6':
				x[4*i]=0;
				x[4*i+1]=1;
				x[4*i+2]=1;
				x[4*i+3]=0;
				break;
			case '7':
				x[4*i]=0;
				x[4*i+1]=1;
				x[4*i+2]=1;
				x[4*i+3]=1;
				break;
			case '8':
				x[4*i]=1;
				x[4*i+1]=0;
				x[4*i+2]=0;
				x[4*i+3]=0;
				break;
			case '9':
				x[4*i]=1;
				x[4*i+1]=0;
				x[4*i+2]=0;
				x[4*i+3]=1;
				break;
			case 'a':
				x[4*i]=1;
				x[4*i+1]=0;
				x[4*i+2]=1;
				x[4*i+3]=0;
				break;
			case 'b':
				x[4*i]=1;
				x[4*i+1]=0;
				x[4*i+2]=1;
				x[4*i+3]=1;
				break;
			case 'c':
				x[4*i]=1;
				x[4*i+1]=1;
				x[4*i+2]=0;
				x[4*i+3]=0;
				break;
			case 'd':
				x[4*i]=1;
				x[4*i+1]=1;
				x[4*i+2]=0;
				x[4*i+3]=1;
				break;
			case 'e':
				x[4*i]=1;
				x[4*i+1]=1;
				x[4*i+2]=1;
				x[4*i+3]=0;
				break;
			case 'f':
				x[4*i]=1;
				x[4*i+1]=1;
				x[4*i+2]=1;
				x[4*i+3]=1;
				break;
	}
}
	printf("\nAAD1 in binary:\n");
	for(i=0;i<128;i++)	printf("%d ",x[i]);
	
	for(i=0;i<32;i++)
	{
		switch(inter1[i])
		{
			case '0':
				y[4*i]=0;
				y[4*i+1]=0;
				y[4*i+2]=0;
				y[4*i+3]=0;
				break;
			case '1':
				y[4*i]=0;
				y[4*i+1]=0;
				y[4*i+2]=0;
				y[4*i+3]=1;
				break;
			case '2':
				y[4*i]=0;
				y[4*i+1]=0;
				y[4*i+2]=1;
				y[4*i+3]=0;
				break;
			case '3':
				y[4*i]=0;
				y[4*i+1]=0;
				y[4*i+2]=1;
				y[4*i+3]=1;
				break;
			case '4':
				y[4*i]=0;
				y[4*i+1]=1;
				y[4*i+2]=0;
				y[4*i+3]=0;
				break;
			case '5':
				y[4*i]=0;
				y[4*i+1]=1;
				y[4*i+2]=0;
				y[4*i+3]=1;
				break;
			case '6':
				y[4*i]=0;
				y[4*i+1]=1;
				y[4*i+2]=1;
				y[4*i+3]=0;
				break;
			case '7':
				y[4*i]=0;
				y[4*i+1]=1;
				y[4*i+2]=1;
				y[4*i+3]=1;
				break;
			case '8':
				y[4*i]=1;
				y[4*i+1]=0;
				y[4*i+2]=0;
				y[4*i+3]=0;
				break;
			case '9':
				y[4*i]=1;
				y[4*i+1]=0;
				y[4*i+2]=0;
				y[4*i+3]=1;
				break;
			case 'a':
				y[4*i]=1;
				y[4*i+1]=0;
				y[4*i+2]=1;
				y[4*i+3]=0;
				break;
			case 'b':
				y[4*i]=1;
				y[4*i+1]=0;
				y[4*i+2]=1;
				y[4*i+3]=1;
				break;
			case 'c':
				y[4*i]=1;
				y[4*i+1]=1;
				y[4*i+2]=0;
				y[4*i+3]=0;
				break;
			case 'd':
				y[4*i]=1;
				y[4*i+1]=1;
				y[4*i+2]=0;
				y[4*i+3]=1;
				break;
			case 'e':
				y[4*i]=1;
				y[4*i+1]=1;
				y[4*i+2]=1;
				y[4*i+3]=0;
				break;
			case 'f':
				y[4*i]=1;
				y[4*i+1]=1;
				y[4*i+2]=1;
				y[4*i+3]=1;
				break;
	}
}
	printf("\nAAD2 in binary:\n");
	for(i=0;i<128;i++)	printf("%d ",y[i]);
	
}
