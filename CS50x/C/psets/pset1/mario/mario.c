#include <stdio.h>
#include <cs50.h>

// Prototypes

void printPyramid(int);
void printBlock(int);

// Print a pyramid with a height determined by the user.

int main(void)
{
    //Prompt for height

    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print pyramid

    printPyramid(height);
}

void printPyramid(int height)
{
    int spaces = height - 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        printBlock(i + 1);

        printf("  ");

        printBlock(i + 1);

        printf("\n");
        spaces--;
    }
}

// Print # the specified amount of times.

void printBlock(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}