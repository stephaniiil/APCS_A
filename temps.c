// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define NUM_CITIES 10 // constant with value of 10

typedef struct // struct with two members
{
    string city; // name of city
    int temp; // average temperature of city
} avg_temp;

avg_temp temps[NUM_CITIES]; // array of avg_temp structures

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp); // print sorted list
    }
}

void sort_cities(void)
{
    for (int i = 0; i < NUM_CITIES - 1; i++) // loop every city
    {
        for (int k = i + 1; k < NUM_CITIES; k++) // loop every other city
        {
            if (temps[i].temp < temps[k].temp) // if temperature of current city is smaller than temperature of other city
            {
                avg_temp placeholder = temps[i]; // swap using placeholder variable
                temps[i] = temps[k];
                temps[k] = placeholder;
            }
            else if (temps[i].temp == temps[k].temp && // if temperature of current city is equal to temperature of other city
                     strcmp(temps[i].city, temps[k].city) > 0) // alphabetical order is wrong
            {
                avg_temp placeholder = temps[i]; // swap using placeholder variable
                temps[i] = temps[k];
                temps[k] = placeholder;
            }
        }
    }
}
