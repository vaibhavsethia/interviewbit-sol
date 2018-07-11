// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int firstOccurence(int arr[], int beginIdx, int endIdx, int key) {
    int potentialIdx = -1;
    while (beginIdx <= endIdx) {
        int mid = (beginIdx + endIdx) / 2;
        if (arr[mid] == key) {
            potentialIdx = mid;
            endIdx = mid  - 1;
        }
        else if (key < arr[mid]){
            endIdx = mid - 1;
        }
        else {
            beginIdx = mid + 1;
        }
    }
    return potentialIdx;
}

void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

int main() {
    int n; cin >> n;
    int arr[100];
    inputArr(arr, n);
    int key; cin >> key;
    int ans = firstOccurence(arr, 0, n - 1, key);
    cout << ans;

}