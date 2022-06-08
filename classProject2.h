#pragma once
class classProject2
{

private:
    double monthlyDeposit;
    double initialAmount;
    double annualInterest;
    int numberOfyears;

    void CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount);

public:
    bool UserInputandValidation(void);
    void DisplayNoMonthly(void);
    void DisplayWithMonthly(void);

    void CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount);

};

