#include"GlobalData.h"
#include"ADMenu.h"
#include"NUMenu.h"
#include"Car.h"
#include"User.h"
using namespace std;
int main()
{
	Admin AdForAll;
	Menu* menuptr;
	int i;
	AdForAll.FileIO::ReadCar(cvecforall);
	AdForAll.FileIO::ReadUser(uvecforall);
	string tempid, temppwd;
	setColor(13);
	cout << "----------------欢迎来到车辆管理系统！------------" << endl;
	cout << "--------------------------------------------------" << endl;
	while (1)
	{
		setColor(11);
		cout << "------------------请输入您的账户id：--------------" << endl;
		cout << "                  ";
		resetColor();
		cin >> tempid;
		cin.ignore();
		setColor(11);
		cout << "------------------请输入您的密码：----------------" << endl;
		cout << "                  ";
		resetColor();
		cin >> temppwd;
		cin.ignore();
		resetColor();
		for (i = 0;i < uvecforall.size();i++)
			if ((uvecforall[i].getid() == tempid) && (uvecforall[i].getpwd() == temppwd))
				break;
		if (i == uvecforall.size())
		{
			setColor(4);
			cout << "您的账号或密码输入错误！" << endl;
			continue;
		}
		else
		{
			if ((uvecforall[i].getauth() == 0) || (uvecforall[i].getauth() == -1))
			{
				menuptr = new NormalUserMenu(tempid, temppwd);
				system("cls");
				menuptr->MainLoop();
				break;
			}
			else if (uvecforall[i].getauth() == 1)
			{
				menuptr = new AdminMenu(tempid, temppwd);
				system("cls");
				menuptr->MainLoop();
				break;
			}
			else if (uvecforall[i].getauth() == 2)
			{
				setColor(10);
				cout << "恭喜您获得了管理员的权限！" << endl;
				resetColor();
				menuptr = new AdminMenu(tempid, temppwd);
				menuptr->RestoreAuth();
				menuptr->MainLoop();
				break;
			}
			else if (uvecforall[i].getauth() == 3)
			{
				setColor(4);
				cout << "抱歉，您的权限升级申请被拒绝了！" << endl;
				resetColor();
				menuptr = new NormalUserMenu(tempid, temppwd);
				menuptr->RestoreAuth();
				menuptr->MainLoop();
				break;
			}
		}
	}
	AdForAll.FileIO::WriteCar(cvecforall);
	AdForAll.FileIO::WriteUser(uvecforall);
	return 1;
}