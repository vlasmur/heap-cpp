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

    T extract_min() {
        T min = heap.front();
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        min_heapify(0);

        return min;
    }

    void print() {
        for (auto e : heap)
            std::cout << e << " ";
    }
};


template <typename T>
void heapsort(std::vector<T>& v) {
    MinHeap<T> min_heap = MinHeap<T>(v);
    std::vector<T> v_sorted;
    
    for (int i = 0; i < v.size(); ++i)
        v_sorted.push_back(min_heap.extract_min());

    v = v_sorted;
}


int main() {
    std::vector<int> v {17, 23, 8, 19, 5, 11, 3};
    MinHeap<int> mh = MinHeap<int>(v);

    std::cout << "\n";
    heapsort(v);
    for (auto e : v)
        std::cout << e << " ";
}
