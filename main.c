/* 
 * File:   main.c
 * Author: anuta
 *
 * Created on 15. Dezember 2013, 01:14
 */

#include <stdio.h>
#include <stdlib.h>
extern char* crappy();
extern void angreifer();


int main(int argc, char** argv) {
    int i,j; 
    char plainText[17]="1234123412341234";
    char chiffreText[17];
    char z[16];
    char a[36];
    char key[11];
    
    PlainTextGenerieren(&plainText);
    *chiffreText=crappy(&plainText);
    //key=angreifer(&plainText, &chiffreText);
    
    
    //Jetzt weiß ich nur chiffreText und plainText
    for (i=0; i<16 ;i++)
    {
        z[i]=chiffreText[i]^plainText[i];
    }
    
    //key=angreifer(&z);
    
    return (EXIT_SUCCESS);
}

void PlainTextGenerieren(char* plainText){
    int i;
    int wahl;
    printf("Um Klartext als Text einzufügen, drücken Sie \"1\",\n"
            "um Klartext als Byte (Zahl zwischen 0 und 256) einzufügen, drücken Sie \"2\",\n"
            "um Klartext \"1234123412341234\" zu benutzen, drücken Sie \"3\"\n");
    scanf("%d", &wahl);
    switch (wahl)
    {
        case 1: 
            printf("Fügen Sie bitte 16 Symbole ein. Benutzen Sie keine Leerzeichen. ");
            scanf("%16s", plainText);//getc(plainText); //funktioniert mit Leerzeichen
        break;
        case 2: 
            for(i=0;i<16;i++)
            {
                printf("Fügen Sie bitte %d. Byte ein: ", i);
                scanf("%d", &plainText[i]); 
            }
        break;
        default:
        break;    
    }
    printf("\n");
}
