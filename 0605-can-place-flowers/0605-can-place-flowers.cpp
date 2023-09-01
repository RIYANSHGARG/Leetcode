class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        if(n==0)    return true;
        if(flowerbed.size() == 1 && flowerbed[0]==0 && n==1)    return true;
        if(flowerbed.size() == 1 && flowerbed[0]==1 && n==1)    return false;
        
        for(int i=0;i<m;i++){
            if(i==0 && flowerbed[0]==0 && flowerbed[i+1]==0){flowerbed[i]=1;n--;} 
            else if(i==m-1 && flowerbed[m-1]==0 && flowerbed[m-2]==0){flowerbed[i]=1;n--;}
            else if(i!=0 && i!=m-1 && flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0){flowerbed[i]=1;n--;}
        }
        return n<=0;
    }
};