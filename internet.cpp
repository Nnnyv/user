#pragma once
#include"internet.h"
using namespace std;
class message_lyh {
public:
	//message_lyh() {};
	message_lyh(SOCKET soc,string a):all(a){
		socket = soc;
	}
	message_lyh(SOCKET soc) {
		socket = soc;
	}
	static int waitsending() {
		int num = 0;
		while (1) {
			if (RECVING == 1) {
				this_thread::sleep_for(chrono::seconds(1));
				num++;
				if (num == 15) {
					cout << "waitting..." << endl;
					num = 0;
				}
			}
			else {
				return 1;
			}
		}
	}
	static int waitrecving() {
		int num = 0;
		while (1) {
			if (SENDING == 1) {
				this_thread::sleep_for(chrono::seconds(1));
				num++;
				if (num == 15) {
					cout << "waitting..." << endl;
					num = 0;
				}
			}
			else {
				return 1;
			}
		}
	}
	static int waitboth() {
		int num = 0;
		while (1) {
			if (RECVING == 1||SENDING==1) {
				this_thread::sleep_for(chrono::seconds(1));
				num++;
				if (num == 15) {
					cout << "waitting..." << endl;
					num = 0;
				}
			}
			else {
				return 1;
			}
		}
	}
	static int send1() {
		if (SENDING == 1) {
			return 0;
		}
		else {
			SENDING = 1;
			return 1;
		}
	}
	static int send0() {
		if (SENDING == 0) {
			return 0;
		}
		else {
			SENDING = 0;
			return 1;
		}
	}
	static int recv1() {
		if (RECVING == 1) {
			return 0;
		}
		else {
			RECVING = 1;
			return 1;
		}
	}
	static int recv0() {
		if (RECVING == 0) {
			return 0;
		}
		else {
			RECVING = 0;
			return 1;
		}
	}
	int setsocket(SOCKET soc) {
		socket = soc;
		return 1;
	}
	int sign(char a[]) {
		int n = ::send(socket, a, 3, 0);
		return n;
	}
	int sign(string str) {
		int n = ::send(socket, str.c_str(), 3, 0);
		return n;
	}
	int recvsign() {
		clear();
		return ::recv(socket, signal, 3, 0);
	}
	char* const nowsignal() {
		return signal;
	}
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
	int send() {
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
	int recv() {
		clear();
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
	static int RECVING;
	static int SENDING;
	SOCKET socket;
	string all;
	char signal[3];
};
int message_lyh::RECVING = 0;
int message_lyh::SENDING = 0;