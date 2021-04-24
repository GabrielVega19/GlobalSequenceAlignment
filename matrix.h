#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using std::ostream;
using std::string;

class ED {
public:
    static int penalty(char a, char b);
    static int min(int x, int y, int z);
    
    ED(string initA, string initB);
    ~ED();

    int optDistance(void);
    int getED(void);
    string Alignment(void);
    char weight(char a, char b);

    friend ostream& operator<<(ostream& out, const ED& right);

private:
    int** op;
    string a, b;
    int eDist;
    int rows, columns;

};

ostream& operator<<(ostream& out, const ED& right);

#endif