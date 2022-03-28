//Jakub Domogała
//100%

//Polecenie: Liczba doskonała jest to taka liczba naturalna, która jest sumą wszystkich swych dzielników właściwych (to znaczy od niej mniejszych). Najmniejszą liczbą doskonałą jest 6,
//ponieważ jej dzielnikami właściwymi są 1, 2, 3 i 1 + 2 + 3 = 6.
//Napisz program, który znajduje wszystkie liczby doskonałe w zadanym przedziale oraz
//ich liczbę.

//Wejście: Pierwszy i jedyny wiersz standardowego wejścia zawiera dwie liczby naturalne 1 <= m, n <= 10^8,
//będące odpowiednio początkiem i końcem przedziału.

//Wyjście: W pierwszym wierszu standardowego wyjścia powinna znaleźć się jedna liczba całkowita
//p: liczba znalezionych liczb doskonałych. Drugi wiersz zawiera dokładnie p liczb całkowitych:
//znalezione liczby doskonałe w porządku rosnącym.


#include <stdio.h>

short isPerf(int num)
{
    if(num == 1)
    { return 0; }
    int dzielSum = 1;
    for(int j = 2; j * j < num; j++)
    {
        if(dzielSum > num)
        { return 0; }

        if(num%j == 0)
        {
            dzielSum = dzielSum + j;
            if(j != num/j)
            {
                dzielSum = dzielSum + num/j;
            }
        }
    }
    if(dzielSum == num)
    { return 1; }
    return 0;
}

int main()
{
    int m;
    int n;
    scanf("%d", &m);
    scanf("%d", &n);
    if(m<0 || n<0 || m>n)
    {
        printf("%d\n", 0);
        return 0;
    }
    int total = 0;
    int tab[n-m+1];
    for(int i = m; i <= n; i++)
    {
        if(isPerf(i) == 1)
        {
            tab[total] = i;
            total++;
        }
    }

    printf("%d\n", total);

    for(int i = 0; i<total; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}