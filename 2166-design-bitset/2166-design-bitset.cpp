class Bitset {
public:
    vector<int> v;
    vector<int> v_flipped;
    int ones,zeros;
    Bitset(int size) {
        v.resize(size);
        fill(v.begin(),v.end(),0);
        v_flipped.resize(size);
        fill(v_flipped.begin(),v_flipped.end(),1);
        ones=0,zeros=v.size();
    }
    
    void fix(int idx) {
        if(v[idx])  return ;
        v_flipped[idx]=0;
        v[idx]=1;
        ones++;zeros--;
    }
    
    void unfix(int idx) {
        if(!v[idx]) return ;
        v_flipped[idx]=1;
        v[idx]=0;
        zeros++;ones--;
    }
    
    void flip() {
        swap(v,v_flipped);
        swap(zeros,ones);
    }
    
    bool all() {
        return ones==v.size();
    }
    
    bool one() {
        return ones>0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string ans;
        for(int i=0;i<v.size();i++){
            ans+=to_string(v[i]);
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */