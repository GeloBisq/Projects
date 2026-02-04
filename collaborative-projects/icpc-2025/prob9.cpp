//
// Created by icpc119 on 11/15/25.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    double money;
    cout << fixed << showpoint;
    while (cin >> money) {
        while (!(money >= 0.03f && money <= 10000.0f)) cin >> money;
        money *= 100.0f;
        int round = static_cast<int> (money + 0.001);
        money /= 100.0f;
        if (round > 10) round %= 10;
        if ((round == 3) || (round == 4)) money += 0.01 * (5 - round);
        else if ((round == 8) || (round == 9)) money += 0.01 * (10 - round);
        else if ((round == 1) || (round == 2)) money -= 0.01 * round;
        else if ((round == 6) || (round == 7)) money -= 0.01 * (round - 5);
        cout << setprecision(2);
        cout << money << endl;

    }

    return 0;
}