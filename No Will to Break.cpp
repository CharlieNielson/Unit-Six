#include <iostream>
using namespace std;


const int SIZE = 10;


void displayArray(int numbers[]){
 for(int i = 0; i < SIZE; i++){
   cout << numbers[i] << ", ";
 }
 cout << endl;
}


int main() {
   int numbers[SIZE] = {5, 9, 3, 4, 5, 3, 2, 1, 4, 7};
   displayArray(numbers);

  return 0;
}
