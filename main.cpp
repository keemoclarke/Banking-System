//
//  main.cpp
//  Programming Methodology 1 - Project (Banking System)
//
//  Created by Keemo Clarke on 3/15/17.
//  Section 01

/* About: This is a banking system. User's job is to manage multiple bank accounts. Here, user can create new accounts, deposit to an account, withdraw from an account, delete account, sort the accounts, or do inspection on one or all bank accounts. The bank maintains a list of accounts. This list has to be available as long as the bank is in business.
*/



#include "bankingSystem.h"




int main(){
    
    
    vector <Account> bankAccounts;
    
    int input;
    int *inputPtr = &input;
    
    
    while(input != 7)  // because option 7 terminates system
    {
        
        menu(inputPtr);
        
        
        while ( (bankAccounts.empty()) &&  (input != 1) && (input != 7) ) // while no accounts exist 
        {
            if( (input > 7) || (input < 1)){
                cout << "\nSelection can only be between 1 and 7.";
            menu(inputPtr);}
         else
         {cout << "\nYou haven't made any accounts yet. ";
             menu(inputPtr);}
        }
    
        
            switch(input)     /* Switch case --  the users input(from the menu fct) is assigned to a case which calls 
                               corresponding function; for example, case1 gives option to make account.*/
            {
            case 1:
                makeAccount(bankAccounts);
                break;
                
            case 2:
                PrintAllAcount(bankAccounts);
                break;
                
            case 3:
                depositAccount(bankAccounts);
                break;
                
            case 4:
                withdrawAccount(bankAccounts);
                break;
                
            case 5:
                printAccount(bankAccounts);
                break;
                
            case 6:
                deleteAccount(bankAccounts);
                break;
                
            case 7:
                quit();
                break;
                
            default:
                cout << "\nSelection can only be between 1 and 7.";
        }
    }
    
    return 0;
}
