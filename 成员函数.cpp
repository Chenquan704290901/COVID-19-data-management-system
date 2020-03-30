
//本页的菜单：
//1.数据文件到-》链表:11行
//2.修改数据时用的交换函数：22
//3.计算各地区数据：46
//4.根据确诊数据排序：114
//5.计算某省的数据：157
//6.计算拐点的函数：255
//7.//计算某段时间的全国平均数据：317
//8.计算全国的数据：358
//9.初始化：436
//10.添加数据：444
//11.调用从数据文件-》链表：484
//12.调用搜索某省的数据：530
//13.调用修改某省数据的函数：537
//14.调用搜索某省的数据：595

#include <iostream>
#include <iomanip>
#include <string>
#include"头文件1.h"
#include<stdlib.h>
using namespace std;

//数据文件到-》链表
Data::Data(int Time, string Province, int New_dia
	, int New_cur, int New_dea, int New_red_sus, int New_red_sev)
{
	time = Time; province = Province; new_dia = New_dia;
	new_cur = New_cur; new_dea = New_dea;
	new_red_sus = New_red_sus; new_red_sev = New_red_sev;
	next = NULL;
}

//修改数据时用的交换函数
void Data::swap()
{
	//定义数据
	int s_sort; string s_province, s_sus_cha, s_ser_cha;
	int s_cum_dia, s_new_dia, s_cum_cur, s_new_dea;
	int s_exi_sus, s_exi_sev, s_new_cur, s_cum_dea;

	//数据交换
	s_sort = sort; sort = next->sort; next->sort = s_sort;
	s_province = province; province = next->province; next->province = s_province;
	s_sus_cha = sus_cha; sus_cha = next->sus_cha; next->sus_cha = s_sus_cha;
	s_ser_cha = ser_cha; ser_cha = next->ser_cha; next->ser_cha = s_ser_cha;
	s_cum_dia = cum_dia; cum_dia = next->cum_dia; next->cum_dia = s_cum_dia;
	s_new_dia = new_dia; new_dia = next->new_dia; next->new_dia = s_new_dia;
	s_cum_cur = cum_cur; cum_cur = next->cum_cur; next->cum_cur = s_cum_cur;
	s_new_dea = new_dea; new_dea = next->new_dea; next->new_dea = s_new_dea;
	s_exi_sus = exi_sus; exi_sus = next->exi_sus; next->exi_sus = s_exi_sus;
	s_exi_sev = exi_sev; exi_sev = next->exi_sev; next->exi_sev = s_exi_sev;
	s_new_cur = new_cur; new_cur = next->new_cur; next->new_cur = s_new_cur;
	s_cum_dea = cum_dea; cum_dea = next->cum_dea; next->cum_dea = s_cum_dea;
}

//计算各地区数据
void Data::display_p(Data* first)
{
	//定义需要的数据
	int p_cum_dia = 0, p_new_dia = 0;
	int p_cum_cur = 0, p_new_cur = 0;
	int p_cum_dea = 0, p_new_dea = 0;
	int p_exi_sus = 0, p_exi_sev = 0;
	string p_sus_cha, p_ser_cha;
	int p_exi_sus_y = 0, p_exi_sev_y = 0;
	int p_exi_sus_n = 0, p_exi_sev_n = 0;

	Data* t = first;
	t = first;
	int max = 0;

	while (t)//找出最新的时间
	{
		max = t->time;
		if (max < t->time)
		{
			max = t->time;
		}
		t = t->next;
	}

	Data* T = first;
	string t_province;

	//计算累计的数据
	while (T)
	{
		t_province = T->province;
		t = first;
		p_cum_dia = 0;
		p_cum_cur = 0;
		p_cum_dea = 0;
		p_exi_sus = 0;
		p_exi_sev = 0;
		while (t)//累计数据
		{
			if (t->province == t_province)
			{
				p_cum_dia += t->new_dia;
				p_cum_cur += t->new_cur;
				p_cum_dea += t->new_dea;
				p_exi_sus += t->new_red_sus;
				p_exi_sev += t->new_red_sev;
				if (t->time == max)
				{
					t->cum_dia = p_cum_dia;
					t->cum_cur = p_cum_cur;
					t->cum_dea = p_cum_dea;
					t->exi_sus = p_exi_sus;
					t->exi_sev = p_exi_sev;
					if (t->new_red_sus > 0) t->sus_cha = "新增";
					else if (t->new_red_sus < 0) t->sus_cha = "减少";
					else t->sus_cha = "不变";
					if (t->new_red_sev > 0) t->ser_cha = "新增";
					else if (t->new_red_sev < 0) t->ser_cha = "减少";
					else t->ser_cha = "不变";
				}
			}
			t = t->next;
		}
		T = T->next;
	}

	//根据确诊数据排序
	t = first;
	Data* p = t;
	while (p->next)
	{
		t = first;
		while (t->next)
		{
			if ((t->next->cum_dia >= t->cum_dia) && (t->time == max) && (t->next->time == max))
			{
				t->swap();
			}
			t = t->next;
		}
		p = p->next;
	}
	//显示各地区数据
	t = first;
	int i = 0;
	system("color F4");
	while (t)
	{
		if (t->time == max)
		{
			t->sort = i + 1;
			cout << setiosflags(ios::fixed) << resetiosflags(ios::right);
			cout << setw(3) << t->sort << "  " << setw(5) << t->province << "     ";
			cout << setw(5) << t->cum_dia << "     " << setw(5) << t->new_dia << "     ";
			cout << setw(5) << t->cum_cur << "     " << setw(5) << t->new_cur << "     ";
			cout << setw(5) << t->cum_dea << "     " << setw(5) << t->new_dea << "     ";
			cout << setw(5) << t->exi_sus << "     " << setw(5) << t->sus_cha << "     ";
			cout << setw(5) << t->exi_sev << "     " << setw(5) << t->ser_cha << "     " << endl;
			cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
			i++;
		}
		t = t->next;
	}

	cout << "截至时间：2020-" << max / 100 << "-" << max % 100 << " 全国数据统计";
	cout << "                                                       注：数据来自国家卫健委" << endl;
}

