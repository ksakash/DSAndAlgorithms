#include <iostream>
#include <vector>

#include "../help/help.h"

void quick_sort (std::vector<int>& a, int l, int r) {
 
    // std::cout << "l: " << l << " r: " << r << std::endl;

    if (r <= l) return;

    int left_pointer = l;
    int right_pointer = r-1;
    
    int p = r;
    int pivot = a[p];

    while (true) {
        // std::cout << "while" << std::endl;
        while (a[left_pointer] < pivot && left_pointer <= r) 
            left_pointer++; // increasing left
        while (a[right_pointer] > pivot && l <= right_pointer) 
            right_pointer--; // decreasing right
        if (left_pointer >= right_pointer) break;
        else {
            int temp = a[left_pointer];
            a[left_pointer] = a[right_pointer];
            a[right_pointer] = temp;
        }
    }
    // exchange l and p in the end
    int temp = a[left_pointer];
    a[left_pointer] = a[p];
    a[p] = temp;

    quick_sort (a, l, left_pointer-1);
    quick_sort (a, left_pointer+1, r);
}

int main () {

    int n; // size of the array
    std::cin >> n;

    if (n <= 0)
        std::cout << "invalid array size" << std::endl;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << "input array: ";
    help::print_array(a);

    quick_sort (a, 0, n-1);

    std::cout << "output array: ";
    help::print_array(a);

    return 0;
}
