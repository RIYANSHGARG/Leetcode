class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,count=0;
        
//         unordered_map<char,int> m;
//         for(int i=0;i<s.length();i++){
//             if(m.count(s[i]) == 0){
//                 m[s[i]]=i;
//                 count++;
//                 ans=max(ans,count);
//             }else{
//                 int prev_idx=m[s[i]];
                
//                 count=i-prev_idx;
//                 ans=max(ans,count);
//                 m[s[i]]=i;
//             }
//         }
        
        unordered_set<char> st;
        int i=0,j=0,n=s.length();
        while(i<n && j<n){
            if(st.count(s[j]) == 0){
                st.insert(s[j++]);
                count=j-i;
                ans=max(ans,count);
            }else{
                while(s[i] !=s[j]){
                    st.erase(s[i++]);
                }
                st.erase(s[i]);i+=1;
                count=j-i;
                ans=max(ans,count);
            }
        }
        
        return ans;
    }
};