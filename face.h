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
//#pragma comment(lib,"WS2_32")#include"include.h"
//class face_lyh {
//public:
//	face_lyh(SOCKET a, user_lyh* b);
//	void start();
//private:
//	const SOCKET socket;
//	const user_lyh* user;
//	void checkfriend_face();
//	void addfriend_face();
//	void deletefriend_face();
//	//δ���
//	void datamore_chatfriend_face() {
//
//	}//δ���//δ���
//	void send_chatfriend_face();
//	void chatfriend_face();
//	void friend_face();
//	//////////////����Ϊgroup����///////////////////////////////////////
//	void checkgroup_face();
//	void addgroup_face();
//	void deletegroup_face();
//	//δ���
//	void datamore_chatfriend_face();
//	void send_chatgroup_face();
//	void chatgroup_face();
//	void newmanage_leader_managegroup_face(string);
//	void delmanage_leader_managegroup_face(string);
//	void kick_leader_managegroup_face(string);
//	void check_leader_managegroup_face(string);
//	void cname_leader_managegroup_face(string);
//	void ckind_leader_managegroup_face(string);
//	void leader_managegroup_face(string);
//	void manage_managegroup_face(string);
//	void creatgroup_face();
//	void managegroup_face();
//	void pullgroup_face();
//	void songroup_face();
//	void group_face();
//	/// //////////////��Ϊ����
//	void name_dataset_face();
//	void birth_dataset_face();
//	void place_dataset_face();
//	void dataset_face();
//	void bindset_face();
//	void delset_face();
//	void set_face();
//};
