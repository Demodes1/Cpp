#include <iostream>
#include <iomanip>

using namespace std;
double factorial(double n) {
    double fact = n;
    if (n>0){
      for(int i = n-2; i>0;i--){
        fact += (fact*i);
      }
      return fact;
    } else if(n == 0){
      return 1;
    } else {
      cout << "It's negative, try again" << endl << endl;
    }
}

int main() {
    double n, total = 0;
    cout << fixed << setprecision(15);
    
    cout << "Enter the n: ";
    cin >> n;
    cout << endl;

    for(int i = 2;i<=n;i++){
      total += (1/(factorial(i)));
    }
    total += 2;
    cout << total << endl;
    
    // Write your main here
    return 0;
}
