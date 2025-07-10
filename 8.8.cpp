#include <iostream>
#include <vector>
using namespace std;

bool canSeat(int x, int M, int N, const vector<int>& favorites, int& notSeated) {
    vector<int> seats(M, 0);
    notSeated = 0;

    for (int i = 0; i < x; ++i) {
        int fav = favorites[i] - 1;
        bool seated = false;

        if (seats[fav] < N) {
            seats[fav]++;
        }
        else {
            int alt = (fav + 1) % M;
            if (seats[alt] < N) {
                seats[alt]++;
                notSeated++;
            } else {
                notSeated++;
            }
        }
    }
    return true; 
}

int main() {
    int X, M, N;
    cout << "Введите количество студентов X: ";
    cin >> X;
    cout << "Введите количество рядов M: ";
    cin >> M;
    cout << "Введите количество мест в ряду N: ";
    cin >> N;

    vector<int> favorites(X);
    cout << "Введите любимые ряды студентов:\n";
    for (int i = 0; i < X; ++i) {
        cin >> favorites[i];
    }

    int badCount = 0;
    canSeat(X, M, N, favorites, badCount);

    cout << "Количество студентов, которые не сели на любимый ряд: " << badCount << endl;
    return 0;
}
