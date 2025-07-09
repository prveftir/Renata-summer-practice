#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    int d = sqrt(x);
    for (int i = 3; i <= d; i += 2)
        if (x % i == 0) return false;
    return true;
}

bool isSquare(double x) {
    int r = (int)(sqrt(x) + 0.5);
    return r * r == (int)(x);
}

int main() {
    int m;
    cout << "Введите M: ";
    cin >> m;

    int count = 0;

    for (int p = 2; p < m; ++p) {
        if (isPrime(p)) {
            double expr = (double)(p * p + 1) / (2 * p);
            if (isSquare(expr)) {
                count++;
                cout << "p = " << p << ", значение = " << expr << " — квадрат" << endl;
            }
        }
    }

    cout << "Количество: " << count << endl;
    return 0;
}
