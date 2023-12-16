#include<iostream>
#include"Purchase.h"
using namespace std;

void Purchase::addViewer(Object* Object)
{
    cout << "Adding Observer" << endl;
	ObjectList.push_back(Object);
    cout << "Observer added" << endl;
}
void Purchase::removeViewer(Object* Object)
{
    cout << "Removing Observer" << endl;
	ObjectList.remove(Object);
    cout << "Observer removed" << endl;
}
void Purchase::tellAllViewer()
{
    for (std::list<Object*>::iterator it = ObjectList.begin(); it != ObjectList.end(); ++it) {
        (*it)->Update();
    }
    cout << "All observers have been notified" << endl;
}
void Purchase::purchase()
{
    cout << "Purchasing" << endl;
    cout << "Purchase finish" << endl;
    tellAllViewer();
}