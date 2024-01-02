#include"command.cpp"
#include<thread>
int main() {
	Command2::test();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}