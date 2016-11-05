#include <stdio.h>

double getDouble(char doubleValue[]) {
    printf("%s\n", doubleValue);
    double text;
    scanf("%lf", &text);

    return text;
}

double nokToUsd(double salaryUSDollars) {
    double currency = 0.12;
    salaryUSDollars = currency * salaryUSDollars;

    return salaryUSDollars;
}

double nokToYen(double salaryYen) {
    double currency = 14.24;
    salaryYen = currency * salaryYen;

    return salaryYen;
}

double nokToBPounds(double salaryPounds) {
    double currency = 0.077;
    salaryPounds = currency * salaryPounds;

    return salaryPounds;
}

double nokToEuro(double salaryEuro) {
    double currency = 0.11;
    salaryEuro = currency * salaryEuro;

    return salaryEuro;
}

/* This calculates time correctly */
double calculatePay(double hours, double pay, double lunch, double days) {
    double toAvoidDecimals = 100;

    double workHours = hours * toAvoidDecimals;

    return ((workHours - lunch) * pay) * days / toAvoidDecimals;
}

double SalaryAfterTax(double salary, double tax) {
    tax = 1 - tax;
    return (salary * tax);
}

int main() {
    double percentage = 1;

    double hourlyPay = getDouble("What is your hourly pay?");
    double hoursWorked = getDouble("How many hours have you worked?");
    double lunchBreak = getDouble("How long is your lunch break (written 0.xx)?");
    double daysTotal = getDouble("How many days will/have you work(ed)?");
    double taxPercentage = getDouble("What is your tax percentage (written 0.xx)?");

    double calculatedPay = calculatePay(hoursWorked, hourlyPay, lunchBreak, daysTotal);
    double finishedSalary = SalaryAfterTax(calculatedPay, taxPercentage);

    char americanDollar[] = "$";
    char japaneseYen[] = "¥";
    char britishPounds[] = "£";
    char euro[] = "€";
    char norwegianCrown[] = " kr";

    printf("Your salary\n");
    printf("NOK before tax:\n%f%s", calculatedPay, norwegianCrown);
    printf("\nNOK after tax:\n%f%s", finishedSalary, norwegianCrown);
    printf("\nNOK to USD:\n%s%f", americanDollar, nokToUsd(finishedSalary));
    printf("\nNOK to JPY:\n%s%f", japaneseYen, nokToYen(finishedSalary));
    printf("\nNOK to GBP:\n%s%f", britishPounds, nokToBPounds(finishedSalary));
    printf("\nNOK to EUR:\n%s%f", euro, nokToEuro(finishedSalary));
}
