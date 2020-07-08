#include "person.h"
#include<string>
#include<string.h>
#include<iomanip>
#include"date.h"
#include<iostream>
using namespace std;
int person::Playercount = 0;
//*******************************************************************************************
person::person(int a,int b)
{
	height=a;
	weight=b;
}
//******************************************************************************************
person::person(const person &r)
{
	   name = r.name;
	     birthday = r.birthday;
	       age = r.age;               
		      height = r.height;
		        weight = r.weight;
		            wortime = r.wortime;
		                value = r.value;
	                 position = r.position ;
                number = r.number;  
	          score = r.score;
	       board = r.board; 
		ill =r.ill;
	Playercount=r.Playercount;        
 }
 
 void person::operator=(const person &r)
 {  name = r.name;
	     birthday = r.birthday;
	       age = r.age;
		      height = r.height;
		        weight = r.weight;
		            wortime = r.wortime;
		                value = r.value;
	                 position = r.position ;
                number = r.number;
	          score = r.score;
	       board = r.board;
		ill =r.ill;
	Playercount=r.Playercount;
 }
//******************************************************************************************
ostream &operator <<(ostream &strm,person &obj)
{   cout<<"***************************************************************"<<endl;
    strm<<"姓名\t"<<"年龄\t"<<"位置\t"<<"号码\t"<<"得分\t"<<"篮板\t"<<"助攻\t"<<"伤病\t"<<endl;
	 strm<<obj.name<<"\t"<<obj.age<<"\t"<<obj.position<<"\t"<<obj.number<<"\t"<<obj.score<<"\t";
		  strm.precision(2);
		     strm<<obj.board<<"\t";
	     strm.precision(2);  //<<setiosflags(ios::fixed)
		     strm<<obj.assit<<"\t";
	 if(obj.ill==0)
	 cout<<"NO"<<endl;
	 else cout<<"YES"<<endl; 
}
//************************************************************************************************
 istream &operator >> (istream &strm,person &obj)//重载>>没毛病
   { int sign1,sign2;
      char sign;
	     cout<<"               -------------------输入单个球员信息中-------------------"<<endl;
	       cout<<"**********姓名:";
              strm>>obj.name;
            cout<<"**********出生日期:";
                strm>>obj.birthday;
                  obj.age = 2018-obj.birthday.GET_Year();//2018减去生日的year
            cout<<"**********身高:";
               strm>>obj.height;
                 strm.ignore();
            cout<<"**********体重:";
               strm>>obj.weight;
                 strm.ignore();
            cout<<"**********在职时间:";
                 strm>>obj.wortime;
                      strm.ignore();
    cout<<"位置:(1-PG-控卫 2-SG-得分后卫 3-C-中锋 4-SF-小前锋 5-PF-大前锋)\n";
	    cin>>sign1;

	  while(sign1>5)//(sign!=1||sign!=2||sign!=3||sign!=4||sign!=5)
	 {  cout<<"没有对应的位置,请重新输入.\n";
	     cin>>sign1;
          }
	  switch(sign1)
	   { case 1 :  obj.position = "PG"  ;break;
		 case 2 :  obj.position = "SG"  ;break;
		 case 3 :  obj.position = "C"   ;break;
		 case 4 :  obj.position = "SF"  ;break;
		 case 5 :  obj.position = "PF"  ;break;
		 default:   break ;
	     }
	    cout<<"是否担当其他位置0-No (1-5)表示位置.\n";
		   cin>>sign2;
	  switch(sign2)
	   { case 1 :  if(sign1!=sign2) obj.position += "/PG"  ;break;
		 case 2 :  if(sign1!=sign2) obj.position += "/SG"  ;break;
		 case 3 :  if(sign1!=sign2) obj.position += "/C"   ;break;
		 case 4 :  if(sign1!=sign2) obj.position += "/SF"  ;break;
		 case 5 :  if(sign1!=sign2) obj.position += "/PF"  ;break;
		 default:   break ;
	    }

	 cout<<"得分--篮板--助攻(模式0--直接输入 模式1--输入多场数据计算获取**最多10场**)请选择模式:";
	 strm>>sign;
	 if (sign=='0')
	    {cout<<"-------------------模式0:-------------------"<<endl;
	     strm>>obj.score>>obj.board>>obj.assit;
	    }
	 else { int sco[10],boa[10],ass[10],i,count;
	         float s1=0,s2=0,s3=0;
	          cout<<"-------------------模式1-------------------"<<endl;
             for(i=0;i<10;i++)
               { cout<<"请输入第"<<i+1<<"场 得分-篮板-助攻 :";
	               strm>>sco[i];
	                  strm.ignore();
				        strm>>boa[i];
						   strm.ignore();
				             strm>>ass[i];
    	                      cout<<"是否继续输入数据(*否,其他是):";
    	                       cin>>sign;
    	                        if(sign=='*')   break;
                                  if (i==9)     break;
	                               }
		                    count = i+1;
	         for(;i>=0;i--)
			   {                 s1+=sco[i];
		                      s2+= boa[i];
		                  s3+=ass[i];
	                       }
	                 obj.score=s1/count;
	            obj.board=s2/count;
	        obj.assit=s3/count;
	      }
      cout<<"**********号码:";
        strm>>obj.number;
          strm.ignore();
            cout<<"**********伤病:";
	         strm>>obj.ill;
	           cout<<"**********身价:";
	             strm>>obj.value;
	                  strm.ignore();
   	 return strm;
   }
