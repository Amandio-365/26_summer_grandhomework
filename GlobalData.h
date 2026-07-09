#pragma once
#define NOMINMAX
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<unordered_map>
#include<limits>
#include"Car.h"
#include"User.h"
#include<Windows.h>
using namespace std;
extern std::vector<Car> cvecforall;
extern std::vector<User> uvecforall;
extern vector<Car> searcher(string num, string owner, string regtime_min, string regtime_max,
	string color, string brand, double length_min, double length_max,
	double width_min, double width_max, double height_min, double height_max);
bool cpirt(const Car& c1, const Car& c2);
bool cpic(const Car& c1, const Car& c2);
bool cpil(const Car& c1, const Car& c2);
bool cpiw(const Car& c1, const Car& c2);
bool cpih(const Car& c1, const Car& c2);
void setColor(int color);
void resetColor();
void reportError();
string GetPlatePinYin(const string& plate);
bool IsDigitChar(char ch);
bool IsAllNumber(const string& str);
bool StringToPositiveDouble(const string& str, double& outNum);
bool CheckRegtimeFormat(const string& str);
bool CheckCarAllInfo(const string& length, const string& width, const string& height, const string& regtime = "1001-01");
void resetCin();