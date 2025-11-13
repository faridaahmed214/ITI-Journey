#include <iostream>
using namespace std;

void replace(int arr[], int size) {
    int mid = size / 2;

    for (int i = 0; i < mid; i++)
        arr[i] = 1;

    for (int i = mid; i < size; i++)
        arr[i] = 0;
}

int main() {
    int nums[] = {9, 8, 7, 6, 5, 4, 3, 2 };
    int size = sizeof(nums) / sizeof(nums[0]);

    replace(nums, size);
    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
