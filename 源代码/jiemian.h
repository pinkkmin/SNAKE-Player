#include <iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include"team.h"
using namespace std;
typedef struct uers
{
	char manager[10];
	char password[7];
     Club  team;
	struct uers *next;
}Uers;
//***************************************************************************************
void Pos(int x,int y)//设置光标位置
{
    COORD pos;
    HANDLE hOutput;
    pos.X=x;
    pos.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
}
//**************************************************************************************
 void returntime()//提示时间
 {
	 int i=15;
	 while(1)
	 {
	     Pos(54,15);
	      if(i>9)
	         printf("提示:界面将在%ds后跳转至登录界面,不进入请按*键.",i);
		    else if(i<9)
		        printf("提示:界面将在0%ds后登录界面,不进入请按*键",i);
		     Sleep(950);
		     i--;
		    if(i==0)    break;
		 //exit(0);
       }
   }
//***************************************************************************************
void creat_U()//录入已有的管理员和密码用于验证仅用于初始化前在
{   int i,k=0;
    char  ch,sign='0';
    Uers head;
    team one;
    fstream file;
    file.open("manager.dat",ios::out|ios::binary);
       if(file.fail())
	          {cout<<"打开文件失败.";
			      exit(0);
		      }
	cout<<"写入已有管理员和密码用于验证登录\n";
	  while(sign!='#')
	{    cout<<"管理员用户:";
	            cin>>head.manager;
	            cout<"球队信息:";
				 cin>>one;
				 head.team=one.Club_team();
	         cout<<"密 码 :";
		      i = 0;
	          head.password[6]='\0';
              while(i<7)
	          {   ch = getch();
                 if(ch==8)
                    {if(i==0)    continue;
	                              cout<<'\b'<<" "<<'\b';
	                               i--;
	                           }
                else
                  {   if(i==6) break;
				      head.password[i] = ch;
     	              cout<<"*";
     	             i++;
	              }
	          }
	    file.write((char*)&head,sizeof(head));
	    cout<<"结束录入用户名和密码请输入#,其他键继续.";
		  cin>>sign;
		if(sign=='#')   break;
	}
	file.close();
  }
//*************************************************************************************
Uers New_Manager()//注册管理员/密码和用户名录入manager.dat
 {  int i;
    string  Test1,Test2;
    char ch,PassWTest[7];
    Uers Newman;
    team one;
	fstream file;
	file.open("manager.dat",ios::out|ios::app|ios::binary) ;
	 if(file.fail()) {cout<<"打开文件失败.";
			            exit(0);
		                       }
	Pos(0,15);
    cout<<"请设置您的用户名:";
	 cin>>Newman.manager;
    cout<"球队信息:";
		cin>>one;
		Newman.team=one.Club_team();
	 while(1)
   {
	 cout<<"请设置您的六位密码:";
	    i=0;7)
	    {  ch = getch();
             if(
        while(i<ch==8)   { if(i==0)   continue;
	                        cout<<'\b'<<" "<<'\b';
	                            i--;
	                     }
             else         {  if(i==6) break;
			                   Newman.password[i] = ch;
     	                      cout<<"*";
     	                   i++;
	                     }
	    }
	    Newman.password[6]='\0';
	    Test1 = Newman.password;
	 cout<<"\n请再次确认密码:";
	     i = 0;
	    while(i<7)
	    {
	        ch = getch();
               if(ch==8)
                   { if(i==0)   continue;
	                   cout<<'\b'<<" "<<'\b';
	                     i--;
	                      }
                        else
                          {  if(i==6) break;
						   PassWTest[i] = ch;
     	                cout<<"*";
     	           i++;
	            }
	     }
	    PassWTest[6]='\0';
	    Test2 = PassWTest;
	if(Test1==Test2)  {     file.write((char*)&Newman,sizeof(Newman));
	                              cout<<"\n注册成功!"<<endl;
	                              break;
	                        }
	     else            cout<<"\n两次输入的密码不一致,请重新设置"<<endl;
    }
 file.close();
 return  Newman;
}
//**************************************************************************************
Uers Judg_PW(Uers test) //验证登录密码
{  fstream file;
	string  mang,pass;
    Uers temp;
    file.open("manager.dat",ios::in|ios::binary);
       if(file.fail())
	          {cout<<"打开文件失败.";
			      exit(0);
		       }
	    while(!file.eof())
		{
	           file.read((char*)&temp,sizeof(temp));
			      mang=temp.manager;
			        pass=temp.password;
				     if(mang==test.manager&&pass==test.password)
				     {   file.close();
				     	return temp;
					 }
	  	}
      strcpy(temp.manager,"0");//标记失败
		return temp ;
		file.close();
}
//*******************************************************************************************************************
Uers  Get_MG()//登录界面入口
{  Uers ker,one;
  int i=0,k=0;
   char ch,c;
	        Pos(49,9); //差值为7下次修改可用
			cin>>ker.manager;
			while(k<3){
			Pos(49,11);
		      i = 0;
	            ker.password[6]='\0';
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//无关紧要,变颜色
            while(i<7)
	          {   ch = getch();
                 if(ch==8)
                    {  if(i==0)    continue;
	                                cout<<'\b'<<"_"<<'\b';
	                               i--;
	                           }
                 else
                  {     if(i==6) break;
				         ker.password[i] = ch;
     	              cout<<"*";
     	             i++;
	               }
	          }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    one=Judg_PW(ker);
   if(one.manager[0]!='0') {   Pos(5,16);
                               cout<<"\n登录成功！！！\n";
							    return one;}//返回登录成功的账户
          else   {      Pos(0,16);
		     if(k==2)  {cout<<"您已输错密码三次,无法再输入"<<endl;
								strcpy(ker.manager,"0");//标记失败
			            		 return one ; }//返回
		     else     {  Pos(0,15);
			             cout<<"您还有"<<2-k<<"次输入密码的机会"<<endl; }
					     Pos(49,11);
					     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
					     cout<<"_________";
		             k++; }
    }
}
//*************************************************************************************************************
/*void ZJmian()
{ int sign;
 	system("title SNAKE球员管理系统");
	     system("mode con cols=114 lines=50");
    while(1){  char ch;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	   cout<<"******************************************************************************************************************\n\n\n\n";
	   cout<<("                                           ■■■■■■■■■■■■■\n");
	   cout<<("                                           ■SNAKE球员信息管理系统 ■\n");
	   cout<<("                                           ■■■■■■■■■■■■■\n");
       Pos(42,9);
	    cout<<"管理员:";
		Pos(49,9);
		cout<<"_______";
	   Pos(42,11);
	     cout<<"密 码 :";
	     cout<<"_______";
	     Pos(5,13);
		 cout<<"0--注册账号              1--游客                  2--登录               3--退出\n";
		 cout<<"操纵区:********************\n";
		  cout<<"选择入口:";
		  cin>>sign;
		  switch(sign)
		  {
		  	case 0:New_Manager();break;
			case 1:break;
		  	case 2:
			        if(Get_MG()==1)
			          Choose_Ent(); ;break;
		  	case 3:exit(0);break;
		   default: "数字不匹配入口.\n";
		  }
		  ch=getch();
		  if(ch=='+')  break;
		   system("cls");
}
}   */
