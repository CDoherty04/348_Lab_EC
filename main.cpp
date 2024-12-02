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

        if (number != -999999.99)
        {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
        else
        {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

// My code
double extractNumeric(const string &str)
{
    double value = 0.0;
    double decimalPlace = 0.1;
    bool isNegative = false;
    bool isDecimal = false;

    // Test for string greater than 20 characters or empty string
    if (str.length() == 0 or str.length() > 20)
    {
        return -999999.99;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        // Handle positive/negative
        if (i == 0 && (c == '-' || c == '+'))
        {
            if (c == '-')
            {
                isNegative = true;
            }
        }
        // Handle decimal points
        else if (c == '.')
        {
            // Checks for extra decimal point
            if (isDecimal)
            {
                return -999999.99;
            }
            isDecimal = true;
        }
        // Handle number digits
        else if (isdigit(c))
        {
            if (!isDecimal)
            {
                value = value * 10 + (c - '0');
            }
            else
            {
                value += (c - '0') * decimalPlace;
                decimalPlace *= 0.1;
            }
        }
        else
        {
            return -999999.99;
        }
    }

    // return the value with a negative if applicable
    return isNegative ? -value : value;
}