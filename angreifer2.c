#include <stdio.h>
#include <stdlib.h>

void angreifer2(char* z)
{
    int k, l, m, n;
    int passt=0;
    char byte, temp;
    char key[17]="";

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
                    //Rotation >>> 5
                    temp = byte;                                    // a = temp = 87654321
                    byte = temp % 20;                 //32 = 2^5       a = 54321
                    byte = byte * 8;                  // 8 = 2^3       a = 54321000
                    temp = temp / 20;                 // 32 = 2^5      temp = 876
                    byte = byte ^ temp;                             // a = 54321876
        
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
