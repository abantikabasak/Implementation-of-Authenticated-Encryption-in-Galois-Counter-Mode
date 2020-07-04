#include<stdio.h>
#include<string.h>
char cinchar[200],cp;
unsigned char ct[100];
int a,b;
/*unsigned char hextext2number(char *text) 
{
	
	int a1 = text[0];
	int a2 = text[1];
	
	a1 = a1 >= 97 ? ((a1 - 97) + 10) : a1 - 48;
	a2 = a2 >= 97 ? ((a2 - 97) + 10) : a2 - 48;
	
	return (unsigned char)(a1 * 16 + a2);
}*/
void main2()
{
	int c1=0,c=0,choice=1,i,len_ct=0;
	FILE *fp;
	unsigned char ch,text[3];
	fp=fopen("ciphertextwrite.txt","w");
	if(fp==NULL)
	{
		printf("Error in opening file:\n");
		//return -1;
	}
	printf("Enter Ciphertext:\n");
	scanf("%s",cinchar);
	
	len_ct=strlen(cinchar)/2;
	
	for(i=0;i<len_ct;i++)
	{
		a=cinchar[2*i];
		b=cinchar[2*i+1];
		
		if(a>=48 && a<=57)
		a=a-48;
		
		else
		a=10+(a%16)-1;
		
		if(b>=48 && b<=57)
		b=b-48;
		
		else
		b=10+(b%16)-1;
		
		cp=a*16+b;
		ct[i]=cp;
	}
	for(i=0;i<len_ct;i++)
	{
		fprintf(fp,"%x\n",ct[i]);
	}
	
	
	fclose(fp);
	printf("Writing in file done.");

	
	

	
}

int main()
{
	main2();
	return 0;
}
