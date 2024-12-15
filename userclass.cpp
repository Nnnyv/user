#pragma once
#include"userclass.h"
using namespace std;
//class bind_lyh;
class user_lyh;
//class group_lyh;
//class toget_in_lyh;
class specific_lyh;
//string类的skip表
//struct skipstring_lyh {
//	skipstring_lyh(string d) { data = d; }
//	string data;
//	skipstring_lyh* next[SKIPMAX] = { 0 };
//};
class user_lyh {
public:
	user_lyh(){}
	virtual ~user_lyh() {}

	
	int way;//1:qq,2:webo,3:wechat
	string ID;//6位
	string name;//最多20位
	string birth;//8位
	string useage;//8位
	string place; //最多40位
	string key;
};
class qq_lyh :public user_lyh {
public:
	qq_lyh() :user_lyh() {
		way = 1;
	}
	~qq_lyh() {}
protected:
	

};
class webo_lyh :public user_lyh {
public:
	webo_lyh() :user_lyh() {
		way = 2;
	}
protected:

};
class wechat_lyh :public user_lyh {
public:
	wechat_lyh() :user_lyh() {
		way = 3;
	}
	~wechat_lyh() {}
protected:

};
//bind类，一起绑定的账户共同指向一个bind类.添加 1：qq 2：wechat////////////////////////////////////////////
//class bind_lyh {
//public:
//	bind_lyh() {};
//	~bind_lyh() {};
//	//第一个string为要添加的账号，第二个为密码;return -1 未找到，0 密码错误， 1 成功
//	int add(string, string, int);
//	//int为选择
//	void del(int);
//	//0为空
//	int num();
//protected:
//	int number = 0;
//	string qq = "0";
//	string wechat = "0";
//};
////group类，group为基类，////////////////////////////////////////////
////群主类，用户储存群主类链表
////等待入群
//class leader_lyh {
//public:
//	leader_lyh(group_lyh* gg, leader_lyh*& nn) : group(gg) {
//		next = nn;
//		nn = this;
//	}
//	void check(int i) { group->check(i); }
//	int set_name(string na) { group->set_name(na); };
//	void add(string id) { group->add(id); };
//	void kick(string id) { group->kick(id); };
//	virtual void del() { group->del(); };
//	virtual void addm(string id) { group->addm(id); };
//	virtual void delm(string id) { group->delm(id); };
//protected:
//	group_lyh* const group;
//	leader_lyh* next;
//};
//class manage_lyh :public leader_lyh {
//public:
//	manage_lyh(group_lyh* gg, leader_lyh*& nn) :leader_lyh(gg, nn) {}
//	virtual void addm(string a) {}
//	virtual void delm(string a) {}
//	virtual void del() {}
//};
//class specific_lyh {
//public:
//	virtual void work1(vector<string>);
//	virtual void work2();
//protected:
//};
//class specific_normal_lyh :public specific_lyh {
//public:
//	virtual void work1(vector<string>);
//	virtual void work2();
//protected:
//
//};
//class specific_work_lyh :public specific_lyh {
//public:
//	virtual void work1(vector<string>);
//	virtual void work2();
//protected:
//
//};
//class group_lyh {
//public:
//	friend leader_lyh;
//	group_lyh(string id) :ID(id) {};
//	virtual ~group_lyh();
//	virtual user_lyh* findm(string);
//	virtual user_lyh* find(string);
//	virtual int join(string);
//protected:
//	virtual void check(int iff);
//	virtual void del();
//	virtual void set_name(string na) ;
//	virtual void add(string);
//	virtual void kick(string);
//	virtual void addm(string newone) {};
//	virtual void delm(string delee) {};
//	const string ID;
//	string name;
//	skipstring_lyh* everyone;
//	int everyone_level = 1;
//	int everyone_num;
//	string leader;
//};
//class qqgroup_lyh :public group_lyh {
//public:
//	qqgroup_lyh(string id) :group_lyh(id) {}
//	~qqgroup_lyh() {
//
//	}
//	virtual void addm(string newone) {}
//	virtual void delm(string delone) {}
//protected:
//	string manager[8] = { 0 };
//	int managernum;
//	int specific_type;
//	specific_lyh* specific;
//};
//////////////////////////////////////////////以下为函数实现///////////////////////////////////////////////////////////
//skipstring_lyh* BuildUpdate(skipstring_lyh* head, int level, string K, skipstring_lyh* update[]) {
//	//在表中查找K并构建update表
//	skipstring_lyh* p = head;
//	for (int i = level - 1; i >= 0; i--) {
//		while (p->next[i] != NULL && p->next[i]->data < K)
//			p = p->next[i];
//		update[i] = p;
//	}
//	p = p->next[0];
//	if (p != NULL && p->data == K)
//		return p;
//	return NULL;
//}
//int random_level() {
//	//以1/2概率向上生长，确定向上插入多少层
//	int newlevel = 1;
//	while (rand() % 2 == 0 && newlevel < SKIPMAX)
//		newlevel++;
//	return newlevel;
//}
////以下为store类
//void user_lyh::set_name(string a) {
//	name = a;
//}
//void user_lyh::set_birth(string a) {
//	birth = a;
//}
//void user_lyh::set_place(string a) {
//	place = a;
//}
//void user_lyh::upload(string a) {
//
//}
//void user_lyh::add_friend(string a) {
//	skipstring_lyh* update[SKIPMAX] = { 0 };
//	skipstring_lyh* p = BuildUpdate(friends, friend_level, a, update); //在表中查找并构建update表
//	if (p != NULL) return; //已有， 无需重复插入
//	int newlevel = random_level(); //确定向上插几层
//	if (newlevel > friend_level) { //比原来层数还高，更新level和update值
//		for (int i = friend_level; i < newlevel; i++)
//			update[i] = friends;
//		friend_level = newlevel;
//	}
//	p = new skipstring_lyh(a); //创建新结点
//	for (int i = 0; i < newlevel; i++) { //自下而上逐层插入结点
//		p->next[i] = update[i]->next[i];
//		update[i]->next[i] = p;
//	}
//	friend_num++;
//}
//void user_lyh::add_group(string a) {
//	skipstring_lyh* update[SKIPMAX] = { 0 };
//	skipstring_lyh* p = BuildUpdate(groups, group_level, a, update); //在表中查找并构建update表
//	if (p != NULL) return; //已有， 无需重复插入
//	int newlevel = random_level(); //确定向上插几层
//	if (newlevel > group_level) { //比原来层数还高，更新level和update值
//		for (int i = group_level; i < newlevel; i++)
//			update[i] = groups;
//		group_level = newlevel;
//	}
//	p = new skipstring_lyh(a); //创建新结点
//	for (int i = 0; i < newlevel; i++) { //自下而上逐层插入结点
//		p->next[i] = update[i]->next[i];
//		update[i]->next[i] = p;
//	}
//	group_num++;
//}
//void user_lyh::del_friend(string a) {
//	skipstring_lyh* update[SKIPMAX] = { 0 };
//	skipstring_lyh* p = BuildUpdate(friends, friend_level, a, update); //在表中查找并构建update表
//	if (p == NULL) return; //表中未找到结点， 无需删除
//	for (int i = 0; i < friend_level; i++) { //自底向上逐层拆下结点p
//		if (update[i]->next[i] != p) break;
//		update[i]->next[i] = p->next[i];
//	}
//	delete p;
//	while (friend_level > 0 && friends->next[friend_level - 1] == NULL) //删除后可能造成某些层变为空
//		friend_level--;
//	friend_num--;
//}
//void user_lyh::del_group(string a) {
//	skipstring_lyh* update[SKIPMAX] = { 0 };
//	skipstring_lyh* p = BuildUpdate(groups, group_level, a, update); //在表中查找并构建update表
//	if (p == NULL) return; //表中未找到结点， 无需删除
//	for (int i = 0; i < group_level; i++) { //自底向上逐层拆下结点p
//		if (update[i]->next[i] != p) break;
//		update[i]->next[i] = p->next[i];
//	}
//	delete p;
//	while (group_level > 0 && groups->next[group_level - 1] == NULL) //删除后可能造成某些层变为空
//		group_level--;
//	group_num--;
//}
//
//void user_lyh::download() {}
//void user_lyh::del_account(string a) {}
////下为bind类
//
//void bind_lyh::del(int choose) {
//	if (choose == 1) {
//		if (qq == "0") {}
//		else {
//			qq = "0";
//			number--;
//		}
//	}
//	else if (choose == 2) {
//		if (qq == "0") {}
//		else {
//			wechat = "0";
//			number--;
//		};
//		if (number == 0) {
//			delete this;
//		}
//	}
//}
//int bind_lyh::num() {
//	return number;
//}
////以下为group类
//void group_lyh::add(string id) {
//	skipstring_lyh* update[SKIPMAX] = { 0 };
//	skipstring_lyh* p = BuildUpdate(everyone, everyone_level, id, update); //在表中查找并构建update表
//	if (p != NULL) return; //已有， 无需重复插入
//	int newlevel = random_level(); //确定向上插几层
//	if (newlevel > everyone_level) { //比原来层数还高，更新level和update值
//		for (int i = everyone_level; i < newlevel; i++)
//			update[i] = everyone;
//		everyone_level = newlevel;
//	}
//	p = new skipstring_lyh(id); //创建新结点
//	for (int i = 0; i < newlevel; i++) { //自下而上逐层插入结点
//		p->next[i] = update[i]->next[i];
//		update[i]->next[i] = p;
//	}
//	everyone_num++;
//}
//void group_lyh::kick(string id) {
//	skipstring_lyh* update[SKIPMAX] = { 0 };
//	skipstring_lyh* p = BuildUpdate(everyone, everyone_level, id, update); //在表中查找并构建update表
//	if (p == NULL) return; //表中未找到结点， 无需删除
//	for (int i = 0; i < everyone_level; i++) { //自底向上逐层拆下结点p
//		if (update[i]->next[i] != p) break;
//		update[i]->next[i] = p->next[i];
//	}
//	delete p;
//	while (everyone_level > 0 && everyone->next[everyone_level - 1] == NULL) //删除后可能造成某些层变为空
//		everyone_level--;
//	everyone_num--;
//	if (find(id) != NULL) {
//		delm(id);
//	}
//}