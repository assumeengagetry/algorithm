#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    const int tableSize = 16;
    const int divisor = 13;
    int elem[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
    const int elemCount = sizeof(elem) / sizeof(elem[0]);

    std::vector<int> hashTable(tableSize, -1);

    auto hashFunc = [divisor](int key) { return key % divisor; };

    for (int v : elem) {
        int idx = hashFunc(v);
        while (hashTable[idx] != -1) {
            idx = (idx + 1) % tableSize;
        }
        hashTable[idx] = v;
    }

    std::cout << "哈希表（大小为16）的存储状态:" << std::endl;
    for (int i = 0; i < tableSize; ++i) {
        std::cout << std::setw(2) << i << " -> ";
        if (hashTable[i] == -1) {
            std::cout << "NULL";
        } else {
            std::cout << hashTable[i];
        }
        std::cout << std::endl;
    }

    std::cout << "请输入要查找的整数: ";
    int target;
    if (!(std::cin >> target)) {
        std::cerr << "输入无效" << std::endl;
        return 1;
    }

    int idx = hashFunc(target);
    int comparisons = 0;
    bool found = false;
    int probedSlots = 0;

    while (probedSlots < tableSize) {
        ++comparisons;
        if (hashTable[idx] == target) {
            found = true;
            break;
        }
        if (hashTable[idx] == -1) {
            break;
        }
        idx = (idx + 1) % tableSize;
        ++probedSlots;
    }

    if (found) {
        std::cout << "查找成功，比较次数: " << comparisons << std::endl;
    } else {
        std::cout << "查找失败，比较次数: " << comparisons << std::endl;
    }

    return 0;
}
