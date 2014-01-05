

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SchluesselGenerieren(char* key){
    int i;
    int wahl;
    printf("Um Schlüssel als Text einzufügen, drücken Sie \"1\",\n"
            "um Schlüssel als Byte (Zahl zwischen 0 und 256) einzufügen, drücken Sie \"2\",\n"
            "um random Schlüssel  zu benutzen, drücken Sie \"3\"\n"
            "um standart Schlüssel '1','0','0','0','0','1','1','2','0','100'\" zu benutzen, drücken Sie \"4\"\n");
    scanf("%d", &wahl);
    switch (wahl)
    {
        case 1:
            printf("Fügen Sie bitte 10 Symbole ein. Benutzen Sie keine Leerzeichen. ");
            scanf("%10s", key);
        break;
        case 2:
            for(i=0;i<10;i++)
            {
                printf("Fügen Sie bitte %d. Byte ein: ", i);
                scanf("%d", &key[i]);
            }
        break;
        case 3:
            for ( i=0;i<10;i++)
                key[i]=rand()%256;
        break;
        default:
        break;
    }
    printf("\n");
}

/* Diese Funktion generiert den Chiffretext durch Ausführung
 * des Crappy-1-Ciphers.
 */
char* crappy(char* plainText) {
    int i,j;
    char key[11]={1,0,0,0,0,1,1,2,0,100};
    /* Da der Pointer am Ende der Funktion zurückgegeben wird und wir noch Zugriff
     * auf den Inhalt des character-Arrays haben möchten, muss das Array auf dem Heap,
     * nicht auf dem Stack erstellt werden. */
    char *chiffreText = malloc(sizeof(char)*17);
    char z[16];
    char a[10];
    char temp;

    SchluesselGenerieren(key);

    for(i=0;i<10;i++)
        a[i]=key[i];
    for (i=0; i<16 ;i++)
    {
        z[i]=(a[i%10]+a [(i+3)%10] ) % 256;
        a [(i+10)%10] = (a[i%10]^a [(i+5)%10] );
        //Rotation >>> 5
        temp = a[(i+10)%10];                              // a = temp = 87654321
        a[(i+10)%10] = temp % 20;         // 32 = 2^5        a = 54321
        a[(i+10)%10] = a[(i+10)%10] * 8;  // 8 = 2^3         a = 54321000
        temp = temp / 20;                 // 32 = 2^5        temp = 876
        a[(i+10)%10] = a[(i+10)%10] ^ temp;               // a = 54321876

        chiffreText[i]=plainText[i]^z[i];
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
    for(i=0;i<10;i++)
        printf("%d ",  a[i]);
    printf("\nSchlüssel  : ");
    for(i=0;i<10;i++)
        printf("%d ", key[i]);
    
    return chiffreText;
}
