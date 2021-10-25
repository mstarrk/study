#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string toUppercase(string s);
void printWinner(int scores[]);

int main(void)
{
    // Get input words from both players

    string words[2];

    for (int i = 0; i < 2; i++)
    {
        words[i] = get_string("Player %i: ", i + 1);
    }

    // Score both words

    int scores[2];

    for (int i = 0; i < 2; i++)
    {
        scores[i] = compute_score(words[i]);
    }

    // Print the winner

    printWinner(scores);
}

int compute_score(string word)
{
    int score = 0;

    // Word to upper.

    word = toUppercase(word);

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // If it is a letter

        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            // Determine letter score (word[i] - 'A') and add it to the sum
            score += POINTS[word[i] - 'A'];
        }
    }

    return score;
}

// Converts an string to uppercase
string toUppercase(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
    }

    return s;
}

void printWinner(int scores[])
{
    if (scores[0] > scores[1])
    {
        printf("Player 1 wins!\n");
        return;
    }

    else if (scores[1] > scores[0])
    {
        printf("Player 2 wins!\n");
        return;
    }

    printf("Tie!\n");
}
