namespace help {
void print_array (const std::vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
}

