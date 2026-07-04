#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"User.h"
#include"Car.h"
using namespace std;
class NormalUser:public User
{
public:
	NormalUser();
	NormalUser(string id, string pwd);
	NormalUser(const NormalUser& other);
	~NormalUser() {}
	virtual void display() const;
	void AddMyCar(string num, string owner, string regtime, string color, string brand,
		double length, double width, double height);
	bool DeleteMyCar(string num);
	bool EditMyCar1(string carnum, int position, string newinfo);
	bool EditMyCar2(string carnum, int position, double newinfo);
	void Editpwd(string pwd);
	void Editauth(int newauth);
	bool ToAdmin(string nuID, string adID, string adPWD);
	void SaveToCVFA();
	void ApplyToBeAdmin();
private:
	vector<Car> myCar;
};
