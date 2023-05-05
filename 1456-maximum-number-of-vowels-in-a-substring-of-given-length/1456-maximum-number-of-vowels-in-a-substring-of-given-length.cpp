class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        set<char> st={'a','e','i','o','u'};
        if(s.length()==1){
            if(st.find(s[0])!=st.end())  return 1;
            else   return false;
        }
        for(int i=0;i<k;i++){
            if(st.find(s[i])!=st.end()){
                count++;
            }
        }
        int ans=count;
        for(int i=1;i<s.length()-k+1;i++){
            bool stv=false,edv=false;
            if(st.find(s[i-1])!=st.end())    stv=true;
            if(st.find(s[i+k-1])!=st.end())   edv=true;
            cout<<s[i-1]<<s[i+k]<<endl;
            if(stv) count--;
            if(edv) count++;
               
            ans=max(ans,count);
        }
        return ans;
    }
};