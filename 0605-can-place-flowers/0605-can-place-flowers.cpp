class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        if(n==0)return true;
        int cnt=0;
        for(int i=0;i<m;i++){
            bool left=(i==0 || flowerbed[i-1]==0),right=(i==m-1 || flowerbed[i+1]==0);
            if(left && right && flowerbed[i]!=1){
                ++cnt;
                flowerbed[i++]=1;
            }
        }
        return cnt>=n;

    }
};