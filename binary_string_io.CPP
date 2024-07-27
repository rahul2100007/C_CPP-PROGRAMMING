#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream ofs("t1.bin",ios::binary);
    string s1="hello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello baccho";
    string s2="hello bhaio";
    ofs.write((char*) &s1,sizeof(s1));
    ofs.write((char*) &s2,sizeof(s2));
    ofs.close();
    ifstream ifs("t1.bin",ios::binary);
    ifs.read((char*) &s1,sizeof(s1));
    ifs.read((char*) &s2,sizeof(s2));
    cout<<s1<<endl;
    cout<<s2<<endl;
    ifs.close();

   
 return 0;
}