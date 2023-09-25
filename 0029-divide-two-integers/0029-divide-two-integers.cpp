class Solution {
public:
    
    int divide(int dividend, int divisor) {
        if( (dividend < 0 && divisor<0) || (dividend > 0 && divisor>0)){
            if(dividend==-pow(2,31) && divisor == -1){
                return pow(2,31)-1;
            }
            return ((abs)(dividend)/(abs)(divisor));
        }else{
            return (-1)*((abs)(dividend)/(abs)(divisor));
        }
        return 0;
    }
};