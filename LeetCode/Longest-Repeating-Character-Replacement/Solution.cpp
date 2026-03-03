1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int l,r,maxlen,maxf;
5        l=r=maxlen=maxf=0;
6        map<char,int>map;
7        while(r<s.size()){
8            map[s[r]]++;
9            maxf=max(maxf,map[s[r]]);
10            while((r-l+1)-maxf>k){
11                map[s[l]]--;
12                maxf=0;
13                for(auto p:map){
14                    maxf=max(maxf,p.second);
15                }
16                l++;
17            }
18            maxlen=max(maxlen, r-l+1);
19            r++;
20        }
21        return maxlen;
22    }
23};