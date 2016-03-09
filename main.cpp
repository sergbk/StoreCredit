#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void processValues(int arr[], int n, int credit);

int main()
{
    int n = 0;                   // # of Items
    int TotalCases = 0;          // # of Cases
    int CaseCounter = 1;         // Variable to display Case#
    int ItemCounter = 0;         // Variable to track # of items/numbers
    int credit = 0;              // Variable to hold Credit Amount

    fstream f1;
    f1.open("Scredit.in", ios::in);

    f1 >> TotalCases;   // Read in Total # of cases

    while(CaseCounter <= TotalCases)
    {

        f1 >> credit;   // Read in Credit Amount

        f1 >> n;        // Read in # of items/numbers

        int arr[n];     // Define Array with 'n' elements

        while(ItemCounter < n)
        {
            f1 >> arr[ItemCounter];    // Read items into an Array
            ItemCounter++;
        }

        cout << "Case#" << CaseCounter << ": ";     // Display Case #
        processValues(arr, n, credit);

        delete[] arr;       // Delete the Array after done processing
        n = 0;              // Reset Number of items/numbers
        credit = 0;         // Reset Credit Amount
        ItemCounter = 0;    // Reset the Item Counter

        CaseCounter++;
    }

    return 0;
}


void processValues(int arr[], int n, int credit)
{
    bool found = false;     // Variable to track if a match has been found

    for(int i = 0; i < n; i++)
    {
        if(found == false)
        {
           while(arr[i] >= credit)  // Loop to prevent comparison of Items that are larger than the Credit Amount
                i++;                // Increase "i" until it's smaller than Credit

            for(int j = 0; j < n; j++)
            {
                while(arr[j] >= credit) // Loop to prevent comparison of Items that are larger than the Credit Amount
                    j++;                // Increase "j" until it's smaller than Credit

                if(i == j)  // Prevent comparison of same Indexes in Array
                    j++;

                if((arr[i] + arr[j]) == credit) // Check if two items add up to the Credit Amount
                {
                    cout << i + 1 << " " << j + 1 << endl;
                    found = true;   // IF a match has been found set to True
                    break;          // Break the for loop
                }
            }
        }
    }
}
