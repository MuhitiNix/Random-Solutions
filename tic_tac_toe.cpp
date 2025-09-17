#include<iostream>
using namespace std;

int isWin(int a[][4], int n) {
   
    for (int i = 1; i <= n; i++) {
        if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != -1) {
            return a[i][1];
        }
    }
    
    for (int j = 1; j <= n; j++) {
        if (a[1][j] == a[2][j] && a[2][j] == a[3][j] && a[1][j] != -1) {
            return a[1][j];
        }
    }
   
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] != -1) {
        return a[1][1];
    }
    if (a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] != -1) {
        return a[1][3];
    }
    return -1;
}

void printcell(int a[][4], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == -1)
                cout << "   ";   
            else if (a[i][j] == 1)
                cout << " X ";
            else if (a[i][j] == 2)
                cout << " O ";

            if (j < n) cout << "|";
        }
        cout << endl;
        if (i < n) cout << "-----------" << endl;
    }
    cout << endl;
}

bool isFull(int a[][4], int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == -1) return false;
    return true;
}

int main() {
    int n = 3;
    int a[4][4];

  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = -1;
        }
    }

    bool player1 = true;

    while (true) {
        printcell(a, n);

        int r, c;
        cout << "Player " << (player1 ? "1 (X)" : "2 (O)") 
             << ", enter row and column (1-3): ";
        cin >> r >> c;

      
        if (r < 1 || r > 3 || c < 1 || c > 3) {
            cout << "Invalid row/column! Try again.\n";
            continue;
        }
        if (a[r][c] != -1) {
            cout << "Cell already filled! Try again.\n";
            continue;
        }

        a[r][c] = (player1 ? 1 : 2);

    
        int winner = isWin(a, n);
        if (winner == 1) {
            printcell(a, n);
            cout << "Player 1 (X) wins!\n";
            break;
        } else if (winner == 2) {
            printcell(a, n);
            cout << "Player 2 (O) wins!\n";
            break;
        }

        if (isFull(a, n)) {
            printcell(a, n);
            cout << "It's a draw!\n";
            break;
        }

        player1 = !player1;
    }

    return 0;
}
