#include <stdio.h>
#include <tuple>
#include <cmath>
#include <random>
#include <time.h>
#include "lib.h"
using namespace std;
tuple<int, int, int> KeyGen(int &m, int *x);
tuple<int, int> El_Gamal(tuple<int,int,int> openKey);
int decoder(int u, int v, int x, int m);
int main() {
    int m, x;
    int u,v;
    tie(u,v) = El_Gamal(KeyGen(m,&x));
    printf("Coded_Massage: %d %d\n",u,v);
    printf("Massage: %d\n",decoder(u,v,x,m));
    return 0;
}

tuple<int, int> El_Gamal(tuple<int,int,int> openKey){
   
    int m,y,g,k,p;
    
    tie(p,g,y) = openKey;
    srand(time(0));
    k = int(1 + rand()%((p-2)-1+1));
    printf("Enter the massage: ");
            scanf("%d", &m);
    
    return make_tuple((int)pow(g,k)%p,(long)(powl(y,k)*m)%p);
}

tuple<int, int, int> KeyGen(int &m, int *x){
    int g = 1,  y;
    printf("Print simp numb\n");
        do {
            scanf("%d", &m);
                if (SimplNumb(m) == false)
                    printf("Try again\n");
        } while (SimplNumb(m) == false);
    srand(time(0));
    *x = int(1 + rand()%((m-2)-1+1));
    //printf("%d\n", x);
    do {
        ++g;
    } while (FermsTheorema(pow(g,m-1),m) == false);
    y = (int)pow(g,*x) % m;
    printf("Key: %d %d %d\n",m,g,y);
    return make_tuple(m,g,y);
}

int decoder(int u, int v, int x, int m){
   // printf("%d %d %d %d\n", x, m, u, v);
    int MX = pow(u,m-1)*pow(u,-x);
    return (int)(MX*v)%m;
}