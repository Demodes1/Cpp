#include <iostream>

using namespace std;
bool isVowel(char v){
    return (v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U' || v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u');
}

int main() {
    char v;
    int vowel = 0;

    cout << "Enter a vowel: ";
    cin >> v;
    cout << endl;
    if(isVowel(v)){
      vowel++;
    }
    cout << v << " is a vowel: " << vowel << endl;

    return 0;
}
