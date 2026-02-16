1class Solution {
2public:
3    int reverseBits(int n) {
4        if(n==0){
5            return 0;
6        }
7        int result = 0;
8        for(int i=0;i<32;i++){
9            result<<=1;
10            result=result|(n&1);
11            n>>=1;
12        }
13        return result;
14    }
15};