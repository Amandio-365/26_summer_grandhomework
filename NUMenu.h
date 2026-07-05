#pragma once
#include<iomanip>
#include"Car.h"
#include"Menu.h"
#include"NormalUser.h"
#include"GlobalData.h"
using namespace std;
class NormalUserMenu : public Menu
{
public:
	NormalUserMenu(string id, string pwd) :Menu() { nu = new NormalUser(id, pwd); }
	NormalUserMenu(const NormalUserMenu& other) :Menu(other) { nu = new NormalUser(*other.nu); }
	virtual void MainLoop()
	{
		while (isRunning)
		{
			DisplayMenu();
			cin >> choice;
			cin.ignore();
			if (!IsAllNumber(choice))
			{
				setColor(4);
				cout << "输入有非数字!" << endl;
				resetColor();
				continue;
			}
			int int_choice = stoi(choice);
			system("cls");
			switch (int_choice)
			{
			case(1):
			{
				string tempcolor, tempbrand, length_min, length_max, 
					width_min, width_max, height_min, height_max;
				while (true)
				{
					setColor(10);
					cout << "按照如下格式输入：" << endl;
					cout << "车辆颜色 + 车辆品牌 + 车辆长度最小值 + 车辆长度最大值 + 车辆宽度最小值 + 车辆宽度最大值";
					cout << "+车辆高度最小值 + 车辆高度最大值" << endl;
					cout << "注意：若您不需要使用某非数字查询条件，请用“\\”填入对应位置, 若您不需要车辆长宽高相应条件";
					cout << "请务必将0填入最小值处， 将100填入最大值处， 各数据间请用空格隔开！" << endl;
					resetColor();
					cin >> tempcolor >> tempbrand;
					cin.ignore();
					cin >> length_min >> length_max >> width_min >> width_max >> height_min >> height_max;
					cin.ignore();
					if ((CheckCarAllInfo(length_min, width_min, height_min)) &&
						(CheckCarAllInfo(length_max, width_max, height_max)))
						break;
					else resetCin();
				}
				vector<Car> tempvect = searcher("\\", "\\", "\\", 
					tempcolor, tempbrand, stod(length_min), stod(length_max), stod(width_min)
					, stod(width_max), stod(height_min), stod(height_max));
				if (tempvect.size() != 0)
				{
					setColor(2);
					cout << "符合条件的车辆有" << tempvect.size() << "辆：" << endl;
					for (int i = 0;i < tempvect.size();i++)
					{
						cout << setw(10) << tempvect[i].getnum() << setw(10) << "********" 
							<< setw(10) << tempvect[i].getcolor() << setw(10) << tempvect[i].getbrand() 
						<< setw(5) << tempvect[i].getlength() << setw(5) << tempvect[i].getwidth() 
							<< setw(5) << tempvect[i].getheight() << endl;
					}
					resetColor();
				}
				else
				{
					setColor(4);
					cout << "没有符合条件的车辆！" << endl;
					resetColor();
				}
				break;
			}
			case(2):
			{
				string temppwd1 = "1", temppwd2 = "2";
				setColor(9);
				cout << "请输入您的新密码：" << endl;
				resetColor();
				cin >> temppwd1;
				cin.ignore();
				setColor(9);
				cout << "请再次输入您的新密码：" << endl;
				resetColor();
				cin >> temppwd2;
				cin.ignore();
				if (temppwd1 == temppwd2)
				{
					nu->Editpwd(temppwd1);
					setColor(10);
					cout << "修改密码成功！" << endl;
					resetColor();
				}
				else
				{
					setColor(4);
					cout << "两次输入密码不一样！请您重新操作！" << endl;
					resetColor();
				}
				break;
			}
			case(3):
			{
				bool sec_isRunning = true;
				while (sec_isRunning)
				{
					second_display();
					string second_choice;
					cin >> second_choice;
					cin.ignore();
					if (!IsAllNumber(second_choice))
					{
						setColor(4);
						cout << "输入有非数字!" << endl;
						resetColor();
						resetCin();
						continue;
					}
					int int_second_choice = stoi(second_choice);
					system("cls");
					switch (int_second_choice)
					{
					case(1):
					{
						while (true)
						{
							string tempnum, tempowner, tempregtime, tempcolor, tempbrand,
								length, width, height;
							setColor(10);
							cout << "请依次输入新车辆的车牌号、用户名、注册时间、颜色、品牌、长度、宽度与高度，用空格分开 " << endl;
							resetColor();
							cin >> tempnum >> tempowner >> tempregtime >> tempcolor
								>> tempbrand >> length >> width >> height;
							cin.ignore();
							if (CheckCarAllInfo(length, width, height, tempregtime))
							{
								setColor(2);
								cout << "录入新车辆成功!" << endl;
								resetColor();
								cin.ignore();
								nu->AddMyCar(tempnum, tempowner, tempregtime,
									tempcolor, tempbrand, stod(length), stod(width), stod(height));
							}
							else
							{
								reportError();
								resetCin();
							}
						}
						break;
					}
					case(2):
					{
						setColor(10);
						cout << "请输入您要删除的车辆的车牌照号：";
						resetColor();
						string tempnum;
						cin >> tempnum;
						cin.ignore();
						if (!(nu->DeleteMyCar(tempnum)))
						{
							setColor(4);
							cout << "未找到对应车牌照的车辆！" << endl;
							resetColor();
						}
						else
						{
							setColor(2);
							cout << "删除成功！" << endl;
							resetColor();
						}
						break;
					}
					case(3):
					{
						string tempnum, newinfo, position, newdata;
						double temp;
						while (true)
						{
							setColor(10);
							cout << "请您输入想要修改信息的车辆车牌号、修改数据类型以及新数据：(之间用空白隔开）" << endl;
							cout << "1--车主姓名  2--车辆颜色  3--车辆长度  4--车辆宽度  5--车辆高度" << endl;
							resetColor();
							cin >> tempnum >> position;
							cin.ignore();
							if (!IsAllNumber(position))
							{
								setColor(4);
								cout << "输入有非数字!" << endl;
								resetColor();
								resetCin();
								continue;
							}
							else break;
						}
						int int_pos = stoi(position);
						if ((int_pos == 1) || (int_pos == 2))
						{
							cin >> newinfo;
							cin.ignore();
							if (!(nu->EditMyCar1(tempnum, int_pos, newinfo)))
							{
								setColor(4);
								cout << "未找到对应车牌照的车辆！" << endl;
								resetColor();
								break;
							}
							else
							{
								setColor(2);
								cout << "修改成功！" << endl;
								resetColor();
							}
						}
						else if ((int_pos == 3) || (int_pos == 4) || (int_pos == 5))
						{
							while (true)
							{
								cin >> newdata;
								cin.ignore();
								if (!StringToPositiveDouble(newdata, temp))
								{
									setColor(4);
									cout << "新数据输入有误!" << endl;
									resetColor();
									resetCin();
									continue;
								}
								else break;
							}
							if (!nu->EditMyCar2(tempnum, int_pos, stod(newdata)))
							{
								setColor(4);
								cout << "未找到对应车牌照的车辆！" << endl;
								resetColor();
								break;
							}
							else
							{
								setColor(2);
								cout << "修改成功！" << endl;
								resetColor();
							}
						}
						break;
					}
					case(4):
					{
						sec_isRunning = false;
						break;
					}
					default:
					{
						reportError();
					}
					}
				}
				break;
			}
			case(4):
			{
				string confirm;
				setColor(12);
				cout << "您是否确认申请成为管理员？(输入1以确认申请，其他输入均会被认为是退出页面)" << endl;
				resetColor();
				cin >> confirm;
				cin.ignore();
				if (confirm == "1")
				{
					nu->ApplyToBeAdmin();
					setColor(10);
					cout << "确认申请！" << endl;
					resetColor();
				}
				break;
			}
			case(5):
			{
				nu->display();
				break;
			}
			case(6):
			{
				setColor(10);
				cout << "感谢使用！" << endl;
				resetColor();
				nu->SaveToCVFA();
				return;
			}
			default:
			{
				reportError();
			}
			}
		}
	}
	virtual void DisplayMenu()
	{
		setColor(14);
		cout << "-----------------欢迎来到普通用户界面！-----------------" << endl;
		cout << "-----------------请选择您需要使用的功能：---------------" << endl;
		cout << "----------------------1.查询车辆------------------------" << endl;
		cout << "---------------------2.修改用户密码---------------------" << endl;
		cout << "------------3.添加、删除或修改个人名下车辆信息----------" << endl;
		cout << "-------------------4.进行权限提升申请-------------------" << endl;
		cout << "-------------------5.查看自己名下车辆-------------------" << endl;
		cout << "----------------------6.退出系统------------------------" << endl;
		resetColor();
	}
	void second_display()
	{
		setColor(14);
		cout << "-------------------请选择您要进行的操作-----------------" << endl;
		cout << "----------------------1.增添名下车辆--------------------" << endl;
		cout << "----------------------2.删除名下车辆--------------------" << endl;
		cout << "--------------------3.修改名下车辆信息------------------" << endl;
		cout << "----------------------4.退回上级菜单--------------------" << endl;
		resetColor();
	}
	virtual void RestoreAuth()
	{
		nu->Editauth(0);
	}
private:
	NormalUser* nu;
};