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
#include"Object Pool Pattern/main.cpp"
#include"Fluent Interface Pattern/main.cpp"
#include"Specification Pattern/test.cpp"
#ifdef _WIN32
#include<Windows.h>
#endif
int main(){
#ifdef _WIN32
		SetConsoleCP(936);
		SetConsoleOutputCP(936);
#endif
	//Just a trial
		//Add prompt for 20 patterns plz
		cout << "Welcome to the design pattern test program!\n";
		//tell the user what 0~19 represents
		cout << "0:Abstract Factory Pattern\n";
		cout << "1:Adapter Pattern\n";
		cout << "2:Builder Pattern\n";
		cout << "3:Command Pattern\n";
		cout << "4:Decorator Pattern\n";
		cout << "5:Facade Pattern\n";
		cout << "6:Factory Pattern\n";
		cout << "7:Fluent Interface Pattern\n";
		cout << "8:Flyweight Pattern\n";
		cout << "9:Interpreter Pattern\n";
		cout << "10:Iterator Pattern\n";
		cout << "11:Mediator Pattern\n";
		cout << "12:Object Pool Pattern\n";
		cout << "13:Observer Pattern\n";
		cout << "14:Prototype Pattern\n";
		cout << "15:Specification Pattern\n";
		cout << "16:State Pattern\n";
		cout << "17:Strategy Pattern\n";
		cout << "18:Visitor Pattern\n";
		cout << "19:Responsibility Chain Pattern\n";
		while (1) {
			//get the user's choice
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
			case 4:
				Decorator::test();
				break;
			case 5:
				Navigation::test();
				break;
			case 6:
				Factory::test();
				break;
			case 7:
				FluentInterface::test();
				break;
			case 8:
				Flyweight::test();
				break;
			case 9:
				Interpreter::test();
				break;
			case 10:
				Iterator2::test();
				break;
			case 11:
				Mediator2::test();
				break;
			case 12:
				ObjectPool::test();
				break;
			case 13:
				Observer::test();
				break;
			case 14:
				Prototype::test();
				break;
			case 15:
				Specification::test();
				break;
			case 16:
				State::test();
				break;
			case 17:
				Strategy::test();
				break;
			case 18:
				Visitor2::test();
				break;
			case 19:
				ResponsibilityChain::test();
				break;
			}
			cout << "What to experience more?" << endl;
			cout << "Press any human-readable key except q to continue" << endl;
			char choice;
			cin >> choice;
			if (choice=='q')
				break;
#ifdef _WIN32
			system("cls");
#elif __linux__
			system("clear");
#endif
		}
}