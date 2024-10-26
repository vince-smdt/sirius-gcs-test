#include "ImGuiCircularLogTextBuffer.h"

#include <algorithm>

ImGuiCircularLogTextBuffer::ImGuiCircularLogTextBuffer(const int maxBufferSize): _writeIndex(0), _maxBufferSize(maxBufferSize), _isBufferFull(false) {
    _buffer.reserve(std::min(1024, _maxBufferSize));
}

void ImGuiCircularLogTextBuffer::append(const char *str, const char* strEnd) {
    const size_t len = strEnd ? strEnd - str : strlen(str);

    updateCapacity(len);

    size_t i = 0;

    if (!_isBufferFull) {
        for (; i < len && _buffer.size() < _buffer.capacity(); i++) {
            _buffer.push_back(str[i]);
        }
        if (_buffer.size() == _maxBufferSize) {
            _isBufferFull = true;
        }
    }

    if (_isBufferFull) {
        for (; i < len; i++) {
            _buffer[_writeIndex++] = str[i];
            if (_writeIndex == _maxBufferSize) {
                _writeIndex = 0;
            }
        }
    }

    updateOutputBuffer();
}

void ImGuiCircularLogTextBuffer::textUnformatted() const {
    ImGui::TextUnformatted(_outputBuffer.begin(), _outputBuffer.end());
}

void ImGuiCircularLogTextBuffer::updateCapacity(const size_t newDataSize) {
    if (_buffer.capacity() == _maxBufferSize) return;

    if (_buffer.capacity() + newDataSize > _maxBufferSize) {
        _buffer.reserve(_maxBufferSize);
        return;
    }

    while (_buffer.capacity() < _buffer.size() + newDataSize) {
        _buffer.reserve(_buffer.capacity() * 2);
    }

    if (_buffer.capacity() > _maxBufferSize) {
        _buffer.reserve(_maxBufferSize);
    }
}

void ImGuiCircularLogTextBuffer::updateOutputBuffer() {
    _outputBuffer.clear();
    if (_writeIndex == 0) {
        _outputBuffer.append(_buffer.begin(), _buffer.end());
        return;
    }
    _outputBuffer.append(&_buffer[_writeIndex], _buffer.end());
    _outputBuffer.append(_buffer.begin(), &_buffer[_writeIndex - 1]);
}
