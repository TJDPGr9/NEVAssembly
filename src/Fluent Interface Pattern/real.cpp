#include"main.cpp"
#include"../style.cpp"
#include<thread>
int main() {
	setConsoleFont(L"黑体", 24, 700);
	system("color E1");
	FluentInterface::test();
	std::this_thread::sleep_for(std::chrono::seconds(15));
	return 0;
}