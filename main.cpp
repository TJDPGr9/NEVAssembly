#ifdef _WIN32
#include<Windows.h>
#define HEIGHT 20
extern "C" {
#include<SDL.h>
#include <cstdio>
#include <SDL_ttf.h>
}
#endif
#include<string>
#include<iostream>
using namespace std;
bool executeExecutable(const std::string& executablePath) {
#ifdef _WIN32
    // Windows平台
    PROCESS_INFORMATION processInfo;
    STARTUPINFO startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);

    if (CreateProcess(
        NULL,
        (LPSTR)executablePath.c_str(),
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &startupInfo,
        &processInfo
    )) {
        WaitForSingleObject(processInfo.hProcess, INFINITE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
        return true;
    }
    else {
        std::cerr << "Failed to create process. Error code: " << GetLastError() << std::endl;
        return false;
    }
#else
    // 非Windows平台
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Failed to fork." << std::endl;
        return false;
    }
    else if (pid == 0) {
        execl(executablePath.c_str(), executablePath.c_str(), NULL);
        std::cerr << "Failed to execute the child process." << std::endl;
        return false;
    }
    else {
        waitpid(pid, NULL, 0);
        return true;
    }
#endif
}
void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y) {
    SDL_Color textColor = { 255, 255, 255 };  // 白色文本
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (TTF_Init() < 0) {
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Text Output Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("C://Windows/Fonts/arial.ttf", 18);
    if (!font) {
        std::cerr << "Unable to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event event;
    SDL_SetRenderDrawColor(renderer, 128, 34, 77, 255);
    SDL_RenderClear(renderer);
    
    //store the above text as a string array
    string rr[20] = { "0: Abstract Factory Pattern",
        "1: Adapter Pattern",
        "2: Builder Pattern",
        "3: Command Pattern",
        "4: Decorator Pattern",
        "5: Facade Pattern",
        "6: Factory Pattern",
        "7: Fluent Interface Pattern",
        "8: Flyweight Pattern",
        "9: Interpreter Pattern",
        "a: Iterator Pattern",
        "b: Mediator Pattern",
        "c: Object Pool Pattern",
        "d: Observer Pattern",
        "e: Prototype Pattern",
        "f: Specification Pattern",
        "g: State Pattern",
        "h: Strategy Pattern",
        "i: Visitor Pattern",
        "j: Responsibility Chain Pattern" 
    };
    //iterate
    for (int i = 0; i < 20; i++) {
		renderText(renderer, font, rr[i], 50, 50 + i * HEIGHT);
	}
    SDL_RenderPresent(renderer);
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            //catch the keyboard event00
            if (event.type == SDL_KEYDOWN|| event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
				case SDLK_0:
                    executeExecutable("abstract.exe");
					break;
                case SDLK_1:
					executeExecutable("adapter.exe");
					break;
                case SDLK_2:
                    executeExecutable("builder.exe");
                    break;
                case SDLK_3:
                    executeExecutable("command.exe");
					break;
                case SDLK_4:
					executeExecutable("decorator.exe");
                    break;
				case SDLK_5:
                    executeExecutable("navigation.exe");
					break;
                case SDLK_6:
					executeExecutable("factory.exe");
                    break;
				case SDLK_7:
					executeExecutable("fluent.exe");
                    break;
                case SDLK_8:
                    executeExecutable("flyweight.exe");
					break;
                case SDLK_9:
                    executeExecutable("interpreter.exe");
					break;
                case SDLK_a:
					executeExecutable("iterator.exe");
                    break;
				case SDLK_b:
                    executeExecutable("mediator.exe");
					break;
                case SDLK_c:
                    executeExecutable("objectpool.exe");
					break;
                case SDLK_d:
                    executeExecutable("observer.exe");
                    break;
                case SDLK_e:
					executeExecutable("prototype.exe");
                    break;
				case SDLK_f:
                    executeExecutable("specification.exe");
					break;
				case SDLK_g:
					executeExecutable("state.exe");
					break;
				case SDLK_h:
					executeExecutable("strategy.exe");
					break;
				case SDLK_i:
					executeExecutable("visitor.exe");
					break;
				case SDLK_j:
					executeExecutable("chain.exe");
					break;
				default:
					break;
				}
			}
        }

        

        // 渲染文本
        
        //renderText(renderer, font, "1: Adapter Pattern", 50, 80);
        
        // ... 添加其他文本
        //SDL_Delay(2000*10);
        
    }

    // 清理资源
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}