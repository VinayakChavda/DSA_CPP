#include <stack>
#include <vector>
//
// Created by vinayak on 15-07-2024.
//
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    stack<int> st;
    for (int i=((2*n)-1);i>=0;i--) {
        while (!st.empty() && nums[i%n] >= st.top()) {
            st.pop();
        }
        ans[i%n] = st.top();
        st.push(nums[i%n]);
    }
    return ans;
}