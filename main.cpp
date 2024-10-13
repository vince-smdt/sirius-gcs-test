#include <iostream>
#include <cstdint>
#include <imgui.h>

union Test {
    struct {
        uint8_t x;
        uint8_t y;
        uint8_t z;
    };
    uint8_t data[3];
};

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
