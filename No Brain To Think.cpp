#include <iostream>
using namespace std;


int main() {
    struct stuff {
        int one;
        int two;
        int three;
    };
    stuff things[5];
    things[1].one = 5;
    things[1].two = 7;
    things[1].three = 2;
    int example[5] = {5, 3, 7, 4, 9};//An array(Apparently like a list).
    int thing[5];
    int exp[2][3] = {//name[rows][collums]
        {1, 2, 4},
        {8, 16, 32}
    };//2D array(LISTS).[[stuff], [stuff], [stuff]]
    string sling = "Many things.";
    char tic = 'M';//single character

    char name[8] = "Charlie";//Strings concatinante with strings only, not numbers.
    char name[8] = {'C', 'h', 'a', 'r', 'l', 'i', 'e', '\0'};


    cout << thing[2] << endl;
    cout << things[1].two << endl;

    return 0;
}
