#include<stdio.h>

int main1()
{
	int choice=1,len=0;
	FILE *fp;
	unsigned char ch;
	fp=fopen("gcmwrite.txt","w");
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
		return -1;
	}
	
	while(choice==1)
	{
		printf("Enter key value:\n");
		scanf("%x",&ch);
		fprintf(fp,"%x\n",ch);
		printf("Choice:\n");
		scanf("%d",&choice);
		len++;
	}
	
	fclose(fp);
	printf("No of hex characters entered:%d\n",len);
	return len;	
	
}
