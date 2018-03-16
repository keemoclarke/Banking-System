//
//  bankingSystem.cpp
//  Programming Methodology 1 - Project (Banking System)
//
//  Created by Keemo Clarke on 3/15/17.
//  Section 01


#include "bankingSystem.h"

// Menu function -- displays all the available options that a bank clerk can perform.
void menu(int *inputPtr)
{
    
    // Prompt for input
    cout << "\n\nWelcome to Clarke's Bank. Please, Select options below: \n\t1. Make new account.\n\t2. Display all accounts.\n\t3. Deposit to an account.\n\t4. Withdraw from an account.\n\t5. Print account.\n\t6. Delete an account.\n\t7. Quit(All stored data will be lost).\nSelection: ";
    while(!(cin>>*inputPtr)){
        cout << "\nInvalid input.\nPlease choose from one of following:\n\n\t1. Make new account.\n\t2. Display all accounts.\n\t3. Deposit to an account.\n\t4. Withdraw from an account.\n\t5. Print account.\n\t6. Delete an account.\n\t7. Quit(All stored data will be lost).\nSelection:  ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    
}


// Function for Selection 1 (make accounts)
void makeAccount(vector<Account>&bankAcc)
{
    bankAcc.push_back({1000,"ln","fn",0});  // new element created each time makeAccount is call;
    
    for(unsigned int i = 0; i < bankAcc.size(); i++)
    {
        if(bankAcc.at(i).lastName != "ln")   // go to other element if last name not "ln."
            continue;
        
        srand(unsigned (time(0)));
        int x = 1000 + rand()%8999;
        bankAcc.at(i).accountNumber = x;
        
        double amount;
        double *amountPtr = &amount;
        
        cout << "Creating account number " << bankAcc.at(i).accountNumber;
        
        cout << "\n\nEnter first name: ";
        cin >> bankAcc.at(i).firstName;
        
        cout << "\nEnter last name: ";
        cin >> bankAcc.at(i).lastName;
        
        cout << "\nEnter Start bal: " ;
        validInputDollar(bankAcc, amountPtr);
        
        if (amount>=0)
            bankAcc.at(i).accountBalance += amount;
        break;
    }
    sortAcounts(bankAcc);
}



// Function for Selection 2 (print all accounts)
void PrintAllAcount(vector<Account>&bankAcc)
{
    for (unsigned int i = 0; i< bankAcc.size(); i++){
        cout << "\nAccount Number: "<< bankAcc.at(i).accountNumber << setw(30)<< "Balance: " << bankAcc.at(i).accountBalance<< endl << "Last name: "<< bankAcc.at(i).lastName << setw(30) << "first name: " << bankAcc.at(i).firstName;
        cout << endl;
        }
}



// Function for Selection 3 (deposit)
void depositAccount(vector<Account>&bankAcc)
{
    int num; double amount;
    int *numPtr = &num;
    double *amountPtr = &amount;
    
    cout << "Enter account number for deposit: ";
    validInputAccNumber(bankAcc, numPtr);
    
    cout << "Enter amount to be deposited: ";
    validInputDollar(bankAcc, amountPtr);
    
    
    for(unsigned int i = 0; i < bankAcc.size(); i++)
    {
        
        if (num == bankAcc.at(i).accountNumber)
            bankAcc.at(i).accountBalance += amount;
    }
}



// Function for Selection 4 (withdraw)
void withdrawAccount(vector<Account>&bankAcc)
{
    int num; double amount;
    int *numPtr = &num;
    double *amountPtr = &amount;
    
    cout << "Enter account number for withdrawal: ";
    validInputAccNumber(bankAcc, numPtr);
    cout << "Enter amount to be withdrawn: ";
    validInputDollar(bankAcc, amountPtr);
    
    
    for(unsigned int i = 0; i < bankAcc.size(); i++)
    {
        
        if (num == bankAcc.at(i).accountNumber)
            bankAcc.at(i).accountBalance -= amount;
    }
}



// Function for Selection 5(Print one account)
void printAccount(vector<Account>&bankAcc)
{
    int num;
    int *numPtr = &num;
    
    cout << "Enter account number: ";
    validInputAccNumber(bankAcc, numPtr);

    
    
    for (unsigned int i = 0; i< bankAcc.size(); i++)
    {
        
        if (num == bankAcc.at(i).accountNumber)
        {
            cout << "\nAccount Number: "<< bankAcc.at(i).accountNumber << setw(30)<< "Balance: " << bankAcc.at(i).accountBalance<< endl << "Last name: "<< bankAcc.at(i).lastName << setw(30) << "first name: " << bankAcc.at(i).firstName;
            cout << endl;
        }
    }
}



// Function for Selection 6 (Deleting)
void deleteAccount(vector<Account>&bankAcc)
{
    int num;
    int *numPtr = &num;
    
    cout << "Enter account number to be deleted: ";
    validInputAccNumber(bankAcc, numPtr);
    
    for (unsigned int i = 0; i< bankAcc.size(); i++)
    {
        
        if (num == bankAcc.at(i).accountNumber)
        {
            cout << "\nYou have successfully deleted "<< bankAcc.at(i).firstName << " "<< bankAcc.at(i).lastName <<"'s account w/ account number: "<< bankAcc.at(i).accountNumber <<endl;
            bankAcc.erase(bankAcc.begin() +i);
        }
        
    }
}



// Function for Selection 7 (Quiting)
void quit()
{
    cout << "\nProgram terminated. \nAll info stored was lost.\n\n" ;
}



bool howToSort (const Account i,Account j) { return (i.accountNumber < j.accountNumber); }

void sortAcounts(vector<Account>&bankAcc) // stable_sort is used over sort to guarantee elements preserve their relative order
{
    stable_sort(bankAcc.begin(), bankAcc.end(), howToSort);
}



// Combine functions below into 1 when done (upadte: I was unable to do this. LOL.)

// for input of Dollars
void validInputDollar(vector<Account>&bankAcc, double *amountPtr)
{
    while(!(cin>>*amountPtr))
    {
        cout << "\nInvalid input.\nEnter new amount: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    
        if(*amountPtr < 0)  // if user enter negative dollar ammount
        {
            while(*amountPtr < 0)
            {
            cout << "Enter positive number: ";
            validInputDollar(bankAcc, amountPtr);
            }
        }
}



// for input of acc no.
void validInputAccNumber(vector<Account>&bankAcc, int *numPtr)
{
    while(!(cin>>*numPtr))
    {
    cout << "\nInvalid input.\nEnter new number: ";
    cin.clear();
    cin.ignore(100,'\n');
    }
    
    int result = linearSearch(bankAcc, numPtr);  // use of the Linear search function here
    if(result < 0)
    {
    cout << "\n\nAccount number not found.\nTry again: ";
    validInputAccNumber(bankAcc, numPtr);
    }
}



// Extra function that (linear) searches vector :)
int linearSearch(vector<Account>&bankAcc, int *numPtr)
{
    for (unsigned int i= 0; i < bankAcc.size(); i++)
    {
        if(bankAcc.at(i).accountNumber == *numPtr)
        return i;
    }
    return -1;
}
 



