#include <stdio.h>
#include <SDL3/SDL.h>
#include <crtdbg.h>
#include <string>

static int StartupError(const std::string &what) {
    std::string message = what + " failed: " + SDL_GetError();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Startup failed", message.c_str(), nullptr);
    return 1;
}

int main(int argc, char *argv[]) {
    (void)argc, (void)argv;

    //_crtBreakAlloc = 3740;

    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
        return StartupError("SDL_Init");

    SDL_Window *window = SDL_CreateWindow("sdl3_tls_leak", 1280, 720, SDL_WINDOW_RESIZABLE);
    if (!window)
        return StartupError("SDL_CreateWindow");

    SDL_Delay(500);

    SDL_DestroyWindow(window), window = nullptr;

    SDL_CleanupTLS();

    SDL_Quit();

    return 0;
}
