class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=1,m=*max_element(piles.begin(),piles.end());
        while(n<=m){
            long long int mid=((m-n)/2)+n,sum=0;
            for(int i=0;i<piles.size();i++) sum+=((piles[i]-1)/mid)+1;
            if(sum<=h)  m=mid-1;
            else   n=mid+1;
        }
        return m+1;
    }
};