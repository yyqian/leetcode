class MaxHeap {
private:
  vector<int> data;
  int N;
public:
  MaxHeap(): data(1), N(0) {}

  void push(int x) {
    data.push_back(x);
    ++N;
    swim(N);
  }

  void pop() {
    data[1] = data[N];
    data.pop_back();
    --N;
    sink(1);
  }

  int top() {
    return data[1];
  }

  void swim(int i) {
    while (i > 1) {
      int parent = i / 2;
      if (data[parent] >= data[i]) {
        break;
      } else {
        swap(data[parent], data[i]);
        i = parent;
      }
    }
  }
  void sink(int i) {
    while (i <= N / 2) {
      int child = i * 2;
      if (child + 1 <= N && data[child] < data[child + 1]) ++child;
      if (data[i] >= data[child]) {
        break;
      } else {
        swap(data[i], data[child]);
        i = child;
      }
    }
  }
};

/*
   3
 4   5
*/