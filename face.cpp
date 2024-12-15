#pragma once
#include"face.h"
using namespace std;
/////////////����Ϊfriend����//////////////////////////////
//���ID  �ǳ�\n
class face_lyh {
public:
	face_lyh(SOCKET Socket, user_lyh* Use,data_lyh *da) :socket(Socket), user(Use),data(da) {}
	void start() {
		char input;
		while (1) {
			system("cls");
			cout << "1������" << endl;
			cout << "2��Ⱥ��" << endl;
			cout << "3������" << endl;
			cout << "4���˳�" << endl;
			cin >> input;
			if (input == '1') {
				friend_face();
			}
			else if (input == '2') {
				group_face();
			}
			else if (input == '3') {
				set_face();
			}
			else if (input == '4') {
				return;
			}
		}
	}
private:
	const SOCKET socket;
	user_lyh* const user;
	data_lyh* data;
	void checkfriend_face() {
		char receive[128];
		message_lyh temp(socket);
		message_lyh::waitboth();
		message_lyh::send1();
		message_lyh::recv1();
		temp.sign("\0\0\1");
		temp.recv();
		temp.putout_num(2);
		/*recv(socket, receive, 128, 0);
		while (1) {
			cout.write(receive + temp + 1, receive[temp]);
			cout << "  ";
			temp += receive[temp] + 1;
			if (receive[temp] == -1) {
				recv(socket, receive, 128, 0);
				temp = 0;
			}
			else if (receive[temp] == 0) {
				break;
			}
			cout.write(receive + temp + 1, receive[temp]);
			cout << endl;
			temp += receive[temp] + 1;
			if (receive[temp] == -1) {
				recv(socket, receive, 128, 0);
				temp = 0;
			}
			else if (receive[temp] == 0) {
				break;
			}
		}*/
		message_lyh::send0();
		message_lyh::recv0();
		_getch();
	}
	void addfriend_face() {
		string newid;
		int check = 0;
		message_lyh message(socket);
		system("cls");
		cout << "ID��";
		cin >> newid; 
		message_lyh::waitboth();
		message_lyh::send1();
		message_lyh::recv1();
		check += message.sign("\0\0\2");
		message.add(newid.c_str());
		check += message.send();
		if (check > 0) {
			cout << "���ʧ��" << endl;
		}
		else {
			cout << "�ѷ�������" << endl;
		}
		message_lyh::send0();
		message_lyh::recv0();
		_getch();
	}
	void deletefriend_face() {
		string newid;
		int check = 0;
		message_lyh message(socket);
		message_lyh::waitboth();
		message_lyh::send1();
		message_lyh::recv1();
		system("cls");
		cout << "ID��";
		cin >> newid;
		check += message.sign("\0\0\3");
		message.add(newid.c_str());
		check += message.send();
		if (check > 0) {
			cout << "ɾ��ʧ��" << endl;
		}
		else {
			cout << "��ɾ����" << newid << endl;
			//use->del_friend(newid);
		}
		message_lyh::send0();
		message_lyh::recv0();
		_getch();
	}
	void datamore_chatfriend_face(string id) {
		string str;
		data->out(str, -1, id);
		cout << str;
	}
	void send_chatfriend_face() {

		string tt;
		int temp = 0;
		message_lyh::waitsending();
		message_lyh::send1();
		cout << "������:";
		cin >> tt;
		message_lyh tempm(socket,tt);
		tempm.setsocket(socket);
		tempm.sign("\0\0\5");
		tempm.send();
		//while (1) {
		//	if (temp + 126 >= tt.size()) {
		//		tt.copy(putout, tt.size() - temp, temp);
		//		putout[tt.size() - temp] = '\0';
		//		putout[127] = '\0';//127λΪ0�����ѽ���
		//		send(socket, putout, 128, 0);
		//		break;
		//	}
		//	tt.copy(putout, 126, temp);
		//	putout[126] = '\0';
		//	putout[127] = '\1';
		//	send(socket, putout, 128, 0);
		//	temp += 126;
		//}
		message_lyh::send0();
	}
	void chatfriend_face() {
		system("cls");
		string id;
		char iff;
		message_lyh message(socket);
		message_lyh::waitboth();
		message_lyh::send0();
		message_lyh::recv0();
		cout << "ѡ����ѣ�";
		cin >> id;
		message.sign("\0\0\4");
		message.add(id.c_str());
		message.send();
		message.recv();
		iff = message.str().c_str()[0];//����1���Ǻ��ѣ����Խ�����һ��
		message_lyh::send0();
		message_lyh::recv0();
		if (iff != 1) {
			cout << "��������ĺ���" << endl;
			_getch();
			return;
		}
		while (1) {
			cout << "1���鿴������Ϣ" << endl;
			cout << "2��������Ϣ" << endl;
			cout << "3���˳�" << endl;
			cin >> iff;
			if (iff == 1) {
				datamore_chatfriend_face(id);//�����ݿ��ڶ���һ�ܵ�������Ϣ
			}
			else if (iff == 2) {
				send_chatfriend_face();
			}
			else if (iff == 3) {
				return;
			}
		}
	}
	void friend_face() {
		char input;
		while (1) {
			system("cls");
			cout << "1���鿴����" << endl;
			cout << "2����Ӻ���" << endl;
			cout << "3��ɾ������" << endl;
			cout << "4����������" << endl;
			cout << "5������" << endl;
			cin >> input;
			if (input == '1') {
				checkfriend_face();
			}
			else if (input == '2') {
				addfriend_face();
			}
			else if (input == '3') {
				deletefriend_face();
			}
			else if (input == '4') {
				chatfriend_face();
			}
			else if (input == '4') {
				return;
			}
		}
	}
	//////////////����Ϊgroup����///////////////////////////////////////
	void checkgroup_face() {
		message_lyh temp(socket);
		message_lyh::waitboth();
		message_lyh::send1();
		message_lyh::recv1();
		temp.sign("\0\1\1");
		temp.recv();
		message_lyh::send0();
		message_lyh::recv0();
		temp.putout_num(2);
		/*char receive[128];
		int temp = 0, temp1;
		send(socket, "\0\1\1", 3, 0);
		recv(socket, receive, 128, 0);
		while (1) {
			cout.write(receive + temp + 1, receive[temp]);
			cout << "  ";
			temp += receive[temp] + 1;
			if (receive[temp] == -1) {
				recv(socket, receive, 128, 0);
				temp = 0;
			}
			else if (receive[temp] == 0) {
				break;
			}
			cout.write(receive + temp + 1, receive[temp]);
			cout << endl;
			temp += receive[temp] + 1;
			if (receive[temp] == -1) {
				recv(socket, receive, 128, 0);
				temp = 0;
			}
			else if (receive[temp] == 0) {
				break;
			}
		}*/
		_getch();
	}
	void addgroup_face() {
		string newid;
		message_lyh mess(socket);
		int check = 0;
		system("cls");
		cout << "ID��";
		cin >> newid;
		message_lyh::waitsending();
		message_lyh::send1();
		check += mess.sign("\0\1\2");
		mess.add(newid.c_str());
		check += mess.send();
		message_lyh::send0();
		if (check > 0) {
			cout << "���ʧ��" << endl;
		}
		else {
			cout << "�ѷ�������" << endl;
		}
		_getch();
	}
	void deletegroup_face() {
		string newid;
		int check = 0;
		message_lyh mess(socket);
		system("cls");
		cout << "ID��";
		cin >> newid;
		message_lyh::waitsending();
		message_lyh::send1();
		check+=mess.sign("\0\1\3");
		mess.add(newid.c_str());
		check += mess.send();
		message_lyh::send0();
		if (check > 0) {
			cout << "�˳�Ⱥ��ʧ��" << endl;
		}
		else {
			cout << "���˳�Ⱥ�ģ�" << newid << endl;
			//use->del_friend(newid);
		}
		_getch();
	}
	void datamore_chatgroup_face(string id) {
		string str;
		data->out(str, -1, id);
		cout << str;
	}
	void send_chatgroup_face() {
		string tt;
		message_lyh mess(socket);
		//char putout[128];
		int temp = 0;
		cout << "������:";
		message_lyh::waitsending();
		message_lyh::send1();
		mess.sign("\0\1\5");
		cin >> tt;
		message_lyh tempm(socket,tt);
		tempm.send();
		message_lyh::send0();
	}
	void chatgroup_face() {
		system("cls");
		string id;
		message_lyh mess(socket);
		char iff;
		cout << "ѡ��Ⱥ�ģ�";
		cin >> id;
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		mess.sign("\0\1\4");
		mess.add(id.c_str());
		mess.recv();
		iff = mess.str().c_str()[0];//����1���Ǻ��ѣ����Խ�����һ��
		message_lyh::recv0();
		message_lyh::send0();
		if (iff != 1) {
			cout << "δ�����Ⱥ��" << endl;
			_getch();
			return;
		}
		//�����ݿ��ڶ���һ�ܵ�������Ϣ
		while (1) {
			cout << "1���鿴������Ϣ" << endl;
			cout << "2��������Ϣ" << endl;
			cout << "3���˳�" << endl;
			cin >> iff;
			if (iff == 1) {
				datamore_chatgroup_face(id);//�����ݿ��ڶ���100��������Ϣ
			}
			else if (iff == 2) {
				send_chatfriend_face();
			}
			else if (iff == 3) {
				return;
			}
		}
	}
	void newmanage_leader_managegroup_face(string id) {
		message_lyh message(socket);
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message.sign("\0\1\7");
		string newid;
		char temp;
		cout << "�¹���ԱID��";
		cin >> newid;
		message.add_num(user->key);//ԭʼ����
		message.add_num(id);//Ⱥid
		message.add_num(newid);//�¹���Աid
		message.add_end();
		message.send();
		message.recv();
		temp = message.str().c_str()[0];
		message_lyh::recv0();
		message_lyh::send0();
		if (temp == 1) {
			cout << "�������" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "����" << endl;
			_getch();
			system("cls");
		}
	}
	void delmanage_leader_managegroup_face(string id) {
		message_lyh message(socket);
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message.sign("\0\1\010");
		string newid;
		char temp;
		cout << "��Ҫɾ���Ĺ���ԱID��";
		cin >> newid;
		message.add_num(user->key);//ԭʼ����
		message.add_num(id);//Ⱥid
		message.add_num(newid);//����Աid
		message.add_end();
		message.send();
		message.recv();
		temp = message.str().c_str()[0];
		message_lyh::recv0();
		message_lyh::send0();
		if (temp == 1) {
			cout << "�������" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "����" << endl;
			_getch();
			system("cls");
		}
	}
	void kick_leader_managegroup_face(string id) {
		message_lyh message(socket);
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message.sign("\000\001\011");
		string newid;
		char temp;
		cout << "ID��";
		cin >> newid;
		message.add_num(user->key);//ԭʼ����
		message.add_num(user->ID);//�û�id
		message.add_num(id);//Ⱥid
		message.add_num(newid);//����Աid
		message.add_end();
		message.send();
		message.recv();
		temp = message.str().c_str()[0];
		message_lyh::recv0();
		message_lyh::send0();
		if (temp == 1) {
			cout << "�������" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "����" << endl;
			_getch();
			system("cls");
		}
	}
	void check_leader_managegroup_face(string id) {
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message_lyh message(socket);
		message.sign("\0\1\10");
		string put, put1;
		char iff;
		message.add_num(user->key);
		message.add_num(user->ID);
		message.add_num(id);
		message.add_end();
		message.send();
		message.recv();
		iff = message.str().c_str()[0];
		if (iff == 0) {
			cout << "����";
			_getch();
			system("cls");
		}
		message.recv();
		message.putout_num(3);//������д    name id pname
		cout << endl;
		while (1) {
			cout << "����0���أ�����1����:";
			cin >> iff;
			if (iff == 0) {
				system("cls");
				message_lyh::recv0();
				message_lyh::send0();
				return;
			}
			cout << "ѡ��ID��";
			cin >> put;
			cout << "����1ͬ��  ����0�ܾ�";
			cin >> put1;
			message.add_num(user->key);
			message.add_num(user->ID);
			message.add_num(id);
			message.add_num(put);
			message.add_num(put1);
			message.add_end();
			message.send();
			message.recv();
			put = message.str();
			if (put[0] == 1) {
				cout << "���" << endl;
			}
			else {
				cout << "����" << endl;
			}
		}
	}
	void cname_leader_managegroup_face(string id) {
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message_lyh message(socket);
		message.sign("\0\1\12");
		string newid;
		char temp;
		cout << "�����ƣ�";
		cin >> newid;
		message.add_num(user->key);//ԭʼ����
		message.add_num(user->ID);//�û�id
		message.add_num(id);//Ⱥid
		message.add_num(newid);//������
		message.add_end();
		message.send();
		message.recv();
		temp = message.str().c_str()[0];
		message_lyh::recv0();
		message_lyh::send0();
		if (temp == 1) {
			cout << "�������" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "����" << endl;
			_getch();
			system("cls");
		}
	}
	void ckind_leader_managegroup_face(string id) {
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message_lyh message(socket);
		message.sign("\0\1\12");
		string newid;
		char temp;
		cout << "1����ͨȺ" << endl;
		cout << "2������Ⱥ" << endl;
		cout << "3����УȺ" << endl;
		cout << "�����ͣ�";
		cin >> newid;
		message.add_num(user->key);//ԭʼ����
		message.add_num(user->ID);//�û�id
		message.add_num(id);//Ⱥid
		message.add_num(newid);//������
		message.add_end();
		message.send();
		message.recv();
		temp = message.str().c_str()[0];
		message_lyh::recv0();
		message_lyh::send0();
		if (temp == 1) {
			cout << "�������" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "����" << endl;
			_getch();
			system("cls");
		}
	}
	void leader_managegroup_face(string id) {
		char iff;
		if (user->way == 1) {
			message_lyh message(socket);
			message.recv();
			cout << "Ⱥ��Ա��:" << endl;
			message.putout_num(2);
			message.recv();
			cout << "����Ա��:" << endl;
			message.putout_num(2);
			while (1) {
				cout << "1�������µĹ���Ա" << endl;
				cout << "2��ȡ������Ȩ��" << endl;
				cout << "3������Ա�߳�Ⱥ��" << endl;
				cout << "4�������Ⱥ����" << endl;
				cout << "5������Ⱥ������" << endl;
				cout << "6������Ⱥ������" << endl;
				cout << "0������" << endl;
				cin >> iff;
				if (iff == 0) {
					return;
				}
				else if (iff == 1) {
					newmanage_leader_managegroup_face(id);
				}
				else if (iff == 2) {
					delmanage_leader_managegroup_face(id);
				}
				else if (iff == 3) {
					kick_leader_managegroup_face(id);
				}
				else if (iff == 4) {
					leader_managegroup_face(id);
				}
				else if (iff == 5) {
					cname_leader_managegroup_face(id);
				}
				else if (iff == 6) {
					ckind_leader_managegroup_face(id);
				}
			}
		}
		else if (user->way == 2 || user->way == 3) {
			message_lyh message(socket);
			message.recv();
			cout << "Ⱥ��Ա��:" << endl;
			message.putout_num(2);
			message.recv();
			cout << "1������Ա�߳�Ⱥ��" << endl;
			cout << "2���鿴��Ⱥ����" << endl;
			cout << "3������Ⱥ������" << endl;
			cout << "0������" << endl;
			cin >> iff;
			if (iff == 0) {
				return;
			}
			else if (iff == 1) {
				kick_leader_managegroup_face(id);
			}
			else if (iff == 2) {
				leader_managegroup_face(id);
			}
			else if (iff == 3) {
				cname_leader_managegroup_face(id);
			}
		}
	}
	void manage_managegroup_face(string id) {
		char iff;
		if (user->way == 1) {
			message_lyh message(socket);
			message.recv();
			cout << "Ⱥ��Ա��:" << endl;
			message.putout_num(2);
			message.recv();
			cout << "����Ա��:" << endl;
			message.putout_num(2);
			while (1) {
				cout << "1������Ա�߳�Ⱥ��" << endl;
				cout << "2�������Ⱥ����" << endl;
				cout << "3������Ⱥ������" << endl;
				cout << "0������" << endl;
				cin >> iff;
				if (iff == 0) {
					return;
				}
				else if (iff == 1) {
					kick_leader_managegroup_face(id);
				}
				else if (iff == 2) {
					leader_managegroup_face(id);
				}
				else if (iff == 3) {
					cname_leader_managegroup_face(id);
				}
			}
		}
		else if (user->way == 2 || user->way == 3) {
			return;
		}
	}//////////////////////////////////////////////////////////δ���
	void creatgroup_face() {
		message_lyh message(socket);
		string id, name;
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message.sign("\0\1\11");
		system("cls");
		cout << "Ⱥ�����ƣ�";
		cin >> name;
		message.add_num(name);
		message.add_end();
		message.send();
		message.recv();
		id = message.str();
		cout << "���ȺIDΪ:" << id;
		message_lyh::recv0();
		message_lyh::send0();
		_getch();
		system("cls");
	}

