#ifndef DATE_H
#define DATE_H
 #include<iostream> 
 using namespace std;
 //Date类 包括year/month/day
class Date
 {
  private:
  int year,month,day;
  public:
  	Date(){	}
    Date(int,int,int);//构造函数
    Date(const Date &r);//拷贝构造
      void Set_YMD(int,int,int);//设置出生年月日
      int GET_Year(){return year;}//返回年，计算年龄
      int GET_Month(){return month;}//返回月
      int GET_Day(){return day;}//返回日
   void Print();//打印Date
   Date operator = (const Date &);//重载=
   bool operator <(const Date &);
   friend  istream &operator >> (istream &,Date &);
   friend  ostream &operator  <<(ostream &,Date &);
 };
#endif
