#include<omp.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include"AES.h"
#include"multiply1.h"
#include"hex_split.h"
#include"plaintextwrite.h"
#include"len_init_cal.h"
#include"len_A.h"
#include"readeverything.h"

int len_AAD,len_iv;
unsigned char AAD[100];//={0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,0xab,0xad,0xda,0xd2};
unsigned char iv[100];//={0xca,0xfe,0xba,0xbe,0xfa,0xce,0xdb,0xad,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char zero[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char key[16],in[16],out[16],counter0[16],counter1[16],counter2[16],counter3[16],counter4[16],counter5[16],counter6[16],counter7[16],counter8[16],result[32],resultH[32];
unsigned char H[16],plaintext1[16],plaintext2[16],plaintext3[16],plaintext4[16],plaintext5[16],plaintext6[16],plaintext7[16],plaintext8[16],plaintext9[16];
unsigned char p[100],ecounter0[16],ecounter1[16],ecounter2[16],ecounter3[16],ecounter4[16],ecounter5[16],ecounter6[16],ecounter7[16],ecounter8[16];
unsigned char *CHex,*len_A;//[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0};
unsigned char lenAlenC[16],tag[16],ciphertext1[16],ciphertext2[16],inter[16],inter1[16],inter2[16],inter3[16],*CHex1,ciphertext3[16],ciphertext4[16],ciphertext5[16];
unsigned char *lenC;//[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xe0};
unsigned char *CHex2,N[16];
int len_pt,*x1,y[128],temp1[128];
unsigned char *ch1,result[32],*ecounter1mod,*len_init;
unsigned char iv1[16],iv2[16],iv3[16],iv4[16];

void findH()
{
	int i;
	for(i=0;i<16;i++)	in[i]=zero[i];
	keyexpansion();
	encrypt();
	for(i=0;i<16;i++)	H[i]=out[i];
	printf("\nH\n");
	for(i=0;i<16;i++)	printf("%x ",H[i]);
}


