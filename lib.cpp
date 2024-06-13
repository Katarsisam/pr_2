#include "lib.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <random>
#include <tuple>
using namespace std;
long long powX(long long &x, int a, int X) { //���������� ����� ��������
    int N = floor(abs(log2(X)+1));
    
    int MX = X;
    vector<int> binaryRep(N);
    for(vector<int>::iterator bR = binaryRep.begin(); bR!= binaryRep.end(); bR++){
        *bR = MX%2;
        MX/=2;}
    //reverse(binaryRep.begin(),binaryRep.end());
    
    for (int i = 0; i < N; i++) {
        cout << binaryRep[N-1-i];
        x *= pow(pow(a, pow(2, i)), binaryRep[i]);
       
    }
    cout << " " << x;
    return x;
}

int FermsTheorema(int number, int deductionModule) { // ������� �����
	if (number % deductionModule == 0) { //���� ����� ������� �� ������� ����� ��� �������
		return 0;                        //���� �� ������ �����
	} else {
		return 1;
	}
}

int SimplNumb(int &a) {
    if (a > 2) {
        for (int i = 2; i < a; i++)
            if (a % i == 0) return false;
        return true;
    }
    else
        return false;
}


void PrintThFerma(int& number, int& degree, int& deductionModule) { // ����� ������� ����� ����� � ������ �
	cout << "\nBy Fermat's theorem:\n" << endl;
	if (FermsTheorema(number, deductionModule) == 0) {          // ����� ����� ������ �������� ������
		cout << number << "^" << degree << " mod " << deductionModule << " = 0" << endl;
	}
	else {    //����� ����� �� ������ ��������
		cout << number << "^" << degree << " mod " << deductionModule << " = " << number << "^" << degree - 1 << " mod " << deductionModule << " = 1";
	}
}


