#pragma once
#include<iostream>
#include<string>
#include"User.h"
using namespace std;
class Menu
{
public:
	int choice;
	bool isRunning;
	Menu() :choice(0), isRunning(1) {}
	Menu(const Menu& other) :choice(other.choice), isRunning(other.isRunning) {}
	virtual void MainLoop() = 0;
	virtual void DisplayMenu() = 0;
	virtual void RestoreAuth() = 0;
};
