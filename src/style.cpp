#include<windows.h>
void setConsoleFont(LPCWSTR fontName, int fontSize, int fontWeight) {
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = fontSize;
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = fontWeight;  // 设置字体权重
    wcscpy_s(fontInfo.FaceName, fontName);
    // 设置控制台缓冲区大小
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { 80, 30 }; // 设置宽度为80，高度为30
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // 设置控制台窗口大小
    SMALL_RECT windowSize = { 0, 0, 69, 24 }; // 设置左上角和右下角坐标
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
}
void setConsoleFont2(LPCWSTR fontName, int fontSize, int fontWeight) {
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = fontSize;
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = fontWeight;  // 设置字体权重
    wcscpy_s(fontInfo.FaceName, fontName);
}