#include"flyweight.cpp"
#include<thread>
int main() {
	Flyweight::test();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}