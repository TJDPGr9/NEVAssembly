#include"Visitor Pattern/test.cpp"
#include"Strategy Pattern/test.cpp"
#include"State Pattern/StatePattern.cpp"
#include"Prototype Pattern/Prototype.cpp"
#include"Observer Pattern/test.cpp"
#include"Mediator Pattern/MediatorPattern.cpp"
#include"Iterator Pattern/test.cpp"
#include"Interpreter Pattern/VIN.cpp"
//#include<nolhmaan/json.h>
//#include"Interpreter Pattern/VIN.cpp"
#include"Flyweight Pattern/flyweight.cpp"
#include"Factory Pattern/factory.cpp"
#include"Facade Pattern/navigation.cpp"
#include"Decorator Pattern/decorator.cpp"
#include"Chain of Responsibility Pattern/responsibility_chain.cpp"
#include"Builder Pattern/test.cpp"
#include"Abstract Factory Pattern/test.cpp"
#include"Adapter Pattern/Adapter.cpp"
#include"Command Pattern/command.cpp"
#ifdef _WIN32
#include<Windows.h>
#endif
int main(){
#ifdef _WIN32
		SetConsoleCP(936);
		SetConsoleOutputCP(936);
#endif
	//Just a trial
		cout << "Select the pattern(0~19):";
		int n = 0;
		cin >> n;
		switch (n) {
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
		}
}