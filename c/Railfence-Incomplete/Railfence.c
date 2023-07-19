/*
 *
 * Rail Fence Ciphers
 * Rail fence ciphers are examples of transposition ciphers: The characters in the plaintext message are permuted
 * to create the ciphertext. In the rail fence cipher, the permutation is obtained from a very simple pattern.
 * Other transposition ciphers use other manipulations to permute the characters.
 * The encryption key for a rail fence cipher is a positive integer.
 * Suppose we want to encrypt the message “buy your books in August” using a rail fence cipher with encryption
 * key 3. Here is how we would proceed.
 * i. Arrange the plaintext characters in an array with 3 rows (the key determines the number of rows),
 * forming a zig-zag pattern:
 * b - - - o - - - o - - - i - - - g - - -
 * - u - y - u - b - o - s - n - u - u - t
 *   - - y - - - r - - - k - - - a - - - s -
 *   ii. Then concatenate the non-empty characters from the rows to obtain the ciphertext:
 *   BOOIGUYUBOSNUUTYRKAS
 *
 */

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int i,j,k,l,key,m,rowSize;
	int flag=0;
	char plainText[MAX];
	//char plainText[MAX]="thisisasecretmessage";
	char **rows;
	char *cipherText;
	char decryptedText[MAX];
	int currRow;
	int *currentPosInRow;

	printf("\nEnter the input string : ");
	scanf("%[^*\n]",plainText);
	
	l=strlen(plainText);

	printf("\nEnter encryption key (integer between 2 and %d) : ",(l-1));
	scanf("%d",&key);
   

	rowSize=(l/key)+2;

	/*Ciphering*/
	
	currentPosInRow = (int*)malloc(key*sizeof(int));

	for(i=0;i<key;i++)
	{
		currentPosInRow[i]=0;
	}

	rows = (char**)malloc(key*sizeof(char*));
	for(i=0;i<key;i++)
	{
		rows[i]=(char*)malloc(rowSize*sizeof(char));
	}
	i=0;

	while(i<l)
	{	for(j=0;j<key;j++)
		{
			if(i>=l)
				break;
			
			if(j==0 && currentPosInRow[j]!=0)
			{
				continue;
			}
			else
			{
				rows[j][currentPosInRow[j]] = plainText[i++];
				//printf("Character added %c at possition %d\n",plainText[i-1],currentPosInRow[j]);
				currentPosInRow[j]++;
			}
	        }
		if(i>=l)
			break;
		
		for(j=key-1;j>=0;j--)
		{
			if(i>=l)
			{
				break;
			}
			if(j==key-1)
			{
				continue;
			}
			else
			{
				rows[j][currentPosInRow[j]] = plainText[i++];
				//printf("Character added %c at possition %d\n",plainText[i-1],currentPosInRow[j]);
				currentPosInRow[j]++;
			}			
	        }
	}
	
	for(i=0;i<key;i++)
	{
		rows[i][currentPosInRow[i]]='\0';
		//printf("Length of row[%d] = %d\n",i,strlen(rows[i]));
	}
	

	printf("\nEncrypted Text : ");
	for(i=0;i<key;i++)
	{
		printf("%s",rows[i]);
	}

	printf("\n");


	/*Deciphering*/
	
	for(i=0;i<key;i++)
	{
		currentPosInRow[i]=0;
	}

	i=0;
	while(i<l)
	{
		for(j=0;j<key;j++)
		{
			if(i>=l)
				break;
			
			if(j==0 && currentPosInRow[j]!=0)
			{
				continue;
			}
			else
			{
				decryptedText[i++] = rows[j][currentPosInRow[j]];
				//printf("Character added %c at possition %d\n",decryptedText[i-1],currentPosInRow[j]);
				currentPosInRow[j]++;
			}
	        }
		if(i>=l)
			break;
		
		for(j=key-1;j>=0;j--)
		{
			if(i>=l)
			{
				break;
			}
			if(j==key-1)
			{
				continue;
			}
			else
			{
				decryptedText[i++] = rows[j][currentPosInRow[j]];				
				//printf("Character added %c at possition %d\n",decryptedText[i-1],currentPosInRow[j]);
				currentPosInRow[j]++;
			}			
	        }
	}	



	decryptedText[l]='\0';

	printf("\nDecrypted Text : ");
	printf("%s\n",decryptedText);

	return 0;
}