	void managegroup_face() {
		message_lyh message(socket);
		string temp;
		char chartemp;
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message.sign("\0\1\6");
		message.recv();
		message.putout_num(2);
		while (1) {
			cout << "ѡ��Ⱥ�Ļ�0����";
			cin >> temp;
			if (temp.size() == 1 && temp[0] == 1) {
				message_lyh::recv0();
				message_lyh::send0();
				return;  
			}
			else if (temp.size() != 6) {
				cout << "id����" << endl;
				_getch();
				system("cls");
			}
			else {
				send(socket, temp.c_str(), 6, 0);
				recv(socket, &chartemp, 1, 0);//0��Ȩ�� 1��Ⱥ�� 2�ǹ���
				if (chartemp == 0) {
					cout << "id����:";
					_getch();
					system("cls");
				}
				else if (chartemp == 1) {
					leader_managegroup_face(temp);
				}
				else if (chartemp == 2) {
					manage_managegroup_face(temp);
				}
			}
		}
	}
	void pullgroup_face() {
		system("cls");
		message_lyh message(socket);
		string fid, gid, temp;
		cout << "�������ID��";
		cin >> fid;
		cout << "����ȺID��";
		cin >> gid;
		message.add_num(user->key);
		message.add_num(user->ID);
		message.add_num(fid);
		message.add_num(gid);
		message.add_end();
		message.send();
		message.recv();
		temp = message.str();
		if (temp[0] == 1) {
			cout << "�������" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "����" << endl;
			_getch();
			system("cls");
		}
	}
	void songroup_face() {
		system("cls");
		message_lyh message(socket);
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message.sign("\0\1\13");
		string fid, id, temp;
		cout << "���븸Ⱥ��ID��";
		cin >> fid;
		message.add_num(user->ID);
		message.add_num(fid);
		message.send();
		message.recv();
		if (message.str()[0] == 0) {
			cout << "����";
			message_lyh::recv0();
			message_lyh::send0();
			_getch();
			system("cls");
			return;
		}
		message.clear();
		cout << "�����û�ID��";
		cin >> id;
		message.add_num(id);
		while (1) {
			cout << "����0���  ����1����";
			cin >> temp;
			if (temp[0] == 0) {
				break;
			}
			cout << "�����û�ID��";
			cin >> id;
			message.add_num(id);
		}
		message.add_end();
		message.send();
		message.recv();
		if (message.str()[0] == 0) {
			cout << "���";
			_getch();
			system("cls");
			message_lyh::recv0();
			message_lyh::send0();
			return;
		}
		else {
			cout << "�����û����ڴ���" << endl;
			message.putout_num(2);
			message_lyh::recv0();
			message_lyh::send0();
			_getch();
			system("cls");
			return;
		}
	}
	void group_face() {
		char input;
		if (user->way == 1) {
			while (1) {
				system("cls");
				cout << "1���鿴Ⱥ��" << endl;
				cout << "2�����Ⱥ��" << endl;
				cout << "3���˳�Ⱥ��" << endl;
				cout << "4��Ⱥ������" << endl;
				cout << "5������Ⱥ��" << endl;
				cout << "6������Ⱥ��" << endl;
				cout << "7���Ƽ����Ѽ���Ⱥ��" << endl;
				cout << "8��������Ⱥ" << endl;
				cout << "0������" << endl;
				cin >> input;
				if (input == '0') {
					return;
				}
				else if (input == '1') {
					checkgroup_face();
				}
				else if (input == '2') {
					addgroup_face();
				}
				else if (input == '3') {
					deletegroup_face();
				}
				else if (input == '4') {
					chatgroup_face();
				}
				else if (input == '5') {
					managegroup_face();
				}
				else if (input == '6') {
					creatgroup_face();
				}
				else if (input == '7') {
					pullgroup_face();
				}
				else if (input == '8') {
					songroup_face();
				}
			}
		}
		else if (user->way == 2 || user->way == 3) {
			while (1) {
				system("cls");
				cout << "1���鿴Ⱥ��" << endl;
				cout << "2���˳�Ⱥ��" << endl;
				cout << "3��Ⱥ������" << endl;
				cout << "4������Ⱥ��" << endl;
				cout << "5������Ⱥ��" << endl;
				cout << "6���Ƽ����Ѽ���Ⱥ��" << endl;
				cout << "0������" << endl;
				cin >> input;
				if (input == '0') {
					return;
				}
				else if (input == '1') {
					checkgroup_face();
				}
				else if (input == '2') {
					deletegroup_face();
				}
				else if (input == '3') {
					chatgroup_face();
				}
				else if (input == '4') {
					managegroup_face();
				}
				else if (input == '5') {
					creatgroup_face();
				}
				else if (input == '6') {
					pullgroup_face();
				}
			}
		}
	}
	/// //////////////��Ϊ����
	void name_dataset_face() {
		message_lyh message(socket);
		string newname;
		while (1) {
			cout << "�������ǳƣ�";
			cin >> newname;
			if (newname.size() > 20) {
				cout << "���ƹ��������20�ַ�" << endl;
			}
			else {
				message.sign("\0\0\1");
				message.add_num(newname);
				message.add_end();
				message.send();
				user->name = newname;
				cout << "�޸����";
				_getch();
				system("cls");
			}
		}
	}
	void birth_dataset_face() {
		message_lyh message(socket);
		string newbirth;
		while (1) {
			cout << "�������ǳƣ�";
			cin >> newbirth;
			if (newbirth.size() > 20) {
				cout << "���ƹ��������20�ַ�" << endl;
			}
			else {
				message.sign("\0\0\2");
				message.add_num(newbirth);
				message.add_end();
				message.send();
				user->birth = newbirth;
				cout << "�޸����";
				_getch();
				system("cls");
			}
		}
	}
	void place_dataset_face() {
		message_lyh message(socket);
		string newplace;
		while (1) {
			cout << "�������ǳƣ�";
			cin >> newplace;
			if (newplace.size() > 20) {
				cout << "���ƹ��������20�ַ�" << endl;
			}
			else {
				message.sign("\0\0\3");
				message.add_num(newplace);
				message.add_end();
				message.send();
				user->place = newplace;
				cout << "�޸����";
				_getch();
				system("cls");
			}
		}
	}
	void dataset_face() {
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message_lyh message(socket);
		message.sign("\0\2\1");
		int temp;
		if (user->way == 1) {
			cout << "���QQ�˺�" << endl;
			cout << "ID��" << user->ID<<endl;
			cout << "�ǳƣ�" << user->name << endl;
			cout << "���գ�" << user->birth << endl;
			cout << "Q�䣺" << user->useage << endl;
			cout << "���ڵ�����" << user->place << endl;
			while (1) {
				cout << endl;
				cout << "1���޸��ǳ�" << endl;
				cout << "2���޸�����" << endl;
				cout << "3���޸ĵ���" << endl;
				cout << "0������" << endl;
				cin >> temp;
				if (temp == 0) {
					message_lyh::recv0();
					message_lyh::send0();
					return;
				}
				else if (temp == 1) {
					name_dataset_face();
				}
				else if (temp == 2) {
					birth_dataset_face();
				}
				else if (temp == 3) {
					place_dataset_face();
				}
				else {}
			}
		}
	}
	void bindset_face() {
		message_lyh::waitboth();
		message_lyh::recv1();
		message_lyh::send1();
		message_lyh message(socket);
		message.sign("\0\2\2");
		string str;
		message.recv();
		cout << "��İ��˻��У�" << endl;
		message.putout_num(2);
		while (1) {
			if (user->way != 1) {
				cout << "1����QQ" << endl;
			}
			if (user->way != 2) {
				cout << "2����΢��" << endl;
			}
			if (user->way != 3) {
				cout << "3����΢��" << endl;
			}
			cout << "0���˳�";
			cin >> str;
			message.clear();
			if (str[0] == '1') { message.sign("\0\0\1"); }
			else if (str[0] == '2') { message.sign("\0\0\2"); }
			else if (str[0] == '3') { message.sign("\0\0\3"); }
			else if (str[0] == '0') {
				message_lyh::recv0();
				message_lyh::send0();
				_getch();
				system("cls");
				return;
			}
			else { 
				continue; 
			}
			message.add_num(user->ID);
			message.add_num(user->key);
			cout << "�����˺ţ�";
			cin >> str;
			message.add_num(str);
			cout << "�������룺";
			cin >> str;
			message.add_num(str);
			message.send();
			message.recv();
			str = message.str();
			if (str[0] == 1) {
				cout << "�󶨳ɹ�";
				_getch();
				system("cls");
			}
			else {
				cout << "����ʧ��";
				_getch();
				system("cls");
			}
		}
	}
	void delset_face() {
		string str;
		cout << "���롰ȷ������ע���˺ţ�";
		cin >> str;
		if (str == "ȷ��") {
			message_lyh message(socket);
			message_lyh::waitboth();
			message_lyh::recv1();
			message_lyh::send1();
			message.sign("\0\2\3");
			message.add_num(user->ID);
			message.add_num(user->key);
			message.recv();
			str = message.str();
			if (str[0] == 1) {
				cout << "ע���ɹ�";
				_getch();
				exit(0);
			}
			else {
				cout << "ע��ʧ��";
				_getch();
				system("cls");
				message_lyh::recv0();
				message_lyh::send0();
				return;
			}
		}
	}
	void set_face() {
		char input;
		while (1) {
			system("cls");
			cout << "1�����Ļ�����Ϣ" << endl;
			cout << "2�����˻�" << endl;
			cout << "3��ע���˻�" << endl;
			cout << "0������" << endl;
			cin >> input;
			if (input == '0') {
				return ;
			}
			if (input == '1') {
				dataset_face();
			}
			else if (input == '2') {
				bindset_face();
			}
			else if (input == '3') {
				delset_face();
			}
		}
	}
};
