//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <math.h>

void binary(int a, int aux_tab[][30], int i)
{
    for (int j=29; j>=0; j--)
    {
        aux_tab[i][j] = a%2;
        a /= 2;
    }
}


int main()
{
    int n, g;
    scanf("%d %d", &n, &g);
    int aux_tab[n+1][30];
    binary(g, aux_tab, 0);
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        binary(tmp, aux_tab, i);

    }

    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            printf("%d", aux_tab[i][j]);
        }
        printf("\n");
    }*/
    int min = n;
    for(int a = 0; a < 30; a++)
    {
        int tmp = 0;
        if(aux_tab[0][a] == 1) // gdy liczba docelowa ma w bin jedynke w danym miejscu
        {
            for(int i = 1; i <= n; i++) // przeszukujemy całą kolumne tych miejsc z liczb w naszej tablicy danych
            {
                if(aux_tab[i][a] == 1) // gdy znajdziemy na jakimś z tych miejsc jedynkę to przeszukujemy cały wiersz danej liczby
                {
                    int check = 1;
                    for(int j = 0; j < 30; j++) // gdy dana liczba ma jedynke gdzie docelowa jej nie ma to wychodzimy z pętli
                    {
                        if(aux_tab[i][j] > aux_tab[0][j])
                        {
                            check = 0;
                            break;
                        }
                    }
                    if(check == 1) tmp++;
                    if(tmp > min) break;
                }
            }
        }
        if(tmp < min && aux_tab[0][a] == 1) min = tmp;
    }
    printf("%d", min);
}