//计算某省的数据
void Data::display_o(Data* first)
{
	int p_cum_dia = 0, p_new_dia = 0;
	int p_cum_cur = 0, p_new_cur = 0;
	int p_cum_dea = 0, p_new_dea = 0;
	int p_exi_sus = 0, p_exi_sev = 0;
	string p_sus_cha, p_ser_cha;
	int p_exi_sus_y = 0, p_exi_sev_y = 0;
	int p_exi_sus_n = 0, p_exi_sev_n = 0;

	Data* t = first;
	t = first;
	int max = 0;

	while (t)//找出最新时间
	{
		max = t->time;
		if (max < t->time)
		{
			max = t->time;
		}
		t = t->next;
	}

	//计算某省的数据
	Data* T = first;
	string t_province;
	while (T)
	{
		t_province = T->province;
		t = first;
		p_cum_dia = 0;
		p_cum_cur = 0;
		p_cum_dea = 0;
		p_exi_sus = 0;
		p_exi_sev = 0;
		while (t)
		{
			if (t->province == t_province)
			{
				p_cum_dia += t->new_dia;
				p_cum_cur += t->new_cur;
				p_cum_dea += t->new_dea;
				p_exi_sus += t->new_red_sus;
				p_exi_sev += t->new_red_sev;
				if (t->time == max)
				{
					t->cum_dia = p_cum_dia;
					t->cum_cur = p_cum_cur;
					t->cum_dea = p_cum_dea;
					t->exi_sus = p_exi_sus;
					t->exi_sev = p_exi_sev;
					if (t->new_red_sus > 0) t->sus_cha = "新增";
					else if (t->new_red_sus < 0) t->sus_cha = "减少";
					else t->sus_cha = "不变";
					if (t->new_red_sev > 0) t->ser_cha = "新增";
					else if (t->new_red_sev < 0) t->ser_cha = "减少";
					else t->ser_cha = "不变";
				}
			}
			t = t->next;
		}
		T = T->next;
	}

	//查出某省的数据
	string s_province;
	cout << "\n请输入查询的地区名："; cin >> s_province;
	t = first;
	int i = 0;
	t = first;
	system("color F4");
	while (t)
	{
		if ((t->time == max) && (t->province == s_province))
		{
			t->sort = i + 1;
			cout << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<====搜索某省结果数据====>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
			cout << " 序号  全国地区 累计确诊  新增确诊  累计治愈  新增治愈  累计死亡  新增死亡  现有疑似  疑似变化  现有重症  重症变化" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
			cout << setiosflags(ios::fixed) << resetiosflags(ios::right);
			cout << setw(3) << t->sort << "  " << setw(5) << t->province << "     ";
			cout << setw(5) << t->cum_dia << "     " << setw(5) << t->new_dia << "     ";
			cout << setw(5) << t->cum_cur << "     " << setw(5) << t->new_cur << "     ";
			cout << setw(5) << t->cum_dea << "     " << setw(5) << t->new_dea << "     ";
			cout << setw(5) << t->exi_sus << "     " << setw(5) << t->sus_cha << "     ";
			cout << setw(5) << t->exi_sev << "     " << setw(5) << t->ser_cha << "     " << endl;
			cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
			cout << "截至时间：2020-" << max / 100 << "-" << max % 100 << " 全国数据统计";
			cout << "                                                       注：数据来自国家卫健委" << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<========>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		}
		t = t->next;
	}
}

