#include "minitalk.h"

int ft_num_len(int num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 2;
    }
    return len;
}

char *ft_dtob(int n)
{
    char *num;
    int len;

    len = ft_num_len(n);
    num = (char *)malloc(sizeof(char) * (len + 1));

    num[len] = '\0';
    while (n != 0)
    {
        num[len - 1] = n % 2 + 48;
        n = n / 2;
        len--;
    }
    return num;
}

void ft_send_binary(int pid, char c)
{
    char *buff;
    int i;

    buff = ft_dtob(c);

    if (strlen(buff) < 8)
    {
        buff = ft_add0(buff);
    }
    printf("%s\n", buff);
    i = 0;
    while (buff[i] != 0)
    {
        if (buff[i] == '1')
        {
            kill(pid, SIGUSR1);
            usleep(100);
        }
        else if (buff[i] == '0')
        {
            kill(pid, SIGUSR2);
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;
    char *buff;

    pid = ft_atoi(argv[1]);

    buff = strdup(argv[2]);

    i = 0;
    while (buff[i] != '\0')
    {
        ft_send_binary(pid, buff[i]);
        i++;
    }
}
