class Solution {
public:
    int sum(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num/10){
            num=sum(num);
        }
        return num;
    }
};