#include<stdio.h>
#include<stdlib.h>
#define MAX 128
int z[MAX],v[MAX],x[MAX],y[MAX],r[MAX];
int temp[8]={1,1,1,0,0,0,0,1};
unsigned char C[32],*CHex,*CHex1;
//unsigned char result[32];//="feedfacedeadbeeffeedfacedeadbeef";
//unsigned char resultH[32];//="b83b533708bf535d0aa6e52980d53b78";
void multiply();
char *convertz();
void printeachz();
char *input(char result[32],char resultH[32]){   
	int i;
/*	printf("Result:\n");
	for(i=0;i<32;i++) printf("%c ",result[i]);
	printf("ResultH:\n");
	for(i=0;i<32;i++) printf("%c ",resultH[i]);
	
*/	
	
	for(i=0;i<8;i++) r[i]=temp[i];
	for(i=8;i<MAX;i++) r[i]=0;
	for(i=0;i<32;i++)
	{
		switch(result[i])
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
	
	for(i=0;i<32;i++)
	{
		switch(resultH[i])
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

/*	printf("X:\n");
		for(i=0;i<128;i++) printf("%d ",x[i]);
	printf("\n");
	printf("Y:\n");
	for(i=0;i<128;i++) printf("%d ",y[i]);
	printf("\n");
/*	CHex1=multiply();
	for(i=0;i<16;i++) printf("%x ",CHex1[i]);
	printf("Z:\n");
	for(i=0;i<128;i++) printf("%d ",z[i]);
	printf("\n");
*/	
	multiply();
	CHex1=convertz();
//	for(i=0;i<16;i++) printf("%x ",CHex1[i]);
	
	return (char *)CHex1;
	
//return 0;	
}
 void printeachv(){
 	int i;
 	printf("V starts: \n");
 	for(i=0;i<MAX;i++){
 		printf("%d",v[i]);
	 }
	 printf("\n");
 }
void multiply()
{
	int i,j,k;
	for(i=0;i<MAX;i++) z[i]=0;
	for(i=0;i<MAX;i++) v[i]=x[i];
	for(i=0;i<MAX;i++){
		if(y[i]==1){
		    for(j=0;j<MAX;j++) z[j]=z[j]^v[j];	
		}
		//if (i<10) printeachv();
		if(v[MAX-1]==0){
		    for(j=MAX-1;j>=1;j--) v[j]=v[j-1];
		    v[0]=0;	
		}
		else{
		
		    for(j=MAX-1;j>=1;j--) v[j]=v[j-1];
			v[0]=0;
			for(k=0;k<MAX;k++) v[k]=v[k]^r[k];	
		}
	}
	
//	printf("Z=\n");
//	for(i=0;i<MAX;i++)	printf("%d ",z[i]);
	
	
}
char *convertz()
{
	int a,b;
	char c;
//	printf("\nInside convertz ");
	int temp,i;
	for(i=0;i<32;i++)
	{    temp=8*z[4*i]+ 4*z[4*i+1]+ 2*z[4*i+2] + z[4*i+3];
		C[i]=(temp>=10)?('a'+temp-10):temp+'0';
	}
	
/*	printf("C:\n");
	
	for(i=0;i<32;i++) printf("%c ",C[i]);
	printf("\n");*/
	CHex=(char *)malloc(16*sizeof(unsigned char));
	for(i=0;i<16;i++)
	{
		a=C[2*i];
		b=C[2*i+1];
		if(a>=48 && a<=57)
		a=a-48;
		
		else
		{
		//printf("%d\n ",a);
		a=10+(a%16)-1;
		//	printf("%d\n ",a);
		}
		
		//printf("a=%d\n",a);
		if(b>=48 && b<=57)
		b=b-48;
		
		else
		b=10+(b%16)-1;
		//printf("b=%d\n",b);
		c=(a*16)+b;
	//	printf("c=%x\n",c);
		CHex[i]=c;
	}
	
//	for(i=0;i<16;i++) printf("%x ",CHex[i]);
	
	//printf("\nCHEx computed.\n");
	
	return (char *)CHex;
	
}

