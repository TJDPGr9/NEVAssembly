#pragma once
#include<iostream>
#include"Object.h"
using namespace std;

class Subject {
public:
	virtual void addViewer(Object* Object) = 0;
	virtual void removeViewer(Object* Object) = 0;
	virtual void tellAllViewer() = 0;
	virtual void purchase() = 0;
};