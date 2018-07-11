// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int binarySearch(int arr[], int be, int en, int key){
    // [be, en]

    while(be <= en){
        int mid = (be + en) / 2;
        if (arr[mid] == key){
            return mid;
        }

        if (key < arr[mid]){
            en = mid - 1;
        }
        else {
            be = mid + 1;
        }
    }
    return -1;
}

int main(){
    
}