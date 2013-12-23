
#include <stdio.h>
#include <stdlib.h>


char variant[256];
char z[17];

//hier kann die Lösung gespeichert werden
//es wäre gut, wenn hier ein halb-dynamisches Array wäre. Etwas wie z.B. *solution[11]
char solution[11][10];
int countSolution=0;

//Die Name von diese Funktion zeigt, was eigentlich bedeutet "Rekursion"
//Wenn jemand weiß bessere Name für diese Funktion, biete ich um die Umbenennung
void recursionWithTheMostBeautifulNameRecursionWithThe(int number, char* key){
    int k,j;
    char byte;
/*
 * Backtracking - prüfen, ob z[i]=(a[i]+a[i+3])%256;
 */
    if (number>3)
    {
        if (((key[number]+key[number-3])%256)!=z[number-3])
            return;
    }
/*
 * Backtracking - prüfen, ob a[i+10]=(a[i]^a[i+5]);
 */
    if (number>10)
    {
        byte=key[number-5]^key[number-10];
        //Rotation >>> 5
        for (j=0;j<5;j++)
        {
            //Rotation >>> 1
            if((byte%2)==1)
            {
                byte>>1;
                byte+=128;
            }else  byte>>1;
        }
        if (byte!=key[number])
            return;
    }
/*
 * Schlüssel ist komplett geprüft, 
 */
    if (number==16) 
                    //Müssen wir noch andere Lösungen suchen, nachdem wir schon eine gefunden haben?
                    //Jetzt sind alle mögliche Werte geprüft (egal, wie viel Lösungen schon gefunden sind)
    {
        printf("\nLösung     : ");
        for (j=0;j<10;j++)
        {
            //solution[countSolution][j]=key[j];
            printf("%d ", key[j]);
        }
        printf("\n");
        //countSolution++;
        return;
    }
/*    
 * Rekursion fortsetzen 
 */ 
    number++;
    for(k=0;k<256;k++)
    {
        key[number]=k;

        recursionWithTheMostBeautifulNameRecursionWithThe(number,key);
    }
}

void angreifer(char* zper)
{
    int i;
    char key[17]="";
    for (i=0;i<16;i++)//kann man das irgendwie ohne Schleifen machen?  Wie z.B. einfach z=zper
    {
        z[i]=zper[i];
    }

    recursionWithTheMostBeautifulNameRecursionWithThe(0, key);
}
