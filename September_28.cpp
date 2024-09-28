class MyCircularDeque {
    vector<int>dq;
    int size = 0;
    int maxSize = 0;
public:
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(size>=maxSize)return false;
        size++;
        dq.insert(dq.begin(),value);
        return true;
    }
    
    bool insertLast(int value) {
        if(size>=maxSize)return false;
        size++;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(size==0)return false;
        size--;
        dq.erase(dq.begin());
        return true;
    }
    
    bool deleteLast() {
        if(size==0)return false;
        size--;
        dq.pop_back();
        return true;
    }
    
    int getFront() {
        if(size==0)return -1;
        return dq[0];
    }
    
    int getRear() {
        if(size==0)return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */