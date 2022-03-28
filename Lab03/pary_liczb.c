//Jakub Domogała
//100%

//Treść: PDF


#include <stdio.h>
#include <stdlib.h>

int my_compare (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int* tab = (int*) calloc(n, sizeof(int));
    int i = 0;
    for(i;i<n;i++)
    {
        scanf("%d", &tab[i]);
    }
    qsort(tab, n, sizeof(int), my_compare);
    int counter = 0;
    for(i = 0; i<n;)
    {
        int repeats = 0;
        int j = i;
        while(j != n && tab[j] == tab[i])
        {
            j++;
            repeats++;
        }
        if(i != 0 && tab[i-1] + k >= tab[i])
        {
            counter += repeats;
        }
        else if(j != n && tab[j] - k <= tab[j-1])
        {
            counter += repeats;
        }

        i = j;

    }
    printf("%d", counter);
}