#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    for (int i = -3; i < 12; i++)
    {
        printf("%i\n", fact(i));
    }
}

int fact(int n)
{
    if (n <= 1)
        return n;

    else
        return n * fact(n - 1);
}