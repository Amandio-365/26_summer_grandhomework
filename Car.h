#pragma once
#include<iostream>
#include<string>
using namespace std;
class Car
{
public:
	Car();
	Car(string num, string owner, string ownerid, string regtime, string color, string brand,
		double length, double width, double height);
	Car(const Car& other);

	void display() const;
	void ResetNum(string num);   //设置新值函数类
	void ResetRegtime(string regtime);
	void ResetOwner(string owner);
	void ResetOwnerid(string ownerid);
	void ResetColor(string color);
	void ResetBrand(string brand);
	void ResetLength(double length);
	void ResetWidth(double width);
	void ResetHeight(double height);

	string getnum() const;       //间接获取私有成员函数
	string getregtime() const;
	string getowner() const;
	string getownerid() const;
	string getcolor() const;
	string getbrand() const;
	double getlength() const;
	double getwidth() const;
	double getheight() const;
	
	bool operator < (const Car& other);   //操作符重载函数
	Car& operator = (const Car& other);
	bool operator == (const Car& other);

private:
	string num;
	string regtime;
	string owner;
	string ownerid;
	string color;
	string brand;
	double length, width, height;
};
