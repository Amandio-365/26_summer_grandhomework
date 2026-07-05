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
void reportError()
{
	setColor(4);
	cout << "输入错误！" << endl;
	resetColor();
}
string GetPlatePinYin(const string& plate)
{
	// 全国车牌省份汉字映射拼音
	static unordered_map<string, string> hanzi2py = {
		{"京", "jing"}, {"津", "jin"}, {"沪", "hu"}, {"渝", "yu"},
		{"冀", "ji"}, {"晋", "jin"}, {"辽", "liao"}, {"吉", "ji"}, {"黑", "hei"},
		{"苏", "su"}, {"浙", "zhe"}, {"皖", "wan"}, {"闽", "min"}, {"赣", "gan"}, {"鲁", "lu"},
		{"豫", "yu"}, {"鄂", "e"}, {"湘", "xiang"}, {"粤", "yue"}, {"琼", "qiong"},
		{"川", "chuan"}, {"贵", "gui"}, {"云", "yun"}, {"陕", "shan"}, {"甘", "gan"},
		{"青", "qing"}, {"宁", "ning"}, {"新", "xin"}, {"港", "gang"}, {"澳", "ao"}, {"台", "tai"} };
	string firstHan = plate.substr(0, 2);
	if (hanzi2py.count(firstHan))
		return hanzi2py[firstHan]; //不再是数组的思维，而是表示一种函数映射
	return "zzzzz";
}

bool IsAllNumber(const string& str)
{
	const char* ptr = str.c_str();
	for (int i = 0;i < str.size();i++)
		if (!IsDigitChar(ptr[i]))
			return false;
	return true;
}
bool IsDigitChar(char ch)
{
	return ch >= '0' && ch <= '9';
}
bool StringToPositiveDouble(const string& s, double& outNum)
{
	int dotCount = 0;
	for (char ch : s)
	{
		if (ch == '.')
		{
			dotCount++;
			if (dotCount > 1) return false; // 多个小数点非法
		}
		else if (!IsDigitChar(ch))
		{
			return false; // 包含非数字、非小数点
		}
	}
	if (s.empty() || s == ".") return false;

	// 转浮点
	outNum = stod(s);
	return outNum > 0;
}
bool CheckRegtimeFormat(const string& timeStr)
{
	int dashIndex = -1;
	int dashCnt = 0;
	for (int i = 0; i < timeStr.size(); i++)
	{
		if (timeStr[i] == '-')
		{
			dashIndex = i;
			dashCnt++;
		}
	}
	// 只能有一个横杠，且横杠在第4位（年份4位）
	if (dashCnt != 1 || dashIndex != 4)
		return false;

	// 年份4位全数字
	for (int i = 0; i < 4; i++)
		if (!IsDigitChar(timeStr[i])) return false;

	// 月份部分
	string monthStr = timeStr.substr(dashIndex + 1);
	if (monthStr.empty() || monthStr.size() > 2) return false;
	for (char ch : monthStr)
		if (!IsDigitChar(ch)) return false;

	int month = stoi(monthStr);
	return (month >= 1 && month <= 12);
}
bool CheckCarAllInfo(const string& lenStr,
	const string& widStr,
	const string& higStr,
	const string& regTimeStr)
{
	if (!CheckRegtimeFormat(regTimeStr))
	{
		setColor(4);
		cout << "数据校验失败：注册时间格式错误！必须为 YYYY-MM，月份1~12" << endl;
		resetColor();
		return false;
	}
	double temp;
	if (!StringToPositiveDouble(lenStr, temp))
	{
		setColor(4);
		cout << "数据校验失败：车辆长度必须为大于0的数字，仅允许一个小数点" << endl;
		resetColor();
		return false;
	}
	// 3. 校验宽度
	if (!StringToPositiveDouble(widStr, temp))
	{
		setColor(4);
		cout << "数据校验失败：车辆宽度必须为大于0的数字，仅允许一个小数点" << endl;
		resetColor();
		return false;
	}
	// 4. 校验高度
	if (!StringToPositiveDouble(higStr, temp))
	{
		setColor(4);
		cout << "数据校验失败：车辆高度必须为大于0的数字，仅允许一个小数点" << endl;
		resetColor();
		return false;
	}

	// 全部校验通过
	return true;
}
void resetCin()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}