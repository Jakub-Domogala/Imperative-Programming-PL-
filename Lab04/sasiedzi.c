//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    int tab[n][n];
    int res[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tab[i][j]);
            //printf("%d ", tab[i][j]);
        }
        //printf("\n");
    }
    int si, ei, sj, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i-r < 0) si = 0;
            else si = i-r;
            if(i+r >= n) ei = n-1;
            else ei = i+r;
            if(j-r < 0) sj = 0;
            else sj = j-r;
            if(j+r >= n) ej = n-1;
            else ej = j+r;
            int sum = 0;
            for(int ii = si; ii <= ei; ii++)
            {
                for(int jj = sj; jj <= ej; jj++)
                {
                    sum += tab[ii][jj];
                }
            }
            res[i][j] = sum;

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}