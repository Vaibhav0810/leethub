// time comp- O(N) bcoz erase in vector takes o(N) bcoz after erase we have to shift elements too
// space -O(N)
/*
class MyCircularQueue {
public:
    
    vector<int>arr;
    int size;
    
    
    MyCircularQueue(int k) {
        size=k;
    }
    
    bool enQueue(int value) {
        
        if(arr.size()<size){
            arr.push_back(value);
            
            return true;
        }
        else return false;
    }
    
    bool deQueue() {
        if(arr.size()>0){
            arr.erase(arr.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        if(arr.size()>0){
            return arr[0];
        }
        else return -1;
    }
    
    int Rear() {
        int n=arr.size();
        if(n==0) return -1;
        else 
        return arr[n-1];
    }
    
    bool isEmpty() {
        if(arr.size()==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(arr.size()==size) return true;
        else return false;
    }
};
*/
//time -O(1)
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data.resize(k);
        maxSize = k;
    }
    bool enQueue(int val) {
        if (isFull()) return false;
        tail = (tail + 1) % maxSize;
        data[tail] = val;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) head = 0, tail = -1;
        else head = (head + 1) % maxSize;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    bool isEmpty() {
        return tail == -1;
    }
    bool isFull() {
        return !isEmpty() && (tail + 1) % maxSize == head;
    }
private:
    int maxSize, head = 0, tail = -1;
    vector<int> data;
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