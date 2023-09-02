class Solution {
public:
    int compress(vector<char>& chars) {
        int count=1;
        if(chars.size()==1) return 1;
        char prev=chars[0];
        string s;
        s+=prev;
        
        for(int i=1;i<chars.size();i++){
            if(chars[i]==prev)  count++;
            else{
                if(count!=1){
                    string counter=to_string(count);
                    for(int k=0;k<counter.length();k++) s+=counter[k];  
                }
                count=1;prev=chars[i];s+=prev;
            }
        }
        
        if(count!=1){
            string counter=to_string(count);
                for(int k=0;k<counter.length();k++){
                    s+=counter[k];    
                }
        }
        
        chars.clear();
        for(int i=0;i<s.length();i++){
            chars.push_back(s[i]);
        }
        return chars.size();
    }
};