//计算拐点的函数
void Data::guai_dian(Data* first)
{
	Data* t = first;
	Data* T = first;
	int a[100] = { 0 }, b[100] = { 0 };
	int* p = a, * q = b;
	int i = 0, d = 0;
	int g_new_dia = 0, Time = 0;

	while (T)
	{
		g_new_dia = 0, d = 0;
		for (i = 0; a[i] != '\0'; i++)
		{
			if (T->time == a[i])
			{
				d++;
			}
		}
		if (d > 0)
		{
			T = T->next;
			continue;
		}
		else
		{
			Time = T->time;
		}
		t = first;
		while (t)
		{
			if (t->time == Time)
			{
				g_new_dia += t->new_dia;
			}
			t = t->next;
		}
		*p = T->time;
		*q = g_new_dia;
		q++; p++;
		T = T->next;
	}
	p = a, q = b;
	for (p = a, i = 0; *p != '\0'; p++, i++);
	system("color F4");
	if (i >= 11)
	{
		for (i = 5; b[i + 5] != '\0'; i++)
		{
			if (b[i] > b[i - 1] && b[i] > b[i - 2] && b[i] > b[i - 3]
				&& b[i] > b[i - 4] && b[i] > b[i - 5] && b[i] > b[i + 1]
				&& b[i + 1] > b[i + 2] && b[i + 2] > b[i + 3]
				&& b[i + 3] > b[i + 4] && b[i + 4] > b[i + 5])
				cout << a[i] << "  ";
			else cout << "目前没有拐点";
		}
	}
	else cout << "目前没有拐点";
}

//计算某段时间的全国平均数据
void Data::j_time(Data* first)
{
	Data* t = first;
	int beg = 0, fin = 0;
	cout << "\n\n\t\t\t注:时间输入格式：如3月2日，输入302；3月15，输入315\n\t\t\t请输入查询起始时间："; cin >> beg;
	cout << "\t\t\t注:时间输入格式：如3月2日，输入302；3月15，输入315\n\t\t\t请输入查询截至时间："; cin >> fin;
	int day = 0;
	day = fin - beg;
	int  s_new_dia = 0;
	int  s_new_cur = 0;
	int  s_new_dea = 0;
	Data* p = first;
	while (p)
	{
		if (p->time >= beg && p->time <= fin)
		{
			while (t)
			{
				if (p->time == t->time)
				{
					s_new_dia += t->new_dia;
					s_new_cur += t->new_cur;
					s_new_dea += t->new_dea;
				}
				t = t->next;
			}
		}
		p = p->next;
	}
	if (s_new_dia > 0 || s_new_cur > 0 || s_new_dea > 0)
	{
		system("color F4");
		cout << "\n\t\t\t-----------------------";
		cout << "\t\t\t 该段时间内：\n";
		cout << "\t\t\t 平均每天新增确诊：" << s_new_dia / day << endl;
		cout << "\t\t\t 平均每天新增治愈：" << s_new_cur / day << endl;
		cout << "\t\t\t 平均每天新增死亡：" << s_new_dea / day << endl;
		cout << "\t\t\t-----------------------";
	}
}

