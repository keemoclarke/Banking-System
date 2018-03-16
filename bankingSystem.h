//
//  bankingSystem.h
//  Programming Methodology 1 - Project (Banking System)
//
//  Created by Keemo Clarke on 3/15/17.
//  Section 01



#ifndef bankingSystem_h
#define bankingSystem_h






// All libraries used included just once inside header
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <ctime>
#include <algorithm>


using namespace std;

// type name account is created using struct
struct Account{
    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;
};



void menu(int *inputPtr);

// Functions prototypes for 7 different selections

void makeAccount(vector<Account>&bankAcc);

void PrintAllAcount(vector<Account>&bankAcc);

void depositAccount(vector<Account>&bankAcc);

void withdrawAccount(vector<Account>&bankAcc);

void printAccount(vector<Account>&bankAcc);

void deleteAccount(vector<Account>&bankAcc);

void quit();


//  prototypes for other functions used

void sortAcounts(vector<Account>&bankAcc);

// two valid input functions used -- one for the dollar input, and another for acc no.
void validInputDollar(vector<Account>&bankAcc, double *amountPtr);
void validInputAccNumber(vector<Account>&bankAcc, int *numPtr);

// search function used inside validInputAccNumber
int linearSearch(vector<Account>&bankAcc, int *numPtr);



#endif /* Header_h */
