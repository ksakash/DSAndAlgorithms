#include <iostream>
#include <vector>

int parent (int i) {
    return int(i/2);
}

int left (int i) {
    return int(2*i);
}

int right (int i) {
    return int(2*i +1);
}

void max_heapify (std::vector<int>& A, int i) {
    int l = left (i);
    int r = right (i);

    int size = A.size()-1;
    int largest;

    if (l <= size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        max_heapify(A, largest);
    }
}

void print_array (const std::vector<int>& array) {
    
    int size = array.size();
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main () {

    int n; // size of array
    std::cin >> n;

    if (n <= 0) {
        std::cout << "invalid size" << std::endl;
        return 1;
    }

    std::vector<int> a(n+1);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    print_array (a);

    int start = int(n/2);
    
    for (int i = start; i >= 1; i--) {
        max_heapify (a, i);
    }
    // max_heapify (a, 3);

    print_array (a);
    return 0;
}

