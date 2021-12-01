#include <iostream>

using namespace std;

// Declare the function
int smallestIndex(int a[],int size);

int main() {
    const int size = 15;
    int p, a[size];
    // Get the array data
    for (int i = 0; i < 15;i++){
      cin >> a[i];
    }
    // Call the function and print its result
    p = smallestIndex(a,size);
    cout << "The position of the first ocrrucence of the smallest element in list is: " << p << endl;
    cout << "The smallest element in list is: " << a[p] << endl;
    return 0;
}
int smallestIndex(int a[],int size){
  int s = 10000, p;
  for(int i = 0; i < size; i++){
    if(a[i] < s){
      s = a[i];
      p = i;
    }
  }
  return p;
}
