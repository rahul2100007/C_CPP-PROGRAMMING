/*#include <iostream>
#include <map>
using namespace std;
int main()
{

    map<int, int> m;
    m.insert(pair<int, string>(1, 100));
    m.insert(pair<int, string>(2, 200));
    m.insert(pair<int, string>(3, 300));
    map<int, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " " << iter->second << '\n';
    }
    return 0;
}

*/
/*
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> m;
    m.insert(pair<int, string>(1, "Sumit"));
    m.insert(pair<int, string>(2, "Vijay"));
    m.insert(pair<int, string>(3, "Sulekha"));
    map<int, string>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " " << iter->second << '\n';
    }
    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()  {
    map<int, string> m;
    m.insert(pair<int, string>(1, "Sumit"));
    m.insert(pair<int, string>(2, "Manish"));
    m.insert(pair<int, string>(3, "Sidharth"));
    m.insert(pair<int, string>(4, "Krimal"));
    m.insert(pair<int, string>(5, "Priyanshu"));

    std::map<int, string>::iterator it;
    it = m.find(2);

    if (it!= m.end())
    {
        cout << endl << "Key 2 has the value: => "<< m.find(2)->second << '\n';
    }
    return 0;
}
*/
//=====================SATCK=============//
/*
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Total number of element in stack:"<<s.size();
    cout<<"\nTop element of  stack:"<<s.top()<<endl;
    return 0;
}
*/
/*
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "\nTotal number of element in stack:" << s.size();
    cout << "\nTop element:" << s.top() << endl;
    s.pop();
    cout << "\nAfter removed one eleement from stack, stacke size:" << s.size() << endl;
    cout << "Top element:" << s.top() << endl;
    s.pop();
    cout << "\nAfter removed one eleement from stack, stacke size:" << s.size() << endl;
    cout << "Top element:" << s.top() << endl;
    cout << "\n Insert element in list:\n";
    s.push(50);
    cout << "\nAfter add one eleement in stack, stacke size:" << s.size() << endl;
    cout << "Top element:" << s.top() << endl;
    cout << "\nNow, total number of element in stack:" << s.size();
    return 0;
}
*/
//=======================queue=============================//
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout<<"Size of queue:"<<q.size()<<endl;
	cout<<"First element of queue:"<<q.front()<<endl;
	q.pop();
	cout<<"Updated size of queue:"<<q.size()<<endl;
	cout<<"First element of queue:"<<q.front()<<endl;
	q.push(50);
	cout<<"Updated size of queue:"<<q.size();
	return 0;
}

