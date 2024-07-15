#include <stack>
#include <vector>
//
// Created by vinayak on 15-07-2024.
//
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> leftSmaller(n);
    vector<int> rightSmaller(n);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        leftSmaller[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n-1;i>=0;i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        rightSmaller[i] = st.empty() ? n-1 : st.top() -1;
        st.push(i);
    }
    int maxA = 0;
    for (int i=0;i<n;i++) {
        maxA = max(maxA,heights[i] * (rightSmaller[i] - leftSmaller[i] +1));
    }
    return maxA;
}
