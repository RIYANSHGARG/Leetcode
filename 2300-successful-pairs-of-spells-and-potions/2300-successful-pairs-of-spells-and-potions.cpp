class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long j=0,k=potions.size()-1;
            while(j<=k){
                long long mid = (k-j)/2+j;
                long long val=(long long int)spells[i]*potions[mid];
                if(val >=success) k=mid-1;
                else    j=mid+1;
            }
            ans.push_back(potions.size()-k-1);
        }
        return ans;
    }
};