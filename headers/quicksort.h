#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

template<typename T>
void quicksort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        T pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Wrapper for easier use
template<typename T>
void quicksort(std::vector<T>& arr) {
    if (!arr.empty()) {
        quicksort(arr, 0, arr.size() - 1);
    }
}

#endif // QUICKSORT_H