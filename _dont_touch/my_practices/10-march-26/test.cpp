#include <iostream>
#include <fstream>

using namespace std;

int rec(ofstream *file, int i){
    *(file) << "line: " << i << endl;
    i--;
    if(i!=0){
        return rec(file, i);
    }
    return 0;
}

int main()
{
    // ofstream file("data.txt");
    // int i = 9999999;
    // rec(&file, i);
    // file.close();

    ifstream file("2.cpp");

    string text;
    while(getline(file, text)){
        cout << text << endl;
    }

    return 0;
}