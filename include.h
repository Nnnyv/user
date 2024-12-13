#pragma once
#include<WinSock2.h>
#include <WS2tcpip.h> 
//#pragma comment(lib,"WS2_32")
#include<stdio.h> 
//#pragma comment(lib,"WS2_32")
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
#include"main.h"
#include"main.cpp"

#include"data.h"
#include"data.cpp"

#include"login.h"
#include"login.cpp"

#include"userclass.h"
#include"userclass.cpp"

#include"recving.h"
#include"recving.cpp"

#include"face.h"
#include"face.cpp"

#include"internet.h"
#include"internet.cpp"
extern user_lyh* use;
extern SOCKET client_socket;
extern int RECVING = 0;
extern int SENDING = 0;
extern data_lyh* DATA;