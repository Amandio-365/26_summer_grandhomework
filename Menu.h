#pragma once
#include<iostream>
#include<string>
using namespace std;
class Menu
{
public:
	string choice;
	bool isRunning;
	Menu() :choice(""), isRunning(1) {}
	Menu(const Menu& other) :choice(other.choice), isRunning(other.isRunning) {}
	virtual void MainLoop() = 0;
	virtual void DisplayMenu() = 0;
	virtual void RestoreAuth() = 0;
};
