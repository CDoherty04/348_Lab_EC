#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Prototype function
double extractNumeric(const string &str);

// Given main function
int main()
{
    string input;

    while (true)
    {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END")
        {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

// My code
double extractNumeric(const string &str) {
    return 1;
}