#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[]){
    //inputs the strings from cin 
    string a, b, c;
    cin >> a;
    cin >> b;

    //created the object and sets the string to c
    ED test(a, b);
    test.optDistance();
    c = test.Alignment();

    //prints out the string and the edit distance
    cout << "Edit distance = " << test.getED() << endl << c << endl;

    return 0;
}


