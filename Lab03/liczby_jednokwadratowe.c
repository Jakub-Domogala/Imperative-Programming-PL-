//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
short isPrime(int num)
{
    if(num == 1)
    { return 0; }
    if(num == 2)
    {return 1;}
    if(num%2 == 0)
    {return 0;}
    for(int i = 3; i*i <= num; i = i + 2)
    {
        if(num%i == 0)
        {return 0;}
    }
    return 1;
}


int squareSum(int num)
{
    int res = 0;
    while(num>0)
    {
        res += ((num%10)*(num%10));
        num /= 10;
    }
    return res;
}


short isOneSquare(int num)
{
    while(num != 1 && num != 4)
    {
        num = squareSum(num);
    }
    return num;
}


int main()
{
    int l, u, k, cnt = 0;
    scanf("%d %d %d", &l, &u, &k);
    for(int i = l; i <= u; i++)
    {
        if(isPrime(i) == isOneSquare(i))
        {
            cnt++;
            if(cnt == k)
            {
                printf("%d", i);
                return 0;
            }
        }
    }
    printf("%d", -1);
    return 0;
}
