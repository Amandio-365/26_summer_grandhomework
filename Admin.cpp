#include"Admin.h"
#include"GlobalData.h"
using namespace std;
Admin::Admin() :User(), FileIO(){}
Admin::Admin(string id, string pwd) :User(id, pwd, 1), FileIO(){}
Admin::Admin(const Admin& other) :User(other), FileIO(other)
{
	for (int i = 0;i < other.EditVect.size();i++)
		EditVect.push_back(other.EditVect[i]);
	for (int i = 0;i < other.AddVect.size();i++)
		AddVect.push_back(other.AddVect[i]);
	for (int i = 0;i < other.DeleteVect.size();i++)
		DeleteVect.push_back(other.DeleteVect[i]);
}
Admin::~Admin(){}
void Admin::display() const
{
	cout << "您是一y7u名管理员" << endl;
	User::display();
}
void Admin::AddCar(string num, string owner, string ownerid, string regtime, string color,
	string brand, double length, double width, double height)
{
	Car temp(num, owner, ownerid, regtime, color, brand, length, width, height);
	cvecforall.push_back(temp);
	Save(AddVect, temp);
}
bool Admin::DeleteCar(string num)
{
	vector<Car>::iterator it;
	bool condition = false;
	for (it = cvecforall.begin();it != cvecforall.end();it++)
	{
		if (it->getnum() == num)
		{
			setColor(12);
			cout << "这辆车的具体信息为:" << endl;
			it->display();
			cout << "请问您确定删除吗？(输入1以确认）" << endl;
			resetColor();
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				condition = true;
				Save(DeleteVect, *it);
				cvecforall.erase(it);
				setColor(2);
				cout << "删除成功!" << endl;
				resetColor();
				return condition;
			}
			else return true;
			break;
		}
	}
	return condition;
}
bool Admin::EditCar1(string carnum, int position, string newinfo)
{
	vector<Car>::iterator it;
	bool condition = false;
	for (it = cvecforall.begin();it != cvecforall.end();it++)
	{
		if (it->getnum() == carnum)
		{
			condition = true;
			break;
		}
	}
	if (condition == false)
		return false;
	Save(EditVect, *it);
	switch (position)
	{
	case(1):
		it->ResetOwner(newinfo);
		break;
	case(2):
		it->ResetColor(newinfo);
		break;
	}
	Save(EditVect, *it);
	return true;
}
bool Admin::EditCar2(string carnum, int position, double newinfo)
{
	vector<Car>::iterator it;
	bool condition = false;
	for (it = cvecforall.begin();it != cvecforall.end();it++)
	{
		if (it->getnum() == carnum)
		{
			condition = true;
			break;
		}
	}
	if (condition == false)
		return false;
	Save(EditVect, *it);
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
	Save(EditVect, *it);
	return true;
}
void Admin::Editpwd(string pwd)
{
	for (int i = 0;i < uvecforall.size();i++)
		if (this->getid() == uvecforall[i].getid())
		{
			uvecforall[i].Resetpwd(pwd);
			break;
		}
}

void Admin::Editauth(int newauth)
{
	for (int i = 0;i < uvecforall.size();i++)
		if (this->getid() == uvecforall[i].getid())
		{
			uvecforall[i].Resetauth(newauth);
			break;
		}
}
void Admin::Save(vector<Car>& vect, const Car& car)
{
	vect.push_back(car);
}
void Admin::DisplayEdit() const
{
	int i;
	setColor(3);
	cout << "本次添加记录如下:" << endl;
	resetColor();
	for (i = 0;i < AddVect.size();i++)
		AddVect[i].display();
	setColor(3);
	cout << "本次删除记录如下:" << endl;
	resetColor();
	for (i = 0;i < DeleteVect.size();i++)
		DeleteVect[i].display();
	i = 0;
	setColor(3);
	cout << "本次修改记录如下:" << endl;
	while (i + 1 < EditVect.size())
	{
		if (EditVect[i].getnum() == EditVect[i + 1].getnum())
		{
			setColor(3);
			cout << "将   ";
			EditVect[i].display();
			setColor(3);
			cout << "改为 ";
			EditVect[i + 1].display();
			i += 2;
		}
	}
	resetColor();
}
void Admin::saveApplyUserVect(const vector<User>& other)
{
	for (int i = 0;i < other.size();i++)
	{
		for (int j = 0;j < uvecforall.size();j++)
		{
			if (uvecforall[j] == other[i])
				uvecforall[j].Resetauth(other[i].getauth());
		}
	}
}