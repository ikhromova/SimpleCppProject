#include <iostream>
#include <vector>
#include <cstring>

int* createArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;  // WARNING: Returning pointer to local variable
}

void memoryLeak() {
    int* ptr = new int[100];
    // WARNING: Memory leak - never deleted
}

int divideNumbers(int a, int b) {
    return a / b;  // WARNING: Potential division by zero
}

void unusedVariable() {
    int x = 42;  // WARNING: Unused variable
    int y = 10;
    std::cout << y << std::endl;
}

int main() {
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    // WARNING: Infinite loop potential
    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl;
    }

    // WARNING: Uninitialized variable
    int uninitializedValue;
    std::cout << "Value: " << uninitializedValue << std::endl;

    // WARNING: Array out of bounds
    int arr[5];
    for (int i = 0; i <= 5; i++) {  // Should be i < 5
        arr[i] = i;
    }

    // WARNING: Null pointer dereference potential
    int* ptr = nullptr;
    if (ptr == nullptr) {
        *ptr = 10;  // Dereferencing null pointer
    }

    // WARNING: Comparing float with equality
    double d1 = 0.1 + 0.2;
    double d2 = 0.3;
    if (d1 == d2) {  // Float comparison should use epsilon
        std::cout << "Equal" << std::endl;
    }

    // WARNING: Signed/unsigned comparison
    int signedInt = -1;
    unsigned int unsignedInt = 5;
    if (signedInt < unsignedInt) {
        std::cout << "Comparison issue" << std::endl;
    }

    // WARNING: Buffer overflow potential
    char buffer[10];
    strcpy(buffer, "This is a very long string that will overflow");

    // WARNING: Resource leak
    memoryLeak();

    // WARNING: Use after scope
    int* badPtr = createArray();
    std::cout << badPtr[0] << std::endl;

    return 0;
}