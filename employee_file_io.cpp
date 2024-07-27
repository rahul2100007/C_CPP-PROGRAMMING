#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int id;
    string name,address,salary;

    ofstream ofs;
    ofs.open("employee.txt",ios::out);
    cout<<"input id name address salary";
    cin>>id>>name>>address>>salary>>endl;
    ofs<<id<<"\t"<<name<<"\t"<<address<<"\t"<<salary<<endl;
    ofs.close();
    ifstream ifs;
    ifs.open("employee.txt",ios::in);
    ifs>>id>>name>>address>>salary;
    cout<<id<<"\t"<<name<<"\t"<<address<<"\t"<<salary<<endl;
    ifs.close();
    return 0;


}