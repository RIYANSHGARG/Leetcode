class StockSpanner {
public:
    int i;
    vector<int> v;
    stack<int> s;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        if(s.empty()){
            s.push(i);
            v.push_back(price);
            i++;
            return 1;
        }
        while(!s.empty() && price>=v[s.top()] ){
            s.pop();
        }
        int ans;
        if(!s.empty())  ans=i-s.top();
        else    ans=i+1;
        s.push(i);
        v.push_back(price);
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */