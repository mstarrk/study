#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototypes

void analyzeString(string);
string toUppercase(string);
float calcGrade(void);
void output(int grade);

// Global vars

int letters = 0;
int words = 0;
int sentences = 0;

int main(void)
{
    string text = get_string("Text: ");

    analyzeString(text);

    int grade = calcGrade();

    output(grade);
}

void analyzeString(string s)
{

    s = toUppercase(s);

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Count letters

        if (isalpha(s[i]))
        {
            letters++;

        }

        // Count words

        if (isspace(s[i]))
        {
            words++;

        }

        // Count sentences

        if (s[i] == '!' || s[i] == '?' || s[i] == '.')
        {
            sentences++;

        }
    }

    // Counting the last word 🤷

    words++;
}

string toUppercase(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
    }

    return s;
}

float calcGrade()
{
    // AVG letters per 100 words

    const float L = letters / (float) words * 100;

    // AVG sentences per 100 words

    const float S = sentences / (float) words * 100;

    // Coleman-Liau Index

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the result to the nearest integer

    return roundf(index);
}

void output(int grade)
{

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return;
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");
        return;
    }

    printf("Grade %i\n", grade);
}
