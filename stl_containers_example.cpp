//                                              ________     _________________     .
//                                             /                     |             |          
//                                            |                      |             |                    
//                                            |                      |             |
//                                             \________             |             |
//                                                      \            |             |  
//                                                       |           |             |
//                                                       |           |             |
//                                             _________/            |             |______________                                     
//                                                                                                      
/*#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> obj;
    obj.push_back(10);
    obj.push_back(20);
    obj.push_back(30);
    obj.push_back(40);
    list<int>::iterator itr;
    for(itr=obj.begin();itr!=obj.end();itr++)
    {
        cout<<*itr<<"\t";
    }

 return 0;
}
*/
/*
#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> obj;
    obj.push_back(60);
    obj.push_back(50);
    obj.push_back(40);
    obj.push_back(30);
    obj.push_back(20);
    obj.push_back(10);
    obj.push_back(10);
    obj.remove(10);
    obj.sort();
    list<int>::iterator itr;
    for(itr=obj.begin();itr!=obj.end();itr++)
    {
        cout<<*itr<<"\t";
    }
    cout<<"\n Insert data at the specified position.\n";
    itr=obj.begin();
    int pos;
    cout<<"Enter the position:";
    cin>>pos;
    advance(itr,pos);
    int num;
    cout<<"\nenter number:";
    cin>>num;
    obj.insert(itr,num);
    for(itr=obj.begin();itr!=obj.end();itr++)
    {
        cout<<*itr<<"\t";
    }
    cout<<"\nDisplay front element from list:";
    cout<<obj.front();
    cout<<"\nDisplay back element from list:";
    cout<<obj.back();

 return 0;
}
*/
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    int j;
    list<int> list1, list2;
    int arr1[] = {40, 30, 20, 10};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    for (j = 0; j < 4; j++)
    {
        list1.push_back(arr1[j]);
    }
    list<int>::iterator itr;

    for (itr = list1.begin(); itr != list1.end(); itr++)
    {
        cout << *itr << "\t";
    }
    cout << "\n";
    for (j = 0; j < 6; j++)
    {
        list2.push_back(arr2[j]);
    }

    for (itr = list2.begin(); itr != list2.end(); itr++)
    {
        cout << *itr << "\t";
    }
    list2.merge(list1);
    cout << "\n";
    while (!list2.empty())
    {
        cout << list2.back() << "\t";
        list2.pop_back();
    }
    return 0;
}
*/
//=======================================================||ASSOCIATED LIST CLASS||=======================================================//
/*
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    for(int i=1;i<=5;i++){
        s.insert(i*10);
    }
    //s.insert(1);
    //s.insert(2);
    //s.insert(3);
    cout << "size of set container:" << s.size() << endl;
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << "Element of set container:" << *it << " " << endl;
    }
    cout << endl;
    cout<<"\n Multiset: Lower bound:\n";
    cout<<*s.lower_bound(30);
    cout<<"\n Multiset: Upper bound:\n";
    cout<<*s.upper_bound(30);


    return 0;
}
*/
//SWAP SET//
/*
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    set<string> s1;
    set<string> s2;
    s1.insert("A");
    s1.insert("B");
    s1.insert("C");
    s1.insert("D");
    s1.insert("E");
     cout << "\nSET 1"<< endl;
    set<string, less<string>>::iterator iter;
    iter = s1.begin();
    while (iter != s1.end())
    {
        cout << *iter++ << "\n";
    }
    cout << "\n\n";
    s2.insert("10");
    s2.insert("20");
    s2.insert("30");
    s2.insert("40");
    s2.insert("50");
     cout << "\nSET 2"<< endl;
    set<string, less<string>>::iterator iter1;
    iter1 = s2.begin();
    while (iter1 != s2.end())
    {
        cout << *iter1++ << "\n";
    }
    s1.swap(s2);
    cout << "\nSET 1"<< endl;
    iter = s1.begin();
    while (iter != s1.end())
    {
        cout << *iter++ << "\n";
    }

     cout << "\nSET 2"<< endl;
    iter1 = s2.begin();
    while (iter1 != s2.end())
    {
        cout << *iter1++ << "\n";
    }
    return 0;
}
*/
//SWAP USING MULTISET//
/*
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    multiset<string> s1;
    multiset<string> s2;

    s1.insert("A");
    s1.insert("B");
    s1.insert("C");
    s1.insert("D");
    s1.insert("E");

    cout << "\nMULTISET 1" << endl;
    multiset<string>::iterator iter;
    for (iter = s1.begin(); iter != s1.end(); ++iter)
    {
        cout << *iter << "\n";
    }

    cout << "\n\n";

    s2.insert("10");
    s2.insert("20");
    s2.insert("30");
    s2.insert("40");
    s2.insert("50");

    cout << "\nMULTISET 2" << endl;
    multiset<string>::iterator iter1;
    for (iter1 = s2.begin(); iter1 != s2.end(); ++iter1)
    {
        cout << *iter1 << "\n";
    }

    s1.swap(s2);

    cout << "\nMULTISET 1" << endl;
    for (iter = s1.begin(); iter != s1.end(); ++iter)
    {
        cout << *iter << "\n";
    }

    cout << "\nMULTISET 2" << endl;
    for (iter1 = s2.begin(); iter1 != s2.end(); ++iter1)
    {
        cout << *iter1 << "\n";
    }

    return 0;
}
*/
#include <iostream> 
#include <map> 
using namespace std; 
int main() 
{ 
    map<int, int> m;
    m.insert(pair<int, int>(1, 100)); 
    m.insert(pair<int, int>(2, 200)); 
    m.insert(pair<int, int>(3, 300)); 
    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    { 
        cout << iter->first<< " " << iter->second << '\n'; 
    } 
     return 0;
}
