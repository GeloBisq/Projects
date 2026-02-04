#include <bits/stdc++.h>
using namespace std;

int main() {

    int cubes;
    cin >> cubes;
    vector<int> sL(cubes);
    vector<int> area(cubes);
    int volume = 0;
    for (int i = 0; i < cubes; i++) {

        cin >> sL[i];
        area[i] = sL[i] * sL[i];
        volume += area[i] * 6;

    }
    for (int i = 0; i < cubes - 1; i++) {

        if (area[i] >= area[i + 1]) volume -= area[i + 1] * 2;
        else if (area[i] < area[i + 1]) volume -= area[i] * 2;

    }

    cout << volume << endl;

    return 0;
}//
// Created by icpc119 on 11/15/25.
//