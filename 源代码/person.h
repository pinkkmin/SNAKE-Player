#include<string>
#include<iostream>
using namespace std;
#include"date.h"
#include"team.h"
//#define PERSON_H
typedef struct date{
	int y;
	int m;
	int d;	
}Dat; 
 typedef struct player{    
	  char name[10];//姓名
	  int age;//年龄
	  Dat  birthday;//出生日期 
	  float height;//身高
	  float weight;//体重 
	  char  position[6];//位置
	  int number;//号码
	  int wortime;//在职时间
	  float score;//场均得分
	  float board;//场均篮板
	  float assit;//助攻 
	  bool  ill;   //伤病
	  float value;//身价 
	}Per;
//************************************************************************
class  person:public team 
{    
   private:
	  string name;//姓名
	  Date  birthday;//出生日期 
	  int age;//年龄
	  float height;//身高
	  float weight;//体重  
	  string position;//位置
	  int number;//号码
	  int wortime;//在职时间
	  float score;//场均得分
	  float board;//场均篮板
	  float  assit;//助攻 
	  bool ill;//伤病
	  float value;//身价 
	  static int Playercount;//总球员人数,静态变量 
	
    public:
        person() 
        {      height = 0; weight = 0;
	                number = 0;wortime = 0;
	                    score = 0;
	               assit = 0;ill = 0;
	          value = 0;  age = 0; 
        }
        person(int,int );
        person(const person&); 
        ~person(){     }
        void account(){ Playercount +=1;}//球员人数
        void  Chan_P();                 //修改person类的信息 
        void print();                  //打印常规比赛数据 
        void All_print();             //打印更隐私信息
        void Change_Per(Per );       //将结构体的内容转换成类的数据
		void Calcu_score();         //由该球员的多场比赛数据,得出平均得分篮板助攻
		string Return_name(){ return name;}
		string Retuen_poition(){ return position;}
		int Return_age(){return	age;}
		 float Return_s(){return score; }
		 float  Return_a(){	return assit;}
		 float Return_b(){return  board;}
		 int Return_n(){return number;}
		 int Return_w(){ return wortime;	 }
		 float Return_v(){return value;}
          Per     Change_person();//类转结构体
        void Return_account(){team::account =Playercount ; }//给基类返回值
        void operator=(const person &);
		friend ostream &operator <<(ostream &,person &);
		friend istream &operator >> (istream &,person &);
};
			 
			  
