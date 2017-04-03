#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;
int main()
{
    char s;
    ifstream file_a;
    ofstream file_b;

    file_a.open("/tmp/a.txt", ios::trunc);
    file_b.open("/tmp/b.txt", ios::trunc);

    if (!(file_a||file_b))
       cout<<"Error in opening file";
    while (!file_a.eof()) {
        file_a>>s;
        file_b<<s;
    }

    file_a.close();
    file_b.close();
}
