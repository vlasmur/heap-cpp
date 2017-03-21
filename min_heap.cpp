#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class MinHeap {
 private:
    std::vector<T> heap;

 public:
    MinHeap(const std::vector<T>& v)
    : heap(v) {
        make_heap();
        print();
    }

    void min_heapify(int i) {
        int min = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < heap.size() && heap[l] < heap[i])
            min = l;
        if (r < heap.size() && heap[r] < heap[min])
            min = r;
        if (min != i) {
            std::swap(heap[i], heap[min]);
            min_heapify(min);
        }
    }

    void make_heap() {
        for (int i = heap.size() / 2; i >= 0; --i)
            min_heapify(i);
    }

    void heapify_up(int i) {
        if (i > 0) {
            int j = (i - 1) / 2;
            if (heap[j] > heap[i])
                std::swap(heap[i], heap[j]);
            heapify_up(j);
        }
    }

    void insert(T x) {
        heap.push_back(x);
        heapify_up(heap.size() - 1);
    }

    void print() {
        for (auto e : heap)
            std::cout << e << " ";
    }
};

int main() {
    std::vector<int> v {17, 23, 8, 19, 5, 11, 3};
    MinHeap<int> mh = MinHeap<int>(v);
}
