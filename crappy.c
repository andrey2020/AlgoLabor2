

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* crappy(char* plainText) {
    int i,j;
    char key[11]="0123456789";
    //char plainText[17]="1234123412341234";
    char chiffreText[17];
    char z[16];
    char a[36];
 
    SchluesselGenerieren(&key);
    
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
    
    
    return chiffreText;
}



void SchluesselGenerieren(char* key){
    int i;
    int wahl;
    printf("Um Schlüssel als Text einzufügen, drücken Sie \"1\",\n"
            "um Schlüssel als Byte (Zahl zwischen 0 und 256) einzufügen, drücken Sie \"2\",\n"
            "um random Schlüssel  zu benutzen, drücken Sie \"3\"\n"
            "um standart Schlüssel \"0123456789\" zu benutzen, drücken Sie \"4\"\n");
    scanf("%d", &wahl);
    switch (wahl)
    {
        case 1: 
            printf("Fügen Sie bitte 10 Symbole ein. Benutzen Sie keine Leerzeichen. ");
            scanf("%10s", key);//getc(plainText); //funktioniert mit Leerzeichen
        break;
        case 2: 
            for(i=0;i<10;i++)
            {
                printf("Fügen Sie bitte %d. Byte ein: ", i);
                scanf("%d", key[i]); //&
            }
        break;
        case 3:
          //  srand(time(NULL));
            for ( i=0;i<10;i++)
                key[i]=rand()%256;
        break;
        default:
        break; 
    }
    printf("\n");
}
    