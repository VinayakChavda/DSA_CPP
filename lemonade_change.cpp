#include <map>
#include <vector>
//
// Created by vinayak on 11-08-2024.
//
using namespace std;

bool lemonadeChange(vector<int>& bills) {
     map<int,int> mpp;
     for (int amount : bills) {
          if (amount == 5) {
               mpp[5]++;
          }else if(amount == 10) {
               if (mpp[5] > 0) {
                    mpp[10]++;
                    mpp[5]--;
               }else {
                    return false;
               }
          }else {
               if (mpp[10] >= 1 && mpp[5] >= 1) {
                    mpp[10]--;
                    mpp[5]--;
               }else if(mpp[5] >= 3) {
                    mpp[20]++;
                    mpp[5] -= 3;
               }else {
                    return false;
               }
          }
     }
     return true;
}