#pragma once
#include<iostream>
#include"AssemblyCompany.h"
using namespace std;

AssemblyCompany::AssemblyCompany()
{
	cout << "I am AssemblyCompany,Waiting for purchase" << endl;
}
void AssemblyCompany::Update()
{
	cout << "The AssemblyCompany has completed the procurement and updated status" << endl;;
}
