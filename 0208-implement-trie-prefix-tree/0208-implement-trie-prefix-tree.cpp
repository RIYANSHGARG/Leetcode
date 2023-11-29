struct Node{
    Node *arr[26];
    bool flag=false;
    
    bool contain(int c){
        return arr[c];
    }
    
    void set(int c, Node *ref){
        arr[c]=ref;
    }
    
    Node *get(int c){
        return arr[c];
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
            if( !node->contain(word[i]-'a') ){
                node->set(word[i]-'a' , new Node());
            }
            node = node->get(word[i]-'a');
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
            if(!node->contain(word[i]-'a')) return false;
            node = node->get(word[i]-'a');
        }
        return (node->flag==true)?true:false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->contain(prefix[i]-'a')) return false;
            node = node->get(prefix[i]-'a');
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */