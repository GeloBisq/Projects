#include <bits/stdc++.h>
using namespace std;

int main() {

    int numRemotes;
    int numTV = 0;
    cin >> numRemotes;
    int remotes[numRemotes][2];
    int pos[numRemotes][2];
    for (int i  = 0; i < numRemotes; i++) {

        cin >> remotes[i][0] >> remotes[i][1];
        pos[i][0] = remotes[i][0] - remotes[i][1];
        pos[i][1] = remotes[i][0] + remotes[i][1];

    }
    for (int i  = 0; i < numRemotes; i++) {

        for (int j = i; j < numRemotes - 1; j++) {

            if (pos[i][0] > pos[j][0] && pos[i][1] < pos[j][1]) numTV++;

        }

    }

    cout << numTV << endl;

    return 0;

}