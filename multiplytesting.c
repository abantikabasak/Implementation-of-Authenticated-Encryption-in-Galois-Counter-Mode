#include<stdio.h>
#include<stdlib.h>
#define MAX 128
int z[MAX],v[MAX],x[MAX],y[MAX],r[MAX];
int temp[8]={1,1,1,0,0,0,0,1};
unsigned char C[32],*CHex,*CHex1,H[32],Auth[32];
//unsigned char B[32];
//unsigned char C[32];
unsigned char cipher1[16]={0xfe,0xed,0xfa,0xce,0xde,0xad,0xbe,0xef,0xfe,0xed,0xfa,0xce,0xde,0xad,0xbe,0xef};
unsigned char cipher2[16]={0xb8,0x3b,0x53,0x37,0x08,0xbf,0x53,0x5d,0x0a,0xa6,0xe5,0x29,0x80,0xd5,0x3b,0x78};
//char H[32]="feedfacedeadbeeffeedfacedeadbeef";
//char Auth[32]="b83b533708bf535d0aa6e52980d53b78";
void multiply();
char *convertz();
void printeachz();
void hexSplit(unsigned char hex[16], unsigned char result[32]) {
    int rem, dividend, c,i;
    unsigned char ch;
    c = 1;
    
    for(i=0;i<16;i++)
    {
	
    dividend = hex[i];
	
//	printf("Dividend:\n");
//	printf("%d ",dividend);
	
	if(dividend >10)
	{
	while(dividend > 0) {
        
        rem = dividend % 16;
  //      printf("\nRemainder:%d\n",rem);
        dividend = dividend / 16;
        if(rem < 10) {
        	//printf("c=%d ",c);
            result[c--] = 48+ rem;
            
        } 
		else {
            // A-F
            //printf("c=%d ",c);
            result[c--] = (char)(97 + (rem - 10));
            //printf("c=%d ",c);
        }
        printf("\n");
       
    }
    
    c=c+4;
	}
	
	else if(dividend < 10)
	{
		result[c--]=48+dividend;
		result[c--]=48;
    	c=c+4;
	}
	
	else if(dividend==10)
	{
		result[c--]=97;
		result[c--]=48;
		c=c+4;
	}
    
    
    
	}
	
}
int main(){
	
	hexSplit(cipher1,H);
	hexSplit(cipher2,Auth);
		
	
    int i;
	for(i=0;i<8;i++) r[i]=temp[i];
	for(i=8;i<MAX;i++) r[i]=0;
	for(i=0;i<32;i++)
	{
		switch(H[i])
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
		switch(Auth[i])
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
	/*	for(i=0;i<128;i++) printf("%d ",x[i]);
	printf("\n");
	for(i=0;i<128;i++) printf("%d ",y[i]);
	printf("\n");
	
	for(i=0;i<128;i++) printf("%d ",z[i]);
	printf("\n");*/
	multiply();
	CHex1=convertz();
	/*
	printf("Inside main.\n");
	for(i=0;i<16;i++) printf("%x ",CHex1[i]);
	*/
return 0;	
}
 void printeachz(){
 	int i;
 	printf("Z starts: \n");
 	for(i=0;i<MAX;i++){
 		printf("%d",z[i]);
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
		if (i>=70 && i<90) 
		printeachz();
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
}
char *convertz()
{
	int a,b;
	char c;
	printf("\nInside convertz ");
	int temp,i;
	for(i=0;i<32;i++)
	{    temp=8*z[4*i]+ 4*z[4*i+1]+ 2*z[4*i+2] + z[4*i+3];
		C[i]=(temp>=10)?('a'+temp-10):temp+'0';
	}
	
	for(i=0;i<32;i++) printf("%c ",C[i]);
	printf("\n");
	
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
		//printf("c=%x\n",c);
		CHex[i]=c;
	}
	
	for(i=0;i<16;i++) printf("%x ",CHex[i]);
	
	return (char *)CHex;
	
}

