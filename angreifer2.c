
#include <stdio.h>
#include <stdlib.h>


//Die Name von diese Funktion zeigt, was eigentlich bedeutet "Rekursion"
//Wenn jemand weiß bessere Name für diese Funktion, biete ich um die Umbenennung

void angreifer2(char* z)
{
    int k,l,m,n,j;
    int i;
    int passt=0;
    char byte;
    char key[17]="";
    char solution[11][10];//es wäre gut, wenn hier ein halb-dynamisches Array wäre. Etwas wie z.B. *solution[11]
    int countSolution=0;
    //char z[17];

    for(i=0;i<256;i++)
    {
        key[0]=i;
        for(j=0;j<256;j++)
        {
            key[1]=j;
            for(k=0;k<256;k++)
            {
                key[2]=k;
                for (l=3;l<10;l++)
                {
                    key[l]=(z[l-3]-key[l-3])%256;
                }
                while ((l<16)&&(passt==0))
                {
                    key[l]=(z[l-3]-key[l-3])%256;
                    byte=key[l-5]^key[l-10];
                    for (m=0;m<5;m++)
                    {
                        if((byte%2)==1)
                        {
                            byte>>1;
                            byte+=128;
                        }else  byte>>1;
                    }
                    if (key[l]!=byte) 
                        passt=1;
                    l++;
                }
                if ((l==16)&&(passt==0))
                {
                    printf("\nLösung     : ");
                    for (l=0;l<10;l++)
                    {
                        printf("%d ", key[l]);
                    }
                    printf("\n");
                }else passt=0;
            }           
        }
    }
}
