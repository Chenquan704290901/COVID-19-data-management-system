
//本页菜单：
//1.定义一个类和对象：9->40行
//2.定义一个友类和对象：42->59行
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Data  //定义一个类
{
	friend class data_message_p;//声明一个友类

private:
	string province;       //省
	int sort;              //序号
	int time;              //时间
	int new_dia;           //新增确诊
	int new_cur;           //新增治愈
	int new_dea;           //新增死亡
	int new_red_sus;       //新增/减少的疑似
	int new_red_sev;       //新增/减少的重症
	int cum_dia;           //累计确诊
	int cum_cur;           //累计治愈
	int cum_dea;           //累计死亡
	int exi_sus;           //现存疑似
	int exi_sev;           //现存重症
	string sus_cha;        //疑似变化
	string ser_cha;        //重症变化
	Data* next;

public:
	Data(int, string, int, int, int, int, int);
	static void display_n(Data*);//计算全国数据的函数
	static void display_p(Data*);//计算各地区数据的函数
	static void display_o(Data*);//计算某省的数据的函数
	static void guai_dian(Data*);//计算拐点的函数
	static void j_time(Data*);//计算某段时间的全国平均数据的函数
	void swap();//排序时用的交换函数
};

class data_message_p//定义友类
{
private:
	Data* first;//定义一个指向对象的指针
	Data* last;//定义一个指向对象的指针

public:
	data_message_p();//初始化
	void revise();//修改数据
	void search_o();//搜索某省数据
	void add();//添加数据
	void showAll_p();//显示各地区数据
	void showAll_n();//显示全国数据
	void g_d();//显示拐点
	void c_p();//显示查询某段时间的全国数据
	void showMenu1();//管理员菜单
	void showMenu2();//用户菜单
	void input();//从数据文件获取数据到链表
	void exitt();//退出
};



