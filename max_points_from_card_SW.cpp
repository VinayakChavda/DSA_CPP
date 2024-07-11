#include <vector>
//
// Created by vinayak on 11-07-2024.
//
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int lsum = 0;
    int rsum = 0;
    for (int i=0;i<k;i++) {
        lsum += cardPoints[i];
    }
    int maxSum = lsum;
    int rInd = cardPoints.size()-1;
    for (int i=k-1;i>=0;i--) {
        lsum -= cardPoints[i];
        rsum += cardPoints[rInd];
        rInd--;
        maxSum = max(maxSum,lsum+rsum);
    }
    return maxSum;
}