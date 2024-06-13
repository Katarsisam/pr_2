#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number, stepen1, stepen2;
    
    cout << "Number: ";
    cin >> number;

    cout << "pow of Number: ";
    cin >> stepen1;

    cout << "pow of pow: ";
    cin >> stepen2;

    long result = pow(number, stepen1);
    result = pow(result, stepen2);

    int lastfigure = result % 10;

    cout << "the last digit of number: " << lastfigure << endl;

    return 0;
}