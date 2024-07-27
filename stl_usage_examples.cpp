#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void vectorModule() {
    vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec.pop_back();

    cout << "Vector size: " << vec.size() << endl;

    vec.insert(vec.begin() + 1, 15);

    cout << "Vector elements: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> vec2 = {1, 2, 3};
    vec.swap(vec2);

    cout << "Vector after swapping: ";
    for (auto &i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void dequeModule() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);

    dq.push_front(5);

    dq.pop_back();
    dq.pop_front();

    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    cout << "Deque size: " << dq.size() << endl;
}

void listModule() {
    list<int> li;

    li.push_back(10);
    li.push_back(20);

    li.push_front(5);

    li.pop_back();
    li.pop_front();

    cout << "Front element: " << li.front() << endl;
    cout << "Back element: " << li.back() << endl;

    cout << "List size: " << li.size() << endl;

    li.reverse();

    li.push_back(10);
    li.push_back(20);
    li.push_back(10);
    li.unique();

    li.sort();

    li.remove(10);

    cout << "List elements: ";
    for (const auto &ele : li) {
        cout << ele << " ";
    }
    cout << endl;
}

void setModule() {
    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout << "Set size: " << s.size() << endl;

    s.erase(20);

    s.clear();

    set<int> s2 = {10, 20, 30, 40, 50};
    auto it1 = s2.lower_bound(25);
    auto it2 = s2.upper_bound(35);

    cout << "Set elements: ";
    for (const auto &ele : s2) {
        cout << ele << " ";
    }
    cout << endl;

    cout << "Lower bound of 25: " << *it1 << endl;
    cout << "Upper bound of 35: " << *it2 << endl;
}

void multisetModule() {
    multiset<int> ms;

    ms.insert(10);
    ms.insert(20);
    ms.insert(10);

    cout << "Multiset size: " << ms.size() << endl;

    ms.erase(10);

    ms.clear();

    multiset<int> ms2 = {10, 20, 30, 40, 50, 50, 60};
    auto it1 = ms2.lower_bound(25);
    auto it2 = ms2.upper_bound(35);

    cout << "Multiset elements: ";
    for (const auto &ele : ms2) {
        cout << ele << " ";
    }
    cout << endl;

    cout << "Lower bound of 25: " << *it1 << endl;
    cout << "Upper bound of 35: " << *it2 << endl;
}

void mapModule() {
    map<string, int> mp;

    mp.insert({"RAHUL", 25});
    mp.insert({"DEV", 30});
    mp.insert({"ADITYA", 22});

    cout << "Map size: " << mp.size() << endl;

    mp.erase("DEV");

    cout << "Map elements: ";
    for (const auto &ele : mp) {
        cout << ele.first << ":" << ele.second << " ";
    }
    cout << endl;

    map<int, string> mp2 = {{10, "RAHUL"}, {20, "DEV"}, {30, "ADITYA"}, {40, "Bob"}};
    auto it1 = mp2.lower_bound(25);
    auto it2 = mp2.upper_bound(35);

    cout << "Lower bound of 25: " << it1->first << ":" << it1->second << endl;
    cout << "Upper bound of 35: " << it2->first << ":" << it2->second << endl;
}

void multimapModule() {
    multimap<string, int> mmp;

    mmp.insert({"RAHUL", 25});
    mmp.insert({"DEV", 30});
    mmp.insert({"RAHUL", 22});

    cout << "Multimap size: " << mmp.size() << endl;

    mmp.erase("RAHUL");

    cout << "Multimap elements: ";
    for (const auto &ele : mmp) {
        cout << ele.first << ":" << ele.second << " ";
    }
    cout << endl;

    multimap<int, string> mmp2 = {{10, "RAHUL"}, {20, "DEV"}, {30, "ADITYA"}, {30, "Bob"}};
    auto it1 = mmp2.lower_bound(25);
    auto it2 = mmp2.upper_bound(35);

    cout << "Lower bound of 25: " << it1->first << ":" << it1->second << endl;
    cout << "Upper bound of 35: " << it2->first << ":" << it2->second << endl;
}

void stackModule() {
    stack<int> stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Stack size: " << stk.size() << endl;

    stk.pop();

    cout << "Top element: " << stk.top() << endl;

    cout << "Stack elements: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void queueModule() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue size: " << q.size() << endl;

    q.pop();

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n======================\n";
        cout << "Choose an option:\n";
        cout << "1. Vector\n";
        cout << "2. Deque\n";
        cout << "3. List\n";
        cout << "4. Set\n";
        cout << "5. Multiset\n";
        cout << "6. Map\n";
        cout << "7. Multimap\n";
        cout << "8. Stack\n";
        cout << "9. Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vectorModule();
                break;
            case 2:
                dequeModule();
                break;
            case 3:
                listModule();
                break;
            case 4:
                setModule();
                break;
            case 5:
                multisetModule();
                break;
            case 6:
                mapModule();
                break;
            case 7:
                multimapModule();
                break;
            case 8:
                stackModule();
                break;
            case 9:
                queueModule();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
