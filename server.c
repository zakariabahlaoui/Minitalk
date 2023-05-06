#include "minitalk.h"

void ft_stock(int sig, char *buff)
{
    int len;

    if (buff[0] == 0)
    {
        len = 0;
    }
    else
    {
        len = ft_strlen(buff);
    }

    if (sig == 10)
        buff[len] = '1';
    else
        buff[len] = '0';
}

int ft_btod(char *buff)
{
    int len = ft_strlen(buff);
    int decimal = 0;
    int base = 1;
    int i = len - 1;
    while (i >= 0)
    {
        if (buff[i] == '1')
        {
            decimal += base;
        }
        base *= 2;
        i--;
    }

    return decimal;
}

void handle_sigusr(int sig)
{
    static char buff[9] = {0};
    int c;

    ft_stock(sig, buff);

    if (ft_strlen(buff) == 8)
    {
        c = ft_btod(buff);
        write(1, &c, 1);
        ft_memset(buff, 0, 9);
    }
}

int main()
{
    int pid;

    pid = getpid();
    printf("%d\n", pid);

    signal(SIGUSR1, &handle_sigusr);
    signal(SIGUSR2, &handle_sigusr);

    while (1)
    {
    }

    return 0;
}
