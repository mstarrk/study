m#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Prototypes

int getKey(string);
string toUppercase(string);
void encipher(string, int, char[]);
void getAlphabet(char[]);

int main(int argc, string argv[])
{
    // Check if there is not a correct amount of args

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get and validate key

    const int KEY = getKey(argv[1]);

    if (KEY == -1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get plaintext and encipher

    string plaintext = get_string("plaintext: ");

    char ciphertext[strlen(plaintext) + 1]; // +1 for null terminator

    ciphertext[strlen(plaintext)] = '\0';

    encipher(plaintext, KEY, ciphertext);

    // Output ciphertext

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Checking if every char in the argument is not a digit.
int getKey(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return -1;
        }
    }

    // Returning key converted to int.
    return atoi(key);
}

// Cipher text and save it in the referenced array.
void encipher(string text, int key, char cipher[])
{
    int length = strlen(text);
    char alphabet[27];
    getAlphabet(alphabet);

    for (int i = 0; i < length; i++)
    {
        // If not alpha, leave as it is and go to next iteration

        if (!isalpha(text[i]))
        {
            cipher[i] = text[i];
            continue;
        }

        // Converting to uppercase to make things easier.

        char letter = toupper(text[i]);

        // Finding letter's index in alphabet array.

        int index = 0;

        for (int j = 0; j < 26; j++)
        {
            if (letter == alphabet[j])
            {
                index = j;
                break;
            }
        }

        // Caesar formula will return the index of the letter in the alphabet.

        int result = (index + key) % 26;

        letter = alphabet[result];

        // Returning letter to lowercase if needed.

        if (islower(text[i]))
        {
            letter = tolower(letter);
        }

        cipher[i] = letter;
    }
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

// Fills a char[27] with alphabet letters (arr[0] to arr[25], arr[26] is used for null terminator)
void getAlphabet(char arr[])
{
    for (int i = 65, j = 0; i < 91; i++)
    {
        arr[j] = (char) i;
        j++;
    }

    arr[26] = '\0';
}