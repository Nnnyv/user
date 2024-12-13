#pragma once
#include"login.h"
using namespace std;
void read_use(user_lyh* &make, int way) {
	int temp = 0, temp1 = 1;
	char SEND[128];
	if (way == 1) {
		make = new qq_lyh;
	}
	else if (way == 2) {
		make = new webo_lyh;
	}
	else if (way == 3) {
		make = new wechat_lyh;
	}
	recv(client_socket, SEND, 128, 0);
	make->ID = string(SEND + temp + 1, SEND[temp]);
	temp += SEND[temp] + 1;
	make->name = string(SEND + temp + 1, SEND[temp]);
	temp += SEND[temp] + 1;
	make->birth = string(SEND + temp + 1, SEND[temp]);
	temp += SEND[temp] + 1;
	make->useage = string(SEND + temp + 1, SEND[temp]);
	temp += SEND[temp] + 1;
	make->place = string(SEND + temp + 1, SEND[temp]);
	recv(client_socket, SEND, 128, 0);
	temp = 0;

}

int login() {
	char way;
	cout << "Ñ¡ÔñµÇÂ¼·½Ê½" << endl << "1 qq|| 2 Î¢²©|| 3 Î¢ÐÅ" << endl;
	cin >> way;
	cout << "ÊäÈëÕËºÅ:";
	string account;
	string password;
	string all;
	int temp = 1, temp1 = 1;
	char SEND[128];
	cin >> account;
	if (account.size() != 6) {
		cout << "ÕË»§´íÎó" << endl;
		system("cls");
		return 0;
	}
	cout << "ÊäÈëÃÜÂë:";
	cin >> password;
	while (waitboth() == 0);
	RECVING = 1;
	SENDING = 1;
	send(client_socket, "\0\0\0", 3, 0);
	all = way + account + password;
	std::strcpy(SEND, all.c_str());
	send(client_socket, SEND, 128, 0);
	recv(client_socket, SEND, 1, 0);
	if (SEND[0] == 0) {
		cout << "ÃÜÂë´íÎó" << endl;
		return 0;
	}
	else {
		system("cls");
		cout << "µÇÂ½³É¹¦" << endl;
	}
	read_use(use,way);
	RECVING = 0;
	SENDING = 0;
	DATA->start(account,way);
}