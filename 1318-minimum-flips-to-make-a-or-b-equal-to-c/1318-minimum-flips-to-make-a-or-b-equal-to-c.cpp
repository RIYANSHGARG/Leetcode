class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a>0 || b>0 || c>0){
            int bit_a=a&1,bit_b=b&1,bit_c=c&1;
            if(bit_c==1){if(bit_a==0 && bit_b==0)    count++;}
            else   count=count+bit_a+bit_b;
            a>>=1;b>>=1;c>>=1;
        }
        return count;
    }
};