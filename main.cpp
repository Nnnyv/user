#pragma once
#include"include.h"
using namespace std;

int start() {
	char addr[10];
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		cout << "����socketʧ��  " << GetLastError() << endl;
		return -1;
	}
	sockaddr_in target ;
	target.sin_family = AF_INET;
	target.sin_port = htons(8080);
	while (1) {
		cout << "����1��������" << endl << "����2�Զ����ַ" << endl;
		if (getchar() == 2) {
			char addr[10];
			scanf("%s", addr);
			target.sin_addr.s_addr = inet_addr(addr);
			break;
		}
		else if (getchar() == 1) {
			target.sin_addr.s_addr = inet_addr("127.0.0.1");
			break;
		}
		system("cls");
	}
	system("cls");
	if (connect(client_socket, (sockaddr*)&target, sizeof(target)) == -1) {
		cout << "����ʧ��" << endl;
		closesocket(client_socket);
		return -1;
	};
	//char get[128];
	//send(client_socket, get, 128, 0);
	//get[0] = '\0';
	//int bytes = recv(client_socket, get, 128, 0);
	//if (bytes == 0) {
	//	cout << "���Ӵ���������" << endl;
	//	return 0;
	//}
	//if (get[0] == '0') {
	//	cout << "�������" << endl;
	//	return 0;
	//}
	int timecontrol = 20000;
	setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timecontrol, sizeof(timecontrol));
	login();
	reciver_lyh reciver;
	reciver.set(client_socket, DATA);
	reciver.start();
}