void findcounter1()
{
	int i;
	len_init=(char *)malloc(16*sizeof(unsigned char));
	len_init=calculate(len_iv);
	printf("\nIV1:\n");
	for(i=0;i<16;i++)	printf("%x ",iv1[i]);
	printf("\n\n");
	printf("\nIV2:\n");
	for(i=0;i<16;i++)	printf("%x ",iv2[i]);
	printf("\n\n");
	printf("\nIV3:\n");
	for(i=0;i<16;i++)	printf("%x ",iv3[i]);
	printf("\n\n");
	printf("\nIV4:\n");
	for(i=0;i<16;i++)	printf("%x ",iv4[i]);
	printf("\n\n");

	CHex=(char *)malloc(sizeof(unsigned char)*16);
	hexSplit(zero,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
/*	printf("\nCHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");*/
	
	for(i=0;i<16;i++)	iv1[i]=CHex[i]^iv1[i];
	hexSplit(iv1,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN1 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	for(i=0;i<16;i++)	iv2[i]=CHex[i]^iv2[i];
	hexSplit(iv2,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN2 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	
	for(i=0;i<16;i++)	iv3[i]=CHex[i]^iv3[i];
	hexSplit(iv3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN3 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
/*	printf("\niv4:\n");
		for(i=0;i<16;i++)	printf("%x ",iv4[i]);
		printf("\n\n");*/
	
	for(i=0;i<16;i++)	iv4[i]=CHex[i]^iv4[i];
	
/*	printf("\niv4:\n");
		for(i=0;i<16;i++)	printf("%x ",iv4[i]);
		printf("\n\n");*/
	
	hexSplit(iv4,result);
	
//	printf("\nResult:\n");
	
//	for(i=0;i<32;i++) printf("%c\n",result[i]);
//	printf("\n\n");
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN4 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");

	for(i=0;i<16;i++)	inter3[i]=CHex[i]^len_init[i];
	hexSplit(inter3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	/*printf("\nN5 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");*/
	
	for(i=0;i<16;i++)	counter0[i]=CHex[i];
	
	printf("\nCounter 0:\n");
	
	for(i=0;i<16;i++)	printf("%x ",counter0[i]);
	
	/*for(i=0;i<16;i++)	in[i]=counter0[i];
	keyexpansion();
	encrypt();
	for(i=0;i<16;i++)	ecounter0[i]=out[i];
	printf("\nE(K,Y0):\n");
	for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
	*/
}



void findcounter2()
{
	int i;
	len_init=(char *)malloc(16*sizeof(unsigned char));

	
	for(i=0;i<12;i++)	counter0[i]=iv[i];
	
	
	for(i=12;i<15;i++)	counter0[i]=0x00;
	
	
	
	counter0[i]=0x01;
	
/*	for(i=0;i<16;i++)	in[i]=counter0[i];
	keyexpansion();
	encrypt();
	for(i=0;i<16;i++)	ecounter0[i]=out[i];
	printf("\nE(K,Y0):\n");
	for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);*/
}

void findcounter3()
{
	int i;
	CHex=(char *)malloc(sizeof(unsigned char)*16);
	len_init=(char *)malloc(16*sizeof(unsigned char));
	len_init=calculate(len_iv);
	hexSplit(zero,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	for(i=0;i<16;i++)	inter3[i]=CHex[i]^iv[i];
	hexSplit(inter3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	
	
	for(i=0;i<16;i++)	inter3[i]=CHex[i]^len_init[i];
	hexSplit(inter3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	for(i=0;i<16;i++)	counter0[i]=CHex[i];
	
	
	printf("\n\nCounter 0:\n");
	
	for(i=0;i<16;i++)	printf("%x ",counter0[i]);
/*	for(i=0;i<16;i++)	in[i]=counter0[i];
	keyexpansion();
	encrypt();
	for(i=0;i<16;i++)	ecounter0[i]=out[i];
	printf("\nE(K,Y0):\n");
	for(i=0;i<16;i++)	printf("%x ",ecounter0[i]); */
}

void findcounter4()
{
	int i;
	len_init=(char *)malloc(16*sizeof(unsigned char));
	len_init=calculate(len_iv);
	printf("\nIV1:\n");
		for(i=0;i<16;i++)	printf("%x ",iv1[i]);
		printf("\n\n");
		printf("\nIV2:\n");
		for(i=0;i<16;i++)	printf("%x ",iv2[i]);
		printf("\n\n");
		printf("\nIV3:\n");
		for(i=0;i<16;i++)	printf("%x ",iv3[i]);
		printf("\n\n");
		

	CHex=(char *)malloc(sizeof(unsigned char)*16);
	hexSplit(zero,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	/*printf("\nCHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");*/
	
	for(i=0;i<16;i++)	iv1[i]=CHex[i]^iv1[i];
	hexSplit(iv1,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN1 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	for(i=0;i<16;i++)	iv2[i]=CHex[i]^iv2[i];
	hexSplit(iv2,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN2 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	
	for(i=0;i<16;i++)	iv3[i]=CHex[i]^iv3[i];
	hexSplit(iv3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN3 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");

	for(i=0;i<16;i++)	inter3[i]=CHex[i]^len_init[i];
	hexSplit(inter3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN4 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	for(i=0;i<16;i++)	counter0[i]=CHex[i];
	
	
	printf("\nCounter 0:\n");
	
	for(i=0;i<16;i++)	printf("%x ",counter0[i]);
	
	/*
	for(i=0;i<16;i++)	in[i]=counter0[i];
	keyexpansion();
	encrypt();
	for(i=0;i<16;i++)	ecounter0[i]=out[i];
	printf("\nE(K,Y0):\n");
	for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
	*/
}

void findcounter5()
{
	int i;
	len_init=(char *)malloc(16*sizeof(unsigned char));
	len_init=calculate(len_iv);
	printf("\nIV1:\n");
	for(i=0;i<16;i++)	printf("%x ",iv1[i]);
	printf("\n\n");
	printf("\nIV2:\n");
	for(i=0;i<16;i++)	printf("%x ",iv2[i]);
	printf("\n\n");
	CHex=(char *)malloc(sizeof(unsigned char)*16);
	hexSplit(zero,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	/*
	printf("\nCHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	*/
	for(i=0;i<16;i++)	iv1[i]=CHex[i]^iv1[i];
	hexSplit(iv1,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN1 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	for(i=0;i<16;i++)	iv2[i]=CHex[i]^iv2[i];
	hexSplit(iv2,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN2 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	for(i=0;i<16;i++)	inter3[i]=CHex[i]^len_init[i];
	hexSplit(inter3,result);
	hexSplit(H,resultH);
	CHex=input(result,resultH);
	
	printf("\nN3 : CHex:\n");
	for(i=0;i<16;i++) 	printf("%x ",CHex[i]);
	printf("\n");
	
	for(i=0;i<16;i++)		counter0[i]=CHex[i];

	printf("\n\nCounter 0:\n");
	
	for(i=0;i<16;i++)	printf("%x ",counter0[i]);
/*	for(i=0;i<16;i++)	in[i]=counter0[i];
	keyexpansion();
	encrypt();
	for(i=0;i<16;i++)	ecounter0[i]=out[i];
	printf("\nE(K,Y0):\n");
	for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
*/
}


int main()
{
	//#pragma omp parallel 
	//{
		
	
	clock_t start, end;
    double cpu_time_used;
	FILE *fp1,*fp2,*fp;
	unsigned char text[3];
	int c=0,c1=0,c2=0,i,j,len_pt,q,r,q1,r1,cnt=0,count=0;
	
    start = clock();
	char ch;
	CHex=(char *)malloc(16*sizeof(unsigned char));
	CHex1=(char *)malloc(16*sizeof(unsigned char));
	CHex2=(char *)malloc(16*sizeof(unsigned char));
//	p=(char *)malloc(100*sizeof(unsigned char));
	x1=(int *)malloc(sizeof(int)*128);
	
	printf("\n");
	len_iv=findiv();
	len_AAD=findAAD();
	len_pt=findplaintextandkey();
	findH();
	
	if(len_iv>48)
	{
		for(i=0;i<16;i++)	iv1[i]=iv[i];
		for(i=16;i<32;i++)	iv2[i-16]=iv[i];
		for(i=32;i<48;i++)	iv3[i-32]=iv[i];
		for(i=48;i<len_iv;i++)	iv4[i-48]=iv[i];
		for(i=(len_iv-48);i<16;i++)	iv4[i]=0x00;
		findcounter1();
	}
	
	else if(len_iv<=48 && len_iv>32)
	{
		for(i=0;i<16;i++)	iv1[i]=iv[i];
		for(i=16;i<32;i++)	iv2[i-16]=iv[i];
		for(i=32;i<len_iv;i++)	iv3[i-32]=iv[i];
		for(i=(len_iv-32);i<16;i++)	iv3[i]=0x00;
		findcounter4();
	}
		
	else if(len_iv<=32 && len_iv>16)
	{
		for(i=0;i<16;i++)	iv1[i]=iv[i];
		for(i=16;i<len_iv;i++)	iv2[i-16]=iv[i];
		for(i=(len_iv-16);i<16;i++)	iv2[i]=0x00;
		findcounter5();	
	}
	else if(len_iv>12 && len_iv<=16)	
	{
		for(i=len_iv;i<16;i++)	iv[i]=0x00;
		
		findcounter3();
	}
	else if(len_iv==12 || len_iv==0)	findcounter2();
	else if(len_iv <12 && len_iv>0 )	
	{
		for(i=len_iv;i<16;i++)	iv[i]=0x00;
		findcounter3();
	}
	
len_A=(char *)malloc(8*sizeof(unsigned char));
len_A=calculatelenA(len_AAD);

if(len_pt %16 == 0)
{
	q=len_pt/16;
	switch(q)
	{
	case 0:
		{
			
			if(len_AAD==0)
			{
				
				for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
				len_A=calculatelenA(len_pt);
				for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
			//	for(i=0;i<16;i++)	ciphertext1[i] = [i]^lenAlenC[i];
				hexSplit(lenAlenC,result);
				hexSplit(H,resultH);
				CHex=input(result,resultH);
				
				for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
				printf("\nTag:\n");
				
				for(i=0;i<16;i++)	printf("%x ",tag[i]);
			}
		}break;
	
	case 1:
		{
				for(i=0;i<15;i++)	counter1[i]=counter0[i];
				counter1[15]=counter0[15]+1;
				#pragma omp parallel
				for(j=0;j<2;j++)
				{
					switch(j)
					{
					
					case 0:
						{
							for(i=0;i<16;i++)	in[i]=counter0[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter0[i]=out[i];
							printf("\nE(K,Y0):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
						}break;
					case 1:
						{
							for(i=0;i<16;i++)	in[i]=counter1[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter1[i]=out[i];
							printf("\nE(K,Y1):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
						}break;
					}
				}
				
				for(i=0;i<16;i++)	plaintext1[i]=p[i];
				for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
				if(len_AAD !=0)
						{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("\nAAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("\nAAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX3:\n");
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n"); //sequence 1 completed.
							
							for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
							len_A=calculatelenA(len_pt);
							for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
							for(i=0;i<16;i++)	ciphertext2[i] = CHex[i]^lenAlenC[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							CHex=input(result,resultH);
				
							for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
							printf("Tag:\n");
				
							for(i=0;i<16;i++)	printf("%x ",tag[i]);
							}// if(q1==1 && r1!=0) ends here.
						}
						
						else if(len_AAD ==0)
						{
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX1=C1.H :\n");
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n"); //sequence 1 completed.
							for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
							len_A=calculatelenA(len_pt);
							for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
							for(i=0;i<16;i++)	ciphertext2[i] = CHex[i]^lenAlenC[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							CHex=input(result,resultH);
				
							for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
							printf("Tag:\n");
				
							for(i=0;i<16;i++)	printf("%x ",tag[i]);
							
						}
							
		}break;
		
		case 2:
			{
				for(i=0;i<15;i++)	counter1[i]=counter0[i];
				counter1[15]=counter0[15]+1;
				for(i=0;i<15;i++)	counter2[i]=counter0[i];
				counter2[15]=counter0[15]+2;
				for(i=0;i<16;i++)	plaintext1[i]=p[i];
				for(i=16;i<32;i++)	plaintext2[i-16]=p[i];
				#pragma omp parallel
				for(j=0;j<3;j++)
				{
					switch(j)
					{
					
					case 0:
						{
							for(i=0;i<16;i++)	in[i]=counter0[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter0[i]=out[i];
							printf("\nE(K,Y0):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
						}break;
					case 1:
						{
							for(i=0;i<16;i++)	in[i]=counter1[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter1[i]=out[i];
							printf("\nE(K,Y1):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
							
							for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
						}break;
					case 2:
						{
							for(i=0;i<16;i++)	in[i]=counter2[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter2[i]=out[i];
							printf("\nE(K,Y2):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter2[i]);
							
							for(i=0;i<16;i++)	ciphertext2[i]=plaintext2[i]^ecounter2[i];
						}break;
					}
				}
				
				if(len_AAD != 0)
					{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("AAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("AAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							}
						
							count=3;
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							//sequence 1 and 2 till lenA||lenC completed.
					}
					
					else if(len_AAD ==0)	
					{
					count=1;
					for(i=0;i<16;i++)	CHex[i]=0x00;
					
						for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
						hexSplit(ciphertext1,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
						for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
						hexSplit(ciphertext2,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
					
					} //sequence 1 and 2 till lenA||lenC completed.
							
					for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
					len_A=calculatelenA(len_pt);
					for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
					for(i=0;i<16;i++)	ciphertext3[i] = CHex[i]^lenAlenC[i];
					hexSplit(ciphertext3,result);
					hexSplit(H,resultH);
					CHex=input(result,resultH);
				
					for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
					printf("Tag:\n");
				
					for(i=0;i<16;i++)	printf("%x ",tag[i]);
			}break;
			
			case 3:
				{
				for(i=0;i<15;i++)	counter1[i]=counter0[i];
				counter1[15]=counter0[15]+1;
				for(i=0;i<15;i++)	counter2[i]=counter0[i];
				counter2[15]=counter0[15]+2;
				for(i=0;i<15;i++)	counter3[i]=counter0[i];
				counter3[15]=counter0[15]+3;
				for(i=0;i<16;i++)	plaintext1[i]=p[i];
				for(i=16;i<32;i++)	plaintext2[i-16]=p[i];
				for(i=32;i<48;i++)	plaintext3[i-32]=p[i];
				#pragma omp parallel
				
				for(j=0;j<4;j++)
				{
					switch(j)
					{
					
					case 0:
						{
							for(i=0;i<16;i++)	in[i]=counter0[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter0[i]=out[i];
							printf("\nE(K,Y0):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
						}break;
					case 1:
						{
							for(i=0;i<16;i++)	in[i]=counter1[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter1[i]=out[i];
							printf("\nE(K,Y1):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
							
							for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
						}break;
					case 2:
						{
							for(i=0;i<16;i++)	in[i]=counter2[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter2[i]=out[i];
							printf("\nE(K,Y2):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter2[i]);
							
							for(i=0;i<16;i++)	ciphertext2[i]=plaintext2[i]^ecounter2[i];
						}break;
					case 3:
						{
							for(i=0;i<16;i++)	in[i]=counter3[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter3[i]=out[i];
							printf("\nE(K,Y3):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter3[i]);
							
							for(i=0;i<16;i++)	ciphertext3[i]=plaintext3[i]^ecounter3[i];
						}break;
					}
				}
				if(len_AAD != 0)
					{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("AAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("AAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							}
						
							count=3;
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
							hexSplit(ciphertext3,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							//sequence 1 and 2 till lenA||lenC completed.
					}
					
					else if(len_AAD ==0)	
					{
					count=1;
					for(i=0;i<16;i++)	CHex[i]=0x00;
					
						for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
						hexSplit(ciphertext1,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
						for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
						hexSplit(ciphertext2,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
						for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
						hexSplit(ciphertext3,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
					
					} //sequence 1 and 2 till lenA||lenC completed.
							
					for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
					len_A=calculatelenA(len_pt);
					for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
					for(i=0;i<16;i++)	ciphertext4[i] = CHex[i]^lenAlenC[i];
					hexSplit(ciphertext4,result);
					hexSplit(H,resultH);
					CHex=input(result,resultH);
				
					for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
					printf("Tag:\n");
				
					for(i=0;i<16;i++)	printf("%x ",tag[i]);
				
			}break;
		case 4:
			{
				for(i=0;i<15;i++)	counter1[i]=counter0[i];
				counter1[15]=counter0[15]+1;
				for(i=0;i<15;i++)	counter2[i]=counter0[i];
				counter2[15]=counter0[15]+2;
				for(i=0;i<15;i++)	counter3[i]=counter0[i];
				counter3[15]=counter0[15]+3;
				for(i=0;i<15;i++)	counter4[i]=counter0[i];
				counter3[15]=counter0[15]+4;
				for(i=0;i<16;i++)	plaintext1[i]=p[i];
				for(i=16;i<32;i++)	plaintext2[i-16]=p[i];
				for(i=32;i<48;i++)	plaintext3[i-32]=p[i];
				for(i=48;i<64;i++)	plaintext4[i-48]=p[i];
			//	omp_set_num_threads(5);
				#pragma omp parallel
				for(j=0;j<5;j++)
				{
					switch(j)
					{
					
					case 0:
						{
							for(i=0;i<16;i++)	in[i]=counter0[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter0[i]=out[i];
							printf("\nE(K,Y0):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
						}break;
					case 1:
						{
							for(i=0;i<16;i++)	in[i]=counter1[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter1[i]=out[i];
							printf("\nE(K,Y1):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
							
							for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
						}break;
					case 2:
						{
							for(i=0;i<16;i++)	in[i]=counter2[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter2[i]=out[i];
							printf("\nE(K,Y2):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter2[i]);
							
							for(i=0;i<16;i++)	ciphertext2[i]=plaintext2[i]^ecounter2[i];
						}break;
					case 3:
						{
							for(i=0;i<16;i++)	in[i]=counter3[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter3[i]=out[i];
							printf("\nE(K,Y3):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter3[i]);
							
							for(i=0;i<16;i++)	ciphertext3[i]=plaintext3[i]^ecounter3[i];
						}break;
					case 4:
						{
							for(i=0;i<16;i++)	in[i]=counter4[i];
							keyexpansion();
							encrypt();
							for(i=0;i<16;i++)	ecounter4[i]=out[i];
							printf("\nE(K,Y4):\n");
							for(i=0;i<16;i++)	printf("%x ",ecounter4[i]);
							
							for(i=0;i<16;i++)	ciphertext4[i]=plaintext4[i]^ecounter4[i];
							
						}break;
					}
				}
				if(len_AAD != 0)
					{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("AAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("AAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							}
						
							count=3;
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
							hexSplit(ciphertext3,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext4[i]=CHex[i] ^ciphertext4[i];
							hexSplit(ciphertext4,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							//sequence 1 and 2 till lenA||lenC completed.
					}
					
					else if(len_AAD ==0)	
					{
					count=1;
					for(i=0;i<16;i++)	CHex[i]=0x00;
					
						for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
						hexSplit(ciphertext1,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
						for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
						hexSplit(ciphertext2,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
						for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
						hexSplit(ciphertext3,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
						for(i=0;i<16;i++)	ciphertext4[i]=CHex[i] ^ciphertext4[i];
						hexSplit(ciphertext4,result);
						hexSplit(H,resultH);
						printf("\nX%d :\n",count++);
						CHex=input(result,resultH);
						//printf("\nCHex:\n");
						for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						printf("\n\n");
						
					
					} //sequence 1 and 2 till lenA||lenC completed.
							
					for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
					len_A=calculatelenA(len_pt);
					for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
					for(i=0;i<16;i++)	ciphertext5[i] = CHex[i]^lenAlenC[i];
					hexSplit(ciphertext5,result);
					hexSplit(H,resultH);
					CHex=input(result,resultH);
				
					for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
					printf("Tag:\n");
				
					for(i=0;i<16;i++)	printf("%x ",tag[i]);
			}break;
	}
}

else if(len_pt%16!=0)
{
	q=len_pt/16;
	r=len_pt%16;
	switch(q)
	{
		case 1:
		{
							
							for(i=0;i<16;i++)	plaintext1[i]=p[i];
							for(i=16;i<(16+r);i++)	plaintext2[i-16]=p[i];
							for(i=r;i<16;i++)	plaintext2[i]=0x00;
							
							for(i=0;i<15;i++)	counter1[i]=counter0[i];
							counter1[15]=counter0[15]+1;
							for(i=0;i<15;i++)	counter2[i]=counter0[i];
							counter2[15]=counter0[15]+2;
							#pragma omp parallel
							for(j=0;j<3;j++)
							{
								switch(j)
								{
								
								case 0:
								{
								for(i=0;i<16;i++)	in[i]=counter0[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter0[i]=out[i];
								printf("\nE(K,Y0):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
								}break;
							case 1:
								{
								for(i=0;i<16;i++)	in[i]=counter1[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter1[i]=out[i];
								printf("\nE(K,Y1):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
							
								for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
								}break;
							case 2:
								{
								for(i=0;i<16;i++)	in[i]=counter2[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter2[i]=out[i];
								printf("\nE(K,Y2):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter2[i]);
							
								for(i=0;i<(len_pt-16);i++)	ciphertext2[i]=plaintext2[i]^ecounter2[i];
								for(i=(len_pt-16);i<16;i++)	ciphertext2[i]=0x00;
								}break;
								}
							}
							
							if(len_AAD != 0)
							{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("AAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("AAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							printf("\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n");
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n");
							}
							count=3;
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							//sequence 1 and 2 till lenA||lenC completed.
						}
						
						else if(len_AAD==0)
						{
							q1=len_AAD/16;
							r1=len_AAD%16;
							count=1;
							for(i=0;i<16;i++)	CHex[i]=0x00;
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
						}
						for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
						len_A=calculatelenA(len_pt);
						for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
						for(i=0;i<16;i++)	ciphertext3[i] = CHex[i]^lenAlenC[i];
						hexSplit(ciphertext2,result);
						hexSplit(H,resultH);
						CHex=input(result,resultH);
						printf("\n");
						/*	for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n"); */
				
						for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
						printf("Tag:\n");
				
						for(i=0;i<16;i++)	printf("%x ",tag[i]);
			}break;
			
			case 2:
				{
							for(i=0;i<16;i++)	plaintext1[i]=p[i];
							for(i=16;i<32;i++)	plaintext2[i-16]=p[i];
							for(i=32;i<(32+r);i++)	plaintext3[i-32]=p[i];
							for(i=r;i<16;i++)	plaintext3[i]=0x00;
							
							for(i=0;i<15;i++)	counter1[i]=counter0[i];
							counter1[15]=counter0[15]+1;
							for(i=0;i<15;i++)	counter2[i]=counter0[i];
							counter2[15]=counter0[15]+2;
							for(i=0;i<15;i++)	counter3[i]=counter0[i];
							counter3[15]=counter0[15]+3;
							#pragma omp parallel
							for(j=0;j<4;j++)
							{
								switch(j)
								{
								
								case 0:
								{
								for(i=0;i<16;i++)	in[i]=counter0[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter0[i]=out[i];
								printf("\nE(K,Y0):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
								}break;
								case 1:
								{
								for(i=0;i<16;i++)	in[i]=counter1[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter1[i]=out[i];
								printf("\nE(K,Y1):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
							
								for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
								}break;
								case 2:
								{
								for(i=0;i<16;i++)	in[i]=counter2[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter2[i]=out[i];
								printf("\nE(K,Y2):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter2[i]);
							
								for(i=0;i<16;i++)	ciphertext2[i]=plaintext2[i]^ecounter2[i];
								}break;
								case 3:
								{
								for(i=0;i<16;i++)	in[i]=counter3[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter3[i]=out[i];
								printf("\nE(K,Y2):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter3[i]);
							
								for(i=0;i<(len_pt-32);i++)	ciphertext3[i]=plaintext3[i]^ecounter3[i];
								for(i=(len_pt-32);i<16;i++)	ciphertext3[i]=0x00;
								}break;
								}
							}
							if(len_AAD != 0)
							{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("AAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("AAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							printf("\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n");
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n");
							}
							count=3;
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
							hexSplit(ciphertext3,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							//sequence 1 and 2 till lenA||lenC completed.
							}
							else if(len_AAD==0)
							{
							q1=len_AAD/16;
							r1=len_AAD%16;
							count=1;
							for(i=0;i<16;i++)	CHex[i]=0x00;
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
							hexSplit(ciphertext3,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							}
						for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
						len_A=calculatelenA(len_pt);
						for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
							
						for(i=0;i<16;i++)	ciphertext4[i] = CHex[i]^lenAlenC[i];
						hexSplit(ciphertext4,result);
						hexSplit(H,resultH);
						CHex=input(result,resultH);
						printf("\n");
						/*	for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n"); */
				
						for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
						printf("Tag:\n");
				
						for(i=0;i<16;i++)	printf("%x ",tag[i]);
				}break;
		case 3:
		{
							printf("\nInside case 3.\n");
							for(i=0;i<16;i++)	plaintext1[i]=p[i];
							for(i=16;i<32;i++)	plaintext2[i-16]=p[i];
							for(i=32;i<48;i++)	plaintext3[i-32]=p[i];
							for(i=48;i<(48+r);i++)	plaintext4[i-48]=p[i];
							for(i=r;i<16;i++)	plaintext4[i]=0x00;
							
							for(i=0;i<15;i++)	counter1[i]=counter0[i];
							counter1[15]=counter0[15]+1;
							for(i=0;i<15;i++)	counter2[i]=counter0[i];
							counter2[15]=counter0[15]+2;
							for(i=0;i<15;i++)	counter3[i]=counter0[i];
							counter3[15]=counter0[15]+3;
							for(i=0;i<15;i++)	counter4[i]=counter0[i];
							counter4[15]=counter0[15]+4;
							
							//clock_t start1, end1;
   							//double cpu_time_used1;
   							//start1=clock();
							
							#pragma omp parallel 
							for(j=0;j<5;j++)
							{
								switch(j)
								{
								
								case 0:
								{
								for(i=0;i<16;i++)	in[i]=counter0[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter0[i]=out[i];
								printf("\nE(K,Y0):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
								printf("\nModule 1\n");
								}break;
								case 1:
								{
								for(i=0;i<16;i++)	in[i]=counter1[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter1[i]=out[i];
								printf("\nE(K,Y1):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter1[i]);
							
								for(i=0;i<16;i++)	ciphertext1[i]=plaintext1[i]^ecounter1[i];
								printf("\nModule 2\n");
								}break;
								case 2:
								{
								for(i=0;i<16;i++)	in[i]=counter2[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter2[i]=out[i];
								printf("\nE(K,Y2):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter2[i]);
							
								for(i=0;i<16;i++)	ciphertext2[i]=plaintext2[i]^ecounter2[i];
								printf("\nModule 3\n");
								}break;
								case 3:
								{
								for(i=0;i<16;i++)	in[i]=counter3[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter3[i]=out[i];
								printf("\nE(K,Y3):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter3[i]);
							
								for(i=0;i<16;i++)	ciphertext3[i]=plaintext3[i]^ecounter3[i];
								printf("\nModule 4\n");
								}break;
								case 4:
								{
								for(i=0;i<16;i++)	in[i]=counter4[i];
								keyexpansion();
								encrypt();
								for(i=0;i<16;i++)	ecounter4[i]=out[i];
								printf("\nE(K,Y4):\n");
								for(i=0;i<16;i++)	printf("%x ",ecounter4[i]);
							
								for(i=0;i<(len_pt-48);i++)	ciphertext4[i]=plaintext4[i]^ecounter4[i];
								for(i=(len_pt-48);i<16;i++)	ciphertext4[i]=0x00;
								printf("\nModule 5\n");
								}break;
								}
							}
							
							
							

							if(len_AAD != 0)
							{
							q1=len_AAD/16;
							r1=len_AAD%16;
							if(r1!=0 && q1==1)
							{
							for(i=0;i<16;i++)	inter[i]=AAD[i];
							for(i=16;i<(16+r1);i++)	inter1[i-16]=AAD[i];
							for(i=r1;i<16;i++)	inter1[i]=0x00;
		
							printf("AAD1:\n");
							for(i=0;i<16;i++)	printf("%x ",inter[i]);
							printf("\n");
		
							printf("AAD2:\n");
							for(i=0;i<16;i++)	printf("%x ",inter1[i]);
							printf("\n");
		
							hexSplit(inter,result);
							hexSplit(H,resultH);
							printf("\nX1:\n");
							CHex=input(result,resultH);
							printf("\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n");
							
							for(i=0;i<16;i++)	inter2[i]=CHex[i]^inter1[i];
							hexSplit(inter2,result);
							hexSplit(H,resultH);
							printf("\nX2:\n");
							CHex=input(result,resultH);
							printf("\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n");
							}
							count=3;
							
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
							hexSplit(ciphertext3,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext4[i]=CHex[i] ^ciphertext4[i];
							hexSplit(ciphertext4,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							//sequence 1 and 2 till lenA||lenC completed.
							}
							else if(len_AAD==0)
							{
							q1=len_AAD/16;
							r1=len_AAD%16;
							count=1;
							for(i=0;i<16;i++)	CHex[i]=0x00;
							for(i=0;i<16;i++)	ciphertext1[i]=CHex[i] ^ciphertext1[i];
							hexSplit(ciphertext1,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext2[i]=CHex[i] ^ciphertext2[i];
							hexSplit(ciphertext2,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext3[i]=CHex[i] ^ciphertext3[i];
							hexSplit(ciphertext3,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							for(i=0;i<16;i++)	ciphertext4[i]=CHex[i] ^ciphertext4[i];
							hexSplit(ciphertext4,result);
							hexSplit(H,resultH);
							printf("\nX%d:\n",count++);
							CHex=input(result,resultH);
							//printf("\nCHex:\n");
							for(i=0;i<16;i++)	printf("%x ",CHex[i]);
							printf("\n\n");
							
							}
						for(i=0;i<8;i++)	lenAlenC[i]=len_A[i];
						len_A=calculatelenA(len_pt);
						for(i=8;i<16;i++)	lenAlenC[i]=len_A[i-8];
printf("\nLENALENC\n");
for(i=0;i<16;i++) printf("%x ",lenAlenC[i]);
							
						for(i=0;i<16;i++)	ciphertext5[i] = CHex[i]^lenAlenC[i];
						hexSplit(ciphertext5,result);
						hexSplit(H,resultH);
						CHex=input(result,resultH);
						//printf("\n");

						//	for(i=0;i<16;i++)	printf("%x ",CHex[i]);
						//	printf("\n"); 
						printf("\nE(K,Y0):\n");
						for(i=0;i<16;i++)	printf("%x ",ecounter0[i]);
						for(i=0;i<16;i++)	tag[i]=ecounter0[i]^CHex[i];
						printf("\nTag:\n");
				
						for(i=0;i<16;i++)	printf("%x ",tag[i]);
		}break;					
	}
}
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nCPU TIME USED:%lf\n",cpu_time_used);
//}
	return 0;
}							
											
							
							
							
							
							
					
