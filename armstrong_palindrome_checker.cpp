#include <iostream>
#include <math.h>
using namespace std;
namespace jaymataji
{
    void checkarmstrong(int num)
    {
        int originalNum, remainder, result = 0;
        originalNum = num;
        while (originalNum != 0)
        {
            remainder = originalNum % 10;
            result += std::pow(remainder, 5);
            originalNum /= 10;
        }
        if (result == num)
            cout << num << " is an Armstrong number.";
        else

            cout << num << " is not an Armstrong number.";
        int n, digit, rev = 0;
    }
    void checkpalindrome(int num)
    {
        int n = num, digit, rev;
        do
        {
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);
        cout << " \nThe reverse of the number is: " << rev;
        if (n == rev)
            cout << "\nThe number is a palindrome.";
        else
            cout << "\nThe number is not a palindrome.";
    }
}
int main()
{
    int num;
    cout << "Enter a five-digit number: ";
    cin >> num;
    jaymataji::checkarmstrong(num);
    jaymataji::checkpalindrome(num);
    return 0;
}