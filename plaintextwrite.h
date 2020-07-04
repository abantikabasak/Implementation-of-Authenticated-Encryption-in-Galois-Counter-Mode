#include<stdio.h>
int len_pt;
unsigned char hextext2number(char *text) 
{
	
	int a1 = text[0];
	int a2 = text[1];
	
	a1 = a1 >= 97 ? ((a1 - 97) + 10) : a1 - 48;
	a2 = a2 >= 97 ? ((a2 - 97) + 10) : a2 - 48;
	
	return (unsigned char)(a1 * 16 + a2);
}
/*
int plaintext()
{
	
	int c1=0,c=0,choice=1,p[100],i;
	FILE *fp;
	unsigned char ch,text[3];
	int len_pt;
	printf("Enter length of plaintext:\n");
	scanf("%d",&len_pt);
	fp=fopen("plaintextwrite.txt","r");
	
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
		return -1;
	}
	while(1)
	{
		if(c1==len_pt)
		break;
		ch=getc(fp);
		if(ch==EOF)
		break;
		if(ch == '\n' || ch == ' ') 
		{
		if(c > 0) 
		{
		text[c] = '\0';
		c = 0;								
				
	
		printf("C1:%d %x\n", c1, hextext2number(text));
		
		p[c1++] = hextext2number(text);
		}
		
		continue;
		}
		printf("\nch=%c c=%d\n",ch,c);
		text[c++] = ch;
		}
		fclose(fp);
		
		for(i=0;i<len_pt;i++)
		printf("%x ",p[i]);
		return len_pt;
	
}*/
