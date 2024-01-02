#include"src/Visitor Pattern/test.cpp"
#include"src/Strategy Pattern/test.cpp"
#include"src/State Pattern/StatePattern.cpp"
#include"src/Prototype Pattern/Prototype.cpp"
#include"src/Observer Pattern/test.cpp"
#include"src/Mediator Pattern/MediatorPattern.cpp"
#include"src/Iterator Pattern/test.cpp"
#include"src/Interpreter Pattern/VIN.cpp"
//#include<nolhmaan/json.h>
//#include"Interpreter Pattern/VIN.cpp"
#include"src/Flyweight Pattern/flyweight.cpp"
#include"src/Factory Pattern/factory.cpp"
#include"src/Facade Pattern/navigation.cpp"
#include"src/Decorator Pattern/decorator.cpp"
#include"src/Chain of Responsibility Pattern/responsibility_chain.cpp"
#include"src/Builder Pattern/test.cpp"
#include"src/Abstract Factory Pattern/test.cpp"
#include"src/Adapter Pattern/Adapter.cpp"
#include"src/Command Pattern/command.cpp"
#include"src/Object Pool Pattern/main.cpp"
#include"src/Fluent Interface Pattern/main.cpp"
#include"src/Specification Pattern/test.cpp"
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

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int TITLE_X = 150;
const int TITLE_Y = 10;
const int TITLE_WIDTH = 500;
const int TITLE_HEIGHT = 50;

const int BUTTON_WIDTH = 400;
const int BUTTON_HEIGHT = 50;
const int BUTTON_MARGIN = 10;
const int BUTTON_GAP = 10;
const int BUTTON_X = 200;
const int BUTTON_START_Y = 80;

const int BACK_BUTTON_X = 600;
const int BACK_BUTTON_Y = 550;
const int BACK_BUTTON_WIDTH = 200;

const int PAGE_NUM = 9;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* font = nullptr;

const SDL_Color DEFAULT_TEXT_COLOR = { 0,0,0,255 };
const SDL_Color DEFAULT_BUTTON_COLOR = { 200,200,200,255 };
const SDL_Color DEFAULT_ONCLICK_COLOR = { 128,128,128,255 };
const SDL_Color DEFAULT_BACK_COLOR = { 255,255,255,255 };
const SDL_Color DEFAULT_TITLE_COLOR = { 0, 0, 255, 255 };
const SDL_Rect DEFAULT_TITLE_RECT = { TITLE_X, TITLE_Y, TITLE_WIDTH, TITLE_HEIGHT };

const int TEXT_BLOCK_X = 50;
const int TEXT_BLOCK_Y = 150;
const int TEXT_BLOCK_WIDTH = 700;

// Pages
enum Page {
    MENU,
    DEVELOPMENT,
    SUPPLY,
    ASSEMBLY,
    INSPECTION,
    TRANSPORTATION,
    SALE,
    USAGE,
    RECOGNITION
};

const char* PAGE_TEXT[PAGE_NUM] = { "MAIN MENU", "RESEARCH & DEVELOPMENT", "SUPPLY", "ASSEMBLY", "QUALITY INSPECTION & TEST", "TRANSPORTATION", "SALE", "USAGE", "CAR RECOGNITION" };

Page currentPage = MENU;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }

    window = SDL_CreateWindow("New Energy Car Assembly", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    font = TTF_OpenFont("C:/Windows/Fonts/times.ttf", 24); 
    if (font == nullptr) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return -1;
    }

    return 0;
}

void cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

char* getPatternResult(int index) {
    // 保存当前的标准输出缓冲区
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    // 创建一个字符串流，用于保存输出内容
    std::ostringstream outputStream;
    // 重定向标准输出到字符串流
    std::cout.rdbuf(outputStream.rdbuf());

    switch (index) {
    case 0:
        AbstractFactory::test();
        break;
    case 1:
        Adapter::test();
        break;
    case 2:
        Builder2::test();
        break;
    case 3:
        Command2::test();
        break;
    case 4:
        Decorator::test();
        break;
    case 5:
        Navigation::test();
        break;
    case 6:
        Factory::test();
        break;
    case 7:
        FluentInterface::test();
        break;
    case 8:
        Flyweight::test();
        break;
    case 9:
        Interpreter::test();
        break;
    case 10:
        Iterator2::test();
        break;
    case 11:
        Mediator2::test();
        break;
    case 12:
        ObjectPool::test();
        break;
    case 13:
        Observer::test();
        break;
    case 14:
        Prototype::test();
        break;
    case 15:
        Specification::test();
        break;
    case 16:
        State::test();
        break;
    case 17:
        Strategy::test();
        break;
    case 18:
        Visitor2::test();
        break;
    case 19:
        ResponsibilityChain::test();
        break;
    }

    // 恢复标准输出
    std::cout.rdbuf(oldCoutStreamBuf);
    // 获取输出的字符串
    std::string outputString = outputStream.str();

    char* charPtr = new char[outputString.size() + 1];  // 记得之后delete 
    std::strcpy(charPtr, outputString.c_str());
    return charPtr;
}

