#include"GlobalData.h"
std::vector<Car> cvecforall;
std::vector<User> uvecforall;
vector<Car> searcher(string num, string owner, string regtime,
	string color, string brand, double length_min, double length_max,
	double width_min, double width_max, double height_min, double height_max)
{
	vector<Car> tempvect;
	for (int i = 0;i < cvecforall.size();i++)
	{
		if (((num == cvecforall[i].getnum()) || (num == "\\"))
			&& ((owner == cvecforall[i].getowner()) || (owner == "\\"))
			&& ((regtime == cvecforall[i].getregtime()) || (regtime == "\\"))
			&& ((color == cvecforall[i].getcolor()) || (color == "\\"))
			&& ((brand == cvecforall[i].getownerid()) || (brand == "\\"))
			&& ((length_min <= cvecforall[i].getlength()) && (length_max >= cvecforall[i].getlength()))
			&& ((width_min <= cvecforall[i].getwidth()) && (width_max >= cvecforall[i].getwidth()))
			&& ((height_min <= cvecforall[i].getheight()) && (height_max >= cvecforall[i].getheight())))
		{
			tempvect.push_back(cvecforall[i]);
		}
	}
	return tempvect;
}
bool cpirt(const Car& c1, const Car& c2)
{
	return (c1.getregtime() < c2.getregtime());
}
bool cpic(const Car& c1, const Car& c2)
{
	return (c1.getcolor() < c2.getcolor());
}
bool cpib(const Car& c1, const Car& c2)
{
	return (c1.getbrand() < c2.getbrand());
}
bool cpil(const Car& c1, const Car& c2)
{
	return (c1.getlength() < c2.getlength());
}
bool cpiw(const Car& c1, const Car& c2)
{
	return (c1.getwidth() < c2.getwidth());
}
bool cpih(const Car& c1, const Car& c2)
{
	return (c1.getheight() < c2.getheight());
}
void setColor(int color)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
}
void resetColor()
{
	setColor(7);
}