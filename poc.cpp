#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > table;

int BinarySearch(vector<int> A, int greater, int smaller) {
    int right = A.size() - 1;
    int left = 0;
    int middle;
    while (left < right) {
        middle = (left + right) / 2;
        if (A[middle] < greater) left = middle + 1;
        else if (A[middle] > smaller) right = middle;
        else return 1;
    }
    if (A[left] < greater || A[left] > smaller)
        return 0;
    else
        return 1;
}

void Read(int a, vector<int>& Array) {
    int x;
    for (int i = 0; i < a; i++) {
        cin >> x;
        Array.push_back(x);
    }
}

void Print(int a, vector<int> Array) {
    for (int i = 0; i < a; i++) {
        cout << Array[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    vector<int> Wagons, Template, Answers, AlreadyChecked, AlreadyChecked_Reverse;

    cin >> n >> m >> k;

    table Positions;
    Positions.resize(k + 1);

    Answers.resize(n, 0);

    Read(n, Wagons);
    Read(m, Template);

    int i = 0, position = 0;
    while (i < n) {
        AlreadyChecked.push_back(position);
        if (position < m && Wagons[i] == Template[position]) {
            Answers[i] = true;
            Positions[Wagons[i]].push_back(position);
            position++;
        }
        else if (position > 0 && Wagons[i] == Template[position - 1]) {
            Answers[i] = true;
        }
        i++;
    }
    position--;
    i--;
    while (i >= 0) {
        AlreadyChecked_Reverse.push_back(position);
        if (position > -1 && Wagons[i] == Template[position]) {
            Answers[i] = true;
            position--;
        }
        else if (position < m - 1 && Wagons[i] == Template[position + 1]) {
            Answers[i] = true;
        }
        i--;
    }
    for (int i = 0; i < n; i++) {
        if (Answers[i] == false && Positions[Wagons[i]].size() > 0) {
            Answers[i] = BinarySearch(Positions[Wagons[i]], AlreadyChecked_Reverse[n - i - 1], AlreadyChecked[i]);
        }
    }
    Print(n, Answers);
    return 0;
}