SDL_Texture* createTextTexture(const char* text, SDL_Color textColor) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return textTexture;
}

void renderButton(const char* text, SDL_Rect buttonRect, SDL_Color textColor = DEFAULT_TEXT_COLOR, SDL_Color buttonColor = DEFAULT_BUTTON_COLOR) {
    SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(renderer, &buttonRect);

    int text_width, text_height;
    TTF_SizeText(font, text, &text_width, &text_height);
    printf("text width: %d, height: %d\n", text_width, text_height);

    SDL_Texture* textTexture = createTextTexture(text, textColor);

    SDL_Rect textRect;
    textRect.x = buttonRect.x + (buttonRect.w - text_width) / 2;
    textRect.y = buttonRect.y + (buttonRect.h - text_height) / 2;
    textRect.w = text_width;
    textRect.h = text_height;

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_DestroyTexture(textTexture);
}

void renderBackButton() {
    SDL_Rect back_button = { BACK_BUTTON_X, BACK_BUTTON_Y, BACK_BUTTON_WIDTH, BUTTON_HEIGHT };
    SDL_Color buttonColor = { 255, 0, 0, 255 };
    renderButton("Back", back_button, DEFAULT_TEXT_COLOR, buttonColor);
}

void renderTitle(const char* text, SDL_Rect titleRect = DEFAULT_TITLE_RECT, SDL_Color textColor = DEFAULT_TITLE_COLOR) {
    int text_width, text_height;
    TTF_SizeText(font, text, &text_width, &text_height);
    text_width = int(float(titleRect.w) / text_width * text_width);
    text_height = int(float(titleRect.h) / text_height * text_height);

    SDL_Texture* titleTexture = createTextTexture(text, textColor);
    SDL_Rect textRect;
    textRect.x = titleRect.x + (titleRect.w - text_width) / 2;
    textRect.y = titleRect.y + (titleRect.h - text_height) / 2;
    textRect.w = text_width;
    textRect.h = text_height;
    SDL_RenderCopy(renderer, titleTexture, nullptr, &textRect);
    SDL_DestroyTexture(titleTexture);
}

void renderTextBlock(const char* text) {
    TTF_SetFontSize(font, 12);
    int text_width, text_height;

    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, text, DEFAULT_TEXT_COLOR, TEXT_BLOCK_WIDTH);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    text_width = textSurface->w;
    text_height = textSurface->h;
    printf("w: %d, h: %d\n", text_width, text_height);

    SDL_FreeSurface(textSurface);

    SDL_Rect textBlockRect = { TEXT_BLOCK_X,TEXT_BLOCK_Y,TEXT_BLOCK_WIDTH,text_height };
    SDL_RenderCopy(renderer, textTexture, NULL, &textBlockRect);
    SDL_DestroyTexture(textTexture);
    TTF_SetFontSize(font, 24);
}

void clearScreen() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);
}

void renderMainMenu() {
    clearScreen();
    // render title
    renderTitle("New Energy Car Assembly");

    // render buttons
    for (int i = 0; i < PAGE_NUM - 1; i++) {
        SDL_Rect buttonRect = { BUTTON_X, BUTTON_START_Y + BUTTON_GAP * i + BUTTON_HEIGHT * i, BUTTON_WIDTH, BUTTON_HEIGHT };
        renderButton(PAGE_TEXT[i + 1], buttonRect);
    }
    SDL_RenderPresent(renderer);
}

