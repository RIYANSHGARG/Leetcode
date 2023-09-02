class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        // for(int i=0;i<height.size();i++){
        //     for(int j=i;j<height.size();j++){
        //         ans=max(ans,min(height[i],height[j])*(j-i) );
        //     }
        // }
        
        int i=0,j=height.size()-1;
        while(i<j){
            int h=min(height[i],height[j]);
            ans=max(ans,(j-i)*h);
            
            while(height[i] <= h && i<j)    i++;
            while(height[j] <= h && i<j)    j--;
        }
        return ans;
    }
};