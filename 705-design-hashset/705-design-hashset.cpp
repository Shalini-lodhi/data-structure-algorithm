class MyHashSet {
public: 
     struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
    };
    
    ListNode* head;
    
    MyHashSet() {
        head = new ListNode(-1); 
    }
    
    void add(int key) {
        ListNode* cur = head;
        if(contains(key)) return;
        
        while(cur->next != NULL){
            cur = cur -> next;
        }
        cur->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* cur = head;
        ListNode* prev = head;
        
        while(cur!=NULL && cur->val!=key){
            prev = cur;
            cur = cur -> next;
        }
        
        if(cur != NULL){
            prev->next = cur->next;
        }
    }
    
    bool contains(int key) {
        ListNode* cur = head;
        
        while(cur!=NULL){
            if(cur->val == key)
                return 1;
            cur = cur -> next;
        }
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */