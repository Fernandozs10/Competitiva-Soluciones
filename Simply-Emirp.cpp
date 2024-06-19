#include <iostream>
#include <cmath>
using namespace std;

// Función para obtener el reverso de un número
long int NReverse(long int n) {
    long int r = 0;
    while(n > 0) {
        r = (r*10) + (n%10);
        n /= 10;
    }
    return r;
}

// Función para verificar si un número es primo
bool IsPrime(long int n) {
    if (n <= 1) return false; // Agregado para manejar casos de números <= 1
    int x = sqrt(n);
    for(int i = 2; i <= x; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    long int n, rn;
    bool p, ep;
    while(cin >> n) {
        ep = p = false;
        p = IsPrime(n);
        rn = NReverse(n);
        if(n != rn) ep = IsPrime(rn);
        if(ep && p)
            cout << n << " is emirp." << endl;
        else if(p)
            cout << n << " is prime." << endl;
        else
            cout << n << " is not prime." << endl;
    }
    return 0;
}
