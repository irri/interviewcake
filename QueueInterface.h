
template<typename T>
class QueueInterface {
public:
  ~QueueInterface() {}
  
  virtual void enqueue(T v) = 0;
  virtual T dequeue() = 0;
  virtual T peek() = 0;
  virtual bool isEmpty() = 0;

};

