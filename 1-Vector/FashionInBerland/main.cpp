#include <iostream>

using namespace std;

int main() {
    int n;
    int temp;
    int count = 0;

    cin >> n;

    if (n == 1) {
        cin >> temp;
        if (temp == 1) {
            cout << "YES";
            return 0;
        } else {
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        cin >> temp;
        if (temp == 0){
            count++;
        }
    }

    if (count == 0 || count > 1){
        cout << "NO";
        return 0;
    } else {
        cout << "YES";
        return 0;
    }
}
