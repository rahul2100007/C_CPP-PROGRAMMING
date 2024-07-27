//============================================================STL===============================================================================//
#include <iostream>
#include <deque>
using namespace std;
int print(deque<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{
    deque<int> v;
    for (int j = 0; j < 10; j++)
    {
        v.push_front(j * 100);
    }

    print(v);

    cout << "============after pop==========" << endl;

    v.pop_front();
    print(v);

    cout << "============after erase==========" << endl;
    v.erase(v.begin() + 2);
    print(v);

    cout << "============after inserting==========" << endl;
    v.insert(v.begin() + 2, 20);
    print(v);
    cout << "============front==========" << endl;
    cout << v.front();
    // v.clear();

    return 0;
}
