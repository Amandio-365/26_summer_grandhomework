#include<iostream>
#include<string>
#include"User.h"
using namespace std;
User::User(string id, string password, int authority)  //User类的构造函数
{
	userID = id;
	this->password = password;
	this->authority = ((authority == 0) || (authority == 1) || (authority == -1)
		 || (authority == 2) || (authority == 3))?authority: 0;
}
User::User(const User& other) //User类的复制构造函数
{
	userID = other.userID;
	password = other.password;
	authority = other.authority;
}
void User::Resetpwd(string password) //设置新密码函数
{
	this->password = password;
}
void User::Resetauth(int auth) //设置新权限值
{
	this->authority = auth;
}
int User::getauth() const //获取权限值（-1、0、1、2或3）
{
	return authority;
}
string User::getid() const //获取用户id
{
	return userID;
}
string User::getpwd() const //获取用户的密码
{
	return password;
}
void User::display() const //输出用户的密码和用户名
{
	cout << "用户名为  " << userID << endl;
	cout << "用户的密码为  " << password << endl;
}
bool User::operator == (const User& other) //重载运算符“==”，用于比较两个User对象是否拥有相同的id
{
	return ((userID == other.getid()) && (password == other.getpwd()));
}