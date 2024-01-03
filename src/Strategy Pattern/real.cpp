#include"test.cpp"
#include<thread>
#include<windows.h>
#include"../style.cpp"
int main() {
    setConsoleFont(L"黑体", 24, 700);
	system("color E1");
	Strategy::test();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	system("color E1");
	return 0;
}