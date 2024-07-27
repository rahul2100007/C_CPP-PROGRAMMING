#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Writing strings to a binary file
    ofstream ofs("t1.bin", ios::binary);
    string s1 = "hello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello bacchoello baccho";
    string s2 = "hello bhaio";
    int len1 = s1.size();
    int len2 = s2.size();
    ofs.write((char*)&len1, sizeof(len1)); // Write length of the first string
    ofs.write(s1.c_str(), len1);           // Write first string data
    ofs.write((char*)&len2, sizeof(len2)); // Write length of the second string
    ofs.write(s2.c_str(), len2);           // Write second string data
    ofs.close();

    // Reading strings from the binary file
    ifstream ifs("t1.bin", ios::binary);
    ifs.read((char*)&len1, sizeof(len1));  // Read length of the first string
    char* buffer1 = new char[len1 + 1];
    ifs.read(buffer1, len1);               // Read first string data
    buffer1[len1] = '\0';                  // Null-terminate the string
    s1 = buffer1;
    delete[] buffer1;

    ifs.read((char*)&len2, sizeof(len2));  // Read length of the second string
    char* buffer2 = new char[len2 + 1];
    ifs.read(buffer2, len2);               // Read second string data
    buffer2[len2] = '\0';                  // Null-terminate the string
    s2 = buffer2;
    delete[] buffer2;

    cout << s1 << endl;
    cout << s2 << endl;
    ifs.close();

    return 0;
}
