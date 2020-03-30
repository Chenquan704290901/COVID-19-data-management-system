
//本页菜单：
// 1.数据文件->链表：15行
// 2.显示系统进入界面：18->91
// 3.显示管理员页面：50行
// 4.显示用户界面：76行
// 5.判断是管理员还是用户：36
// 6.判断密码是否正确：43
// 7.处理管理员操作：62
// 8.处理用户操作：87
#include <iostream>
#include <iomanip>
#include"头文件1.h" 
#include <string>
using namespace std;
int main()
{
	int h, z;
	int password = 123456, put_word = 0;//管理员密码：123456
	data_message_p d;//定义友类的对象
	d.input();//数据文件->链表

	while (1) //显示系统进入界面
	{
		system("color F0");
		cout << endl << endl;
		cout << "\t\t\t***********************************************" << endl;
		cout << "\t\t\t**                                           **" << endl;
		cout << "\t\t\t**        新冠疫情数据管理系统               **" << endl;
		cout << "\t\t\t**                                           **" << endl;
		cout << "\t\t\t**            1.  管理员                     **" << endl;
		cout << "\t\t\t**            2.  用户                       **" << endl;
		cout << "\t\t\t**                                           **" << endl;
		cout << "\t\t\t***********************************************" << endl;
		cout << "\t\t\t请输入操作的序号："; cin >> z;

		//判断是管理员还是用户
		switch (z)
		{
		case 1:
		{   
			system("color F0");
			cout << "\t\t\t\t请输入管理员密码："; cin >> put_word;//输入密码
			int D = 0;

			while (D != 1)
			{
				if (password != put_word)//判断密码是否正确
				{
					cout << "\n\t\t\t\t密码错误！请重新输入："; cin >> put_word;//密码不正确
				}
				else  D = 1;//密码正确

			}
			system("cls");//清屏

			while (1)
			{
				d.showMenu1();//显示用户界面
				cout << "\t\t\t\t请输入操作的序号：";
				cin >> h;
				cout << endl;

				switch (h)//处理管理员操作
				{
				case 1:system("cls"); d.add(); break;//添加数据
				case 2:system("cls"); d.showAll_p(); break;//显示地区的数据
				case 3:system("cls"); d.showAll_n(); break;//显示全国数据
				case 4:system("cls"); d.revise(); break;//修改数据
				case 5:system("cls"); d.search_o(); break;//搜索某省数据
				case 6:system("cls"); d.g_d(); break;//找拐点
				case 7:system("cls"); d.c_p(); break;//查某段时间的平均数据
				case 8:system("cls"); d.exitt(); break;//退出
				default: system("cls"); cout << "\n\t\t\t\t输入错误！" << endl;
					break;
				}
			}
		}
		case 2:
		{
			system("cls");//清屏

			while (1)
			{
				d.showMenu2();//显示用户界面
				cout << "\t\t\t\t请输入操作的序号：";
				cin >> h;
				cout << endl;

				switch (h)//处理用户操作
				{
				case 1:system("cls"); d.showAll_p(); break;//显示地区的数据
				case 2:system("cls"); d.showAll_n(); break;//显示全国数据
				case 3:system("cls"); d.search_o(); break;//搜索某省数据
				case 4:system("cls"); d.g_d(); break;//找拐点
				case 5:system("cls"); d.c_p(); break;//查某段时间的平均数据
				case 6:system("cls"); d.exitt(); break;//退出
				default: cout << "\n\t\t\t\t输入错误！" << endl;
					break;
				}
			}
		}
		default:system("cls"); cout << "\n\t\t\t\t输入错误！" << endl;
		}
	}


}