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
class user_lyh;
//#include"类.cpp"
//class user_lyh;
//
//class user_lyh {
//public:
//	user_lyh() {}
//	virtual ~user_lyh() {}
//	int way;//1:qq,2:webo,3:wechat
//	string ID;//6位
//	string name;//最多20位
//	string birth;//8位
//	string useage;//8位
//	string place; //最多40位
//	string key;
//};
//class qq_lyh :public user_lyh {
//public:
//	qq_lyh() :user_lyh() {}
//	~qq_lyh() {}
//protected:
//
//
//};
//class webo_lyh :public user_lyh {
//public:
//	webo_lyh():user_lyh(){}
//	~webo_lyh(){}
//protected:
//
//};
//class wechat_lyh :public user_lyh {
//public:
//	wechat_lyh() :user_lyh() {}
//	~wechat_lyh() {}
//protected:
//
//};