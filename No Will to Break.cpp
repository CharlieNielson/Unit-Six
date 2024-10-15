#include <iostream>
using namespace std;


const int SIZE = 10;


void displayArray(int numbers[]){
 for(int i = 0; i < SIZE; i++){
   cout << numbers[i] << ", ";
 }
 cout << endl;
}

void displayBackwards(int numbers[]){
 for(int i = SIZE - 1; i >= 0; i--){
   cout << numbers[i] << ", ";
 }
 cout << endl;
}

void sum(int numbers[]) {
  int end = 0;
  for (int i = 0; i < SIZE; i++) {
    end += numbers[i];
  }
  cout << end << endl;
}

void swap(int numbers[]) {
  cout << numbers[SIZE - 1] << ", ";
  for(int i = 1; i < SIZE - 1; i++){
   cout << numbers[i] << ", ";
 }
 cout << numbers[0] << endl;
}

int main() {
   int numbers[SIZE] = {5, 9, 3, 4, 5, 3, 2, 1, 4, 7};
   displayArray(numbers);
   displayBackwards(numbers);
   sum(numbers);
   swap(numbers);
  return 0;
}
