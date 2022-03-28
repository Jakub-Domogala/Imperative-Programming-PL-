//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <math.h>
//1 1 1 0 -1 -1 -1 0
//-1 0 1 1 1 0 -1 -1

int main()
{
    int n, k;
    int Imoves[] = {1,1,1,0,-1,-1,-1,0};
    int Jmoves[] = {-1,0,1,1,1,0,-1,-1};
    scanf("%d %d", &n, &k);
    int t[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &t[i][j]);
            //printf("%d ", t[i][j]);
        }
        //printf("\n");
    }
    int maxsum = -INFINITY;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int move = 0; move < 8; move++)
            {
                int x = i;
                int y = j;
                int tmpSum = 0;
                for(int l = 0; l < k; l++)
                {


                    tmpSum += t[x][y];
                    x += Imoves[move];
                    y += Jmoves[move];
                    if(x == n) x = 0;
                    if(x == -1) x = n - 1;
                    if(y == n) y = 0;
                    if(y == -1) y = n - 1;
                }
                if(maxsum < tmpSum) maxsum = tmpSum;
            }
        }
    }
    printf("%d", maxsum);
}