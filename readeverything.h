#include<stdio.h>
#include<stdlib.h>



unsigned char AAD[100];
unsigned char iv[100];
unsigned char p[100],key[16];


int findiv()
{
	FILE *fp;
	char ch;
	int c=0,c1=0,i;
	unsigned char text[3];
	int len_iv=0;
	fp=fopen("ivwrite.txt","r");
	
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
	//	return -1;
	}
	while(1)
	{
		
		ch=getc(fp);
		if(ch==EOF)
		break;
		if(ch == '\n' || ch == ' ') 
		{
		if(c > 0) 
		{
		text[c] = '\0';
		c = 0;								
		len_iv++;			
	
	//	printf("C1:%d %x\n", c1, hextext2number(text));
		
		iv[c1++] = hextext2number(text);
		}
		
		continue;
		}
		
		else if(ch==255)
		break;
		//printf("\nch=%c c=%d\n",ch,c);
		text[c++] = ch;
		}
		fclose(fp);
		printf("\nIV:\n");
		for(i=0;i<len_iv;i++)	printf("%x ",iv[i]);	
		return len_iv;
}


int findAAD()
{
	FILE *fp;
	char ch;
	int c=0,c1=0,len_AAD=0,i;
	unsigned char text[3];
	fp=fopen("AADwrite.txt","r");
	
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
	//	return -1;
	}
	while(1)
	{
		
		ch=getc(fp);
		if(ch==EOF)
		break;
		if(ch == '\n' || ch == ' ') 
		{
		if(c > 0) 
		{
		text[c] = '\0';
		c = 0;								
		len_AAD++;			
	
	//	printf("C1:%d %x\n", c1, hextext2number(text));
		
		AAD[c1++] = hextext2number(text);
		}
		
		continue;
		}
		
		else if(ch==255)
		break;
		//printf("\nch=%c c=%d\n",ch,c);
		text[c++] = ch;
		}
		fclose(fp);
		printf("\nAAD:\n");
		for(i=0;i<len_AAD;i++)	printf("%x ",AAD[i]);
		return len_AAD;
}

int findplaintextandkey()
{
	int len_pt=0,i;
	FILE *fp1,*fp2,*fp;
	int c1=0,c=0;
	char ch;
	unsigned char text[3];
	//p=(char *)malloc(100*sizeof(unsigned char));
	
	fp1=fopen("gcmwrite1.txt","r");
	if(fp1==NULL)
	{
		printf("Error in opening file.\n");
		//return -1;
	}
	
	while(1)
	{
		if(c1==16)
		break;
		ch=getc(fp1);
		if(ch==EOF)
		break;
		if(ch == '\n' || ch == ' ') 
		{
		if(c > 0) 
		{
		text[c] = '\0';
		c = 0;								
				
	
	//	printf("C1:%d %x\n", c1, hextext2number(text));
		
		key[c1++] = hextext2number(text);
		}
		
		continue;
		}
	//	printf("\nch=%c c=%d\n",ch,c);
		text[c++] = ch;
	}
		fclose(fp1);
		printf("\nKey:\n");
		for(i=0;i<16;i++)	printf("%x ",key[i]);

		c1=0;

		fp=fopen("plaintextwrite.txt","r");
	
		if(fp==NULL)
		{
		printf("Error in opening file:\n");
		//return -1;
		}
		printf("\n");
		while(1)
		{
		
		ch=getc(fp);
		if(ch==EOF)
		break;
		if(ch == '\n' || ch == ' ') 
		{
		if(c > 0) 
		{
		text[c] = '\0';
		c = 0;								
		len_pt++;			
	
	//	printf("C1:%d %x\n", c1, hextext2number(text));
		
		p[c1++] = hextext2number(text);
		}
		
		continue;
		}
		
		else if(ch==255)
		break;
		//printf("\nch=%c c=%d\n",ch,c);
		text[c++] = ch;
		}
		fclose(fp);
		
	//	printf("Len_pt:%d\n",len_pt);
		printf("\nPlaintext:\n");
		for(i=0;i<len_pt;i++)
		printf("%x ",p[i]);
		
		return len_pt;
		
}
