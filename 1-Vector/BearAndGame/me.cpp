#include <iostream>
#include <vector>

using namespace std;

int main() {
    int interesMins, increasOrder;
    vector<int> watchMins;

    cin >> interesMins;

    watchMins.push_back(0);
    for(int i = 0; i < interesMins; i++) {
        cin >> increasOrder;
        watchMins.push_back(increasOrder);
    }
    watchMins.push_back(90);

    for(int i = 0; i < watchMins.size(); i++) {
        if (watchMins[i] - watchMins[i-1] > 15) {
            cout << watchMins[i-1] + 15;
            return 0;
        }
    }

    cout << "90";
    return 0;
}
