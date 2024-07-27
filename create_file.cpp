#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ofstream obj;
    string fname;
    cin>>fname;
    obj.open(fname.c_str());
    if(obj.good()){
        cout<<"file created";
    }
    else{
        exit(0);
    }
    obj.close();
    return 0;
}