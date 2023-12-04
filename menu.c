#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int *readFile(string name, int size, int size2); // read integers from a file into an array based on the specified file name and size
void linear_search(int option[], int size); // search for number within an array using linear search and print index
void binary_search(int option[], int size); // search for number within an array using binary search and print index
void selection_sort(int option[], int size); // sort an array in ascending order using selection algorithm and print sorted list
void bubble_sort(int option[], int size); // sort an array in ascending order using bubble algorithm and print sorted list
void calcTime(void (*func)(int[], int), int option[], int size); // measure execution time of a specified function on an array and print time taken

int main(void)
{
    int choice = 0;
    while (choice != 5)
    {
        do
        {
            printf("==========================================\n");
            printf("#                  MENU                  #\n");
            printf("#   1. Search for a number with linear   #\n");
            printf("#   2. Search for a number with binary   #\n");
            printf("#   3. Sort the list with selection      #\n");
            printf("#   4. Sort the list with bubble         #\n");
            printf("#   5. Exit                              #\n");
            printf("==========================================\n");
            choice = get_int("Enter choice number: "); // menu choice
        }
        while (choice < 1 || choice > 5);

        if (choice == 5)
        {
            printf("Thank you! \n");
            return -1; // exit program
        }

        int size;
        do
        {
            size = get_int("Enter 5000, 10000, or 50000 for desired size: "); // get file size
        }
        while (size != 5000 && size != 10000 && size != 50000); // file size can only be 5000, 10000, or 50000

        char name[17];
        int *option = 0;
        if (choice != 2)
        {
            sprintf(name, "random%i.txt", size); // create file name using "random" and size
            option = readFile(name, size, 5); // read file
        }
        else if (choice == 2)
        {
            sprintf(name, "reversed%i.txt", size); // create file name using "reversed" and size
            option = readFile(name, size, 5); // read file
        }

        switch (choice) // switch for choice
        {
            case 1:
                calcTime(linear_search, option, size); // linear search
                break;
            case 2:
                calcTime(binary_search, option, size); // binary search
                break;
            case 3:
                calcTime(selection_sort, option, size); // selection sort
                break;
            case 4:
                calcTime(bubble_sort, option, size); // bubble sort
                break;
        }
        free(option);
    }
}

int *readFile(string name, int size, int size2)
{
    FILE* file1 = fopen(name, "r");
    if (!file1) // check if file exists
    {
        printf("Unable to open: %s \n", name);
        return 0;
    }
    char line[size][size2]; // "size" strings and "size2" characters per line
    int *option = malloc(size * sizeof(int)); // allocated memory with size of "size" times number of bytes
    for (int i = 0; i < size; i++)
    {
        if (fscanf(file1, "%s", line[i]) != 1) // check if file reads correctly
        {
            printf("Error reading from: %s \n", name);
            fclose(file1);
            return 0;
        }
        option[i] = atoi(line[i]);
    }
    fclose(file1);
    return option;
}

void linear_search(int option[], int size)
{
    int guess;
    do
    {
        guess = get_int("Enter a number between 0 to %i: ", size); // get number to search for
    }
    while (guess < 0 || guess > size);
    for (int i = 0; i < size; i++)
    {
        if (option[i] == guess) // if i in file is equal to number
        {
            printf("Number: %i Random Index: %i \n", guess, i + 1); // print number and index
        }
    }
}

void binary_search(int option[], int size)
{
    int guess;
    do
    {
        guess = get_int("Enter a number between 0 to %i: ", size); // get number to search for
    }
    while (guess < 0 || guess > size);

    int start = 0; // make start 0
    int end = size - 1; // make end "size" - 1
    while (start <= end)
    {
        int mid = (start + end) / 2; // mid is middle of start and end
        if (option[mid] == guess) // if middle in file is equal to number
        {
            printf("Number: %i Reversed Index: %i \n", guess, mid + 1); // print number and index
            return;
        }
        else if (option[mid] > guess) // if middle in file is larger than number
        {
            start = mid + 1; // make start as middle
        }
        else if (option[mid] < guess) // if middle in file is smaller than number
        {
            end = mid - 1; // make end as middle
        }
    }
}

void selection_sort(int option[], int size)
{
    for (int i = 0; i < size - 1; i++) // loop every number
    {
        for (int k = i + 1; k < size; k++) // loop every other number
        {
            if (option[i] > option[k]) // if current number is bigger than other number
            {
                int temp = option[i]; // swap using temporary variable
                option[i] = option[k];
                option[k] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%i ", option[i]); // print sorted list
    }
    printf("\n");
}

void bubble_sort(int option[], int size)
{
    for (int n = 0; n < size - 1; n++) // loop every position
    {
        for (int i = 0; i < size - 1; i++) // loop every number
        {
            int k = i + 1;
            if (option[i] > option[k]) // if current number is bigger than next number in order
            {
                int temp = option[i]; // swap using temporary variable
                option[i] = option[k];
                option[k] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%i ", option[i]); // print sorted list
    }
    printf("\n");
}

void calcTime(void (*func)(int[], int), int option[], int size)
{
    clock_t start_t, end_t;
    double total_t;
    start_t = clock(); // start measuring time
    func(option, size); // execute function
    end_t = clock(); // end measuring time
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // calculate total time taken
    printf("Time taken: %fs \n", total_t); // print elapsed time
}
