#pragma once
#include<iostream>
#include<string>
using namespace std;
class User
{
public:
	User(string id = "", string password = "", int authority = 0);
	User(const User& other);
	void Resetpwd(string password);
	void Resetauth(int auth);
	virtual void display() const;
	int getauth() const;
	string getid() const;
	string getpwd() const;
	bool operator == (const User& other);
private:
	string userID;
	string password;
	int authority;
};
