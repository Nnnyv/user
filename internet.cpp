#pragma once
#include"internet.h"
using namespace std;
class message_lyh {
public:
	message_lyh() {};
	message_lyh(string a):all(a){}
	void reload(string a) {
		all = a;
	}
	void add(string a) {
		all += a;
	}
	void add_num(string a) {
		char temp = a.size();
		all += temp;
		all += a;
	}
	void add_end() {
		all += '\0';
	}
	int send(SOCKET socket) {
		char length[3];
		length[2] = all.size() % 128;
		length[1] = (all.size() / 128) % 128;
		length[1] = (all.size() / 128) / 128;
		int iff;
		iff=::send(socket, length, 3, 0);
		if (iff == SOCKET_ERROR) {
			return SOCKET_ERROR;
		}
		return ::send(socket, all.c_str(), all.size(), 0);
	}
	int recv(SOCKET socket) {
		char length[3];
		int leng=0;
		int iff;
		iff=::recv(socket, length, 3, 0);
		if (iff == SOCKET_ERROR) {
			return SOCKET_ERROR;
		}
		leng += length[2];
		leng += length[1] * 128;
		leng += length[0] * 16384;
		return ::recv(socket, &all[0], leng, 0);
	}
	void putout_num(int space=0) {
		int temp = 0, temp1 = 0;
		while (all[temp] != 0) {
			cout.write(&all[0] + temp + 1, all[temp]);
			temp1++;
			if (temp1 >= space) { 
				cout << endl;
				temp1 = 0;
			}
			else cout << "  ";
			temp += all[temp] + 1;
		}
	}
	const string str() {
		return all;
	}
	void clear(int iff=1) {
		if (iff == 1)all = "";
		else all.clear();
	}
private:
	string all;
};