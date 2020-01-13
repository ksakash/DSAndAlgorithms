#include <iostream>
#include <vector>

int main () {
    
    int N;
    std::cin >> N;
    
    std::vector<int> array(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    
    int swaps = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1-i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swaps++;
            }
        }
    }
    std::cout << swaps << std::endl;
    
    return 0;
}
