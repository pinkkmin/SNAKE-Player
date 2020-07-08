#include "team.h"
#include<iostream>
#include<iomanip>
#include<string.h>
#include<string>
using namespace std;
int team::account = 0;
team::team()//缺省构造函数
{
	win_count = 0;
    fail_count = 0;
}
 team::team(const team &r)//拷贝构造函数
{    Coach = r. Coach;
      ClubName = r. ClubName;
        win_count = r.win_count; 
       fail_count = r.fail_count;
       account  =r.account;
}
team team::operator=(const team &r)
{
	 	 Coach = r. Coach;
      ClubName = r. ClubName;
        win_count = r.win_count;
       fail_count = r.fail_count;
       account  =r.account;
       return *this;
}
bool team::operator > (team & r)
{
	if(win_count>=r.win_count) return true;
	else return    false;
}
istream &operator >>(istream &strm,team &obj)//重载>>
{
    cout<<"俱乐部:";
     strm>>obj.ClubName;
      cout<<"教练:";
       strm>>obj.Coach;
        cout<<"战绩:(胜--负)";
          strm>>obj.win_count>>obj.fail_count;
            cout<<"球员人数:";
              strm>>obj.account;
}
ostream &operator <<(ostream &strm,team &obj)//重载<<
{
  strm<<"*******************"<<endl;
    strm<<"*    "<<obj.ClubName<<"俱乐部    *"<<endl;
      strm<<"* 教练:"<<obj.Coach<<"       *"<<endl;
       strm<<"* 战绩:"<<obj.win_count<<"胜--"<<obj.fail_count<<"负 *"<<endl; 
		strm<<"* 球员:"<<obj.account<<"人        *"<<endl;
}
void team::Team_Change(Club ker)//结构体Club转变为team类
{
	 Coach = ker.Coach;
       ClubName = ker.ClubName;
         win_count = ker.win_count ; 
         fail_count = ker.fail_count ;
 }
 Club team::Club_team()//team类转变为Club结构体
 {    Club C;
    strcpy(C.Coach,Coach.c_str());
	   strcpy(C.ClubName,ClubName.c_str());
	   C.win_count  = win_count ;
	   C.fail_count = fail_count;
	   return C;
 }
 void team::print()//打印显示
 {    cout<<"*******************"<<endl;
  cout<<"*    "<<ClubName<<"俱乐部    "<<endl;
   cout<<"* 教练:"<<Coach<<"       "<<endl;
    cout<<"* 战绩:"<<win_count<<"胜--"<<fail_count<<"负 "<<endl;
      cout<<"* 球员:"<<account<<"人        "<<endl;
        cout<<"*******************"<<endl;	
 }
void team::Print()
{   float wf;
	wf=win_count/(win_count*1.0+fail_count*1.0);
    cout<<"                                       俱乐部       "<<"战绩\t"<<"胜率\t"<<endl;
	cout<<"                                       "<<ClubName<<"       "<<win_count<<"胜--"<<fail_count<<"负  \t";
	cout.precision(3);
	cout<<100*wf<<"%"<<endl;
	
}
team::~team()
{
}
