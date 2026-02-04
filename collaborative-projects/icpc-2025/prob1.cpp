#include <bits/stdc++.h>
using namespace std;

int main() {

    int numGrades;
    string grade;
    cin >> numGrades;
    int sum = 0;
    float gpa = 0.0f;
    int gpaA = 0;

    for (int i = 0; i < numGrades; i++) {

        cin >> grade;
        if (grade[0] == 'A') sum += 4;
        if (grade[0] == 'B') sum += 3;
        if (grade[0] == 'C') sum += 2;
        if (grade[0] == 'D') sum += 1;

        if (grade[1] == '1' && (grade[0] != 'D' && grade[0] != 'E')) gpaA += 50;
        if (grade[1] == '2' && (grade[0] != 'D' && grade[0] != 'E')) gpaA += 25;

    }

    gpa = static_cast<float> (sum) / static_cast<float> (numGrades);
    gpa += gpaA * 0.001f;

    cout << fixed << setprecision(10);
    cout << gpa << endl;

    return 0;
}