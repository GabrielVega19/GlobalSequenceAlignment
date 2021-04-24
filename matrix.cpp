#include <iostream>
#include "matrix.h"

using std::string;
using std::endl;
using std::cout;

ED::ED(string initA, string initB): a(initA), b(initB), eDist(0), rows(a.length() + 1), columns(b.length() + 1){
    op = new int*[rows];
    for (int i = 0; i < rows; ++i){
        op[i] = new int [columns];
    } 
}

ED::~ED(){
    for (int i = 0; i < rows; ++i){
        delete[] op[i];
    }

    delete[] op;
}

int ED::optDistance(void){
    //sets up the gap column and row
    op[rows - 1][columns - 1] = 0;
    for (int i = columns - 2; 0 <= i; --i){
        op[rows-1][i] = op[rows-1][i + 1] + 2;
    }
    for (int i = rows - 2; 0 <= i; --i){
        op[i][columns - 1] = op[i + 1][columns - 1] + 2;
    }

    //calculations to set up the rest of the table
    for (int i = rows - 2; 0 <= i; --i){
        for (int j = columns - 2; 0 <= j; --j){
            op[i][j] = ED::min(op[i + 1][j + 1] + ED::penalty(a[i], b[j]), op[i + 1][j] + 2, op[i][j + 1] + 2);
        }
    }
    
    //return the ED
    eDist = op[0][0];
    return op[0][0];
}

int ED::min(int x, int y, int z){
    int l = (x < y) ? x : y;
    l = (l < z) ? l : z;

    return l;
}

string ED::Alignment(void){
    int i = 0, j = 0;
    string output;

    while (i != rows - 1 || j != columns - 1){
        if(((a[i] == b[j]) && (op[i][j] == op[i + 1][j + 1])) || ((a[i] != b[j]) && (op[i][j] == op[i + 1][j + 1] + 1))){
            output += a[i];
            output += ' ';
            output += b[j];
            output += ' ';
            output += weight(a[i], b[j]);

            i += 1;
            j += 1;
        }else if(op[i][j] == op[i + 1][j] + 2){
            output += a[i];
            output += ' ';
            output += '-';
            output += ' ';
            output += weight(a[i], '-');

            i += 1;
        }else {
            output += '-';
            output += ' ';
            output += b[j];
            output += ' ';
            output += weight('-', b[j]);

            j += 1;
        }

        output += '\n';
    }

    return output;
}

int ED::penalty(char a, char b){
    return (a == b) ? 0 : 1;
}


ostream& operator<<(ostream& out, const ED& right){
    for (int i = 0; i < right.rows; ++i){
        for (int j = 0; j < right.columns; ++j){
            out << right.op[i][j] << ' ';
        }
        out << endl;
    }

    out << "A: " << right.a << endl << "B: " << right.b << endl;
    out << "ED: " << right.eDist << endl << "Rows: " << right.rows << endl << "Columns: " << right.columns << endl;

    return out;
}

char ED::weight(char a, char b){
    if (a == b){
        return '0';
    }else if (a == '-' || b == '-'){
        return '2';
    }
    else {
        return '1';
    }
}

int ED::getED(void){
    return eDist;
}