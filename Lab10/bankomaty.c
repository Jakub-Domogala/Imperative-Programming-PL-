//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <stdint.h>
#include <string.h>
int check_if_empty(int bin[100])
{
    for(int i = 0; i < 100; i++)
    {
        if(bin[i] > 0) return 0;
    }
    return 1;
}


int addbin(int_fast8_t bin[100], int ind)
{
    bin[ind]++;
    while(bin[ind] > 1)
    {
        //for(int j = 0; j < 100; j++) printf("%d", bin[j]); printf(" ADD\n");
        bin[ind] = 0;
        bin[ind-1]++;
        ind--;
        if(ind == 0 && bin[ind] > 1) return -1;
    }
    return 0;
}


int subbin(int_fast8_t bin[100], int ind)
{
    bin[ind] = 0;
    //for(int j = 0; j < 100; j++) printf("%d", bin[j]); printf(" SUB\n");
    return 0;
}


void divide_tab_by_2(int num[30])
{
    int tmp = 0, rest;
    for(int i = 0; i < 30; i++)
    {
        tmp = tmp*10 + num[i];
        if(tmp >= 2)
        {
            num[i] = tmp/2;
            tmp = tmp%2;
        }
        else
        {
            num[i] = 0;
        }
    }
}


int main()
{
    char tmp[30];
    scanf("%s", &tmp);
    int_fast8_t tmps = strlen(tmp) - 1, tmp1 = 29;
    int num[30];
    for(int i = 0; i < 30; i++) num[i] = 0;
    for(int i = tmps; i >= 0; i--, tmp1--) num[tmp1] = tmp[i]-48;
    //for(int i = 0; i < 30; i++) printf("%d", num[i]); printf("\n");
    int_fast8_t binadd[100];
    int_fast8_t binsub[100];
    int_fast8_t resadd[100];
    int_fast8_t ressub[100];
    short cadd = 1, csub = 1;
    int indadd = 0, indsub = 0;
    for(int i = 0; i < 100; i++) binadd[i] = 0;
    for(int i = 0; i < 100; i++) binsub[i] = 0;
    for(int i = 0; i < 100; i++) resadd[i] = -1;
    for(int i = 0; i < 100; i++) ressub[i] = -1;
    for(int i = 99; i >= 0; i--)
    {
        binadd[i] = num[29]%2;
        binsub[i] = num[29]%2;
        divide_tab_by_2(num);
    }
    for(int i = 99; i >= 0; i--)
    {
        if(binadd[i] == 1)//gdy znajdziemy jedynke w ciągu binarnym
        {
            //printf("%d\n", 99-i);
            resadd[indadd] = 99-i;
            indadd++;
            //for(int j = 0; j < 100; j++) printf("%d", binadd[j]); printf("\n");
            if(i%2 == 1) //jeśli jest bankomat parzysty będziemy dodawać
            {
                if(addbin(binadd, i) == -1) //gdy wyjdziemy poza listę przerywamy
                {
                    cadd = 0;
                    break;

                }
            }
            else
            {
                subbin(binadd, i);
            }
            if(check_if_empty(binadd) == 1) break;
        }
    }
    for(int i = 99; i >= 0; i--)
    {
        if(binsub[i] == 1)//gdy znajdziemy jedynke w ciągu binarnym
        {
            //printf("%d\n", 99-i);
            ressub[indsub] = 99-i;
            indsub++;
            //for(int j = 0; j < 100; j++) printf("%d", binadd[j]); printf("\n");
            if(i == 0) { csub = 0; break;}
            if(i%2 == 0) //jeśli jest bankomat parzysty będziemy dodawać
            {
                if(addbin(binsub, i) == -1) //gdy wyjdziemy poza listę przerywamy
                {
                    csub = 0;
                    break;
                }
            }
            else
            {
                subbin(binsub, i);
            }
            if(check_if_empty(binsub) == 1) break;
        }
    }
    //for(int i = 0; i < 100; i++) printf("%d", binadd[i]);
    //printf("\n");
    int i = 0;
    if(csub == 1) {
        while (ressub[i] != -1) {
            printf("%d ", ressub[i]);
            i++;
        }
        i = 0;
    } else { printf("NO");}
    printf("\n");
    if(cadd == 1) {
        while (resadd[i] != -1) {
            printf("%d ", resadd[i]);
            i++;
        }
    } else { printf("NO");}


    return 0;
}