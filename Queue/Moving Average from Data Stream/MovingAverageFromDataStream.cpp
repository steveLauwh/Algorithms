#include <queue>

class MovingAverage {
public:
    MovingAverage(int size) : len(size), sum(0){
    }
    
    double next(int val) {
        if (q.size() > len) {
            sum -= q.front();
            q.pop();
        }
        
        sum += val;
        q.push(val);
        
        return sum / q.size();
    }
private:
    queue<int> q;
    int len;
    double sum;
};
