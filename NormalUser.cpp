#include<iostream>
#include"NormalUser.h"
#include"GlobalData.h"
using namespace std;
NormalUser::NormalUser():User(){}
NormalUser::NormalUser(string id, string pwd) :User(id, pwd)
{
	for (int i = 0; i < cvecforall.size(); i++)
	{
		if (cvecforall[i].getownerid() == id)
		{
			myCar.push_back(cvecforall[i]);
		}
	}
}
NormalUser::NormalUser(const NormalUser & other):User(other)
{
	for (int i = 0;i < other.myCar.size();i++)
	{
		myCar.push_back(other.myCar[i]);
	}
}
void NormalUser::display() const
{
	cout << "您是一名普通用户" << endl;
	User::display();
	cout << "您的账户名下有" << myCar.size() << "辆车" << endl;
	for (int i = 0;i < myCar.size(); i++)
		myCar[i].display();
}
void NormalUser::AddMyCar(string num, string owner, string regtime, string color, string brand,
	double length, double width, double height)
{
	Car temp(num, owner, User::getid(), regtime, color, brand, length, width, height);
	myCar.push_back(temp);
}
bool NormalUser::DeleteMyCar(string num)
{
	vector<Car>::iterator it;
	bool condition = false;
	for (it = myCar.begin();it != myCar.end();it++)
	{
		if (it->getnum() == num)
		{
			cout << "这辆车的具体信息为:" << endl;
			it->display();
			cout << "请问您确定删除吗？(输入1以确认）" << endl;
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				condition = true;
				cvecforall.erase(it);
				cout << "删除成功!" << endl;
				return condition;
			}
			else return true;
			break;
		}
	}
	return condition;
}
bool NormalUser::EditMyCar1(string carnum, int position, string newinfo)
{
	vector<Car>::iterator it;
	bool condition = false;
	for (it = myCar.begin();it != myCar.end();it++)
	{
		if (it->getnum() == carnum)
		{
			condition = true;
			break;
		}
	}
	if (condition == false)
		return false;
	switch (position)
	{
	case(1):
		it->ResetOwner(newinfo);
		break;
	case(2):
		it->ResetColor(newinfo);
		break;
	}
	return true;
}
bool NormalUser::EditMyCar2(string carnum, int position, double newinfo)
{
	vector<Car>::iterator it;
	bool condition = false;
	for (it = myCar.begin();it != myCar.end();it++)
	{
		if (it->getnum() == carnum)
		{
			condition = true;
			break;
		}
	}
	if (condition == false)
		return false;
	switch (position)
	{
	case(3):
		it->ResetLength(newinfo);
		break;
	case(4):
		it->ResetWidth(newinfo);
		break;
	case(5):
		it->ResetHeight(newinfo);
		break;
	}
	return true;
}
void NormalUser::Editpwd(string pwd)
{
	for (int i = 0;i < uvecforall.size();i++)
		if (this->getid() == uvecforall[i].getid())
		{
			uvecforall[i].Resetpwd(pwd);
			break;
		}
}
void NormalUser::Editauth(int newauth)
{
	for (int i = 0;i < uvecforall.size();i++)
		if (this->getid() == uvecforall[i].getid())
		{
			uvecforall[i].Resetauth(newauth);
			break;
		}
}
bool NormalUser::ToAdmin(string nuID, string adID, string adPWD)
{
	for (int i = 0;i < uvecforall.size();i++)
		if ((uvecforall[i].getid() == adID) && (uvecforall[i].getpwd() == adPWD) && (uvecforall[i].getauth() == 1))
		{
			for (int j = 0;j < uvecforall.size();j++)
				if (uvecforall[j].getid() == nuID)
				{
					uvecforall[j].Resetauth(1);
					break;
				}
			return true;
			break;
		}
	return false;
}
void NormalUser::SaveToCVFA()
{
	for (int i = 0;i < cvecforall.size();)
	{
		if (cvecforall[i].getownerid() == User::getid())
			cvecforall.erase(cvecforall.begin() + i);
		else i++;
	}
	for (int i = 0;i < myCar.size();i++)
		cvecforall.push_back(myCar[i]);
}
void NormalUser::ApplyToBeAdmin()
{
	for (int i = 0;i < uvecforall.size();i++)
		if (this->getid() == uvecforall[i].getid())
		{
			uvecforall[i].Resetauth(-1);
			break;
		}
}