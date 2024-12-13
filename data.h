#pragma once
#include"include.h"
using namespace std;
using namespace std::filesystem;
//class allfile_lyh {
//public:
//	const string id();
//	allfile_lyh(path);
//	void in(string, time_t);
//	void out(string&, int);
//	void flash();
//	void close();
//protected:
//	int row = 0;
//	string ID;
//	fstream file;
//};
//class data_lyh {
//public:
//	data_lyh(string, char);
//	data_lyh() {};
//	void start(string, char);
//	void flash();
//	int in(string, time_t, string);
//	int out(string&, int a=-1, string s='\0');
//	int remove(string);
//	int newone(string);
//	static int creatfile(string, char);
//protected:
//	string ID;
//	char way;
//	vector<allfile_lyh> file;
//	allfile_lyh* find(string);
//};