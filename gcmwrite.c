#include<stdio.h>
#include<string.h>
char keyinchar[32],c;
unsigned char key[16];
int a,b;

int main()
{
	int choice=1,len=0,i;
	FILE *fp;
	unsigned char ch;
	fp=fopen("gcmwrite1.txt","w");
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
		return -1;
	}
	printf("Enter Key:\n");
	scanf("%s",keyinchar);
	
	len=strlen(keyinchar)/2;
	
	for(i=0;i<len;i++)
	{
		a=keyinchar[2*i];
		b=keyinchar[2*i+1];
		
		if(a>=48 && a<=57)
		a=a-48;
		
		else
		a=10+(a%16)-1;
		
		if(b>=48 && b<=57)
		b=b-48;
		
		else
		b=10+(b%16)-1;
		
		c=a*16+b;
		key[i]=c;
	}
	for(i=0;i<len;i++)
	{
		fprintf(fp,"%x\n",key[i]);
	}
	
	
	fclose(fp);
	printf("Writing in file done.");
	return 0;
	
	
	
/*	while(choice==1)
	{
		printf("Enter hex value:\n");
		scanf("%x",&ch);
		fprintf(fp,"%x\n",ch);
		printf("Choice:\n");
		scanf("%d",&choice);
		len++;
	}*/
	

	
}
