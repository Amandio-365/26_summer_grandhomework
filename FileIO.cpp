#include"FileIO.h"
#include<string>
#include<iostream>
using namespace std;
FileIO::FileIO():cm(','), UserFile("User.txt.txt"), CarFile("Car.txt.txt") //FileIO类构造函数
{
	ErrorInfo = "All fine!";
}
FileIO::FileIO(const FileIO& other) :cm(other.cm), UserFile(other.UserFile),
CarFile(other.CarFile) //FileIO类的复制构造函数
{
	ErrorInfo = other.ErrorInfo;
}
bool FileIO::ReadUser(vector<User>& vec) //从文本文件中读入数据存入User类全局容器vector
{
	ifstream inf(UserFile, ios_base::in);
	if (!(inf.good()))
	{
		ErrorInfo = "Fail to open the user readin_file!";
		cout << ErrorInfo << endl;
		return false;
	}
	string tempID, tempPwd;
	int tempauth;
	char cma;
	while ((inf >> tempID) && (inf >> cma) && (inf >> tempPwd) && (inf >> cma)
		&& (inf >> tempauth))
	{
		User temp(tempID, tempPwd, tempauth);
		vec.push_back(temp);
	}
	cout << "Readin process finished  " << ErrorInfo << endl;
	return true;
}
bool FileIO::ReadCar(vector<Car>& vec) //从文本文件中读入数据存入User类全局容器vector
{
	ifstream inf(CarFile, ios_base::in);
	if (!(inf.good()))
	{
		ErrorInfo = "Fail to open the car readin_file!";
		cout << ErrorInfo << endl;
		return false;
	}
	string tempnum, tempregtime, tempowner, tempownerid, tempcolor, tempbrand;
	double templength, tempwidth, tempheight;
	char cma;
	while ((inf >> tempnum) && (inf >> cma) && (inf >> tempowner) && (inf >> cma)
		&& (inf >> tempownerid) && (inf >> cma) && (inf >> tempregtime) && (inf >> cma)
		&&(inf >> tempcolor) && (inf >> cma) && (inf >> tempbrand) && (inf >> cma) 
		&& (inf >> templength) && (inf >> cma) &&(inf >> tempwidth) && (inf >> cma)
		&& (inf >> tempheight))
	{
		Car tcar(tempnum, tempowner, tempownerid, tempregtime, tempcolor, tempbrand, templength
			,tempwidth, tempheight);
		vec.push_back(tcar);
	}
	cout << "Readin process finished  " << ErrorInfo << endl;
	return true;
}
bool FileIO::WriteUser(vector<User>& vec) //将经过各类处理后的User类全局容器vector中的数据写回文本文件
{
	ofstream outf(UserFile, ios_base::out);
	if (!(outf.good()))
	{
		ErrorInfo = "Fail to open the user writein_file!";
		cout << ErrorInfo << endl;
		return false;
	}
	int i = 0;
	while ((outf << vec[i].getid()) && (outf << " " << cm << " ") && (outf << vec[i].getpwd()) && (outf << " " << cm << " ")
		&& (outf << vec[i].getauth()) && (outf << endl))
	{
		i = i + 1;
		if (i == vec.size())
		{
			cout << "writein process finished!" << ErrorInfo << endl;
			break;
		}
	}
	if (i < vec.size())
	{
		ErrorInfo = "writein process unfinished!";
		cout << ErrorInfo << endl;
	}
}
bool FileIO::WriteCar(vector<Car>& vec) //将经过各类处理后的User类全局容器vector中的数据写回文本文件
{
	ofstream outf(CarFile, ios_base::out);
	if (!(outf.good()))
	{
		ErrorInfo = "Fail to open the car writein_file!";
		cout << ErrorInfo << endl;
		return false;
	}
	int i = 0;
	while ((outf << vec[i].getnum()) && (outf << " " << cm << " ") && (outf << vec[i].getowner()) && (outf << " " << cm << " ")
		&& (outf << vec[i].getownerid()) && (outf << " " << cm << " ") && (outf << vec[i].getregtime()) && (outf << " " << cm << " ")
		&&(outf << vec[i].getcolor()) && (outf << " " << cm << " ") && (outf << vec[i].getbrand()) && (outf << " " << cm << " ")
		&& (outf << vec[i].getlength()) && (outf << " " << cm << " ") && (outf << vec[i].getwidth()) && (outf << " " << cm << " ")
		&& (outf << vec[i].getheight()) &&(outf << endl))
	{
		i = i + 1;
		if (i == vec.size())
		{
			cout << "writein process finished!" << ErrorInfo << endl;
			break;
		}
	}
	if (i < vec.size())
	{
		ErrorInfo = "writein process unfinished!";
		cout << ErrorInfo << endl;
	}
}