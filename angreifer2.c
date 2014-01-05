#include <stdio.h>
#include <stdlib.h>

void angreifer2(char* z)
{
    int k,l,m,n,b;
    int passt=0;
    char byte;
    char key[17]="";
        
    //hier kann die Lösung gespeichert werden
    //es wäre gut, wenn hier ein halb-dynamisches Array wäre. Etwas wie z.B. *solution[11]
    char solution[11][10];
    int countSolution=0;

    for(k=0;k<256;k++)
    {
        key[0]=k;
        for(l=0;l<256;l++)
        {
            key[1]=l;
            for(m=0;m<256;m++)
            {
                key[2]=m;
                for (n=3;n<10;n++)
                {
                    key[n]=(z[n-3]-key[n-3])%256;
                }
                while ((n<19)&&(passt==0))
                {
                    key[n]=(z[n-3]-key[n-3])%256;
                    byte=key[n-5]^key[n-10];
                    for (b=0;b<5;b++)
                    {
                        if((byte%2)==1)
                        {
                            byte>>1;
                            byte+=128;
                        }else  byte>>1;
                    }
                    if (key[n]!=byte) 
                        passt=1;
                    n++;
                }
                if (passt==0)
                {
                    printf("\nLösung     : ");
                    for (n=0;n<10;n++)
                    {
                        printf("%d ", key[n]);
                    }
                    printf("\n");
                }else passt=0;
            }           
        }
    }
}
