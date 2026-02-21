
class MyCircularQueue {
    vector<int> q;
    int head, tail, size, cap;
public:
    MyCircularQueue(int k) : q(k), head(0), tail(-1), size(0), cap(k) {}
    bool enQueue(int val) {
        if (isFull()) return false;
        tail = (tail + 1) % cap;
        q[tail] = val;
        size++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        size--;
        return true;
    }
    int Front() { return isEmpty() ? -1 : q[head]; }
    int Rear() { return isEmpty() ? -1 : q[tail]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
};