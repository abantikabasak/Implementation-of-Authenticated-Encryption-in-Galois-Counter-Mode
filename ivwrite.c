#include<stdio.h>
#include<string.h>
char IVinchar[200],c;
unsigned char iv[100];
int a,b;
/*
unsigned char hextext2number(char *text) 
{
	
	int a1 = text[0];
	int a2 = text[1];
	
	a1 = a1 >= 97 ? ((a1 - 97) + 10) : a1 - 48;
	a2 = a2 >= 97 ? ((a2 - 97) + 10) : a2 - 48;
	
	return (unsigned char)(a1 * 16 + a2);
}*/
void main2()
{
	int c1=0,c=0,choice=1,p[100],i,len_iv=0;
	FILE *fp;
	unsigned char ch,text[3];
	fp=fopen("ivwrite.txt","w");
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
		//return -1;
	}
	
/*	while(choice==1)
	{
		printf("Enter iv value:\n");
		scanf("%x",&ch);
		fprintf(fp,"%x\n",ch);
		printf("Choice:\n");
		scanf("%d",&choice);
		len_iv++;
	}*/
	printf("Enter IV:\n");
	scanf("%s",IVinchar);
	
	len_iv=strlen(IVinchar)/2;
	
	for(i=0;i<len_iv;i++)
	{
		a=IVinchar[2*i];
		b=IVinchar[2*i+1];
		
		if(a>=48 && a<=57)
		a=a-48;
		
		else
		a=10+(a%16)-1;
		
		if(b>=48 && b<=57)
		b=b-48;
		
		else
		b=10+(b%16)-1;
		
		c=a*16+b;
		iv[i]=c;
	}
	for(i=0;i<len_iv;i++)
	{
		fprintf(fp,"%x\n",iv[i]);
	}
	
	
	fclose(fp);
	printf("Writing in file done.");

}

int main()
{
	main2();
	return 0;
}
