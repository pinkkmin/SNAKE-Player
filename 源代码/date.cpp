#include <iostream>
#include "date.h"
using namespace std;
 Date::Date(int year,int month,int day)
 {
 this->year=year;
 this->month=month;
  this->day=day;
 }
 Date::Date(const Date &r)
 {
 year = r.year;
 month = r.month;
 day = r.day;
  }
Date Date::operator = (const Date &r)
{
 year = r.year;
 month = r.month;
 day = r.day;
 return *this;
}
bool Date::operator <(const Date &r)//判断年龄大小,精确到日
{
   if(year > r.year )     return true;
  else
	 {
		if(year==r.year)
		   {   	if(month>r.month)   return true;
			     else{  if(month==r.month)
				         {   if(day>=r.day)   return   true;
					         else          return   false;
					     }
			         }
		    }
    	else return false;
	 }
}
void Date::Set_YMD(int y,int m,int d)
{
  year = y;
    month = m;
     day = d;
}
void Date::Print()
 {
 cout<<year<<'.'<<month<<'.'<<day<<endl;
 }
 ostream &operator << (ostream &strm,Date &obj)
 {   
   strm<<obj.year<<"-"<<obj.month<<"-"<<obj.day;	
  return strm;
 }
istream &operator >> (istream &strm,Date &obj)
{     cout<<"year-month-day";
      strm>>obj.year;
      strm>>obj. month;
      strm>>obj.day;
      return  strm;   
} 
