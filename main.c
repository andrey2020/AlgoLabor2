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
    char key[10];
    SchluesselGenerieren(key);
    
    int i;
    

    char *plainText="1234";
    char *chiffreText;
    
    char *z;
    char *a;
    
        a=key;
    printf("qqqqqd");
    for (i=0;i< sizeof(plainText);i++)
    {
        z[i]=(a[i]+a[i+3])%256;
        a[i+10]=(a[i]^a[i+5]) >> 5;//XOR
        chiffreText[i]=plainText[i]^z[i];//XOR
        printf("%d = %d XOR %d \n",chiffreText[i], plainText[i], z[i]);
    }
    //system("PAUSE");
    return (EXIT_SUCCESS);
}


void SchluesselGenerieren(char key[]){
    int i;
    for ( i=0;i<10;i++)
        key[i]=rand()%256-128;
      
    
}

