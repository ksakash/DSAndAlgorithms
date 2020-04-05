#include <iostream>
#include <vector>

void print_array (const std::vector<int>& a) {
    int size = a.size();

    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

std::vector<int> merge (std::vector<int> a, std::vector<int> b) {
    int size = a.size() + b.size();
    std::vector<int> c(size);

    int a_i = 0;
    int b_i = 0;
    int c_i = 0;

    while (c_i < size && a_i < a.size() && b_i < b.size()) {
        if (a[a_i] < b[b_i]) {
            c[c_i] = a[a_i];
            a_i++;
        }
        else {
            c[c_i] = b[b_i];
            b_i++;
        }
        c_i++;    
    }

    if (c_i == size) {
        return c;
    }
    else if (a_i == a.size()) {
        while (c_i < size && b_i < b.size()) {
            c[c_i] = b[b_i];
            c_i++;
            b_i++;
        }
    }
    else {
        while (c_i < size && a_i < a.size()) {
            c[c_i] = a[a_i];
            c_i++;
            a_i++;
        }
    }
    return c;
}

std::vector<int> merge_sort (std::vector<int>& a, int i, int j) {
    if (i == j) {
        std::vector<int> c(1);
        c[0] = a[i];
        return c;
    }
    else {
        int k = int ((i+j)/2);
        std::vector<int> b = merge_sort (a, i, k);
        std::vector<int> c = merge_sort (a, k+1, j);
        std::vector<int> d = merge (b, c);
        return d;
    }
}

int main () {

    int n; // size of input array
    
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << "input array: ";
    print_array(a);

    std::vector<int> b = merge_sort (a, 0, n-1);

    std::cout << "ouput array: ";
    print_array(b);

    return 0;
}
