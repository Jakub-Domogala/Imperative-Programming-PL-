//Jakub Domogała
//100%

//Treść: PDF
#include <stdio.h>
#include <stdlib.h>


void right(int * T, int i) {
    T[i] += 1;
    T[i - 1] -= 1;
    T[i - 2] -= 1;
}

void two(int * T, int i) {
    T[i] -= 2;
    T[i - 2] += 1;
    T[i + 1] += 1;
}

void three(int *T, int i) {
    T[i] -= 3;
    T[i - 2] += 1;
    T[i + 2] += 1;
}

void seven(int *T, int i) {
    T[i] -= 7;
    T[i - 4] += 1;
    T[i + 4] += 1;
}

void eighting(int *T, int i) {
    T[i] -= 18;
    T[i - 6] += 1;
    T[i + 6] += 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int **p = malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++) p[i] = malloc(sizeof (int) * 2);
    for(int i = 0; i < n; i++) scanf("%d %d", &p[i][0], &p[i][1]);
    int max = p[0][0];
    for(int i = 0; i < n; i++) if(p[i][0] > max) max = p[i][0];
    int size = max + 80, shift = - 40;
    int * T = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) T[i] = 0;
    for(int i = 0; i < n; i++) T[p[i][0] - shift] = p[i][1];
    int check = 0;
    while(1) {
        for (int i = 2; i < size; i++) {
            while (T[i - 2] > 0 && T[i - 1] > 0) {
                right(T, i);
                check = 1;
            }
            while (T[i] >= 18) {
                eighting(T, i);
                check = 1;
            }
            while (T[i] >= 7){
                seven(T, i);
                check = 1;
            }
            while (T[i] >= 3) {
                three(T, i);
                check = 1;
            }
            while (T[i] >= 2){
                two(T, i);
                check = 1;
            }
        }
        if(check == 0)
            break;
        else
            check = 0;
    }
    for(int i = 0; i < size; i ++) {
        if(T[i] != 0)
            printf("%d ", i + shift);
    }
    return 0;
}
