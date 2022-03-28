//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <math.h>

int semimulti(int n, int m)
{
    int max = pow(2, n), count = 0;
    for(int i = 1; i < max; i++)
    {
        if(i % m != 0)
        {
            for(int j = 0; j < n; j++)
            {
                int res = i ^ (1UL << j);
                if(res % m == 0 && res != 0)
                {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", semimulti(n, m));
    return 0;
}