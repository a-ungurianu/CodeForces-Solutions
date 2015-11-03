#include <fstream>
#include <iostream>

using namespace std;

long long pow(long long b, int e) {
    long long res = 1;

    for(int i = 0; i < e; ++i) {
        res *= b;
    }
    return b;
}

long long result1(long long n) {
    //      x*(1 + x -     x^2)  /(   (1-x)^4*(1+x))
    return (n*(1 + n - pow(n,2)))/(pow(1-n,4)*(1+n));
}

long long resultFib(long long n) {

    long long f1 = 3;
    long long f2 = 5;

    for(int i = 0; i < n; ++i) {
        long long t = f2;
        
        f2 = f1 + f2;
        
        f1 = t;
    }

    return f2 - 4;
}

int main() {
    long long n;

    cin >> n;

    cout << resultFib(n-3) << '\n';
}