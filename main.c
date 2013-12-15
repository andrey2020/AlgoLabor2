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
    char key[20];
    int i;
    
    for ( i=0;i<10;i++) key[i]=rand()%256-128;
 
    

    char *plainText;
    //plainText = malloc(sizeof(char)*2);
   // plainText = "gsdfsfsdfsdfsfdfsdf";
    plainText[0] = "f";
    plainText[1] = "f";
    plainText[2] = "h";
     //char plainText[10];// = {"f","f","f"};
    //gets(plainText);
    printf("%d \n",sizeof(*plainText));

    char *chiffreText = malloc(sizeof( char ));
    
    char *z = malloc(sizeof( char ));
    //char *a = malloc( sizeof ( char ) );
    
    
    
    for (i=0;i< sizeof(plainText);i++)
    {
        z[i]=(key[i]+key[i+3])%256;
        key[i+10]=(key[i]^key[i+5]) >> 5;//XOR
        chiffreText[i]=plainText[i]^z[i];//XOR
       // printf("%d = %d XOR %d \n",chiffreText[i], plainText[i], z[i]);
    }
    printf("%s \n",chiffreText);
    printf("%d \n",sizeof(chiffreText));
    //system("PAUSE");
    return (EXIT_SUCCESS);
}