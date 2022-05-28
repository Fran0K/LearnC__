//
// Created by Frank Lin on 15/12/21.
//

#include <iostream>
#include <vector>
//using namespace std;
int main() {

    std::vector<int> a;
    std::cout << "a.size(): " << a.size() << "       a.capacity(): " << a.capacity() << std::endl;
    for (int i = 0; i < 10; i++) {

        a.push_back(i);
        std::cout << "a.size(): " << a.size() << "   a.capacity(): " << a.capacity() << std::endl;
    }
    return 0;
}