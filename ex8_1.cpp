#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double alpha[50];
    // First 25 elements
    for(int i = 0; i <= 25;i++){
      alpha[i] = pow(i,2);
    }
    // Last 25 elements
    for(int i = 26; i <= 49;i++){
      alpha[i] = i*3;
    } 
    //
    for(int i = 0; i < 50;i++){
      cout << setw(4) << alpha[i] << " ";
      if ((i+1 % 5) == 0){
        cout << endl;
      }
    }
    return 0;
}
