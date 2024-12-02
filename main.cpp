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

    double value = 0;

    // Test for empty string
    if (str.length() == 0 or str.length() > 20)
    {
        return -999999.99;
    }

    // Test for invalid characters
    for (int i = 0; i < str.length(); i++)
    {
        // If the character is not a digit and isn't a plus or minus (at the beginning)
        if (!isdigit(str[i]) && ((i != 0)))
        {
            value = -999999.99;
        }
        // If the character is a plus or minus at the beginning
        else if (!isdigit(str[i]) && ((i == 0)))
        {
            if (str[i] == '-')
            {
                value = -1;
            }
            else if (str[i] == '+')
            {
                value = 1;
            }
        }
    }

    // Return the input as a double
    return value;
}