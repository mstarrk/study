#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    for (int i = 1; i < 12; i++)
    {
        printf("%i\n", collatz(i));
    }
}

int collatz(int n)
{
    if (n == 1) return 0;

    if (n % 2 == 0) return 1 + collatz(n / 2);

    else return 1 + collatz(n * 3 + 1);
}