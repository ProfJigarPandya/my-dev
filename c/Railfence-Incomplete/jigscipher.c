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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
 //char plainText[]="buy your books in August";
 //char plainText[]="buyyourbooksinAugust";
 char plainText[]="thisisasecretmessage";
 //char plainText[MAX];
 int slen,key,rowsize,i,j,m,startpos,offset;
 char **rows;
 char decryptedText[MAX];

 /*printf("\nEnter the input string : ");
 scanf("%s",plainText);*/

 slen=strlen(plainText);

 printf("\nEnter encryption key (integer between 2 and %d - 1 ) : ",slen);
 scanf("%d",&key);

 rowsize=(slen/key)+2;

 /*Ciphering*/
	
 rows = (char**)malloc(key*sizeof(char*));
 for(i=0;i<key;i++)
 {
	rows[i]=(char*)malloc(rowsize*sizeof(char));
 }

 //For every row
 for(m=0;m<key;m++)
 {
	startpos=(m);

	if(m<(key-1))
	{			
		offset= (key - (m+1)) * 2 -1;
	}
	else
	{
		offset= (key - 1) * 2 -1;
	}
	
	j=startpos;

	printf("Row no : %d, offset = %d, startpos = %d\n",m,offset,startpos);
	//i=0;
	/*while(j<slen)
	{
		rows[m][i++]=plainText[j];
		j+=offset;
	}
	rows[m][i]='\0';*/
 }


 /*printf("\nCipher text after applying rail fence :");
 for(i=0;i<key;i++)
 {
 	printf("\n%s",rows[i]);
 }

 printf("\n");*/
 
 /*Deciphering*/
//For every row
 for(m=1;m<=key;m++)
 {
	startpos=(m-1);

	if(m==1 || m==(key)) //For first and last row, offset is same as number of rows
		offset=key;
	else
	{
		offset= (  ( key - m) * 2 - 1 );
	}
	
	j=startpos;
	i=0;
	while(j<slen)
	{
		decryptedText[j]=rows[m-1][i++];
		j+=offset+1;
	}
 }
 decryptedText[slen]='\0';
 printf("\nDecrypted text : %s ",decryptedText);

 return 0;
}
