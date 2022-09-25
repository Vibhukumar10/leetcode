class MyCircularQueue {
public:
    vector<int> q;
    int front,rear,sz;
    
    MyCircularQueue(int k) {
        q=vector<int> (k);
        front=rear=-1;
        sz=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        if(isEmpty()) {
            front=0;
        }
        rear=(rear+1)%sz;   
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        if(front==rear) {
            front=rear=-1;
        } else {
            front=(front+1)%sz;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return ((rear+1)%sz)==front;
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