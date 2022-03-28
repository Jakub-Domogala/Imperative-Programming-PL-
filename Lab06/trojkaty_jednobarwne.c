//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>

int checkColor(int size, int t[size][2], int a, int b, int c)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        if(t[i][0] == a || t[i][0] == b || t[i][0] == c)
        {
            if(t[i][1] == a || t[i][1] == b || t[i][1] == c )
            {
                sum += 1;
            }
        }
    }
    return sum;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int t[m][2];
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &t[i][0], &t[i][1]);
        t[i][0] -= 1;
        t[i][1] -= 1;
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int l = j+1; l < n; l++)
            {
                int temp = 1;
                temp = checkColor(m, t, i, j, l);
                if(temp == 0 || temp == 3)
                {
                    res += 1;
                }

            }
        }
    }
    printf("%d", res);

    return 0;
}