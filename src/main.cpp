/// \file

#include <iostream>
#include <cstdint>
#include <imgui.h>

/// A test union
/*!
  Contains a struct and an uint8_t array, both sharing the same memory space.
 */
union Test {
    struct {
        uint8_t x;
        uint8_t y;
        uint8_t z;
    };
    uint8_t data[3]; ///< This contains xyz data
};

/// The program's entry point.
int main() {
    IMGUI_CHECKVERSION();

    std::cout << "Running ImGui v" << ImGui::GetVersion() << std::endl;

    constexpr Test a = {65, 66, 67};
    for (const unsigned char i : a.data) {
        std::cout << i << std::endl;
    }
    std::cout << a.x << a.y << a.z << std::endl;

    return 0;
}
