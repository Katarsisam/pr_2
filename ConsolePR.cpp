#include "lib.h"
#include <iostream>
#include <stdio.h>
#include <locale>

using namespace std;



int main()
{
    setlocale(LC_ALL, "RUS");

    long long x = 1;
    int p, X, a;
    
    printf("Print A\n");
    scanf("%d", &a);
        do {
            printf("Print mod\n");
            scanf("%d", &p);
                if (SimplNumb(p) == false)
                    printf("Try again\n");
        } while (SimplNumb(p) == false);
    X = p - 1; 
    printf("Pow %d\n", X);//степень
    printf("\na^x Mod(%d) = %lld\n", p, powX(x, a,  X)%p);
    PrintThFerma(a,X,p);
   
    return 0;
}


