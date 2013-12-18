
#include <stdio.h>
#include <stdlib.h>


char variant[256];
char z[17];
char solution[11][10];



void angreifer(char* zper)
{
    int i;
    char a[36];
    char key[17]="";
    
    for (i=0;i<16;i++)
    {
        z[i]=zper[i];
    }
    
    for (i=0;i<256;i++)//Array von alle mögliche Byten
    {
        variant[i]=i;
    }
    
    rekyr(0, key);
    
}


void rekyr(int nomer, char* key){
    int k,l,j;
    int anzahlSolution=0;
    char byte;
    
    if (nomer>3)
    {
        if (((key[nomer]+key[nomer-3])%256)!=z[nomer-3])
            return;
    }
    
    if (nomer>10)
    {
        byte=key[nomer-5]^key[nomer-10];
        for (j=0;j<5;j++)//Rotation >>> 5
        {
            if((byte%2)==1)//Rotation >>> 1
            {
                byte>>1;
                byte+=128;
            }else  byte>>1;  
        }  
        if (byte!=key[nomer])
            return;        
    }
    
    if (nomer==16)
    {
        printf("\nLösung     : ");
        for (j=0;j<10;j++)
        {
            if (anzahlSolution>=10) return;
            solution[anzahlSolution][j]=key[j];
            printf("%d ", key[j]);
        }
        printf("\n");
        anzahlSolution++;
        return;
    }
    nomer++;
    for(k=0;k<256;k++)
    {
        key[nomer]=variant[k];
        
        rekyr(nomer,key);
    }
}


