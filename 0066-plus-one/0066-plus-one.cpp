class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=0,carry=0;
        reverse(digits.begin(),digits.end());
        while(i<digits.size()){
            if(digits[i]!=9){
                digits[i]=digits[i]+1;
                reverse(digits.begin(),digits.end());
                return digits;
            }
            else{
                digits[i]=0;
                i++;
                carry=1;
            }
        }
        if(carry==1)    digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};