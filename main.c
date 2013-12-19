/*
 * File:   main.c
 * Author: anuta
 *
 * Created on 15. Dezember 2013, 01:14
 */

//Es ist noch ganz nicht Ideal, aber alles, was im Hauptteil des Projekts beschrieben ist, funktioniert. Ich denke. Ich hoffe. Meiner Meiung nach.
//Wenn jemand etwas ändernn möchtet, ich wäre froh

#include <stdio.h>
#include <stdlib.h>
#include "angreifer.h"
#include "crappy.h"


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

int main(int argc, char** argv) {
    int i,j;
    char *plainText ="2234123412341234";
    char *chiffreText=malloc(sizeof(char)*17);
    char z[16];
    char a[36];
    char key[11];

    PlainTextGenerieren(plainText);
    chiffreText=crappy(plainText);
    
//Jetzt beginnt Angreifer zu schachern
    for (i=0; i<16 ;i++)
    {
        z[i]=chiffreText[i]^plainText[i];
    }
    printf("\n");
    angreifer(z);

        //Muss Speicherplatz freigegeben wird?
 /*   free(a);
  *   free(z);
  *   free(key);
  */
    
    return (EXIT_SUCCESS);
}