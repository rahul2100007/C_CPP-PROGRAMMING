#include <iostream>
using namespace std;
int main()
{
    int distance;
    cout << "What distance will you travel?:";
    cin >> distance;
    cout << "\n===========(WELCOME TO GSRTC)===========\n";
    if (distance >= 0 && distance <= 20)
    {
        cout << "\nYOUR TOTAL FARE IS:" << (distance * 1) << "Rs.\n\n";
    }
    else if (distance >= 21 && distance <= 40)
    {
        cout << "\nYOUR TOTAL FARE IS:" << (distance * 2) << "Rs.\n\n";
    }
    else if (distance >= 41 && distance <= 60)
    {
        cout << "\nYOUR TOTAL FARE IS:" << (distance * 3) << "Rs.\n\n";
    }
    else if (distance >= 61 && distance <= 80)
    {
        cout << "\nYOUR TOTAL FARE IS:" << (distance * 4) << "Rs.\n\n";
    }
    else if (distance >= 81 && distance <= 100)
    {
        cout << "\nYOUR TOTAL FARE IS:" << (distance * 5) << "Rs.\n\n";
    }
    else if (distance > 100)
    {
        cout << "\nYOUR TOTAL FARE IS:" << (distance * 6) << "Rs.\n\n";
    }
    cout << "=============(CHALO BYE)===============\n\n";
    return 0;
}