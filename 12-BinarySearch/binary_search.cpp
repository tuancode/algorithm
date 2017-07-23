#include <iostream>
#include <vector>

using namespace std;

/**
 * Search number from an integer list by applying Binary Search Algorithm.
 * The list is required sorted.
 *
 * @param  needle   The number to search for
 * @param  haystack The sorted list to search in
 * @return Position of needle in list if found, otherwise -1.
*/
int binarySearch(int needle, vector<int> haystack) {
    int low = 0;
    int high = haystack.size() - 1;
    int mid, guess;
    
    while (low <= high) {
        mid = (low + high) /2;
        guess = haystack[mid];
        if (guess == needle) {
            return mid;
        } else if (guess < needle) {
            low = mid + 1;
        } else if (guess > needle) {
            high = mid -1;
        }
    }
    
    return -1;
}

int main() {
    int num, needle, input, result;
    vector<int> haystack;
    
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> input;
        haystack.push_back(input);
    }
    cin >> needle;
    
    result = binarySearch(needle, haystack);
    cout << "result: ";
    if (result != -1) {
        cout << result;
    } else {
        cout << "none";
    }
    cout << "\n";
    
    return 0;
}