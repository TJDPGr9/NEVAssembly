#include<iostream>
#include"Purchase.h"
#include"BYD.h"
#include"NIO.h"
#include"Tesla.h"
#include"AssemblyCompany.h"
using namespace std;
namespace Observer {
	void test()
	{
		Subject* subject = new Purchase;

		Object* byd = new BYD;
		Object* nio = new NIO;
		Object* tesla = new Tesla;
		Object* assemblyCompany = new AssemblyCompany;
		cout << endl;

		subject->addViewer(byd);
		subject->addViewer(nio);
		subject->addViewer(tesla);
		subject->addViewer(assemblyCompany);
		cout << endl;

		subject->purchase();
		cout << endl;

		subject->removeViewer(byd);
		subject->removeViewer(nio);
		subject->removeViewer(tesla);
		subject->removeViewer(assemblyCompany);

	}
}