//Jakub Domogała
//100%

//Polecenie: Napisz program, który dla zadanej liczby naturalnej n odpowiada na pytanie, czy liczba
//ta jest iloczynem dowolnych dwóch kolejnych wyrazów ciągu Fibonacciego. Zakładamy,
//że pierwsze dwa wyrazy ciągu Fibonacciego to 0 i 1.

//Wejście: Pierwszy i jedyny wiersz standardowego wejścia zawiera jedną liczbę naturalną 1 <= n <= 10^8.

//Wyjście: W pierwszym i jedynym wierszu standardowego wyjścia powinien znajdować się napis YES
//jeżeli liczba n jest iloczynem dowolnych dwóch kolejnych wyrazów ciągu Fibonacciego i
//napis NO w przeciwnym przypadku.


#include <stdio.h>

short isFibIl(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;
    while(b <= n)
    {
        if(n < a*b)
        { return 0;}
        if(n == a*b)
        { return 1;}
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    if(isFibIl(n) == 1)
    { printf("YES"); }
    if(isFibIl(n) == 0)
    { printf("NO"); }
    return 0;
}