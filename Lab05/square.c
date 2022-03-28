//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>



int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int t[n][n];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &t[i][j]);
            //printf("%d ", t[i][j]);
            sum += t[i][j];
        }
        //printf("\n");
    }

    if(sum < k)
    {
        printf("0");
        return 0;
    }

    int amount = 0, res[n*n][2];
    for(int size = 1; size < (n-1)/2 + 1; size++)
    {
        for (int i = size; i < n - size; i++)
        {
            for (int j = size; j < n - size; j++)
            {
                sum = 0;
                for(int x = i - size; x < i + size + 1; x++)
                {
                    sum = sum + t[x][j + size] + t[x][j - size];
                }
                for(int y = j - size + 1; y < j + size; y++)
                {
                    sum = sum + t[i + size][y] + t[i - size][y];
                }
                if(k == sum)
                {
                    res[amount][0] = i;
                    res[amount][1] = j;
                    //printf("git, pozdrawiam %d %d\n", i, j);
                    amount++;
                }
            }
        }
    }
    printf("%d", amount);
    for(int i = 0; i < amount; i++)
    {
        for(int j = 0; j < amount - 1; j++)
        {
            if(res[j][1]>res[j+1][1])
            {
                int p0, p1;
                p0 = res[j][0];
                p1 = res[j][1];
                res[j][0] = res[j+1][0];
                res[j][1] = res[j+1][1];
                res[j+1][0] = p0;
                res[j+1][1] = p1;
            }
        }
    }
    for(int i = 0; i < amount; i++)
    {
        for(int j = 0; j < amount - 1; j++)
        {
            if(res[j][0]>res[j+1][0])
            {
                int p0, p1;
                p0 = res[j][0];
                p1 = res[j][1];
                res[j][0] = res[j+1][0];
                res[j][1] = res[j+1][1];
                res[j+1][0] = p0;
                res[j+1][1] = p1;
            }
        }
    }

    for(int i = 0; i < amount; i++)
    {
        printf("\n%d %d", res[i][0], res[i][1]);
    }



    return 0;
}