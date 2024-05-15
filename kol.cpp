#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 2000;

struct coordinate {
    int x, y;
};

int Board[MAX_LEN][MAX_LEN] = { 0 };
int Head[MAX_LEN][MAX_LEN] = { 0 };
vector<int> snake;

void Load_Board(int m) {
    for (int i = 0; i < m; i++) {
        int row, col, cell;
        cin >> row >> col >> cell;
        Board[row - 1][col - 1] = cell;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, p, n;
    cin >> m >> p >> n;
    for (int i = 0; i < MAX_LEN; i++)
        for (int j = 0; j < MAX_LEN; j++) {
            Board[i][j] = -1;
        }
    Load_Board(p);
    coordinate head = { 0, 0 };
    Head[0][0] = 1;
    snake.push_back(0);
    int move = 1;
    for (int i = 0; i < n; i++) {
        char order;
        cin >> order;
        if (order == 'D') {
            head.x++;
            move++;
            Head[head.x][head.y] = move;
            if (Board[head.x][head.y] >= 0) {
                snake.push_back(Board[head.x][head.y]);
                Board[head.x][head.y] = -1;
            }
        }
        else if (order == 'G') {
            head.x--;
            move++;
            Head[head.x][head.y] = move;
            if (Board[head.x][head.y] >= 0) {
                snake.push_back(Board[head.x][head.y]);
                Board[head.x][head.y] = -1;
            }
        }
        else if (order == 'P') {
            head.y++;
            move++;
            Head[head.x][head.y] = move;
            if (Board[head.x][head.y] >= 0) {
                snake.push_back(Board[head.x][head.y]);
                Board[head.x][head.y] = -1;
            }
        }
        else if (order == 'L') {
            head.y--;
            move++;
            Head[head.x][head.y] = move;
            if (Board[head.x][head.y] >= 0) {
                snake.push_back(Board[head.x][head.y]);
                Board[head.x][head.y] = -1;
            }
        }
        else if (order == 'Z') {
            coordinate query;
            cin >> query.x >> query.y;
            query.x--; query.y--;
            if (Head[query.x][query.y] != 0 && move - Head[query.x][query.y] < snake.size())
                cout << snake[snake.size() - move + Head[query.x][query.y] - 1] << "\n";
            else cout << -1 << "\n";
        }

    }
    return 0;
}
