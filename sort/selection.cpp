#include <iostream>
#include <vector>

int main () {
    
    int N, x;
    
    std::cin >> N >> x;
    
    std::vector<int> array(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (i >= x) {
            break;
        }
        int min = array[i];
        int min_idx = i;
        for (int j = i; j < N; j++) {
            if (array[j] < min) {
                min = array[j];
                min_idx = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
    
    for (int i = 0; i < N; i++) {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
