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
//#include"��.cpp"
//class user_lyh;
//
//class user_lyh {
//public:
//	user_lyh() {}
//	virtual ~user_lyh() {}
//	int way;//1:qq,2:webo,3:wechat
//	string ID;//6λ
//	string name;//���20λ
//	string birth;//8λ
//	string useage;//8λ
//	string place; //���40λ
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