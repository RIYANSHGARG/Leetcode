class Node{
    public:
    int data;
    Node *next;
    Node(int el){
        data=el;
        next=NULL;
    }
};

class MyHashSet {
public:
    
    // ------------------- Chaining Method --------------
    // ------------------- Using Linked list-------------
    
    vector<Node *> v;
    int size=100;
    MyHashSet() {
        v.resize(size);
        for(int i=0;i<size;i++){
            v[i]=new Node(-1);;
        }
    }
    
    int hashKey(int key){
        return key%size;
    }
    
    Node *search(int key){
        Node *temp=v[hashKey(key)];
        while(temp->next){
            if(temp->next->data==key) return temp;
            temp=temp->next;
        }
        return NULL;
    }
    
    void add(int key) {
        int val=hashKey(key);
        if(search(key)!=NULL){
            return ;
        }
        Node *newNode = new Node(key);
        newNode->next=v[val]->next;
        v[val]->next=newNode;
    }
    
    void remove(int key) {
        Node *temp=search(key);
        if(temp==NULL)  return;
        temp->next=temp->next->next;
    }
    
    bool contains(int key) {
        if(search(key)!=NULL)   return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */