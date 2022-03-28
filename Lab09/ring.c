//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <string.h>

int main()
{
    char word[50];
    scanf("%s", word);
    int n = strlen(word);
    int o = 0;
    int lowest_letters[n];
    int index_of_lowest = 1;
    lowest_letters[0] = o;
    int Primes[15]  = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for (int i = 1; i < n; ++i)
    {
        if (word[i] < word[o])
        {
            o = i;
            lowest_letters[0] = o;
            index_of_lowest = 1;
        }
        else if (word[i] == word[o])
        {
            lowest_letters[index_of_lowest] = i;
            index_of_lowest += 1;
        }
    }
    int remp = 2, rem, remo = lowest_letters[0], i1, i2;
    for (int i = 0; i < index_of_lowest; ++i)
    {
        rem = 0;
        int p = Primes[rem];
        o = lowest_letters[i];
        while (p < n)
        {
            for (int k = 0; k < n; ++k)
            {
                i1 = remp * k + remo;
                i2 = p * k + o;
                /*while (i1 >= n) i1 -= n;
                while (i2 >= n) i2 -= n;*/
                i1 = i1 % n;
                i2 = i2 % n;
                if (word[i1] > word[i2])
                {
                    remp = p;
                    remo = o;
                    break;
                }
                if (word[i1] < word[i2])
                {
                    break;
                }
            }
            p = Primes[rem];
            rem += 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        i1 = remp * i + remo;
        while (i1 >= n) i1 -= n;
        printf("%c", word[i1]);
    }
    return 0;
}