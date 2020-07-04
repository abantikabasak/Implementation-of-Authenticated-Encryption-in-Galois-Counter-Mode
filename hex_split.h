#include<stdio.h>

// assume 1 byte long hex-number
void hexSplit(unsigned char hex[16], unsigned char result[32]) {
    int rem, dividend, c,i;
    unsigned char ch;
    c = 1;
    
    for(i=0;i<16;i++)
    {
	
    dividend = hex[i];
	
	//printf("Dividend:\n");
	//printf("%d ",dividend);
	
	if(dividend >15)
	{
	while(dividend > 0) {
        
        rem = dividend % 16;
      //  printf("\nRemainder:%d\n",rem);
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
        //printf("\n");
       
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
    
    else if(dividend==11)
	{
		result[c--]=98;
		result[c--]=48;
		c=c+4;
	}
	else if(dividend==12)
	{
		result[c--]=99;
		result[c--]=48;
		c=c+4;
	}
	
	else if(dividend==13)
	{
		result[c--]=100;
		result[c--]=48;
		c=c+4;
	}
	
	else if(dividend==14)
	{
		result[c--]=101;
		result[c--]=48;
		c=c+4;
	}
    
    else if(dividend==15)
	{
		result[c--]=102;
		result[c--]=48;
		c=c+4;
	}
    
    
	}
	
}

/*
 int main() {
	 
	 int i;
	 unsigned char hexResult[32];
	 unsigned char arr[16]= {0xb8,0x3b,0x53,0x37,0x08,0xbf,0x53,0x5d,0x0a,0xa6,0xe5,0x29,0x80,0xd5,0x3b,0x78};
	 
	 
	 hexSplit(arr,hexResult);
	
	
	for(i=0;i<32;i++)
	{
		printf("hexResult[%d]=%c\n",i,hexResult[i]);
	}
	return 0;
 }*/
