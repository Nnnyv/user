#pragma once
#include"face.h"
/////////////����Ϊfriend����//////////////////////////////
//���ID  �ǳ�\n
class face_lyh {
public:
	face_lyh(SOCKET Socket, user_lyh* Use) :socket(Socket), user(Use) {}
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
	void checkfriend_face() {
		char receive[128];
		message_lyh temp;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\0\1", 3, 0);
		temp.recv(socket);
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
		RECVING = 0;
		SENDING = 0;
		_getch();
	}
	void addfriend_face() {
		string newid;
		int check = 0;
		system("cls");
		cout << "ID��";
		cin >> newid;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		check += send(socket, "\0\0\2", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		if (check > 0) {
			cout << "���ʧ��" << endl;
		}
		else {
			cout << "�ѷ�������" << endl;
		}
		RECVING = 0;
		SENDING = 0;
		_getch();
	}
	void deletefriend_face() {
		string newid;
		int check = 0;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		system("cls");
		cout << "ID��";
		cin >> newid;
		check += send(socket, "\0\0\3", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		if (check > 0) {
			cout << "ɾ��ʧ��" << endl;
		}
		else {
			cout << "��ɾ����" << newid << endl;
			//use->del_friend(newid);
		}
		RECVING = 0;
		SENDING = 0;
		_getch();
	}
	//δ���
	void datamore_chatfriend_face() {

	}//δ���//δ���
	void send_chatfriend_face() {

		string tt;
		int temp = 0;
		while (waitsending() == 0);
		SENDING = 1;
		cout << "������:";
		send(socket, "\0\0\5", 3, 0);
		cin >> tt;
		message_lyh tempm(tt);
		tempm.send(socket);
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
		SENDING = 0;
	}
	void chatfriend_face() {
		system("cls");
		string id;
		char iff;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		cout << "ѡ����ѣ�";
		cin >> id;
		send(socket, "\0\0\4", 3, 0);
		send(socket, id.c_str(), 7, 0);
		recv(socket, &iff, 1, 0);//����1���Ǻ��ѣ����Խ�����һ��
		RECVING = 0;
		SENDING = 0;
		if (iff != 1) {
			cout << "��������ĺ���" << endl;
			_getch();
			return;
		}
		while (1) {
			cout << "1���鿴��100����Ϣ" << endl;
			cout << "2��������Ϣ" << endl;
			cout << "3���˳�" << endl;
			cin >> iff;
			if (iff == 1) {
				datamore_chatfriend_face();//�����ݿ��ڶ���һ�ܵ�������Ϣ
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
		message_lyh temp;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\1", 3, 0);
		temp.recv(socket);
		RECVING = 0;
		SENDING = 0;
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
		int check = 0;
		system("cls");
		cout << "ID��";
		cin >> newid;
		while (waitsending() == 0);
		SENDING = 1;
		check += send(socket, "\0\1\2", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		SENDING = 0;
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
		system("cls");
		cout << "ID��";
		cin >> newid;
		while (waitsending() == 0);
		SENDING = 1;
		check += send(socket, "\0\1\3", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		SENDING = 0;
		if (check > 0) {
			cout << "�˳�Ⱥ��ʧ��" << endl;
		}
		else {
			cout << "���˳�Ⱥ�ģ�" << newid << endl;
			//use->del_friend(newid);
		}
		while (waitrecving() == 0);
		_getch();
	}
	//δ���
	void datamore_chatfriend_face() {

	}
	void send_chatgroup_face() {
		string tt;
		//char putout[128];
		int temp = 0;
		cout << "������:";
		while (waitsending() == 0);
		SENDING = 1;
		send(socket, "\0\1\5", 3, 0);
		cin >> tt;
		message_lyh tempm(tt);
		tempm.send(socket);
		SENDING = 0;
	}
	void chatgroup_face() {
		system("cls");
		string id;
		char iff;
		cout << "ѡ��Ⱥ�ģ�";
		cin >> id;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\4", 3, 0);
		send(socket, id.c_str(), 7, 0);
		recv(socket, &iff, 1, 0);//����1���Ǻ��ѣ����Խ�����һ��
		RECVING = 0;
		SENDING = 0;
		if (iff != 1) {
			cout << "δ�����Ⱥ��" << endl;
			_getch();
			return;
		}
		//�����ݿ��ڶ���һ�ܵ�������Ϣ
		while (1) {
			cout << "1���鿴һ��ǰ������" << endl;
			cout << "2��������Ϣ" << endl;
			cout << "3���˳�" << endl;
			cin >> iff;
			if (iff == 1) {
				datamore_chatfriend_face();//�����ݿ��ڶ���һ�ܵ�������Ϣ
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\7", 3, 0);
		message_lyh message;
		string newid;
		char temp;
		cout << "�¹���ԱID��";
		cin >> newid;
		message.add_num(use->key);//ԭʼ����
		message.add_num(id);//Ⱥid
		message.add_num(newid);//�¹���Աid
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\010", 3, 0);
		message_lyh message;
		string newid;
		char temp;
		cout << "��Ҫɾ���Ĺ���ԱID��";
		cin >> newid;
		message.add_num(use->key);//ԭʼ����
		message.add_num(id);//Ⱥid
		message.add_num(newid);//����Աid
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\000\001\011", 3, 0);
		message_lyh message;
		string newid;
		char temp;
		cout << "ID��";
		cin >> newid;
		message.add_num(use->key);//ԭʼ����
		message.add_num(use->ID);//�û�id
		message.add_num(id);//Ⱥid
		message.add_num(newid);//����Աid
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\10", 3, 0);
		string put, put1;
		char iff;
		message_lyh message;
		message.add_num(use->key);
		message.add_num(use->ID);
		message.add_num(id);
		message.add_end();
		message.send(socket);
		recv(socket, &iff, 1, 0);
		if (iff == 0) {
			cout << "����";
			_getch();
			system("cls");
		}
		message.recv(socket);
		message.putout_num(3);//������д    name id pname
		cout << endl;
		while (1) {
			cout << "����0���أ�����1����:";
			cin >> iff;
			if (iff == 0) {
				system("cls");
				RECVING = 0;
				SENDING = 0;
				return;
			}
			cout << "ѡ��ID��";
			cin >> put;
			cout << "����1ͬ��  ����0�ܾ�";
			cin >> put1;
			message.add_num(use->key);
			message.add_num(use->ID);
			message.add_num(id);
			message.add_num(put);
			message.add_num(put1);
			message.add_end();
			message.send(socket);
			message.recv(socket);
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\12", 3, 0);
		message_lyh message;
		string newid;
		char temp;
		cout << "�����ƣ�";
		cin >> newid;
		while (waitrecving() == 0);
		RECVING = 1;
		message.add_num(use->key);//ԭʼ����
		message.add_num(use->ID);//�û�id
		message.add_num(id);//Ⱥid
		message.add_num(newid);//������
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\12", 3, 0);
		message_lyh message;
		string newid;
		char temp;
		cout << "1����ͨȺ" << endl;
		cout << "2������Ⱥ" << endl;
		cout << "3����УȺ" << endl;
		cout << "�����ͣ�";
		cin >> newid;
		message.add_num(use->key);//ԭʼ����
		message.add_num(use->ID);//�û�id
		message.add_num(id);//Ⱥid
		message.add_num(newid);//������
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
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
		if (use->way == 1) {
			message_lyh message;
			message.recv(socket);
			cout << "Ⱥ��Ա��:" << endl;
			message.putout_num(2);
			message.recv(socket);
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
		else if (use->way == 2 || use->way == 3) {
			message_lyh message;
			message.recv(socket);
			cout << "Ⱥ��Ա��:" << endl;
			message.putout_num(2);
			message.recv(socket);
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
		if (use->way == 1) {
			message_lyh message;
			message.recv(socket);
			cout << "Ⱥ��Ա��:" << endl;
			message.putout_num(2);
			message.recv(socket);
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
		else if (use->way == 2 || use->way == 3) {
			return;
		}
	}//////////////////////////////////////////////////////////δ���
	void creatgroup_face() {
		message_lyh message;
		string id, name;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\11", 3, 0);
		system("cls");
		cout << "Ⱥ�����ƣ�";
		cin >> name;
		message.add_num(name);
		message.add_end();
		message.send(socket);
		message.recv(socket);
		id = message.str();
		cout << "���ȺIDΪ:" << id;
		RECVING = 0;
		SENDING = 0;
		_getch();
		system("cls");
	}

	void managegroup_face() {
		message_lyh message;
		string temp;
		char chartemp;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\6", 3, 0);
		message.recv(socket);
		message.putout_num(2);
		while (1) {
			cout << "ѡ��Ⱥ�Ļ�0����";
			cin >> temp;
			if (temp.size() == 1 && temp[0] == 1) {
				RECVING = 0;
				SENDING = 0;
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
		message_lyh message;
		string fid, gid, temp;
		cout << "�������ID��";
		cin >> fid;
		cout << "����ȺID��";
		cin >> gid;
		message.add_num(use->key);
		message.add_num(use->ID);
		message.add_num(fid);
		message.add_num(gid);
		message.add_end();
		message.send(socket);
		message.recv(socket);
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\13", 3, 0);
		string fid, id, temp;
		message_lyh message;
		cout << "���븸Ⱥ��ID��";
		cin >> fid;
		message.add_num(use->ID);
		message.add_num(fid);
		message.send(socket);
		message.recv(socket);
		if (message.str()[0] == 0) {
			cout << "����";
			RECVING = 0;
			SENDING = 0;
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
		message.send(socket);
		message.recv(socket);
		if (message.str()[0] == 0) {
			cout << "���";
			_getch();
			system("cls");
			RECVING = 0;
			SENDING = 0;
			return;
		}
		else {
			cout << "�����û����ڴ���" << endl;
			message.putout_num(2);
			RECVING = 0;
			SENDING = 0;
			_getch();
			system("cls");
			return;
		}
	}
	void group_face() {
		char input;
		if (use->way == 1) {
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
		else if (use->way == 2 || use->way == 3) {
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
		message_lyh message;
		string newname;
		while (1) {
			cout << "�������ǳƣ�";
			cin >> newname;
			if (newname.size() > 20) {
				cout << "���ƹ��������20�ַ�" << endl;
			}
			else {
				send(socket, "\1", 1, 0);
				message.add_num(newname);
				message.add_end();
				message.send(socket);
				use->name = newname;
				cout << "�޸����";
				_getch();
				system("cls");
			}
		}
	}
	void birth_dataset_face() {
		message_lyh message;
		string newbirth;
		while (1) {
			cout << "�������ǳƣ�";
			cin >> newbirth;
			if (newbirth.size() > 20) {
				cout << "���ƹ��������20�ַ�" << endl;
			}
			else {
				send(socket, "\2", 1, 0);
				message.add_num(newbirth);
				message.add_end();
				message.send(socket);
				use->birth = newbirth;
				cout << "�޸����";
				_getch();
				system("cls");
			}
		}
	}
	void place_dataset_face() {
		message_lyh message;
		string newplace;
		while (1) {
			cout << "�������ǳƣ�";
			cin >> newplace;
			if (newplace.size() > 20) {
				cout << "���ƹ��������20�ַ�" << endl;
			}
			else {
				send(socket, "\3", 1, 0);
				message.add_num(newplace);
				message.add_end();
				message.send(socket);
				use->place = newplace;
				cout << "�޸����";
				_getch();
				system("cls");
			}
		}
	}
	void dataset_face() {
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\2\1", 3, 0);
		int temp;
		if (use->way == 1) {
			cout << "���QQ�˺�" << endl;
			cout << "ID��" << use->ID<<endl;
			cout << "�ǳƣ�" << use->name << endl;
			cout << "���գ�" << use->birth << endl;
			cout << "Q�䣺" << use->useage << endl;
			cout << "���ڵ�����" << use->place << endl;
			while (1) {
				cout << endl;
				cout << "1���޸��ǳ�" << endl;
				cout << "2���޸�����" << endl;
				cout << "3���޸ĵ���" << endl;
				cout << "0������" << endl;
				cin >> temp;
				if (temp == 0) {
					RECVING = 0;
					SENDING = 0;
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
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\2\2", 3, 0);
		message_lyh message;
		string str;
		message.recv(socket);
		cout << "��İ��˻��У�" << endl;
		message.putout_num(2);
		while (1) {
			if (use->way != 1) {
				cout << "1����QQ" << endl;
			}
			if (use->way != 2) {
				cout << "2����΢��" << endl;
			}
			if (use->way != 3) {
				cout << "3����΢��" << endl;
			}
			cout << "0���˳�";
			cin >> str;
			message.clear();
			if (str[0] == '1') { send(socket, "\1", 1, 0); }
			else if(str[0] == '2') { send(socket, "\2", 1, 0); }
			else if (str[0] == '3') { send(socket, "\3", 1, 0); }
			else if (str[0] == '0') {
				RECVING = 0;
				SENDING = 0;
				_getch();
				system("cls");
				return;
			}
			else { 
				continue; 
			}
			message.add_num(use->ID);
			message.add_num(use->key);
			cout << "�����˺ţ�";
			cin >> str;
			message.add_num(str);
			cout << "�������룺";
			cin >> str;
			message.add_num(str);
			message.send(socket);
			recv(socket, &str[0], 1, 0);
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
			message_lyh message;
			while (waitboth() == 0);
			RECVING = 1;
			SENDING = 1;
			send(socket, "\0\2\3", 3, 0);
			message.add_num(use->ID);
			message.add_num(use->key);
			recv(socket, &str[0], 1, 0);
			if (str[0] == 1) {
				cout << "ע���ɹ�";
				_getch();
				exit(0);
			}
			else {
				cout << "ע��ʧ��";
				_getch();
				system("cls");
				RECVING = 0;
				SENDING = 0;
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
