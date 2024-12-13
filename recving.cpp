#pragma once
#include"recving.h"
using namespace std;
int waitrecving() {
	if (RECVING == 1) {
		this_thread::sleep_for(chrono::seconds(1));
		return 1;
	}
	else return 0;
}
int waitsending() {
	if (SENDING == 1) {
		this_thread::sleep_for(chrono::seconds(1));
		return 1;
	}
	else return 0;
}
int waitboth() {
	if (SENDING == 1||RECVING==1) {
		this_thread::sleep_for(chrono::seconds(1));
		return 1;
	}
	else return 0;
}
class reciver_lyh {

protected:
	void getit() {
		string str;
		int timecontrol = 500;
		int normaltime = 20000;
		int iff;
		while (1) {
			setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timecontrol, sizeof(timecontrol));
			iff=::recv(socket, &str[0], 3, 0);
			if(iff==SOCKET_ERROR){
				setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&normaltime, sizeof(normaltime));
				this_thread::sleep_for(chrono::seconds(1));
			}
			else  {
				while (waitrecving() == 0);
				RECVING = 1;
				if (str == "001") {
					putindata();
				}
				RECVING = 0;
			}
		}
	}
	int putindata() {
		message_lyh mess;
		string str, str1, str2;
		time_t ti;
		mutex mtx;
		int normaltime = 20000;
		setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&normaltime, sizeof(normaltime));
		mess.recv(socket);
		str = mess.str();
		mess.recv(socket);
		str1 = mess.str();
		ti = stoi(str);
		mess.recv(socket);
		str2 = mess.str();
		mtx.try_lock();
		data->in(str, ti, str2);
		mtx.unlock();
		return 1;
	}
	SOCKET socket;
	data_lyh* data;
public:
	void start() {
		thread putin(getit);
		putin.detach();
	}
	reciver_lyh() {};
	void set(SOCKET s, data_lyh* daaa) {
		socket = s;
		//data = daaa;
	}
};
