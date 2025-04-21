#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
void findpairs(const vector<int>& arr, int Sum) {
    unordered_set<int> seen; 
    unordered_set<string> pairs; 
    for (int num : arr) {
        int compl = Sum - num;
        if (seen.find(compl) != seen.end()) {
            int smaller = min(num, compl);
            int larger = max(num, compl);
            string pair = to_string(smaller) + "," + to_string(larger);
            if (pairs.find(pair) == pairs.end()) {
                pairs.insert(pair); 
                cout << "(" << smaller << ", " << larger << ")" << endl;
            }
        }
        seen.insert(num); 
    }
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5, 3, 2, 8, 10, -2, 3};
    int Sum = 8;
    cout << "Уникальные пары с суммой " << Sum << ":" << endl;
    findpairs(arr, Sum);

    return 0;
}