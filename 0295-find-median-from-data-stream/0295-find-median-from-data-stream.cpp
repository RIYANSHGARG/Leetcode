class MedianFinder {
public:
    priority_queue<int> first_half;
    priority_queue<int,vector<int>, greater<int> > second_half;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first_half.size()==0 || first_half.top() > num)   first_half.push(num);
        else    second_half.push(num);
        
        if(first_half.size() > second_half.size()+1){
            second_half.push(first_half.top());
            first_half.pop();
        }else if (second_half.size() > first_half.size()+1){
            first_half.push(second_half.top());
            second_half.pop();
        }
        
    }
    
    double findMedian() {
         if(first_half.size() == second_half.size()) return ((first_half.top()+second_half.top())/2.0);
        else return (first_half.size() > second_half.size())? first_half.top():second_half.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */