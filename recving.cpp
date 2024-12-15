#pragma once
#include"recving.h"
using namespace std;
//int waitrecving() {
//	if (RECVING == 1) {
//		this_thread::sleep_for(chrono::seconds(1));
//		return 1;
//	}
//	else return 0;
//}
//int waitsending() {
//	if (SENDING == 1) {
//		this_thread::sleep_for(chrono::seconds(1));
//		return 1;
//	}
//	else return 0;
//}
//int waitboth() {
//	if (SENDING == 1||RECVING==1) {
//		this_thread::sleep_for(chrono::seconds(1));
//		return 1;
//	}
//	else return 0;
//}
class reciver_lyh {

protected:
	void getit() {
		string str;
		int timecontrol = 500;//0.5Ãë
		int normaltime = 20000;//20Ãë
		int iff;
		while (1) {
			message_lyh::waitrecving();
			message_lyh::recv1();
			setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timecontrol, sizeof(timecontrol));
			iff = mess.recvsign();
			if(iff==SOCKET_ERROR){
				message_lyh::recv0();
				setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&normaltime, sizeof(normaltime));
				this_thread::sleep_for(chrono::seconds(1));
			}
			else  {
				if (str == "001") {
					putindata();
				}
			}
			message_lyh::recv0();
		}
	}
	int putindata() {
		string str, str1, str2;
		time_t ti;
		mutex mtx;
		int normaltime = 20000;
		setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&normaltime, sizeof(normaltime));
		mess.recv();
		str = mess.str();
		mess.recv();
		str1 = mess.str();
		ti = stoi(str);
		mess.recv();
		str2 = mess.str();
		mtx.try_lock();
		data->in(str, ti, str2);
		mtx.unlock();
		return 1;
	}
	message_lyh mess;
	SOCKET socket;
	data_lyh* data;
public:
	void start() {
		thread putin(getit);
		putin.detach();
	}
	reciver_lyh(SOCKET soc):mess(soc) {
		socket = soc;
	};
	void set(SOCKET s, data_lyh* daaa) {
		socket = s;
		//data = daaa;
	}
};