void renderDevelopment(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,450,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    SDL_Rect button_rect = { 500,10,250,25 };
    const char* button_text = "Command Pattern";
    renderButton(button_text, button_rect);

    if (x >= 500 && x <= 750 && y >= 10 && y <= 35) {
        int index = (y - 10) / 30;
        renderButton(button_text, button_rect, DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);

        char *text = getPatternResult(3);
        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
        delete[] text;
    }
    else {
        const char* original_text = "Research & Development Part contains:\n  1.Command Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderAssembly(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,200,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    const int patternNum = 4;
    SDL_Rect button_rect[patternNum] = {
        {400,10,300,25},
        {400,40,300,25},
        {400,70,300,25},
        {400,100,300,25}
    };

    const char* button_text[patternNum] = {
        "Factory Pattern",
        "Abstract Factory Pattern",
        "Builder Pattern",
        "Object Pool Pattern"
    };

    for (int i = 0; i < patternNum; i++) {
        renderButton(button_text[i], button_rect[i]);
    }

    char* text = nullptr;
    if (x >= 400 && x <= 700 && y >= 10 && y <= 125) {
        int index = (y - 10) / 30;
        renderButton(button_text[index], button_rect[index], DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);

        switch (index) {
        case 0:
            text = getPatternResult(6);
            break;
        case 1:
            text = getPatternResult(0);
            break;
        case 2:
            text = getPatternResult(2);
            break;
        case 3:
            text = getPatternResult(12);
            break;
        default:
            break;
        }

        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text[index]);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
    }
    else {
        const char* original_text = "Assembly Part contains:\n  1.Factory Pattern\n  2.Abstract Factory Pattern\n  3.Builder Pattern\n  4.Object Pool Pattern";
        renderTextBlock(original_text);
    }
    if (text)
        delete[] text;
    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderSupply(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,150,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    const int patternNum = 3;
    SDL_Rect button_rect[patternNum] = {
        {350,10,350,25},
        {350,40,350,25},
        {350,70,350,25}
    };

    const char* button_text[patternNum] = {
        "Mediator Pattern",
        "Chain of Responsibility Pattern",
        "Observer Pattern"
    };

    for (int i = 0; i < patternNum; i++) {
        renderButton(button_text[i], button_rect[i]);
    }
    
    if (x >= 350 && x <= 700 && y >= 10 && y <= 95) {
        int index = (y - 10) / 30;
        renderButton(button_text[index], button_rect[index], DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);
        char* text = nullptr;
        switch (index) {
        case 0:
            text = getPatternResult(11);
            break;
        case 1:
            text = getPatternResult(19);
            break;
        case 2:
            text = getPatternResult(13);
            break;
        default:
            break;
        }
        renderTextBlock(text);
        if (text)
            delete[] text;
    }
    else {
        const char* original_text = "Supply Part contains:\n  1.Mediator Pattern\n  2.Chain of Responsibility Pattern\n  3.Observer Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderInspection(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,450,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    const int patternNum = 3;
    SDL_Rect button_rect[patternNum] = {
        {500,10,250,25},
        {500,40,250,25},
        {500,70,250,25}
    };

    const char* button_text[patternNum] = {
        "State Pattern",
        "Visitor Pattern",
        "Adapter Pattern"
    };

    for (int i = 0; i < patternNum; i++) {
        renderButton(button_text[i], button_rect[i]);
    }

    if (x >= 500 && x <= 750 && y >= 10 && y <= 95) {
        int index = (y - 10) / 30;
        renderButton(button_text[index], button_rect[index], DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);
        char* text = nullptr;
        switch (index) {
        case 0:
            text = getPatternResult(16);
            break;
        case 1:
            text = getPatternResult(18);
            break;
        case 2:
            text = getPatternResult(1);
            break;
        default:
            break;
        }
        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text[index]);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
        if (text)
            delete[] text;
    }
    else {
        const char* original_text = "Quality Inspection & Test Part contains:\n  1.State Pattern\n  2.Visitor Pattern\n  3.Adapter Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderTransportation(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,300,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    const int patternNum = 3;
    SDL_Rect button_rect[patternNum] = {
        {350,10,350,25},
        {350,40,350,25},
        {350,70,350,25}
    };

    const char* button_text[patternNum] = {
        "Flyweight Pattern",
        "Iterator Pattern",
        "Strategy Pattern"
    };

    for (int i = 0; i < patternNum; i++) {
        renderButton(button_text[i], button_rect[i]);
    }

    if (x >= 350 && x <= 700 && y >= 10 && y <= 95) {
        int index = (y - 10) / 30;
        renderButton(button_text[index], button_rect[index], DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);
        char* text = nullptr;
        switch (index) {
        case 0:
            text = getPatternResult(8);
            break;
        case 1:
            text = getPatternResult(10);
            break;
        case 2:
            text = getPatternResult(17);
            break;
        default:
            break;
        }
        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text[index]);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
        if (text)
            delete[] text;
    }
    else {
        const char* original_text = "Transportation Part contains:\n  1.Flyweight Pattern\n  2.Iterator Pattern\n  3.Strategy Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderSale(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,100,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    SDL_Rect button_rect = { 500,10,250,25 };
    const char* button_text = "Prototype Pattern";
    renderButton(button_text, button_rect);

    if (x >= 500 && x <= 750 && y >= 10 && y <= 35) {
        int index = (y - 10) / 30;
        renderButton(button_text, button_rect, DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);

        char* text = nullptr;
        text = getPatternResult(14);
        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
        delete[] text;
    }
    else {
        const char* original_text = "Sale Part contains:\n  1.Prototype Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderUsage(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,150,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    const int patternNum = 3;
    SDL_Rect button_rect[patternNum] = {
        {350,10,350,25},
        {350,40,350,25},
        {350,70,350,25}
    };

    const char* button_text[patternNum] = {
        "Decorator Pattern",
        "Fluent Interface Pattern",
        "Specification Pattern"
    };

    for (int i = 0; i < patternNum; i++) {
        renderButton(button_text[i], button_rect[i]);
    }

    if (x >= 350 && x <= 700 && y >= 10 && y <= 95) {
        int index = (y - 10) / 30;
        renderButton(button_text[index], button_rect[index], DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);

        char* text = nullptr;
        switch (index) {
        case 0:
            text = getPatternResult(4);
            break;
        case 1:
            text = getPatternResult(7);
            break;
        case 2:
            text = getPatternResult(15);
            break;
        default:
            break;
        }
        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text[index]);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
        if (text)
            delete[] text;
    }
    else {
        const char* original_text = "Usage Part contains:\n  1.Decorator Pattern\n  2.Fluent Interface Pattern\n  3.Specification Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderRecognition(int x = -1, int y = -1) {
    clearScreen();
    SDL_Rect titleRect = { 20,10,300,50 };
    renderTitle(PAGE_TEXT[int(currentPage)], titleRect);

    SDL_Rect button_rect = { 400,10,300,25 };
    const char* button_text = "Interpreter Pattern";
    renderButton(button_text, button_rect);

    if (x >= 400 && x <= 700 && y >= 10 && y <= 35) {
        int index = (y - 10) / 30;
        renderButton(button_text, button_rect, DEFAULT_TEXT_COLOR, DEFAULT_ONCLICK_COLOR);

        char* text = nullptr;
        text = getPatternResult(9);
        //char text[255];  // should be output of the pattern
        //strcpy_s(text, sizeof(text), button_text);
        //strcat_s(text, sizeof(text), "\n\n");
        renderTextBlock(text);
        delete[] text;
    }
    else {
        const char* original_text = "Car Recognition Part contains:\n  1.Interpreter Pattern";
        renderTextBlock(original_text);
    }

    renderBackButton();
    SDL_RenderPresent(renderer);
}

void renderCurrentPage(int x = -1, int y = -1) {
    SDL_Color textColor = { 0, 0, 0, 255 };
    switch (currentPage) {
    case MENU:
        renderMainMenu();
        break;
    case DEVELOPMENT:
        renderDevelopment(x, y);
        break;
    case SUPPLY:
        renderSupply(x, y);
        break;
    case ASSEMBLY:
        renderAssembly(x, y);
        break;
    case INSPECTION:
        renderInspection(x, y);
        break;
    case TRANSPORTATION:
        renderTransportation(x, y);
        break;
    case SALE:
        renderSale(x, y);
        break;
    case USAGE:
        renderUsage(x, y);
        break;
    case RECOGNITION:
        renderRecognition(x, y);
        break;
    }
}

bool reactToClick(int x, int y) {
    // return true if changed
    printf("pos: %d, %d\n", x, y);
    if (currentPage == MENU) {
        if (x >= BUTTON_X && x <= BUTTON_X + BUTTON_WIDTH) {
            currentPage = Page((y - BUTTON_START_Y) / (BUTTON_HEIGHT + BUTTON_GAP) + 1);
            printf("current page: %d\n", currentPage);
            return true;
        }
    }
    else {
        if (x >= BACK_BUTTON_X && y >= BACK_BUTTON_Y) {
            currentPage = MENU;
            printf("current page: %d\n", currentPage);
            return true;
        }
        else {
            renderCurrentPage(x, y);
        }
    }

    return false;
}

int main(int argc, char* args[]) {
    init();
    renderCurrentPage();

    bool quit = false;
    bool changePage = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                changePage = reactToClick(x, y);
            }
        }
        if (changePage) {
            renderCurrentPage();
            changePage = false;
        }
    }

    // 清理资源
    cleanup();
    return 0;
}