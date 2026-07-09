#pragma once
#include"Menu.h"
#include"Admin.h"
#include"GlobalData.h"
class AdminMenu: public Menu
{
public:
	AdminMenu(string id, string pwd) :Menu() 
	{ 
		ad = new Admin(id, pwd);
		for (int i = 0;i < uvecforall.size();i++)
		{
			if (uvecforall[i].getauth() == -1)
			{
				ApplyUserVect.push_back(uvecforall[i]);
			}
		}
	}
	AdminMenu(const AdminMenu& other) :Menu(other) { ad = new Admin(*other.ad); }
	virtual void MainLoop()
	{
		while (true)
		{
			DisplayMenu();
			cin >> choice;
			cin.ignore();
			if (!IsAllNumber(choice))
			{
				setColor(4);
				cout << "选项输入有非数字!" << endl;
				resetColor();
				resetCin();
				continue;
			}
			int int_choice = stoi(choice);
			system("cls");
			switch (int_choice)
			{
			case(1):
			{
				string tempnum, tempowner, tempregtime1, tempregtime2, tempcolor, tempbrand, tempstr1, tempstr2;
				double length_min, length_max, width_min, width_max, height_min, height_max;

				setColor(10);
				cout << "欢迎使用系统查询功能:" << endl;
				cout << "请输入车牌照号: ";
				cin >> tempnum;
				cin.ignore();
				if (tempnum != "\\")
				{
					vector<Car> vect = searcher(tempnum, "\\", "\\", "\\", "\\", "\\",  0, 100,
						0, 100, 0, 100);
					if (vect.size() == 0)
					{
						setColor(4);
						cout << "没有找到对应车辆!" << endl;
						continue;
					}
					else
					{
						cout << "符合条件的车辆有 1 辆：" << endl;
						vect[0].display();
					}
				}
				cout << "请输入车主姓名: ";
				cin >> tempowner;
				cin.ignore();
				cout << "请输入注册时间范围(如：2001-01  2008-09)";
				cin >> tempregtime1 >> tempregtime2;
				cin.ignore();
				if ((!CheckRegtimeFormat(tempregtime1) && (tempregtime1 != "\\")) ||
					(!CheckRegtimeFormat(tempregtime2) && (tempregtime2 != "\\")))
				{
					setColor(4);
					cout << "数据校验失败：注册时间格式错误！必须为 YYYY-MM，月份1~12" << endl;
					resetCin();
					setColor(10);
					continue;
				}
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
				vector<Car> tempvect = searcher(tempnum, tempowner, tempregtime1, tempregtime2, tempcolor, tempbrand,
					length_min, length_max, width_min, width_max, height_min
					, height_max);
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
				if ((temppwd1 == temppwd2) && (temppwd1 != ad->getpwd()))
				{
					setColor(10);
					cout << "修改成功！" << endl;
					ad->Editpwd(temppwd1);
					resetColor();
				}
				else if ((temppwd1 == temppwd2) && (temppwd1 == ad->getpwd()))
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
						cout << "选项输入有非数字!" << endl;
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
						string tempnum, tempowner, tempownerid, tempregtime, tempcolor, tempbrand, tempstr;
						double length, width, height;

						setColor(10);		cout << "请输入车牌照号: ";		resetColor();
						cin >> tempnum;		cin.ignore();
						setColor(10);		cout << "请输入车主姓名: ";		resetColor();
						cin >> tempowner;		cin.ignore();
						setColor(10);		cout << "请输入车主ID: ";		resetColor();
						cin >> tempownerid;		cin.ignore();
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
						ad->AddCar(tempnum, tempowner, tempownerid, tempregtime, tempcolor, tempbrand,
							length, width, height);
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
						if (!(ad->DeleteCar(tempnum)))
						{
							setColor(4);
							cout << "未找到对应车牌照的车辆！" << endl;
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
							if (!(ad->EditCar1(tempnum, int_pos, newinfo)))
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

							if (!ad->EditCar2(tempnum, int_pos, stod(newdata)))
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
				ad->DisplayEdit();
				break;
			}
			case(5):
			{
				setColor(3);
				cout << "您想以下面哪个条件进行车辆的排序？" << endl;
				cout << "1.车牌号  2.注册时间  3.颜色" << endl;
				cout << "4.车辆长度  5.车辆宽度  6.车辆高度" << endl;
				resetColor();
				string i;
				int j;
				cin >> i;
				cin.ignore();
				if (!IsAllNumber(i))
				{
					setColor(4);
					cout << "选项输入有非数字!" << endl;
					resetColor();
					resetCin();
					continue;
				}
				int int_i = stoi(i);
				switch (int_i)
				{
				case(1):
				{
					sort(cvecforall.begin(), cvecforall.end());
					for (j = 0;j < cvecforall.size();j++)
						cvecforall[j].display();
					break;
				}
				case(2):
				{
					sort(cvecforall.begin(), cvecforall.end(), cpirt);
					for (j = 0;j < cvecforall.size();j++)
						cvecforall[j].display();
					break;
				}
				case(3):
				{
					sort(cvecforall.begin(), cvecforall.end(), cpic);
					for (j = 0;j < cvecforall.size();j++)
						cvecforall[j].display();
					break;
				}
				case(4):
				{
					sort(cvecforall.begin(), cvecforall.end(), cpil);
					for (j = 0;j < cvecforall.size();j++)
						cvecforall[j].display();
					break;
				}
				case(5):
				{
					sort(cvecforall.begin(), cvecforall.end(), cpiw);
					for (j = 0;j < cvecforall.size();j++)
						cvecforall[j].display();
					break;
				}
				case(6):
				{
					sort(cvecforall.begin(), cvecforall.end(), cpih);
					for (j = 0;j < cvecforall.size();j++)
						cvecforall[j].display();
					break;
				}
				default: cout << "输入错误！请您重新尝试！" << endl;
				}
				break;
			}
			case(6):
			{
				if (ApplyUserVect.size() == 0)
				{
					setColor(13);
					cout << "目前没有待处理的用户权限提升申请!";
					resetColor();
					continue;
				}
				setColor(9);
				cout << "输入1以批准用户申请，其他输入均将被当作拒绝申请" << endl;
				cout << "(注：输入back即可结束处理退回上级菜单)" << endl;
				resetColor();
				string confirm;
				for (int i = 0;i < ApplyUserVect.size();i++)
				{
					setColor(13);
					cout << "申请用户的id：";
					setColor(3);
					cout << ApplyUserVect[i].getid() << "   ";
					resetColor();
					cin >> confirm;
					cin.ignore();
					if (confirm == "1") ApplyUserVect[i].Resetauth(2);
					else if (confirm == "back") break;
					else ApplyUserVect[i].Resetauth(3);
				}
				setColor(10);
				cout << "处理完毕！" << endl;
				resetColor();
				ad->saveApplyUserVect(ApplyUserVect);
				break;
			}
			case(7):
			{
				setColor(10);
				cout << "感谢使用！" << endl;
				resetColor();
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
		cout << endl;
		setColor(12);
		cout << "-------------------欢迎来到管理员界面！-----------------" << endl;
		cout << "-----------------请选择您需要使用的功能：---------------" << endl;
		cout << "-------------------1.查询车辆与排序---------------------" << endl;
		cout << "------------------2.修改个人账户密码--------------------" << endl;
		cout << "---------------3.添加、删除或修改车辆信息---------------" << endl;
		cout << "----------------4.查看本次登录后操作记录----------------" << endl;
		cout << "--------------------5.查看车辆排序----------------------" << endl;
		cout << "---------------6.查看用户申请提升权限记录---------------" << endl;
		cout << "----------------------7.退出系统------------------------" << endl;
		resetColor();
	}
	void second_display()
	{
		setColor(12);
		cout << "-------------------请选择您要进行的操作-----------------" << endl;
		cout << "-----------------------1.增添车辆-----------------------" << endl;
		cout << "-----------------------2.删除车辆-----------------------" << endl;
		cout << "----------------------3.修改车辆信息--------------------" << endl;
		cout << "----------------------4.退回上级菜单--------------------" << endl;
		resetColor();
	}
	virtual void RestoreAuth()
	{
		ad->Editauth(1);
	}
private:
	Admin* ad;
	vector<User> ApplyUserVect;
};
