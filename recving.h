#pragma once
#include<WinSock2.h>
#include <WS2tcpip.h> 
#pragma comment(lib,"WS2_32")
#include<stdio.h> 
#include<iostream>
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
//int waitrecving();
//int waitsending();
//int waitboth();
//class reciver_lyh {
//public:
//	void start();
//	void set(SOCKET, data_lyh*);
//	reciver_lyh();
//protected:
//	void getit();
//	int putindata();
//	SOCKET socket;
//	data_lyh* data;
//};
