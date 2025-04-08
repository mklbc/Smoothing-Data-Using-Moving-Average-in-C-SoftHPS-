#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int main() {
    const int N = 16000;
    vector<double> a(N);
    vector<double> b(N);

    // Diziyi sıralı değerlerle doldur
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    // Ortalama değerleri hesapla
#pragma omp parallel for
    for (int i = 1; i < N - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }

    // Sonuçları yazdır
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << b[i] << " ";
    }

    cout << endl;

    return 0;
}
