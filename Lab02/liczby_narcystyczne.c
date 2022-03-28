//Jakub Domogała
//100%

//Polecenie:
//PDF

//Wejście: Pierwszy i jedyny wiersz standardowego wejścia zawiera dwie liczby naturalne 1 <= m <= 8
//(liczba cyfr szukanych liczb w układzie o podstawie b) i 2 <= b <= 16 (podstawa systemu
//liczenia).

//Wyjście: Pierwszy i jedyny wiersz standardowego wyjścia powinien zawierać znalezione liczby mnarcystyczne (wypisane w układzie o podstawie b) oddzielone znakiem spacji, lub napis
//NO jeżeli takich liczb nie ma. Dla liczb w systemach b > 10 dodatkowe cyfry powinny być
//zapisane jako kolejne duże litery alfabetu (A - F).



#include <stdio.h>
#include <stdbool.h>

int power(int n, int p)
{
    int res = 1;
    for( int i = 0; i < p; i++)
        res *= n;
    return res;
}

bool is_narc( int num, int sys, int len )
{
    int num_cpy = num;
    int sum = 0;
    int t;
    while (num)
    {
        t = num % sys;
        sum += power(t,len);
        num /= sys;
    }
    return sum == num_cpy;
}

void dec2sys( int val, int sys, int len )
{
    int res[len];
    int poz = len - 1;
    while (val > 0)
    {
        int tmp = val % sys;
        res[poz]= tmp;
        val /= sys;
        poz--;
    }

    for (int i=0;i < len; i++)
    {
        int tmp = res[i];
        if (tmp < 10)
        {
            printf("%d", tmp);
        }
        else
        {
            char chr =  tmp + 55;
            printf("%c", chr);
        }
    }
    printf(" ");
}

int main() {
    int m, sys;
    scanf("%d %d", &m, &sys);
    int maxv = power(sys, m);
    int minv = power(sys, m - 1) + 1;
    bool check = false;
    for (minv; minv < maxv; minv++) {
        if (is_narc(minv, sys, m)) {
            dec2sys(minv, sys, m);
            check = true;
        }
    }
    if (check == false) {
        printf("NO");
    }
}