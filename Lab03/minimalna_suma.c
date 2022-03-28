//Jakub Domogała
//100%

//Polecenie: Mamy daną tablicę A dodatnich liczb całkowitych o długości N,
// na której możemy wykonać co najwyżej K operacji.
// Operacja jest zdefiniowana następująco:
//1. Wybierz dowolny element tablicy A (A[i])
//2. Zastąp A[i] przez floor(A[i]/2)
//Proszę napisać program wyznaczający minimalną sumę elementów tablicy po wykonaniu
//na niej co najwyżej K operacji.

//Wejście: W pierwszym wierszu standardowego wejścia znajdują się dwie liczby całkowite N i K
//oznaczające odpowiednio długość tablicy A i maksymalną liczbę operacji. Kolejny wiersz
//zawiera N liczb całkowitych: wartości tablicy.

//Wyjście: Standardowe wyjście powinno zawierać jedną liczbę całkowitą:
// minimalną sumę elementów tablicy po wykonaniu co najwyżej K operacji.

#include <stdio.h>

int find_max(int t[], int n)
{
    int max = 0;
    for(int i = 1; i<n; i++)
    {
        if(t[max] < t[i])
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);
    int A[N];
    for(int i = 0; i < N; i++)
    {
        int p;
        scanf("%d", &p);
        A[i] = p;
    }
    for(int i = 0; i < K; i++)
    {
        int ind;
        ind = find_max(A,N);
        A[ind] = (A[ind]/2);
    }
    int res = 0;
    for(int i = 0; i < N; i++)
    {
        res += A[i];
    }
    printf("%d", res);

    return 0;
}