
#include <stdio.h>
#include <stdlib.h>

char variant[256];
char z[17];

void recursion(int number, char* key){
    int k,j;
    char byte, temp;
/*
 * Backtracking - prüfen, ob z[i]=(a[i]+a[i+3])%256;
 */
    if (number > 3)
    {
        if (((key[number] + key[number-3]) % 256) != z[number-3])
            return;
    }
/*
 * Backtracking - prüfen, ob a[i+10]=(a[i]^a[i+5]);
 */
    if (number > 10)
    {
        byte=key[number-5]^key[number-10];
        //Rotation >>> 5
        temp = byte;                                    // a = temp = 87654321
        byte = temp % 20;                 //32 = 2^5       a = 54321
        byte = byte * 8;                  // 8 = 2^3       a = 54321000
        temp = temp / 20;                 // 32 = 2^5      temp = 876
        byte = byte ^ temp;                             // a = 54321876
        
        if (byte!=key[number])
            return;
    }
/*
 * Schlüssel ist komplett geprüft, 
 */
    if (number==16) 
    {
        printf("\nLösung     : ");
        for (j=0;j<10;j++)
        {
            printf("%d ", key[j]);
        }
        printf("\n");
        return;
    }
/*    
 * Rekursion fortsetzen 
 */ 
    number++;
    for(k=0;k<256;k++)
    {
        key[number]=k;
        recursion(number,key);
    }
}

void angreifer(char* zper)
{
    int i;
    char key[17]="";
    for (i=0;i<16;i++)
    {
        z[i]=zper[i];
    }
    recursion(0, key);
}
