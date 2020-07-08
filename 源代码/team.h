#ifndef TEAM_H
#define TEAM_H
#include<string>
using namespace std;
typedef struct club
 {
	char  Coach[10];
  	char  ClubName[10];
  	int    win_count;
  	int   fail_count;
	  }Club;
class team
{       
  protected:
  	string Coach;//教练
  	string ClubName;//俱乐部简称
  	int    win_count;//胜场
  	int    fail_count;//负场;
	static int  account;	
	public:
		team();//构造函数
		team(const team&);//拷贝构造函数
		 void Print();//战绩模式显示
		int re_win(){ return win_count;}
		void Set_Acc(){ account++;}
		 void print();    //打印显示
		void Team_Change(Club); //结构体向类的转换
		Club Club_team();//类向结构体的转换
	    string Get_ClubName(){return ClubName;}//获取俱乐部名字
	team     operator=(const team &);//重载=
	bool     operator > (team &);
	friend	 ostream &operator << (ostream &, team &);
    friend   istream  &operator >> (istream &, team &);
	~team();
};
#endif
