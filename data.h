#pragma once
#include<WinSock2.h>
#include <WS2tcpip.h> 
#pragma comment(lib,"WS2_32")
#include<stdio.h> 
#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
#include<ctime>
#include<vector>
#include<thread>
#include<ctime>
#include <conio.h>
#include"main.cpp"

#include"data.cpp"

#include"login.cpp"

#include"userclass.cpp"

#include"recving.cpp"

#include"face.cpp"

#include"internet.cpp"
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