#include <iostream>
#include <complex>
using namespace std;

int main() {
    int n;
    cout << "Введите количество комплексных чисел: ";
    cin >> n;

    complex<float> sum = 0;
    for (int i = 0; i < n; ++i) {
        float a, b;
        cout << "Введите действительную и мнимую части a[" << i+1 << "]: ";
        cin >> a >> b;
        complex<float> c(a, b);
        sum += c;
    }

    cout << "Сумма комплексных чисел: " << sum.real() << " + " << sum.imag() << "i\n";
    return 0;
}
