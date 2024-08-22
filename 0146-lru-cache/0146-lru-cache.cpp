
class LRUCache {
public:
    class Node{
    public:
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };

    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    unordered_map<int,Node*>mp;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode){
        Node* temp=head->next;
        head->next=newNode;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
    }

    void delNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node * resnode = mp[key];
            int res = resnode -> val;
            mp.erase(key);
            delNode(resnode);
            addNode(resnode);
            mp[key] = head -> next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node * existingnode = mp[key];
            mp.erase(key);
            delNode(existingnode);
        }
        if (mp.size() == cap) {
            mp.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }
        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */