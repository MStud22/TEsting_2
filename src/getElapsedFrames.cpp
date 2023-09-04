#include <chrono>
#include  "../header/Engine.h"

int Engine::getElapsedFrames() {
    static auto start = std::chrono::high_resolution_clock::now();
    static int frames = 0;
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
    ++frames;
    return frames;
}

String Engine::getClasse() {
    return classe;
}
