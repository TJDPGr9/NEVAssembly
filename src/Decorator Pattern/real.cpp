#include"decorator.cpp"
#include<thread>
int main() {
	Decorator::test();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}