//计算全国的数据
void Data::display_n(Data* first)
{
	int n_cum_dia = 0, n_new_dia = 0;
	int n_cum_cur = 0, n_new_cur = 0;
	int n_cum_dea = 0, n_new_dea = 0;
	int n_exi_sus = 0, n_exi_sev = 0;
	string n_sus_cha, n_ser_cha;
	int n_exi_sus_n = 0, n_exi_sev_n = 0;
	Data* t = first;
	while (t)
	{
		n_cum_dia += t->new_dia;
		n_cum_cur += t->new_cur;
		n_cum_dea += t->new_dea;
		n_exi_sus += t->new_red_sus;
		n_exi_sev += t->new_red_sev;
		t = t->next;
	}
	t = first;
	int max;
	while (t)
	{
		max = t->time;
		if (max < t->time)
		{
			max = t->time;
		}
		t = t->next;
	}
	t = first;
	while (t)
	{
		if (t->time == max)
		{
			n_new_dia += t->new_dia;
			n_new_cur += t->new_cur;
			n_new_dea += t->new_dea;
			n_exi_sus_n += t->new_red_sus;
			n_exi_sev_n += t->new_red_sev;
		}
		t = t->next;
	}
	if (n_exi_sus_n > 0) n_sus_cha = "新增";
	else if (n_exi_sus_n < 0) n_sus_cha = "减少";
	else n_sus_cha = "不变";
	if (n_exi_sev_n > 0) n_ser_cha = "新增";
	else if (n_exi_sev_n < 0) n_ser_cha = "减少";
	else n_ser_cha = "不变";
	cout << endl;
	system("color F4");
	cout << "\t\t\t<<<<<<<<<<<<<<<<====全国疫情数据====>>>>>>>>>>>>>>>>>>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          截至时间：" << setw(2) << max / 100 << "-" << setw(2) << max % 10 << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          累计确诊：" << setw(6) << n_cum_dia << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          新增确诊：" << setw(6) << n_new_dia << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          累计治愈：" << setw(6) << n_cum_cur << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          新增治愈：" << setw(6) << n_new_cur << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          累计死亡：" << setw(6) << n_cum_dea << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          新增死亡：" << setw(6) << n_new_dea << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          现有疑似：" << setw(6) << n_exi_sus << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          疑似变化：" << setw(6) << n_sus_cha << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          现有重症：" << setw(6) << n_exi_sev << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          重症变化：" << setw(6) << n_ser_cha << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<<<<<<<<<<<<<<<=====================>>>>>>>>>>>>>>>>>" << endl;
}

//初始化
data_message_p::data_message_p()
{
	first = NULL;
	last = NULL;
}

//添加数据
void data_message_p::add()
{
	int Time, New_dia, New_cur, New_dea, New_red_sus, New_red_sev;
	string Province;
	cout << endl << endl;
	cout << "\t\t\t注:时间输入格式：如3月2日，输入302；3月15，输入315\n\t\t\t时间："; cin >> Time;
	cout << "\t\t\t地区："; cin >> Province;
	cout << "\t\t\t新增确诊："; cin >> New_dia;
	cout << "\t\t\t新增治愈："; cin >> New_cur;
	cout << "\t\t\t新增死亡："; cin >> New_dea;
	cout << "\t\t\t新增/减少疑似："; cin >> New_red_sus;
	cout << "\t\t\t新增/减少重症："; cin >> New_red_sev;

	Data* t = new Data(Time, Province, New_dia, New_cur, New_dea, New_red_sus, New_red_sev);
	Data* p = first;
	while (p)
	{
		if ((p->time == t->time) && (p->province == t->province))
		{
			cout << "\n\t\t\t今天数据已录入!" << endl;
			return;
		}
		p = p->next;
	}
	ofstream outfile("数据.dat", ios::app);
	outfile << Time << " " << Province << " " << New_dia << " " << New_cur << " " << New_dea << " " << New_red_sus << " " << New_red_sev << " " << endl;
	outfile.close();
	if (first == NULL)
	{
		first = last = t;
	}
	else
	{
		last->next = t;
		last = last->next;
	}
}

//调用从数据文件-》链表
void data_message_p::input()
{
	int Time, New_dia, New_cur, New_dea, New_red_sus, New_red_sev;
	string Province;
	ifstream infile("数据.dat");
	if (!infile)
	{
		cout<<"\t\t没有数据，";
		exit(1);
	}
	//文件已经打开，已经创建文件
	//文件  有没有数据
	//数据---》链表
	while (!infile.eof())
		//while (infile.peek() != EOF)
	{

		infile >> Time >> Province >> New_dia >> New_cur
			>> New_dea >> New_red_sus >> New_red_sev;
		Data* p = first;
		while (p)
		{
			if (p->time == Time && p->province == Province)
			{
				return;
			}
			p = p->next;
		}
		Data* t = new Data(Time, Province, New_dia, New_cur, New_dea, New_red_sus, New_red_sev);
		if (first == NULL)
		{
			first = last = t;
		}
		else
		{
			last->next = t;
			last = last->next;
		}
	}

	infile.close();

}

//调用搜索某省的数据
void data_message_p::c_p()
{
	Data::j_time(first);
}

