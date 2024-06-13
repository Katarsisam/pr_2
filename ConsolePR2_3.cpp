
#include <iostream>
#include <stdio.h>


#include <tuple>
using namespace std;

tuple<int, int, int> generEuclidAlg(int a, int b) {
    if (b == 0) {
        return make_tuple(a, 1, 0);
    } else {
        int d, x, y;
        tie(d, x, y) = generEuclidAlg(b, a % b);
        return make_tuple(d, y, x - (a / b) * y);
    }
}

int findMultIn(int d, int m) {
    int s, _;
    tie(_, s, _) = generEuclidAlg(d, m);
    return (s % m + m) % m;  // Handling negative modulo result
}

int main() {
    int m;  
    int num;
    printf("Enter d,mod:\n");
    scanf("%d%d",&num,&m); 
    int s = findMultIn(num, m);

    cout << num << "^-1" << " mod " << m << " = " << s << endl;
    cout << num << " * " << s << " mod " << m << " = 1" << endl;

    return 0;
}
