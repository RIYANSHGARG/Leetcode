class MyCircularQueue {
public:
    vector<int> v;
    int cnt,front,rear,size;
    MyCircularQueue(int k) {
        v.resize(k);
        fill(v.begin(),v.end(),-1);
        front=rear=cnt=0;
        size=k;
    }
    
    bool enQueue(int value) {
        if(isFull())    return false;
        v[rear] = value;
        rear = (rear + 1) % size;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())   return false;
        v[front] = -1;
        front = (front + 1) % size;
        cnt--;
        return true;
    }
    
    int Front() {
        if(isEmpty())   return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty())   return -1;
        return v[(rear - 1 + size) % size];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */