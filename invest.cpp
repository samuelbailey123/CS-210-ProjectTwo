/**
    @author-Samuel Bailey 
    CS-210 | Project Two Source Code REDO
    09-29-2020  
    This code was written in VS Code 
    The goal of this code was written to with the rubric of project two. The only thing that differs from the rubric 
    is the ending, there is a loop implemented to keep the code going incase you would like to try multiple #'s.
    This isn't against the rubric just something to add to the program. 
    The code is mainly moderate size void functions. This makes the main code small and extremly easy to read.
    The functions are void because they don't need to return anything we control the loop in main. 
        **/

//include statements to give basic funcionality to keyboard and display
#include <iostream>
#include <iomanip>

using namespace std;

// all variables in the program
double IniInvest, MonthlyDeposit , AnnualInterest , NumOfYears,finalAmount,yearlyInterest, monthEndInterest,loopInvest, loopInterest;
char userInput, tryAgain;
    
    //function for data input for the program | doing it in a function gives us more control and is easy to recall in later loops
void dataInput(){
    cout << "****************************************" << endl;
    cout << "************* Data Input ***************" << endl;
    cout << "Initial Investment: $";
    cin >> IniInvest; 
    cout << "Monthly Deposit: $"; 
    cin >> MonthlyDeposit; 
    cout << "Annual Interest: %"; 
    cin >> AnnualInterest; 
    cout << "Number of years:";
    cin >> NumOfYears; 
    //this next line is mainly for the next function to activate. 
    cout << "Press 'c' to continue..."; 
    cin >> userInput; 
}

//function for displaying the data that was inputted from the user 
void displayData(){
    loopInvest = IniInvest; 
    if (userInput == 'c'){
        //displays first report without monthly deposits
        cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
        cout << "==================================================================" << endl;
        cout << "   Year\t\tYear End Balance\tYear End Earned Interest" << endl;
        cout << "------------------------------------------------------------------" << endl;
        //for loop to increment the data
        for (int i=0; i < NumOfYears; i++){
            yearlyInterest = loopInvest * (AnnualInterest / 100); 
            loopInvest = yearlyInterest + loopInvest; 
            cout << "   " << i+1 << "\t\t$" << fixed << setprecision(2) << loopInvest << "\t\t\t$" <<  yearlyInterest << endl;
        }
        //displays second report with monthly deposits
        cout << endl;
        cout << "Balance and Interest With Additional Montly Deposits" << endl;
        cout << "==================================================================" << endl;
        cout << "   Year\t\tYear End Balance\tYear End Earned Interest" << endl;
        cout << "------------------------------------------------------------------" << endl;
        //for loop to increment the data of second report
        for (int i = 0; i < NumOfYears; i++) {
            monthEndInterest = 0;  
            for (int j =0; j < 12; j++){
                yearlyInterest = (loopInvest + MonthlyDeposit) * ((AnnualInterest/100)/12);
                monthEndInterest = yearlyInterest + loopInvest; 
                loopInvest = monthEndInterest + yearlyInterest + MonthlyDeposit; 
            }
         cout << "   " << i+1 << "\t\t$" << fixed << setprecision(2) << loopInvest << "\t\t$" << yearlyInterest << endl;
        }
    }
    //this keeps the loop going or ends the loop
    cout << "Would you like to try another set of numbers? (y for yes)"; 
    cin >> tryAgain;  
}
int main(){
    tryAgain = 'y'; 
    while (tryAgain == 'y'){
        dataInput();
        displayData();
    }
}