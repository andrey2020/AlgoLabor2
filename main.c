/* 
 * File:   main.c
 * Author: anuta
 *
 * Created on 15. Dezember 2013, 01:14
 */

#include <stdio.h>
#include <stdlib.h>
 
/*
 * 
 */
int main(int argc, char** argv) {
    int i,j;
    char key[10];  
    //char *plainText=malloc(sizeof(char)*16);
    //scanf("%s",plainText);
    char *plainText="abdwqr,123456789";
    char *chiffreText=malloc(sizeof(char)*16); 
    char *z=malloc(sizeof(char)*16);
    char *a=malloc(sizeof(char)*37);
    
    
    SchluesselGenerieren(key);
    for(i=0;i<10;i++) 
        a[i]=key[i];
    for (i=0; i<16 ;i++)
    {
        z[i]=(a[i]+a[i+3])%256;
        a[i+10]=(a[i]^a[i+5]);//XOR
        for (j=0;j<5;j++)//Rotation >>> 5
        {
            if((a[i+10]%2)==0)//Rotation >>> 1
            {
                a[i+10]>>1;
                a[i+10]+=128;
            }else  a[i+10]>>1;  
        }
        chiffreText[i]=plainText[i]^z[i];//XOR
     //   printf("%d   %d = %d XOR %d \n",i,chiffreText[i], plainText[i], z[i]);
    }
    printf("\nKlartext   : ");
    for(i=0;i<16;i++)
        printf("%d ", plainText[i]);
    printf("\nChiffretext: ");
    for(i=0;i<16;i++)
        printf("%d ", chiffreText[i]);
    printf("\nZ          : ");
    for(i=0;i<16;i++)
        printf("%d ", z[i]);
    printf("\nSchlüsselA : ");
    for(i=0;i<26;i++)
        printf("%d ", a[i]);
    printf("\nSchlüssel  : ");
    for(i=0;i<10;i++)
        printf("%d ", key[i]);
    
    
 /*   free(a);
    free(z);
    free(plainText);
    free(chiffreText);*/
    
    
    
    return (EXIT_SUCCESS);
}



void SchluesselGenerieren(char key[]){
    int i;
    key[0]=0;
    for ( i=1;i<10;i++)
        key[i]=rand()%256;
}
    