class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,count=0,maxcount=0,k=2;
        unordered_map<int,int> m;
        while(r<fruits.size()){
            count++;
            m[fruits[r]]++;
            
            while(m.size()>2){
                count--;
                m[fruits[l]]--;
                if(m[fruits[l]]==0) m.erase(fruits[l]);
                l++;
            }
            maxcount=max(count,maxcount);
            r++;
        }
        return maxcount;
    }
};