//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int arab2roman(int x)
{
    int tmp = 0;
    char* l[]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char* m[]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char* s[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
    tmp = x/1000;
    while(tmp>0)
    {
        printf("M");
        tmp--;
    }
    x %= 1000;
    tmp = x/100;
    if (tmp>0) printf("%s",l[tmp-1]);
    x %= 100;
    tmp = x/10;
    if(tmp>0) printf("%s",m[tmp-1]);
    x %= 10;
    if (x>0) printf("%s",s[x-1]);
}

int roman2arab( char x[])
{
    char *letters = "IVXLCDM";
    int values[] = {1,5,10,50,100,500,1000};
    int n=strlen(x),res=0,prev;
    char tempx;
    for(int i=0;i<7;i++)
    {
        if(x[0]==letters[i])
        {
            res += values[i];
            prev = i;
        }
    }
    for (int i=1;i<n;i++)
    {
        tempx = x[i];
        for(int j=0;j<7;j++)
        {
            if (tempx==letters[j])
            {
                res += values[j];

                if (values[prev]<values[j])
                {
                    res -= 2*values[prev];
                }
                prev = j;
            }
        }
    }
    return res;
}

int main()
{
    char l1[20],l2[20];
    scanf("%s",&l1);
    scanf("%s",&l2);
    int ldec1,ldec2;
    ldec1 = roman2arab(l1);
    ldec2 = roman2arab(l2);
    arab2roman(ldec1+ldec2);
    return 0;
}