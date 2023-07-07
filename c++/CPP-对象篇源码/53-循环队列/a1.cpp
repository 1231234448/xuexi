class MyQue{
public:
    MyQue(){ rear=0; front=0; }
    MyQue& enque(int x){
        if((rear + 1) % N == front) throw -1;
        buf[rear] = x;
        rear = (rear + 1) % N;
        return *this;
    }
    int deque(){
        if(empty()) throw -2;
        int rt = buf[front];
        front = (front + 1) % N;
        return rt;
    }
    bool empty(){ return front==rear; }
private:
    static const int N = 5;
    int buf[N];
    int rear;
    int front;
};