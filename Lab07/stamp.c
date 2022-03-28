//Jakub Domogała
//100%

//Treść: PDF


#include <stdio.h>
#include <math.h>
int main()
{
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    int t[n][n], p[k][l], maxsum = -INFINITY;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &t[i][j]); // wczytywanie t
    for(int i = 0; i < k; i++) for(int j = 0; j < l; j++) scanf("%d", &p[i][j]); // wczytywanie p
    for(int i = 0; i < n - k + 1; i++) for(int j = 0; j < n - l + 1; j++)
        {
            int tmpsum = 0;
            for(int x = i; x < i+k; x++) for (int y = j; y < j + l; y++) if(p[x - i][y - j] == 1) tmpsum += t[x][y];
            if(maxsum < tmpsum) maxsum = tmpsum;
        }
    printf("%d", maxsum);
}
