class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        stack<int> s;
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            while(!s.empty()){
                if(s.top()==popped[j])  {s.pop();j++;}
                else    break;
            }
        }
        return (!s.size());
    }
};