//****************************************************************************************
void person::Calcu_score()
{ int sco[10],boa[10],ass[10],count,i ;
  float s1 = 0,s2 = 0,s3 = 0;
   char sign;
   cout<<"最多可输入十场比赛的数据用于计算场均 得分-篮板-助攻"<<endl;
   for(i=0;i<10;i++)
    {    cout<<"请输入第"<<i+1<<"场 得分-篮板-助攻 :";
	       cin>>sco[i]>>boa[i]>>ass[i]; 
    	     cout<<"是否继续输入数据(*否,其他是):";
    	      cin>>sign;
    	   if(sign=='*')   break;
        if(i==9)     break;
	 } 
		count = i+1;
	 for(;i>=0;i--)
	 {
		 s1+=sco[i];
		     s2+= boa[i];
		        s3+=ass[i];
	  } 
	  score=s1/count;
	      board=s2/count;
	         assit=s3/count;
}
//***************************************************************************************
void person::Change_Per(Per datePer)
{
    name = datePer.name;
			  height = datePer.height; 
			  birthday.Set_YMD(datePer.birthday.y,datePer.birthday.m,datePer.birthday.d); 
			    age = 2018-birthday.GET_Year();
			        weight = datePer.weight;	       
			position = datePer.position;
			    number = datePer.number;
			      wortime =datePer.wortime;
			        score =datePer.score;
			          board =datePer.board;
			            assit =datePer.assit;
			              ill=datePer.ill;
			                value=datePer.value;  
}
Per person::Change_person()
{   Per datePer;
datePer.height = height;
	  strcpy(datePer.name,name.c_str());
		  datePer.birthday.y = birthday.GET_Year();
		  datePer.birthday.m =birthday. GET_Month();
		  datePer.birthday.d = birthday.GET_Day();
	         datePer.weight = weight;
	 strcpy(datePer.position, position.c_str() ) ;
			  datePer.number =  number ;
			       datePer.wortime= wortime;
			         datePer.score = score;
			          datePer.board = board ;
			            datePer.assit  =  assit;
			              datePer.ill = ill;
			                datePer.value = value;
	return datePer;
}
//**********************************************************************************************
void person::Chan_P()
{    int sign;
     char ch; 
  cout<<"               -------------------修改单个球员信息中-------------------"<<endl;
  cout<<"//0-姓名 1-出生日期 2-身高 3-体重 4-号码 5-位置 6-得分 7-篮板8-助攻 9-伤病 10-在职时间 11-身价//"<<endl; 
   while(1){
   	        cout<<"请输入修改选项的数字:";
                 cin>>sign; 
   	         switch(sign)
			   { 	  
   	                 case 0 :  cout<<"********姓名:";	
   	                              cin>>name; break;             
   	                 case 1 :  cout<<"********出生日期:";
		                          cin>>birthday; break;		        
   	                 case 2 :  cout<<"********身高:";
	                              cin>>height;  break;	            
   	                 case 3 :  cout<<"********体重:";
		   	                      cin>>weight; break;		   	    
   	                 case 4 :  cout<<"********号码:";	
	           	                  cin>>number; break;	         	
   	                 case 5 :  cout<<"********位置:";		
		                          cin>>position; break;		        
   	                 case 6 :  cout<<"********得分:";	
		                          cin>>score; break;
					 case 7 :  cout<<"********篮板:";	
		                          cin>>board; break;
					 case 8 :  cout<<"********助攻:";	
		                          cin>>assit; break;			  			  			  		        
	                 case 9 :   cout<<"********伤病:";	
		                           cin>>ill; break; 				  									   	
	                 case 10 :   cout<<"********在职时间:";
	                              cin>>wortime; break;
					 case 11 :  cout<<"********身价:";
	                              cin>>value; break;				  		
	           	default: cout<<"该数字无法匹配到相关信息."<<endl; 
		        }
		       cout<<"是否继续修改,退出请按*键.";
		   cin>>ch;
		if(ch=='*')  break; 
	   }	
}
//***************************************************************************************************
void person::print()//球员数据输出 
{  
	cout<<"姓名\t"<<"位置\t"<<endl;
	cout<<name<<"\t"<<position<<"\t"<<endl;	
}
//*************************************************************************************************** 
void person::All_print()//球员信息全部打印 
{   cout<<" -------------------------------------------------------------------------------------"<<endl;
	cout<<"姓名\t"<<"出生日期\t"<<"身高\t"<<"体重\t"<<"位置\t";
	cout<<"号码\t"<<"得分\t"<<"篮板\t"<<"助攻\t"<<"伤病\t"<<endl;
	cout<<name<<"\t"<<birthday<<"\t";
		cout.precision(4);
	cout<<height<<"\t";
		cout.precision(3);
	cout<<weight<<"\t";
	cout<<position<<"\t"<<number<<"\t";
	cout.precision(3);
	cout<<score<<"\t";
	cout.precision(2);
	  cout<<board<<"\t";
	   cout.precision(2);
	    cout<<assit<<"\t";
	 if ( ill==0 )
	 cout<<"NO\t"<<endl;
	 else cout<<"YES\t"<<endl;
}
//******************************************************************************************************   
