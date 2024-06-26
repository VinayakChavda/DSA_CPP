//
// Created by vinayak on 25-06-2024.
//


#include<iostream>
using namespace std;

void selectionSort(int arr[],int n) {
    for (int i=0;i<=n-2;i++) {
        int min = i;
        for (int j=i;j<=n-1;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// int main() {
//     int arr[] = {13,46,24,52,20,9};
//     for (int i=0;i<6;i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     selectionSort(arr,6);
//     for (int i=0;i<6;i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

