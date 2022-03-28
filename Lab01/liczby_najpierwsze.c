//Jakub Domogała
//100%

//Polecenie: Dana jest liczba całkowita dodatnia n. Napisz program, który znajduje wszystkie liczby
//pierwsze mniejsze od n, których cyfry tworzą ciąg niemalejący.

//Wejście: W pierwszym i jedynym wierszy standardowego wejścia znajduje się jedna dodatnia liczba
//naturalna n (n <= 10^8).

//Wyjście: W kolejnych wierszach standardowego wyjścia powinny znaleźć się w porządku rosnącym
//wszystkie liczby pierwsze, których cyfry tworzą ciąg niemalejący.



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

short forePrime(int num)
{
    int prev = 10;
    while(num > 0)
    {
        /*printf("%s ","cokolwiek");*/
        if(num%10 > prev)
        { return 0; }
        prev = num%10;
        num = num / 10;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        if(forePrime(i) == 1 && isPrime(i) == 1)
        {
            printf("%d\n", i);
        }
    }
}