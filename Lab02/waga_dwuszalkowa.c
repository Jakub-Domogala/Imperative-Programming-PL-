//Jakub Domogała
//100%

//Polecenie: Mamy dany zestaw n odważników o masach
// danych liczbami naturalnymi. Napisz program,
// który sprawdza, czy zadany ciężar w można zważyć przy
// pomocy wagi dwuszalkowej (czyli odważniki mogą być po obu stronach wagi).

//Wejście: Pierwszy wiersz standardowego wejścia zawiera dwie liczby naturalne 1 <= n <= 100 (liczba
//odważników, jakie mamy do dyspozycji) i 1 <= w <= 106
//(masa, jaką chcemy zważyć).
//W kolejnym wierszu znajduje się dokładnie n liczb naturalnych: masy poszczególnych
//odważników.

//Wyjście: W pierwszym i jedynym wierszu standardowego wyjścia powinien znajdować się napis YES
//jeżeli masę w można zważyć używając dowolnego podzbioru posiadanych odważników i
//napis NO w przeciwnym przypadku.

#include <stdio.h>
#include <malloc.h>
int abs(int n)
{
    if(n<0) { return -n;}
    return n;
}
int wagi(int t[], int w, int i, int wleft)
{
    if( w == 0) { return 1;}
    if( i == -1) { return 0;}
    if(wleft< abs(w)) { return 0;}
    return wagi(t, w - t[i], i - 1, wleft - t[i]) + wagi(t, w + t[i], i - 1, wleft - t[i]) + wagi(t, w, i - 1, wleft - t[i]);
}

int main()
{
    int n;
    scanf("%i", &n);
    int w;
    scanf("%i", &w);
    int*t = (int*)malloc(n*sizeof(int));
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        int pom;
        scanf("%i", &pom);
        sum += pom;
        if(pom == w) { printf("YES"); return 0;}
        t[i] = pom;
    }
    if( sum < w) { printf("NO"); return 0;}
    int res;
    res = wagi(t, w, n-1, sum);
    if( res >= 1) { printf("YES"); return 0; }
    else { printf("NO");}
    free(t);
    return 0;
}