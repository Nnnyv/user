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
#include<mutex>
#include<ctime>
#include <conio.h>
#include"main.cpp"

#include"data.cpp"

#include"login.cpp"

#include"userclass.cpp"

#include"recving.cpp"

#include"face.cpp"

#include"internet.cpp"
//class message_lyh;
//#pragma comment(lib,"WS2_32")/*

//class message_lyh {
//public:
//	message_lyh();
//	message_lyh(string);
//	void reload(string );
//	void add(string );
//	void add_num(string);
//	void add_end();
//	int send(SOCKET);
//	int recv(SOCKET);
//	void putout_num(int);
//	const string str();
//	void clear(int iff=1);
//private:
//	string all;
//};*/