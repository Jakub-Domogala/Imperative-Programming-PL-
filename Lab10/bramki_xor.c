//Jakub Domogała
//100%

//Treść: PDF
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

int_fast8_t net_result(int lgates_amm, int model[lgates_amm][3], int inputs_amm, char start[inputs_amm], int last_gate)
{
    //printf("last gate = %d\n", last_gate);
    if(model[last_gate][2] != -1) return model[last_gate][2];
    int_fast8_t a, b;
    if(model[last_gate][0] < 0)
    {
        a = start[-model[last_gate][0]-1] - 48;
    }
    else
    {
        a = net_result(lgates_amm, model, inputs_amm, start, model[last_gate][0] - 1);
    }
    if(model[last_gate][1] < 0)
    {
        b = start[-model[last_gate][1]-1] - 48;
    }
    else
    {
        b = net_result(lgates_amm, model, inputs_amm, start, model[last_gate][1] - 1);
    }
    model[last_gate][2] = a^b;
    return model[last_gate][2];
}


void binAddOne(int len, char tmp[len])
{
    tmp[len - 1]++;
    int i = len - 1;
    while(tmp[i] == 50)
    {
        tmp[i] = 48;
        tmp[i - 1]++;
        i--;
    }
}


int main()
{
    int inputs_amm, lgates_amm, last_gate;
    scanf("%d %d %d", &inputs_amm, &lgates_amm, &last_gate);
    int model[lgates_amm][3];
    char start[inputs_amm], end[inputs_amm];
    for(int i = 0; i < lgates_amm; i++) model[i][2] = -1;
    for(int i = 0; i < lgates_amm; i++) for(int j = 0; j < 2; j++) scanf("%d", &model[i][j]);
    scanf("%s", &start);
    scanf("%s", &end);
    int counter = 0;
    for(; strcmp(start, end) < 0; binAddOne(inputs_amm, start))
    {
        //printf("start = %s\n", start);
        counter += net_result(lgates_amm, model, inputs_amm, start, last_gate - 1);
        for(int i = 0; i < lgates_amm; i++)
        {
            model[i][2] = -1;
        }
    }
    counter += net_result(lgates_amm, model, inputs_amm, start, last_gate - 1);
    printf("%d", counter);
}
