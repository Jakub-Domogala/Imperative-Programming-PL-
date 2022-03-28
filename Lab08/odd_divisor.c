//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
int main()
{
    unsigned long long int n, s = 0, j = 4, i = 1;
    scanf("%llu", &n);
    for(; i < 2000000000; i = i*2, j *= 4)
    {
        s = s + ((n + i - ((n + i) % (2*i)))*(n + i - ((n + i) % (2*i))) / j);
    }
    printf("%llu", s);
}