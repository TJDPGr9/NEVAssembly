#include"StatePattern.cpp"
#include<thread>
int main() {
	State::test();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}