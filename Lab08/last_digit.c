//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <math.h>

int main() {
    long long int S;
    scanf("%lld", &S);
    int n = floor(log10(S)) + 1;
    int num[n];
    for (int i=0; i<n; i++) num[i]=0;
    long long int res = 1;
    for (int i = 1; i < n; i++) res = res * 10 + 1;
    for (int i = 0; i < n; i++) {
        while (S - res >= 0) {
            S -= res;
            num[i]++;
            if (num[i] > 9) {
                printf("-1");
                return 0;
            }
        }
        res /= 10;
    }
    for (int i = 0; i < n; i++) {
        if (num[i] == 0 && i == 0) continue;
        printf("%d", num[i]);
    }
    return 0;
}

