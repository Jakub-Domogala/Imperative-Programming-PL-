//Jakub Domogała
//100%

//Polecenie: Napisz program, który przyjmuję tablicę liczb naturalnych i zwraca taki indeks, że sumy
//wartości elementów tablicy na lewo i na prawo od wyznaczonego miejsca są równe. Można
//założyć, że rozwiązanie istnieje.

//Wejście: W pierwszym wierszu standardowego wejścia znajduje się jedna dodatnia liczba całkowita
//1 <= n <= 1000 oznaczająca liczbę elementów tablicy. Kolejny wiersz zawiera dokładnie n
//liczb całkowitych - elementy tablicy.

//Wyjście: Na standardowym wyjściu programu powinna znaleźć się jedna liczba - indeks elementu
//dzielącego tablicę na dwie części o równych sumach.

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int t[n];
    int element;
    int rsum = 0;
    for(short i = 0; i<n; i++)
    {
        scanf("%d", &element);
        t[i] = element;
        if(i>0)
        {
            rsum = rsum + element;
        }
    }
    int lsum = 0;
    for(short i = 0; i<n; i++)
    {
        if(lsum == rsum)
        { printf("%d", i); break;}
        if(i<n-1)
        {
            lsum = lsum + t[i];
            rsum = rsum - t[i+1];
        }
    }

    return 0;
}