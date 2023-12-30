#pragma once
#include<iostream>
#include"Subject.h"
using namespace std;

class Purchase:public Subject {
private:
	list<Object*> ObjectList;
public:
	void addViewer(Object* Object);
	void removeViewer(Object* Object);
	void tellAllViewer();
	void purchase();
};