//Jakub Domogała
//100%

//Treść: PDF
#include <stdio.h>

int invertColor(int color)
{
    if(color == 1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int size = 200;
    int n;
    scanf("%d", &n);
    int t[2*size + 1][2*size + 1];
    for(int i = 0; i <= 2*size; i++)
    {
        for(int j = 0; j <= 2*size; j++)
        {
            t[i][j] = 0;
        }
    }
    for(int k = 0; k < n; k++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 += size;
        y1 += size;
        x2 += size;
        y2 += size;
        for(int i = x1; i < x2; i++)
        {
            for(int j = y1; j < y2; j++)
            {
                t[i][j] = invertColor(t[i][j]);
            }
        }
        for(int i = 0; i <= 2*size; i++)
        {
            for(int j = 0; j <= 2*size; j++)
            {
                //printf("%d", t[i][j]);
            }
        }
    }
    int res = 0;
    for(int i = 0; i <= 2*size; i++)
    {
        for(int j = 0; j <= 2*size; j++)
        {
            res += t[i][j];
        }
    }
    printf("%d", res);

    return 0;
}
