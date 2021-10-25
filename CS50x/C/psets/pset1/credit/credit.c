#include <stdio.h>
#include <cs50.h>

// Credit Card validator

// Prototypes

void luhn(long);
void output(bool, int, int, int);

// Main

int main(void)
{
    long ccNumber = get_long("Number: ");
    luhn(ccNumber);
}

void luhn(long ccNumber)
{
    int digit = 0;

    int firstDigit = 0;
    int secondDigit = 0;

    int length = 0;

    int sum = 0;
    bool skip = true;

    while (ccNumber >= 1)
    {
        digit = ccNumber % 10;

        ccNumber /= 10;

        // Checking for first and second digit

        if (ccNumber < 10)
        {
            firstDigit = digit;
        }

        if (ccNumber > 9 && ccNumber < 100)
        {
            secondDigit = ccNumber % 10;
        }

        // Checking if this iteration should be skipped

        if (skip)
        {
            sum += digit;
        }

        else
        {
            // Multiply every other digit by 2

            digit *= 2;

            // If number has two digits

            if (digit > 9)
            {
                // Sum both

                sum += (digit / 10) + (digit % 10);
            }

            else
            {
                sum += digit;
            }
        }

        // me: mom can we have math.h?
        // mom: we have math.h at home
        // math.h at home:
        length++;

        // You are not you
        skip = !skip;
    };

    // Call output
    output(sum % 10 == 0, firstDigit, secondDigit, length);
}

void output(bool valid, int firstDigit, int secondDigit, int length)
{
    // Visa = starts with 4
    // MC = starts with 51, 52, 53, 54, or 55
    // AMEX = starts with 34 or 37

    if (!valid
        || (valid && !(firstDigit == 3 || firstDigit == 4 || firstDigit == 5))
        || !(length > 12 && length < 17) // Between 13 & 16 digits
       )
    {
        printf("INVALID\n");
        return;
    }

    if (firstDigit == 4)
    {
        printf("VISA\n");
        return;
    }

    if (firstDigit == 5 && (secondDigit > 0 && secondDigit < 6))
    {
        printf("MASTERCARD\n");
        return;
    }

    if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
    {
        printf("AMEX\n");
        return;
    }

    // Valid credit cards like Diners Club or MC starting with 22 will end up here 🤷️
    printf("INVALID\n");
}