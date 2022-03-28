//Jakub Domogała
//100%

//Treść: PDF

#include <stdio.h>
#include <string.h>

int next_highest(char string[], int index, int length_of_str)
{
    char highest = string[index];
    for (int i = index; i < length_of_str; i++) if(highest < string[i])
        {
            highest = string[i];
            index = i;
        }
    return index;
}

int main()
{
    char string[51];
    char substring[51];
    int length;
    scanf("%s", &string);
    length = strlen(string);
    int i = 0, sub_ind = 0, current, counter = 0;
    while (i < length)
    {
        current = next_highest(string, i, length);
        counter += 1;
        i = current + 1;
        substring[sub_ind] = string[current];
        sub_ind+=1;
    }
    for(int a=0;a<counter;a++)
    {
        printf("%c",substring[a]);
    }
    return 0;
}
