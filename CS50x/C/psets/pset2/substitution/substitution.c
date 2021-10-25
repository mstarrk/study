#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Prototypes

bool validateKey(string);
string toUppercase(string);
void cipherText(string, string, char[]);
void getAlphabet(char[]);

int main(int argc, string argv[])
{

    // Check if there is not a correct amount of args

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get key

    const string KEY = toUppercase(argv[1]);

    // Validate key

    if (!validateKey(KEY))
    {
        return 1;
    }

    // Get plaintext

    string plaintext = get_string("plaintext: ");

    // Encipher

    // +1 for null terminator
    char cipher[strlen(plaintext) + 1];

    cipher[strlen(plaintext)] = '\0';

    cipherText(plaintext, KEY, cipher);

    // Output ciphertext

    printf("ciphertext: %s\n", cipher);

    return 0;
}

bool validateKey(string key)
{
    int length = strlen(key);
    int sum = 0;

    // Validate length

    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }


    // The sum of all uppercase letters is equal to 2015

    for (int i = 0; i < length; i++)
    {
        // Sum values

        sum += key[i];

        // Check if char is not alphabetic.

        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    // If the values are not equal to 2015, then there is a repeated character.

    if (sum != 2015)
    {
        printf("Key must not contain repeated characters.\n");
        return false;
    }

    return true;
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

void cipherText(string text, string key, char arr[])
{
    int length = strlen(text);
    char alphabet[27];
    getAlphabet(alphabet);

    // Cipher text.
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char letter = toupper(text[i]);

            for (int j = 0; j < 26; j++)
            {
                // Comparing alphabet and key indexes to make the substitution
                if (alphabet[j] == letter)
                {
                    arr[i] = key[j];
                }
            }
        }

        // If it is not alphabetic, leave as it is.

        else
        {
            arr[i] = text[i];
        };

        // Check for lowercase and return them back

        if (islower(text[i]))
        {
            arr[i] = tolower(arr[i]);
        }
    }
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