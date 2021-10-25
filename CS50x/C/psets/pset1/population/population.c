#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size

    int startSize;

    do
    {
        startSize = get_int("Start size (must be equal or greater than 9): ");
    }
    while (startSize < 9);

    // Prompt for end size

    int endSize;

    do
    {
        endSize = get_int("End size (must be greater than the start size): ");
    }
    while (endSize < startSize);

    // Calculate number of years until we reach threshold

    int newbornLlamas;

    int deceasedLlamas;

    int years = 0;
    int population = startSize;

    if (startSize != endSize)
    {
        do
        {
            deceasedLlamas = population / 4;

            newbornLlamas = population / 3;

            population = population + newbornLlamas - deceasedLlamas;
            years++;
        }
        while (population < endSize);
    }

    // Print number of years

    printf("Years: %i\n", years);

}