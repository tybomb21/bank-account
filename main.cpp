#include "project2.h"

int main()
{


    project2 bank;
    bank.UserInputandValidation();
    bank.DisplayNoMonthly();
    bank.DisplayWithMonthly();

    // get user input for new values
    char choice;
    bool run = true; //@stefaanv-https://stackoverflow.com/questions/40156859/yes-no-program-using-while-loop-in-c
    while (run)
    {
        // Make your calculation
        cout << "Would you like to try different values? (Y/y or N/n): " << endl;
        cin >> choice;

        if (choice == 'N' || choice == 'n')
        {
            run = false;
        }

        if (choice == 'Y' || choice == 'y')
        {
            run = true;
            project2 bank;
            bank.UserInputandValidation();
            bank.DisplayNoMonthly();
            bank.DisplayWithMonthly();

        }
    }
}