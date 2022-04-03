#pragma once

using namespace std;

template<class T>
class Queue {

private:
    int m_head;
    int m_tail;
    size_t MAX = 0;
    T *m_nodes = nullptr;

 public:
    Queue();
    ~Queue();

    bool isInit(void) { return m_nodes != nullptr; }
    int init(size_t maxQueueSize);
    size_t size(void);
    T front();
    int enqueue(const T& in);
    int dequeue(T& out);
    bool empty();
};

template <class T>
Queue<T>::Queue() : m_head(0), m_tail(0)
{
}

template <class T>
Queue<T>::~Queue()
{
    if (m_nodes){
        delete[] m_nodes;
        m_nodes = nullptr;
    }
}

template <class T>
int Queue<T>::init(size_t maxQueueSize) {

    if (maxQueueSize == 0){
        return -2;
    }

    if (!isInit()){
        m_nodes = new T[maxQueueSize];
    } else {
        return -3;
    }

    if (!m_nodes){
        return -1;
    } else {
        MAX = maxQueueSize;
    }

    return 0;
}

template <class T>
size_t Queue<T>::size() {
  if (m_tail > m_head) { 
    return m_tail - m_head;
  }
  else {
    return m_tail + MAX - m_head;
  }
}

template <class T>
T Queue<T>::front() {
    return m_nodes[m_head];
}

template <class T>
int Queue<T>::enqueue(const T& in) {

    if (!isInit()){
        return -1;
    }

    m_nodes[m_tail] = in;
    m_tail = (m_tail + 1) % MAX;

    return 0;
}

template <class T>
int Queue<T>::dequeue(T& out) {
    
    if (!isInit()){
        return -1;
    }

    out = m_nodes[m_head];
    m_head = (m_head + 1) % MAX;
    
    return 0;
}

template <class T>
bool Queue<T>::empty() {

    if (!isInit()){
        return false;
    }

    if (m_head == m_tail) {
        return true;
    } else {
        return false;
    }
}