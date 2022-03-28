//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>

void bin_len_n(dec, n)
{
    int t[n];
    for(int i = 0; i < n; i++)
    {
        t[i] = 0;
    }
    int i = n-1;
    while(dec > 0)
    {
        t[i] = dec%2;
        dec = dec/2;
        i--;
    }
    for(int j = 0; j < n; j++)
    {
        printf("%d", t[j]);
    }
}


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    long int i = 0;
    int cnt = 0;
    while(1)
    {
        int curr, prev;
        curr = prev = -1;
        int tmp = i, mark = 1;
        int size = 0;
        while(tmp > 0)
        {
            prev = curr;
            curr = tmp%2;
            tmp = tmp/2;
            if(prev == 1 && curr == 1)
            {
                mark = 0;
                break;
            }
            size++;
            if(size == n+1)
            {
                printf("-1");
                return 0;
            }
        }
        if(mark == 1)
        {
            cnt += 1;
        }
        if(cnt == k)
        {
            bin_len_n(i, n);
            return 0;
        }
        i++;
    }
    return 0;
}