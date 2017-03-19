#include <iostream>
#include <vector>
#include <utility>

class MinHeap {
 private:
    std::vector<int> heap;

 public:
    MinHeap(const std::vector<int>& v)
    : heap(v) {
        make_heap();
        print();
    }

    void heapify_up(size_t i) {
        if (i > 0) {
            size_t j = (i - 1) / 2;
            if (heap[j] > heap[i])
                std::swap(heap[i], heap[j]);
            heapify_up(j);
        }
    }

    void max_heapify(int i) {
        int min = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < heap.size() && heap[l] < heap[i])
            min = l;
        if (r < heap.size() && heap[r] < heap[min])
            min = r;
        if (min != i) {
            std::swap(heap[i], heap[min]);
            max_heapify(min);
        }
    }

    void make_heap() {
        for (int i = heap.size() / 2; i >= 0; --i)
            max_heapify(i);
    }

    void print() {
        for (auto e : heap)
            std::cout << e << " ";
    }
};

int main() {
    std::vector<int> v {17, 23, 8, 19, 5, 11, 3};
    MinHeap mh = MinHeap(v);
}
