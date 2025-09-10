#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void sortDescending(string &str) {
    sort(str.begin(), str.end(), greater<char>());
}

int main() {
    string input;
    cin >> input;

    sortDescending(input);

    cout << input << endl;

    return 0;
}
