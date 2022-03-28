//Jakub Domogała
//100%

//Treść: PDF


#include <stdio.h>

int main() {
    short n;
    scanf("%d", &n);
    int tab[158], pom[158];
    for(int i = 0; i < 158; i++) tab[i] = 0, pom[i] = 0;
    tab[157] = 1;
    for(int j = 1; j <= n; j++)
    {
        for(int i = 157; i >= 0; i--)
        {
            pom[i] = tab[i] * j;
        }
        for(int i = 157; i >= 0; i--)
        {
            tab[i] = pom[i]%10;
            if (pom[i]/10 > 0)
            {
                pom[i-1] += pom[i]/10;
            }
        }
    }
    int i = 0;
    while(tab[i] == 0)
    {
        i++;
    }
    for(; i<158; i++)
    {
        printf("%d", tab[i]);
    }





    return 0;
}
