#pragma once
#include"face.h"
/////////////以下为friend界面//////////////////////////////
//输出ID  昵称\n
class face_lyh {
public:
	face_lyh(SOCKET Socket, user_lyh* Use) :socket(Socket), user(Use) {}
	void start() {
		char input;
		while (1) {
			system("cls");
			cout << "1：好友" << endl;
			cout << "2：群组" << endl;
			cout << "3：设置" << endl;
			cout << "4：退出" << endl;
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
		cout << "ID：";
		cin >> newid;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		check += send(socket, "\0\0\2", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		if (check > 0) {
			cout << "添加失败" << endl;
		}
		else {
			cout << "已发送请求" << endl;
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
		cout << "ID：";
		cin >> newid;
		check += send(socket, "\0\0\3", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		if (check > 0) {
			cout << "删除失败" << endl;
		}
		else {
			cout << "已删除：" << newid << endl;
			//use->del_friend(newid);
		}
		RECVING = 0;
		SENDING = 0;
		_getch();
	}
	//未完成
	void datamore_chatfriend_face() {

	}//未完成//未完成
	void send_chatfriend_face() {

		string tt;
		int temp = 0;
		while (waitsending() == 0);
		SENDING = 1;
		cout << "请输入:";
		send(socket, "\0\0\5", 3, 0);
		cin >> tt;
		message_lyh tempm(tt);
		tempm.send(socket);
		//while (1) {
		//	if (temp + 126 >= tt.size()) {
		//		tt.copy(putout, tt.size() - temp, temp);
		//		putout[tt.size() - temp] = '\0';
		//		putout[127] = '\0';//127位为0，则已结束
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
		cout << "选择好友：";
		cin >> id;
		send(socket, "\0\0\4", 3, 0);
		send(socket, id.c_str(), 7, 0);
		recv(socket, &iff, 1, 0);//返回1则是好友，可以进行下一步
		RECVING = 0;
		SENDING = 0;
		if (iff != 1) {
			cout << "他不是你的好友" << endl;
			_getch();
			return;
		}
		while (1) {
			cout << "1：查看近100条消息" << endl;
			cout << "2：发送信息" << endl;
			cout << "3：退出" << endl;
			cin >> iff;
			if (iff == 1) {
				datamore_chatfriend_face();//从数据库内读出一周的聊天信息
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
			cout << "1：查看好友" << endl;
			cout << "2：添加好友" << endl;
			cout << "3：删除好友" << endl;
			cout << "4：好友聊天" << endl;
			cout << "5：返回" << endl;
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
	//////////////以下为group界面///////////////////////////////////////
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
		cout << "ID：";
		cin >> newid;
		while (waitsending() == 0);
		SENDING = 1;
		check += send(socket, "\0\1\2", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		SENDING = 0;
		if (check > 0) {
			cout << "添加失败" << endl;
		}
		else {
			cout << "已发送请求" << endl;
		}
		_getch();
	}
	void deletegroup_face() {
		string newid;
		int check = 0;
		system("cls");
		cout << "ID：";
		cin >> newid;
		while (waitsending() == 0);
		SENDING = 1;
		check += send(socket, "\0\1\3", 3, 0);
		check += send(socket, newid.c_str(), 7, 0);
		SENDING = 0;
		if (check > 0) {
			cout << "退出群聊失败" << endl;
		}
		else {
			cout << "已退出群聊：" << newid << endl;
			//use->del_friend(newid);
		}
		while (waitrecving() == 0);
		_getch();
	}
	//未完成
	void datamore_chatfriend_face() {

	}
	void send_chatgroup_face() {
		string tt;
		//char putout[128];
		int temp = 0;
		cout << "请输入:";
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
		cout << "选择群聊：";
		cin >> id;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\4", 3, 0);
		send(socket, id.c_str(), 7, 0);
		recv(socket, &iff, 1, 0);//返回1则是好友，可以进行下一步
		RECVING = 0;
		SENDING = 0;
		if (iff != 1) {
			cout << "未加入此群聊" << endl;
			_getch();
			return;
		}
		//从数据库内读出一周的聊天信息
		while (1) {
			cout << "1：查看一周前的内容" << endl;
			cout << "2：发送信息" << endl;
			cout << "3：退出" << endl;
			cin >> iff;
			if (iff == 1) {
				datamore_chatfriend_face();//从数据库内读出一周的聊天信息
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
		cout << "新管理员ID：";
		cin >> newid;
		message.add_num(use->key);//原始密码
		message.add_num(id);//群id
		message.add_num(newid);//新管理员id
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
		if (temp == 1) {
			cout << "操作完成" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "错误" << endl;
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
		cout << "将要删除的管理员ID：";
		cin >> newid;
		message.add_num(use->key);//原始密码
		message.add_num(id);//群id
		message.add_num(newid);//管理员id
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
		if (temp == 1) {
			cout << "操作完成" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "错误" << endl;
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
		cout << "ID：";
		cin >> newid;
		message.add_num(use->key);//原始密码
		message.add_num(use->ID);//用户id
		message.add_num(id);//群id
		message.add_num(newid);//管理员id
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
		if (temp == 1) {
			cout << "操作完成" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "错误" << endl;
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
			cout << "错误";
			_getch();
			system("cls");
		}
		message.recv(socket);
		message.putout_num(3);//变量待写    name id pname
		cout << endl;
		while (1) {
			cout << "输入0返回，输入1继续:";
			cin >> iff;
			if (iff == 0) {
				system("cls");
				RECVING = 0;
				SENDING = 0;
				return;
			}
			cout << "选择ID：";
			cin >> put;
			cout << "输入1同意  输入0拒绝";
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
				cout << "完成" << endl;
			}
			else {
				cout << "错误" << endl;
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
		cout << "新名称：";
		cin >> newid;
		while (waitrecving() == 0);
		RECVING = 1;
		message.add_num(use->key);//原始密码
		message.add_num(use->ID);//用户id
		message.add_num(id);//群id
		message.add_num(newid);//新名称
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
		if (temp == 1) {
			cout << "操作完成" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "错误" << endl;
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
		cout << "1：普通群" << endl;
		cout << "2：工作群" << endl;
		cout << "3：家校群" << endl;
		cout << "新类型：";
		cin >> newid;
		message.add_num(use->key);//原始密码
		message.add_num(use->ID);//用户id
		message.add_num(id);//群id
		message.add_num(newid);//新类型
		message.add_end();
		message.send(socket);
		recv(socket, &temp, 1, 0);
		RECVING = 0;
		SENDING = 0;
		if (temp == 1) {
			cout << "操作完成" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "错误" << endl;
			_getch();
			system("cls");
		}
	}
	void leader_managegroup_face(string id) {
		char iff;
		if (use->way == 1) {
			message_lyh message;
			message.recv(socket);
			cout << "群成员有:" << endl;
			message.putout_num(2);
			message.recv(socket);
			cout << "管理员有:" << endl;
			message.putout_num(2);
			while (1) {
				cout << "1：任用新的管理员" << endl;
				cout << "2：取消管理权限" << endl;
				cout << "3：将成员踢出群聊" << endl;
				cout << "4：审核入群申请" << endl;
				cout << "5：更改群聊名称" << endl;
				cout << "6：更改群聊类型" << endl;
				cout << "0：返回" << endl;
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
			cout << "群成员有:" << endl;
			message.putout_num(2);
			message.recv(socket);
			cout << "1：将成员踢出群聊" << endl;
			cout << "2：查看入群申请" << endl;
			cout << "3：更改群聊名称" << endl;
			cout << "0：返回" << endl;
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
			cout << "群成员有:" << endl;
			message.putout_num(2);
			message.recv(socket);
			cout << "管理员有:" << endl;
			message.putout_num(2);
			while (1) {
				cout << "1：将成员踢出群聊" << endl;
				cout << "2：审核入群申请" << endl;
				cout << "3：更改群聊名称" << endl;
				cout << "0：返回" << endl;
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
	}//////////////////////////////////////////////////////////未完成
	void creatgroup_face() {
		message_lyh message;
		string id, name;
		while (waitboth() == 0);
		RECVING = 1;
		SENDING = 1;
		send(socket, "\0\1\11", 3, 0);
		system("cls");
		cout << "群聊名称：";
		cin >> name;
		message.add_num(name);
		message.add_end();
		message.send(socket);
		message.recv(socket);
		id = message.str();
		cout << "你的群ID为:" << id;
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
			cout << "选择群聊或按0返回";
			cin >> temp;
			if (temp.size() == 1 && temp[0] == 1) {
				RECVING = 0;
				SENDING = 0;
				return;  
			}
			else if (temp.size() != 6) {
				cout << "id错误" << endl;
				_getch();
				system("cls");
			}
			else {
				send(socket, temp.c_str(), 6, 0);
				recv(socket, &chartemp, 1, 0);//0无权限 1是群主 2是管理
				if (chartemp == 0) {
					cout << "id错误:";
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
		cout << "输入好友ID：";
		cin >> fid;
		cout << "输入群ID：";
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
			cout << "邀请完成" << endl;
			_getch();
			system("cls");
		}
		else {
			cout << "错误" << endl;
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
		cout << "输入父群聊ID：";
		cin >> fid;
		message.add_num(use->ID);
		message.add_num(fid);
		message.send(socket);
		message.recv(socket);
		if (message.str()[0] == 0) {
			cout << "错误";
			RECVING = 0;
			SENDING = 0;
			_getch();
			system("cls");
			return;
		}
		message.clear();
		cout << "输入用户ID：";
		cin >> id;
		message.add_num(id);
		while (1) {
			cout << "输入0完成  输入1继续";
			cin >> temp;
			if (temp[0] == 0) {
				break;
			}
			cout << "输入用户ID：";
			cin >> id;
			message.add_num(id);
		}
		message.add_end();
		message.send(socket);
		message.recv(socket);
		if (message.str()[0] == 0) {
			cout << "完成";
			_getch();
			system("cls");
			RECVING = 0;
			SENDING = 0;
			return;
		}
		else {
			cout << "以下用户存在错误" << endl;
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
				cout << "1：查看群聊" << endl;
				cout << "2：添加群聊" << endl;
				cout << "3：退出群聊" << endl;
				cout << "4：群聊聊天" << endl;
				cout << "5：管理群聊" << endl;
				cout << "6：创建群聊" << endl;
				cout << "7：推荐好友加入群聊" << endl;
				cout << "8：创建子群" << endl;
				cout << "0：返回" << endl;
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
				cout << "1：查看群聊" << endl;
				cout << "2：退出群聊" << endl;
				cout << "3：群聊聊天" << endl;
				cout << "4：管理群聊" << endl;
				cout << "5：创建群聊" << endl;
				cout << "6：推荐好友加入群聊" << endl;
				cout << "0：返回" << endl;
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
	/// //////////////下为设置
	void name_dataset_face() {
		message_lyh message;
		string newname;
		while (1) {
			cout << "输入新昵称：";
			cin >> newname;
			if (newname.size() > 20) {
				cout << "名称过长，最多20字符" << endl;
			}
			else {
				send(socket, "\1", 1, 0);
				message.add_num(newname);
				message.add_end();
				message.send(socket);
				use->name = newname;
				cout << "修改完成";
				_getch();
				system("cls");
			}
		}
	}
	void birth_dataset_face() {
		message_lyh message;
		string newbirth;
		while (1) {
			cout << "输入新昵称：";
			cin >> newbirth;
			if (newbirth.size() > 20) {
				cout << "名称过长，最多20字符" << endl;
			}
			else {
				send(socket, "\2", 1, 0);
				message.add_num(newbirth);
				message.add_end();
				message.send(socket);
				use->birth = newbirth;
				cout << "修改完成";
				_getch();
				system("cls");
			}
		}
	}
	void place_dataset_face() {
		message_lyh message;
		string newplace;
		while (1) {
			cout << "输入新昵称：";
			cin >> newplace;
			if (newplace.size() > 20) {
				cout << "名称过长，最多20字符" << endl;
			}
			else {
				send(socket, "\3", 1, 0);
				message.add_num(newplace);
				message.add_end();
				message.send(socket);
				use->place = newplace;
				cout << "修改完成";
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
			cout << "你的QQ账号" << endl;
			cout << "ID：" << use->ID<<endl;
			cout << "昵称：" << use->name << endl;
			cout << "生日：" << use->birth << endl;
			cout << "Q龄：" << use->useage << endl;
			cout << "所在地区：" << use->place << endl;
			while (1) {
				cout << endl;
				cout << "1：修改昵称" << endl;
				cout << "2：修改生日" << endl;
				cout << "3：修改地区" << endl;
				cout << "0：返回" << endl;
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
		cout << "你的绑定账户有：" << endl;
		message.putout_num(2);
		while (1) {
			if (use->way != 1) {
				cout << "1：绑定QQ" << endl;
			}
			if (use->way != 2) {
				cout << "2：绑定微博" << endl;
			}
			if (use->way != 3) {
				cout << "3：绑定微信" << endl;
			}
			cout << "0：退出";
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
			cout << "输入账号：";
			cin >> str;
			message.add_num(str);
			cout << "输入密码：";
			cin >> str;
			message.add_num(str);
			message.send(socket);
			recv(socket, &str[0], 1, 0);
			if (str[0] == 1) {
				cout << "绑定成功";
				_getch();
				system("cls");
			}
			else {
				cout << "更改失败";
				_getch();
				system("cls");
			}
		}
	}
	void delset_face() {
		string str;
		cout << "输入“确定”以注销账号：";
		cin >> str;
		if (str == "确定") {
			message_lyh message;
			while (waitboth() == 0);
			RECVING = 1;
			SENDING = 1;
			send(socket, "\0\2\3", 3, 0);
			message.add_num(use->ID);
			message.add_num(use->key);
			recv(socket, &str[0], 1, 0);
			if (str[0] == 1) {
				cout << "注销成功";
				_getch();
				exit(0);
			}
			else {
				cout << "注销失败";
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
			cout << "1：更改基本信息" << endl;
			cout << "2：绑定账户" << endl;
			cout << "3：注销账户" << endl;
			cout << "0：返回" << endl;
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
