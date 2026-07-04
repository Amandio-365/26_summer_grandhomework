#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"User.h"
#include"FileIO.h"
#include"GlobalData.h"
using namespace std;
class Admin :public User, public FileIO
{
public:
	Admin();
	Admin(string id, string pwd);
	Admin(const Admin& other);
	~Admin();
	virtual void display() const;
	void DisplayEdit() const;
	void AddCar(string num, string owner, string ownerid, string regtime, string color,
		string brand, double length, double width, double height);
	bool DeleteCar(string num);
	bool EditCar1(string carnum, int position, string newinfo);
	bool EditCar2(string carnum, int position, double newinfo);
	void Editpwd(string pwd);
	void Editauth(int newauth);
	void saveApplyUserVect(const vector<User>& other);
private:
	vector<Car> EditVect;
	vector<Car> AddVect;
	vector<Car> DeleteVect;
	void Save(vector<Car>& vect, const Car& car);
};