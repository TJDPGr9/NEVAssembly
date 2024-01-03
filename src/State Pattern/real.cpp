#include"StatePattern.cpp"
#include<thread>
#include"../style.cpp"
int main() {
	setConsoleFont(L"黑体", 24, 700);
	system("color E1");
	State::test();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}