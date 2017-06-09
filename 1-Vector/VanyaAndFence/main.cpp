#include <iostream>
#include <vector>

using namespace std;

int main() {
    int amount, fenceHeight;
    int temp;
    int width = 0;

    cin >> amount;
    cin >> fenceHeight;

    for(int i = 0; i < amount; i++) {
        cin >> temp;
        if (temp > fenceHeight) {
            width += 2;
        } else {
            width++;
        }
    }

    cout << width;
    return 0;
}
