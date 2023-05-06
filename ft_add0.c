#include "minitalk.h"

char *ft_add0(char *buff)
{
    int i = 0;
    int j;
    char *buff2;

    buff2 = (char *)malloc(sizeof(char) * 9);
    int r = 8 - strlen(buff);

    while (i < r)
    {
        buff2[i] = '0';
        i++;
    }
    j = 0;
    while (j < strlen(buff))
    {
        buff2[i] = buff[j];
        i++;
        j++;
    }
    return buff2;
}
