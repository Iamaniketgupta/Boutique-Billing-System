#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// structure for storing product information
struct product
{
    char name[20];
    int id;
    int price;
};

// structure for storing customer information
struct customer
{
    char name[20];
    int id;
    char contact[20];
};

// function to display shop details
void shopdetails()
{
    printf("\n=================================================================================================================================");
    printf("\n\t\t\t\t\tPCTE Boutique\n\t\t\t\t\tSec -38 , Noida\n \t\t\t\t\tContact : +91 93838-97339   Email: pcteboutique@gmail.com");
    printf("\n=================================================================================================================================\n\n");
    printf("To : ");

    // including system time
    time_t t;
    time(&t);
    printf("\t\t\t\t\t\t\t\t\t\t\tOn: %s\n", ctime(&t));
}

// function to get customer info and display it
void consumer()
{
    struct customer cus[5];

    printf("Please Enter name of the customer : ");
    scanf(" %[^\n]", cus[0].name);

    printf("Please Enter ID of the customer : ");
    scanf("%d", &cus[0].id);

    printf("Please Enter the Contact no. : ");
    scanf("%s", cus[0].contact);

    system("cls"); // to clear the previous buffer

    printf("\n\nGenerating.");
    sleep(1); // to delay 1 for sec
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    system("cls"); // to clear the previous buffer

    // displaying customer & shop details
    shopdetails();

    printf("\nCustomer Name: %s", cus[0].name);
    printf("\nCustomer ID: %d", cus[0].id);
    printf("\nCustomer Contact: %s", cus[0].contact);
}

// function to store product names, id, price
void items()
{

    struct product item[5] = {{"Shirt", 1, 500},
                              {"Trousers", 2, 750},
                              {"Suit", 3, 1000},
                              {"T-Shirt", 4, 350},
                              {"Lehnga", 5, 2000}};

    printf("\n\t\tPlease Select Product\n\n");
    printf("Product             ID                 Price\n\n");

    // displaying the product name, id, price
    for (int i = 0; i < 5; i++)
    {
        printf("%-20s", item[i].name);
        printf("%-20d", item[i].id);
        printf("%-20d", item[i].price);
        printf("\n");
    }
    // asking to select by id
    printf("------------------------------------------------------------------\n");
    int slct;
    printf("Select product ID : ");
    scanf("%d", &slct);

    // asking to decide quantity

    int quant;
    printf("Select Quantity : ");
    scanf("%d", &quant);
    printf("\n-------------------------------------------------------------------\n\n\n");

    int op;

    while (1) // Loop until valid input is received
    {
        printf("\t\t1. Generate Invoice\n");
        printf("\t\t2. Generate Bill\n");
        printf("\t\tPress 0 to EXIT\n");

        printf("\n Please enter the option number: ");
        scanf("%d", &op);

        if (op == 0)
        {
            printf("\nExiting program...\n");
            exit(0); // Exit the program if 0 is entered
        }
        else if (op == 1 || op == 2)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a valid option number.\n");
        }
    }

    printf("\n\n=================================================================================================================================\n");

    consumer();

    switch (op)
    {
    case 1: // to choose Invoice

        printf("\n\n=================================================================================================================================\n");
        printf("\t\t\t\t\tINVOICE");
        printf("\n\n=================================================================================================================================\n");
        printf("PRODUCT NAME      | ID |           | QUANTITY |          | PRICE |\n");

        printf("%-20s", item[slct - 1].name);
        printf("%-20d", item[slct - 1].id);
        printf("%-20d", quant);
        printf("%-20d", item[slct - 1].price);
        printf("\n\n\n\n");

        printf("\n\n=================================================================================================================================\n");

        int total = 0;
        total = total + (quant * item[slct - 1].price);
        printf("Your Payable Amount : %d\n", total);

        if (total <= 1000)
        {
            printf("Net Amount to pay: %d\n\n", total);
        }
        else
        {
            printf("Welcome Discount 500rs applied \n");
            printf("Net Amount to pay: %d\n\n", total - 500);
        }
        printf("\t\t\t\tTHANK YOU ! ...Please Visit Again....");
        break;

    case 2: // to choose Bill

        printf("\n\n=================================================================================================================================\n");
        printf("\t\t\t\t\tBILL\n");
        printf("=================================================================================================================================\n");

        int tot = 0;
        tot = tot + (quant * item[slct - 1].price);
        printf("Your Payable Amount : %d\n", tot);

        if (tot <= 1000)
        {

            printf("Net Amount to pay: %d\n\n", tot);
        }
        else
        {
            printf("Welcome Discount Rs 500. applied \n");
            printf("Net Amount to pay: %d\n\n", tot - 500);
        }
        printf("\t\t\t\tTHANK YOU ! ...Please Visit Again....");

        break;

    default:
        printf("Please Enter Valid Input");
    }
}
// function to display options at start
void welcome()
{
    int op;
    while (1) // Loop until valid input is received
    {
        printf("\n\n\t\t\t\t\t\t*=======WELCOME=======*\n");
        printf("\n Please select an option:\n\n");
        printf("1. Order Products\n");
        printf("2. Generate Invoice\n");
        printf("3. Generate Bill\n");
        printf("Press 0 to EXIT\n");

        printf("\n Please enter the option number: ");
        scanf("%d", &op);

        if (op == 0)
        {
            printf("\nExiting program...\n");
            exit(0); // Exit the program if 0 is entered
        }
        else if (op == 1)
        {
            items();
            break;
        }
        else if (op == 2 || op == 3)
        {
            printf("Please order first.\n");
        }
        else
        {
            printf("Invalid input. Please enter a valid option number.\n");
        }
    }
}

int main()
{

    printf("\n\n****************************************************************************************************************************************************");
    printf("\n\t\t\t\t\t\tBOUTIQUE BILLING SYSTEM\t\t\t\t");
    printf("\n\t\t\t\t\t\t-----------------------\t\t\t\t");
    printf("\n\t\t\t\t Made by: Aniket Gupta \t\t\t\t");

    printf("\n****************************************************************************************************************************************************\n");

    welcome();
    printf("\n=================================================================================================================================\n");
    printf("\t\t\tfor more information Please visit our website : www.pcteboutique.com\t\t\t\t\t");
    printf("\n=================================================================================================================================\n\n");

    return 0;
}