//调用修改某省数据的函数
void data_message_p::revise()
{
	string r_province;
	int r_time, r_new_dia, r_new_cur, r_new_dea;
	int r_new_red_sus, r_new_red_sev;
	cout << endl << endl;
	cout << "\n\t\t\t请输入需要修改的地区："; cin >> r_province;
	cout << "\n\t\t\t注:时间输入格式：如3月2日，输入302；3月15，输入315\n\t\t\t请输入需要修改的时间："; cin >> r_time;
	int a;
	while (1)
	{
		cout << "\n\t\t\t\t------------------ ";
		cout << "\n\t\t\t\t1.新增确诊\n\t\t\t\t2.新增治愈\n\t\t\t\t3.新增死亡";
		cout << "\n\t\t\t\t4.新增 / 减少疑似\n\t\t\t\t5.新增 / 减少重症";
		cout << "\n\t\t\t\t------------------ ";
		cout << "\n\t\t\t\t修改的某项数据？请输入相应序号："; cin >> a;
		if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5)
		{
			cout << "\n\t\t\t\t输入序号有误，请重新输入！" << endl;
		}
		else break;
	}
	switch (a)
	{
	case 1:cout << "\n\t\t\t\t新增确诊改为："; cin >> r_new_dia; break;
	case 2:cout << "\n\t\t\t\t新增治愈改为："; cin >> r_new_cur; break;
	case 3:cout << "\n\t\t\t\t新增死亡改为："; cin >> r_new_dea; break;
	case 4:cout << "\n\t\t\t\t新增/减少疑似改为："; cin >> r_new_red_sus; break;
	case 5:cout << "\n\t\t\t\t新增/减少重症改为："; cin >> r_new_red_sev; break;
	}
	Data* t = first;
	while (t)
	{
		if ((t->time == r_time) && (t->province == r_province))
		{
			switch (a)
			{
			case 1:t->new_dia = r_new_dia; break;
			case 2:t->new_cur = r_new_cur; break;
			case 3:t->new_dea = r_new_dea; break;
			case 4:t->new_red_sus = r_new_red_sus; break;
			case 5:t->new_red_sev = r_new_red_sev; break;
			}
		}
		t = t->next;
	}
	t = first;
	ofstream outfile("数据.dat", ios::out);
	while (t)
	{
		outfile << t->time << " " << t->province << " " << t->new_dia << " " << t->new_cur << " " << t->new_dea << " " << t->new_red_sus << " " << t->new_red_sev << " " << endl;
		t = t->next;
	}
	outfile.close();
}

//调用搜索某省的数据
void data_message_p::search_o()
{
	Data::display_o(first);
}
void data_message_p::g_d()
{
	cout << endl << endl;
	cout << "\t\t\t\t拐点情况： ";
	Data::guai_dian(first);
}
void data_message_p::showAll_p()
{
	cout << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<====全国地区疫情数据====>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << " 序号  全国地区 累计确诊  新增确诊  累计治愈  新增治愈  累计死亡  新增死亡  现有疑似  疑似变化  现有重症  重症变化" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
	Data::display_p(first);
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<========>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
}
void data_message_p::showAll_n()
{
	Data::display_n(first);
}
void data_message_p::exitt()
{
	exit(1);
}
void data_message_p::showMenu1()
{
	cout << endl << endl;
	cout << "\t\t\t***********************************************" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**       新冠疫情数据管理系统主菜单          **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**           1.  录入数据                    **" << endl;
	cout << "\t\t\t**           2.  各地区数据                  **" << endl;
	cout << "\t\t\t**           3.  全国数据                    **" << endl;
	cout << "\t\t\t**           4.  修改数据                    **" << endl;
	cout << "\t\t\t**           5.  查询某省数据                **" << endl;
	cout << "\t\t\t**           6.  查询拐点                    **" << endl;
	cout << "\t\t\t**           7.  查询一段时间全国的平均数据  **" << endl;
	cout << "\t\t\t**           8.  退出                        **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t***********************************************" << endl;
}
void data_message_p::showMenu2()
{
	cout << endl << endl;
	cout << "\t\t\t***********************************************" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**       新冠疫情数据管理系统主菜单          **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**         1.  各地区数据                    **" << endl;
	cout << "\t\t\t**         2.  全国数据                      **" << endl;
	cout << "\t\t\t**         3.  查询某省数据                  **" << endl;
	cout << "\t\t\t**         4.  查询拐点                      **" << endl;
	cout << "\t\t\t**         5.  查询一段时间全国的平均数据    **" << endl;
	cout << "\t\t\t**         6.  退出                          **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t***********************************************" << endl;
}