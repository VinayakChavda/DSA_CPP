#include <string>
//
// Created by vinayak on 12-07-2024.
//
using namespace std;

int characterReplacement(string s, int k) {
    int l=0,r=0,maxlen=0,maxf=0;
    int hash[26] = {0};
    while (r<s.size()) {
        hash[s[r] - 'a']++;
        maxf = max(maxf,hash[s[r]-'a']);
        while ((r-l+1)-maxf > k) {
            hash[s[r] - 'a']--;
            maxf = 0;
            for (int i=0;i<26;i++) {
                maxf = max(maxf,hash[i]);
                l++;
            }
            if ((r-l+1) - maxf <= k) {
                maxlen = max(maxlen,r-l+1);
            }
        }
    }
    return maxlen;
}