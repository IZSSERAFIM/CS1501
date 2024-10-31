#include <iostream>
#include <set>
#include <algorithm>

int main() {
    char input[80];
    std::cout << "Please input a string: ";
    std::cin >> input;

    bool char_set[128] = {false};
    char unique_chars[80];
    int unique_index = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (!char_set[(unsigned char) input[i]]) {
            char_set[(unsigned char) input[i]] = true;
            unique_chars[unique_index++] = input[i];
        }
    }
    unique_chars[unique_index] = '\0';

    std::sort(unique_chars, unique_chars + unique_index, [](char a, char b) {
        return a > b;
    });

    std::cout << unique_chars << std::endl;

    return 0;
}
