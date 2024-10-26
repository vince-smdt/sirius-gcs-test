#ifndef IMGUICIRCULARLOGTEXTBUFFER_H
#define IMGUICIRCULARLOGTEXTBUFFER_H

#include <imgui.h>

class ImGuiCircularLogTextBuffer {
public:
    explicit ImGuiCircularLogTextBuffer(int maxBufferSize);
    void append(const char* str, const char* strEnd = nullptr);
    void textUnformatted() const;
private:
    void updateCapacity(size_t newDataSize);
    void updateOutputBuffer();

    ImVector<char> _buffer;
    ImGuiTextBuffer _outputBuffer;
    int _writeIndex;
    int _maxBufferSize;
    bool _isBufferFull;
};

#endif //IMGUICIRCULARLOGTEXTBUFFER_H
