//Jakub Domogała
//100%

//Treść: PDF

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

bool check(int a,int b,int c,int d,int n, int T[n][n])
{
    for (int i = a;i<=c;i++)
    {
        for (int j = b;j<=d;j++)
        {
            if(T[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int T[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &T[i][j]);
        }
    }
    if (check(0,0,n-1,n-1,n,T))
    {
        int res = n*n;
        printf("%d",res);
        return 0;
    }

    int max_res=0,pole=0;
    for (int i =0; i<n; i++)
    {
        for (int j =0;j<n;j++)
        {
            for (int k = i;k<n;k++)
            {
                for( int l =j;l<n;l++)
                {
                    if(check(i,j,k,l,n,T))
                    {
                        pole = (abs(i-k)+1)*(abs(j-l)+1);
                        if(pole>max_res)
                        {
                            max_res = pole;
                        }
                    }
                }
            }
        }
    }
    printf("%d",max_res);
    return 0;
}