//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>

int main() {
    short n;
    scanf("%d", &n);
    int tab[n*n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &tab[i*n+j]);
        }
    }
    int res[n*n];
    for(int i = 0; i < n*n; i++)
    {
        res[i] = -1;
    }
    int max = -1;
    for(int i = 0; i < n*n; i++)
    {
        if(tab[i] > max)
        {
            max = tab[i];
        }
    }
    int ind = 0;
    int bottom = -1;
    int new_min = tab[0];
    for(int i = 0; i < n*n; i++)
    {
        new_min = max;
        if(bottom == max)
        {
            break;
        }
        for(int j = 0; j < n*n; j++)
        {
            if(tab[j] > bottom && tab[j] < new_min)
            {
                new_min = tab[j];
            }
        }
        res[ind] = new_min;
        bottom = new_min;
        ind++;
    }
    for(int i = 0; i < n*n; i++)
    {
        if(res[i] != -1)
        {
            printf("%d ", res[i]);
        }
    }
    return 0;
}