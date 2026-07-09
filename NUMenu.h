#pragma once
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
				string tempcolor, tempbrand, tempstr1, tempstr2;
				double length_min, length_max, width_min, width_max, height_min, height_max;

				setColor(10);
				cout << "欢迎使用系统查询功能!" << endl;
				cout << "请输入车辆颜色: ";
				cin >> tempcolor;
				cin.ignore();
				cout << "请输入车辆品牌: ";
				cin >> tempbrand;
				cin.ignore();
				cout << "请输入车辆长度范围(如：3.68  4.32)  ";
				cin >> tempstr1 >> tempstr2;
				cin.ignore();
				if (!StringToPositiveDouble(tempstr1, length_min) || (!StringToPositiveDouble(tempstr2, length_max)))
				{
					setColor(4);
					cout << "数据校验失败：车辆长度必须为大于0的数字，仅允许一个小数点" << endl;
					resetCin();
					setColor(10);
					continue;
				}
				cout << "请输入车辆宽度范围(如：1.72  2.24)  ";
				cin >> tempstr1 >> tempstr2;
				cin.ignore();
				if (!StringToPositiveDouble(tempstr1, width_min) || (!StringToPositiveDouble(tempstr2, width_max)))
				{
					setColor(4);
					cout << "数据校验失败：车辆宽度必须为大于0的数字，仅允许一个小数点" << endl;
					resetCin();
					setColor(10);
					continue;
				}
				cout << "请输入车辆高度范围(如：1.38  1.62)  ";
				cin >> tempstr1 >> tempstr2;
				cin.ignore();
				if (!StringToPositiveDouble(tempstr1, height_min) || (!StringToPositiveDouble(tempstr2, height_max)))
				{
					setColor(4);
					cout << "数据校验失败：车辆高度必须为大于0的数字，仅允许一个小数点" << endl;
					resetCin();
					setColor(10);
					continue;
				}
				vector<Car> tempvect = searcher("\\", "\\", "\\", "\\", tempcolor, tempbrand,
					length_min, length_max, width_min, width_max, height_min, height_max);
				if (tempvect.size() != 0)
				{
					sort(tempvect.begin(), tempvect.end());
					setColor(2);
					cout << "符合条件的车辆有" << tempvect.size() << "辆：" << endl;
					for (int i = 0;i < tempvect.size();i++)
						tempvect[i].display();
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
				if ((temppwd1 == temppwd2) && (temppwd1 != nu->getpwd()))
				{
					setColor(10);
					cout << "修改成功！" << endl;
					nu->Editpwd(temppwd1);
					resetColor();
				}
				else if ((temppwd1 == temppwd2) && (temppwd1 == nu->getpwd()))
				{
					setColor(4);
					cout << "新密码不能与旧密码相同!" << endl;
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
						string tempnum, tempowner, tempregtime, tempcolor, tempbrand, tempstr;
						double length, width, height;

						setColor(10);		cout << "请输入车牌照号: ";		resetColor();
						cin >> tempnum;		cin.ignore();
						setColor(10);		cout << "请输入车主姓名: ";		resetColor();
						cin >> tempowner;		cin.ignore();
						setColor(10);		cout << "请输入注册时间: ";		resetColor();
						cin >> tempregtime;		cin.ignore();
						if (!CheckRegtimeFormat(tempregtime))
						{
							setColor(4);
							cout << "数据校验失败：注册时间格式错误！必须为 YYYY-MM，月份1~12" << endl;
							resetCin();		setColor(10);
							continue;
						}
						setColor(10);		cout << "请输入车辆颜色: ";		resetColor();
						cin >> tempcolor;		cin.ignore();
						setColor(10);		cout << "请输入车辆品牌: ";		resetColor();
						cin >> tempbrand;		cin.ignore();
						setColor(10);		cout << "请输入车辆长度: ";		resetColor();
						cin >> tempstr;			cin.ignore();
						if (!StringToPositiveDouble(tempstr, length))
						{
							setColor(4);
							cout << "数据校验失败：车辆长度必须为大于0的数字，仅允许一个小数点" << endl;
							resetCin();		setColor(10);
							continue;
						}
						setColor(10);		cout << "请输入车辆宽度: ";		resetColor();
						cin >> tempstr;			cin.ignore();
						if (!StringToPositiveDouble(tempstr, width))
						{
							setColor(4);
							cout << "数据校验失败：车辆宽度必须为大于0的数字，仅允许一个小数点" << endl;
							resetCin();		setColor(10);
							continue;
						}
						setColor(10);		cout << "请输入车辆高度: ";		resetColor();
						cin >> tempstr;			cin.ignore();
						if (!StringToPositiveDouble(tempstr, height))
						{
							setColor(4);
							cout << "数据校验失败：车辆高度必须为大于0的数字，仅允许一个小数点" << endl;
							resetCin();		setColor(10);
							continue;
						}
						nu->AddMyCar(tempnum, tempowner, tempregtime, tempcolor, tempbrand,
							length, width, height);
						setColor(10);
						cout << "添加成功!" << endl;
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

						setColor(10);
						cout << "请您输入想要修改信息的车辆车牌号、修改数据类型以及新数据：(之间用空白隔开）" << endl;
						cout << "1--车主姓名  2--车辆颜色  3--车辆长度  4--车辆宽度  5--车辆高度" << endl;
						resetColor();
						cin >> tempnum >> position;
						cin.ignore();
						if (!IsAllNumber(position))
						{
							setColor(4);
							cout << "修改选项输入有非数字!" << endl;
							resetColor();
							resetCin();
							continue;
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
							cin >> newdata;
							cin.ignore();
							if (!StringToPositiveDouble(newdata, temp))
							{
								setColor(4);
								cout << "新数据输入有误!" << endl;
								cout << "车辆长宽高必须为大于0的数字且仅允许一个小数点" << endl;
								resetColor();
								resetCin();
								continue;
							}
							if (!nu->EditMyCar2(tempnum, int_pos, stod(newdata)))
							{
								setColor(4);
								cout << "未找到对应车牌照的车辆！" << endl;
								resetColor();
								continue;
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
		setColor(12);
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
		setColor(12);
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