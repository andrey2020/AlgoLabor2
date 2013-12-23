/*
 * File:   main.c
 * Author: anuta
 *
 * Created on 15. Dezember 2013, 01:14
 */

#include <stdio.h>
#include <stdlib.h>
#include "angreifer.h"
#include "crappy.h"
#include "angreifer2.h"


void PlainTextGenerieren(char* plainText){
    int i;
    int wahl;
    printf("Um Klartext als Text einzufügen, drücken Sie \"1\",\n"
            "um Klartext als Byte (Zahl zwischen 0 und 256) einzufügen, drücken Sie \"2\",\n"
            "um Standart-Klartext zu benutzen, drücken Sie \"3\"\n");
    scanf("%d", &wahl);
    switch (wahl)
    {
        case 1:
            printf("Fügen Sie bitte 16 Symbole ein. Benutzen Sie keine Leerzeichen. ");
            scanf("%16s", plainText);
        break;
        case 2:
            for(i=0;i<16;i++)
            {
                printf("Fügen Sie bitte %d. Byte ein: ", i);
                scanf("%d", &plainText[i]);
            }
        break;
        default:
            for(i=0;i<16;i++)
            {
                plainText[i]=(i*10+19);
            }
        break;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int i,j;
    char *plainText =malloc(sizeof(char)*17);
    char *chiffreText=malloc(sizeof(char)*17);
    char z[16];
    int wahl;

    PlainTextGenerieren(plainText);
    chiffreText=crappy(plainText);
    
//Jetzt beginnt Angreifer zu schachern
    printf("\n\nAngriff!!!\n\n");
    for (i=0; i<16 ;i++)
    {
        z[i]=chiffreText[i]^plainText[i];
    }
    
    printf("Um Angreifer Basis-Algorithmus (Backtracking) zu beutzen, drücken Sie \"1\",\n"
            "um schneller Angreifer-Algorithmus aus der Bonusaufgabe 1 zu benutzen, drücken Sie \"2\",\n");
    scanf("%d", &wahl);
    switch (wahl)
    {
        case 1:
              angreifer(z);//Basis-Algorithmus (Backtracking)
        break;
        default:
              angreifer2(z);//schneller Algorithmus aus der Bonusaufgabe 1
        break;
    }
       
    free(plainText);
    free(chiffreText);

    return (EXIT_SUCCESS);
}