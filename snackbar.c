// Practice using structs
// Practice writing a linear search function

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// number of menu items
#define NUM_ITEMS 10

// menu items with item and price
typedef struct
{
    string item;
    float price;
} menu_item;

// array of menu items
menu_item menu[NUM_ITEMS];

// add items to menu
void add_items(void);

// calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0) // if nothing is added
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total); // print total cost
}

void add_items(void)
{
    menu[0].item = "Burger";
    menu[0].price = 9.5;

    menu[1].item = "Vegan Burger";
    menu[1].price = 11;

    menu[2].item = "Hot Dog";
    menu[2].price = 5;

    menu[3].item = "Cheese Dog";
    menu[3].price = 7;

    menu[4].item = "Fries";
    menu[4].price = 5;

    menu[5].item = "Cheese Fries";
    menu[5].price = 6;

    menu[6].item = "Cold Pressed Juice";
    menu[6].price = 7;

    menu[7].item = "Cold Brew";
    menu[7].price = 3;

    menu[8].item = "Water";
    menu[8].price = 2;

    menu[9].item = "Soda";
    menu[9].price = 2;
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    for (int i = 0; i < NUM_ITEMS; i++) // loop every item
    {
        if (strcasecmp(menu[i].item, item) == 0) // if item in menu is the same item
        {
            return menu[i].price; // return price
        }
    }
    return 0.0;
}
