#include"command.cpp"
#include<thread>
#include"../style.cpp"
int main() {
	setConsoleFont2(L"黑体", 18, 700);
	system("color E1");
	Command2::test();
	std::this_thread::sleep_for(std::chrono::seconds(15));
	return 0;
}