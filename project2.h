#pragma once
#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

// Interest formula
// (Opening Amount + Deposited Amount) * ((Interest Rate/100)/12)

class project2
{

private:
    double monthlyDeposit;
    double initialAmount;
    double annualInterest;
    double finalAmount;
    double finalAmountWithout;
    int numberOfYears;

public:
    bool UserInputandValidation(void);
    void DisplayNoMonthly(void);
    void DisplayWithMonthly(void);

    void CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount);
    void CalcYearInterestWithout(double initialAmount, double& interestAmount, double& finalAmountWithout);



};

// Calculate yearly interest amount and balance with a monthly deposit

void project2::CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount)
{
    interestAmount = 0.0;
    finalAmount = initialAmount;

    for (int month = 0; month < 12; month++)
    {
        finalAmount += monthlyDeposit;
        double monthlyInterestAmount = finalAmount * ((annualInterest / 100.0) / 12.0);
        finalAmount += monthlyInterestAmount;
        interestAmount += monthlyInterestAmount;
    };

}

void project2::CalcYearInterestWithout(double initialAmount, double& interestAmount, double& finalAmountWithout)
{
    interestAmount = 0.0;
    finalAmountWithout = initialAmount;

    for (int month = 0; month < 12; month++)
    {
        finalAmountWithout += 0;
        double monthlyInterestAmount = finalAmountWithout * ((annualInterest / 100.0) / 12.0);
        finalAmountWithout += monthlyInterestAmount;
        interestAmount += monthlyInterestAmount;
    };

}



bool project2::UserInputandValidation() {

    cout << "***************************************" << endl;
    cout << "***************Data Input**************" << endl;
    do {
        cout << "Initial Investment Amount: " << endl;
        cin >> initialAmount;
        if (initialAmount < 0)
            cout << "Initial Amount can not be negative.";
    } while (initialAmount < 0);

    do {
        cout << "Monthly Deposit: " << endl;
        cin >> monthlyDeposit;
        if (monthlyDeposit < 0)
            cout << "Monthly Deposit can not be negative.";
    } while (monthlyDeposit < 0);

    do {
        cout << "Annual Interest: " << endl;
        cin >> annualInterest;
        if (annualInterest < 0)
            cout << "Annual Interest can not be negative.";
    } while (annualInterest < 0);

    do {
        cout << "Number of years:  " << endl;
        cin >> numberOfYears;
        if (numberOfYears < 0)
            cout << "Number of years can not be negative.";
    } while (numberOfYears < 0);

    cout << "Press any key to continue..." << endl;

    cout << endl;
    cout << endl;

    cout << "***************************************" << endl;
    cout << "***************Data Input**************" << endl;
    cout << "Initial Investment Amount: " << "$" << initialAmount << endl;
    cout << "Monthly Deposit: " << "$" << monthlyDeposit << endl;
    cout << "Annual Interest: " << "%" << annualInterest << endl;
    cout << "Number of years: " << numberOfYears << endl;
    cout << "Press any key to continue..." << endl;
    
    cout << endl;
    cout << endl;

    return true;


}


void project2::DisplayNoMonthly() {

    double finalAmountWithout;	//to hold the year end earned interest + deposited amount
    double yearlyInterest; //to hold year end earned interest 
    double yearlyInitial = initialAmount; //to hold the initial balance for the year

    //add "Balance and Interest With Additional Monthly Deposits" TABLE HEADER
    // YEAR    YEAR END BALANCE    YEAR EARNED INTEREST
    //finalAmount = initialAmount + monthlyDeposit + annualInterest;
    //cout << table headers 

    cout << "   Balance and Interest Without Additional Monthly Deposits    " << endl;
    cout << "===============================================================" << endl;
    cout << setw(5) << right << "Year" << setw(25) << right << "Year End Balance" << setw(32) << right << "Year End Earned Interest" << endl;
    cout << "_______________________________________________________________" << endl;



    for (int year = 1; year <= numberOfYears; year++)
    {
        CalcYearInterestWithout(yearlyInitial, yearlyInterest, finalAmountWithout);
        cout << setw(5) << right << year << setw(19) << right << "$" << setw(12) << left << fixed << setprecision(2) << finalAmountWithout << setw(20) << right << "$" << left << fixed << setprecision(2) << yearlyInterest << endl;
        cout << endl;
        yearlyInitial = finalAmountWithout;
    };


    //for loop will run till 1 to numberOfYears
    //call CalcYearInterest function with initialAmount, interestAmount,  finalAmount






}

void project2::DisplayWithMonthly() {

    double finalAmount;	//to hold the year end earned interest + deposited amount
    double yearlyInterest; //to hold year end earned interest 
    double yearlyInitial = initialAmount; //to hold the initial balance for the year

    //add "Balance and Interest With Additional Monthly Deposits" TABLE HEADER
    // YEAR    YEAR END BALANCE    YEAR EARNED INTEREST
    //finalAmount = initialAmount + monthlyDeposit + annualInterest;
    //cout << table headers 

    cout << "     Balance and Interest With Additional Monthly Deposits     " << endl;
    cout << "===============================================================" << endl;
    cout << setw(5)<<right<<"Year" << setw(25) << right <<"Year End Balance" << setw(32) << right << "Year End Earned Interest" << endl;
    cout << "_______________________________________________________________" << endl;
    for (int year = 1; year <= numberOfYears; year++)
    {
        CalcYearInterest(yearlyInitial, yearlyInterest, finalAmount);
        cout << setw(5) << right << year << setw(19) << right << "$" << setw(12) << left << fixed << setprecision(2) << finalAmount << setw(20) << right << "$" << left << fixed << setprecision(2) << yearlyInterest << endl;
        cout << endl;
        yearlyInitial = finalAmount;

    };
   
    
   

}


