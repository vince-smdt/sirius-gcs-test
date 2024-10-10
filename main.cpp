#include <iostream>
#include <cstdint>

int main() {
    union Test {
        struct {
            uint8_t x;
            uint8_t y;
            uint8_t z;
        };
        uint8_t data[3];
    };

    std::cout << "Hello, World!" << std::endl;

    constexpr Test a = {65, 66, 67};

    for (const unsigned char i : a.data) {
        std::cout << i << std::endl;
    }

    std::cout << a.x << a.y << a.z << std::endl;

    return 0;
}
