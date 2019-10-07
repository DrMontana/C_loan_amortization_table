//Wesley Smith
//9-20-19
//Lab 3 Interest Calculator

#include <stdio.h>
#include <math.h>

/* This program will take a user input value for
 * an initial amount borrowed, annual interest rate
 * and number of payments to simulate a customized
 * loan amortization table*/

double calculate(double p, double i, double pay){
    double payment, powResult;

    powResult = pow((1+i),(-pay));
    //Formula on pg. 167
    payment = ((i*p)/((1-(powResult))));
    return (payment);
}

int main(void){
    
    //Setting up our variables for catching inputs later on
    //calc - catching what we get from our
    double borrow, interest, payments, calc;
    
    printf("Enter the amount borrowed => ");
    scanf("%lf", &borrow);

    //Converting our annual interest rate to a percentage, then
    //figuring out the monthly rate from that
    printf("Enter the annual interest rate => ");
    scanf("%lf", &interest);
    interest /= 100;
    interest /= 12;

    printf("Enter the number of payments => ");
    scanf("%lf", &payments);
    
    //Calculates our monthly payment based on our principle and 
    //annual interest rate for how many monthly payments
    calc = calculate(borrow, interest, payments);
    
    
    //Setting up the format for our table
    printf("Payment\t\t Interest\t Principal\t Principal Balance\n\n");

    //Variable declarations for our table values
    //finalPayment - what our final payment will be
    //inter - how much of our payment is interest
    //princ - how much the payment is without interest added on
    //balance - how much we have left to pay off
    double finalPayment, inter, princ, balance;
    
    for(int i=1;i<payments+1;i++){
    
        //Our interest payment is equal to our monthly interest rate times
        //the amount we have left at the end of each month    
        inter = interest * borrow;
        
        //Our principal payment is based off of our calculated monthly
        //payments minus our monthly interest rate multiplied by our current
        //amount we have left over
        princ = calc - (interest*borrow);

        //The balance we have left over is taken from our current amount
        //and subtracting the payment without interest from that
        balance = borrow - princ;

        //Formatting for printing out our 4 fields listed above
        printf("%d\t\t %.2lf\t\t  %.2lf\t %.2lf\n\n", i, inter, princ, balance);
        
        //Each loop through we have to reset our current borrowed amount left
        //to what our balance is at the end of the loop
        borrow = balance;

        //Conditional to check for our last payment and calculate it using the
        //principal payment and interest left at the end of the loop
        if (i==payments){
        
            finalPayment = princ + inter;
        }
        
    }

    //Conditional to deal with a final payment that might be less than zero dollars
    if(finalPayment <= 0){

       princ -= finalPayment; 

    }
    
    //Printing out our final payment
    printf("Final Payment\t$%.2lf\n",finalPayment);

    return(0); 
    
}

main();
