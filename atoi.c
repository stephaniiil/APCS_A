#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i])) // check for digit
        {
            printf("Invalid Input!\n");
            return 1; // exit program
        }
    }

    printf("%i\n", convert(input)); // convert string to integer
}

int convert(string input)
{
    if (input[0] == '\0') // check for null
    {
        return 0; // break
    }
    int digit = input[strlen(input) - 1] - '0'; // convert last digit to integer
    input[strlen(input) - 1] = '\0'; // set last digit to null
    return digit + convert(input) * 10; // process remaining string
}
