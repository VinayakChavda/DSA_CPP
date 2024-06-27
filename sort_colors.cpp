//
// Created by vinayak on 27-06-2024.
//
#include <vector>
using namespace std;

// ********************************* DUTCH NATIONAL FLAG ALGORITHAM **************************************
void sortColors(vector<int>& nums) {
    int mid = 0;
    int low = 0;
    int high = nums.size() - 1;
    while (high >= mid) {
        if (nums[mid] == 0) {
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }else if(nums[mid] == 1) {
            mid++;
        }else {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
