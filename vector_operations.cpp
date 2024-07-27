//============================================================STL===============================================================================//
#include <iostream>
#include <vector>
using namespace std;
int print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{

    vector<int> v;
    for (int j = 0; j < 10; j++)
    {
        v.push_back(j * 10);
    }

    print(v);

    cout << "============after pop==========" << endl;

    v.pop_back();
    print(v);

    cout << "============after erase==========" << endl;
    v.erase(v.begin() + 2);
    print(v);

    cout << "============after inserting==========" << endl;
    v.insert(v.begin() + 2, 20);
    print(v);
    cout << "============back==========" << endl;
    cout << v.back();
    // v.clear();

    return 0;
}
