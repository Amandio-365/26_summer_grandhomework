#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"User.h"
#include"Car.h"
#include<vector>
using namespace std;
class FileIO
{
public:
	FileIO();
	FileIO(const FileIO& other);
	bool ReadUser(vector<User>& vec);
	bool ReadCar(vector<Car>& vec);
	bool WriteUser(vector<User>& vec);
	bool WriteCar(vector<Car>& vec);
private:
	const string UserFile;
	const string CarFile;
	const char cm;
	string ErrorInfo;
};
