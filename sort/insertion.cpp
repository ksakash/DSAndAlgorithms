#include <iostream>
#include <vector>

void insert (std::vector<int>& array, int max_idx, int element_idx) {
    
    while (array[max_idx] > array[element_idx] && max_idx > -1) {
        int temp = array[element_idx];
        array[element_idx] = array[max_idx];
        array[max_idx] = temp;
        
        element_idx = max_idx;
        max_idx = max_idx-1;
    }
}

void print_array (const std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int find_position(int element, const std::vector<int>& sorted_array) {
   for (int i = 0; i < sorted_array.size(); i++) {
       if (element == sorted_array[i]) {
           return i+1;
       }
   } 
}

int main () {
    int N;
    std::cin >> N;
    
    std::vector<int> array (N);
    std::vector<int> org_array(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];    
    }
    
    org_array = array;
    
    int max = array[0];
    int max_idx = 0;
    
    for (int i = 1; i < N; i++) {
        if (array[i] < max) {
            insert(array, max_idx, i);
            max_idx++;
        }
        else {
            max = array[i];
            max_idx = i;
        }
    }
    
    std::vector<int> position_array(N);
    
    for (int i = 0; i < N; i++) {
        position_array[i] = find_position(org_array[i], array);    
    }
    
    print_array(position_array);
    return 0;
}
