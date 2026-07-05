#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include"Car.h"
#include"GlobalData.h"
using namespace std;
Car::Car():num(""), owner(""), ownerid(""), regtime(""), color(""), brand(""),
length(0.0), width(0.0), height(0.0){}
Car::Car(string num, string owner, string ownerid, string regtime, string color, string brand
	, double length, double width, double height)
{
	this->num = num;
	this->owner = owner;
	this->ownerid = ownerid;
	this->regtime = regtime;
	this->color = color;
	this->brand = brand;
	this->length = length;
	this->width = width;
	this->height = height;
}
Car::Car(const Car& other)
{
	this->num = other.num;
	this->owner = other.owner;
	this->ownerid = other.ownerid;
	this->regtime = other.regtime;
	this->color = other.color;
	this->brand = other.brand;
	this->length = other.length;
	this->width = other.width;
	this->height = other.height;
}
void Car::display() const
{
	setColor(9);
	cout << left << "车牌照号：";
	setColor(14);
	cout << left << setw(11) << num;
	setColor(9);
	cout << left << "车主姓名：";
	setColor(14);
	cout << left << setw(10) << owner;
	setColor(9);
	cout << left << "注册时间：";
	setColor(14); 
	cout << left << setw(12) << regtime;
	setColor(9);
	cout << left<< "颜色：";
	setColor(14); 
	cout << left << setw(8) << color;
	setColor(9);
	cout << left << "品牌：";
	setColor(14);
	cout << left << setw(8) << brand;
	setColor(9);
	cout << left << "长宽高：";
	setColor(14); 
	cout << left << setw(5) << length << "   " << setw(5) << width << "   " << setw(5) << height << endl;
}
void Car::ResetNum(string num)
{
	this->num = num;
}
void Car::ResetRegtime(string regtime)
{
	this->regtime = regtime;
}
void Car::ResetOwner(string owner)
{
	this->owner = owner;
}
void Car::ResetOwnerid(string ownerid)
{
	this->ownerid = ownerid;
}
void Car::ResetColor(string color)
{
	this->color = color;
}
void Car::ResetBrand(string brand)
{
	this->brand = brand;;
}
void Car::ResetLength(double length)
{
	this->length = length;
}
void Car::ResetWidth(double width)
{
	this->width = width;
}
void Car::ResetHeight(double height)
{
	this->height = height;
}
string Car::getnum() const
{
	return num;
}
string Car::getregtime() const
{
	return regtime;
}
string Car::getowner() const
{
	return owner;
}
string Car::getownerid() const
{
	return ownerid;
}
string Car::getcolor() const
{
	return color;
}
string Car::getbrand() const
{
	return brand;
}
double Car::getlength() const
{
	return length;
}
double Car::getwidth() const
{
	return width;
}
double Car::getheight() const
{
	return height;
}
bool Car::operator < (const Car& other)
{
	string py1 = GetPlatePinYin(num);
	string py2 = GetPlatePinYin(other.num);
	if (py1 != py2)
	{
		return py1 < py2;
	}
	return num < other.num;
}
Car& Car::operator = (const Car& other)
{
	if (this == &other)
		return *this;
	num = other.num;
	owner = other.owner;
	ownerid = other.ownerid;
	regtime = other.regtime;
	color = other.color;
	brand = other.brand;
	length = other.length;
	width = other.width;
	height = other.height;
	return *this;
}
bool Car::operator == (const Car& other)
{
	return (num == other.num);
}
