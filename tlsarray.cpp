#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // INPUT SIZE OF ARRAY

    if (n <= 0 || cin.fail()) return 0;
    
    vector<int> arr(n);
    vector<int> reversedArr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // INPUT INTO ARRAY
    }

    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            int num = arr[i];
            int reversedNum = 0;

            while (num != 0) {
                int remainder = num % 10;
                reversedNum = reversedNum * 10 + remainder;
                num /= 10;
            }

            reversedArr[i] = reversedNum;
        } else {
            reversedArr[i] = arr[i];
        }
    }

    for (int i = 0; i < reversedArr.size(); i++) {
        cout << reversedArr[i] << " ";
    }

    return 0;
}