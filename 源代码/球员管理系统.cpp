#include<string>
#include<string.h>
#include<iostream>
#include<fstream>
#include"person.h"
#include"team.h" 
#include"date.h"
#include"jiemian.h"
using namespace std;
/*typedef struct date{
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
	}Per; */
void Prin_Snake()//显示系统名称
{  cout<<"*****************************************************************************************************************\n\n\n\n";
	cout<<("                                           ■■■■■■■■■■■■■\n");
	cout<<("                                           ■SNAKE球员信息管理系统 ■\n");
	cout<<("                                           ■■■■■■■■■■■■■\n\n");
	
}

//**********************************************************************************
  void Set_Posit(Per &datePer)
{    char sign1,sign2;
	cout<<"位置:(1-PG-控卫 2-SG-得分后卫 3-C-中锋 4-SF-小前锋 5-PF-大前锋)\n";
	    cin>>sign1;
	  while(sign1>5)
	 {  cout<<"没有对应的位置,请重新输入.\n";
	   cin>>sign1;
     }
	  switch(sign1)
	   { case '1' :  strcpy(datePer.position ,"PG")  ;break;
		 case '2' :  strcpy(datePer.position ,"SG" ) ;break;
		 case '3' :  strcpy(datePer.position ,"C"  ) ;break;
		 case '4' :  strcpy(datePer.position ,"SF" ) ;break;
		 case '5' :  strcpy(datePer.position ,"PF")  ;break;
		 default:   break ;
	   }
	 cout<<"是否担当其他位置?\n";
		 cin>>sign2;
	  switch(sign2)
	   { case '1' :  if(sign1!=sign2) strcat(datePer.position,"/PG");break;
		 case '2' :  if(sign1!=sign2) strcat(datePer.position,"/SG") ;break;
		 case '3' :  if(sign1!=sign2) strcat(datePer.position ,"/C" ) ;break;
		 case '4' :  if(sign1!=sign2) strcat(datePer.position ,"/SF");break;
		 case '5' :  if(sign1!=sign2) strcat(datePer.position ,"/PF") ;break;
		 default:   break ;
	   }
}
//二.1显示进程*******************************************************************************************
person Best_date( person s[],int num)//数据王部分
{    int i,maxw;
	 float maxs,maxb,maxa,maxv;
      int sign0=0,sign1=0,sign2=0,sign3=0,sign4=0;
		maxs = s[0].Return_s();
		   maxb = s[0].Return_b() ;
		      maxa = s[0].Return_a();
		       maxw = s[0].Return_w();
	   if(num>1){
		for(i = 1;i<num;i++)
		{ if(maxs<s[i].Return_s())
	            {maxs = s[i].Return_s();
				                 sign0 = i;}
	                 if(maxb<s[i].Return_b())
	                  {maxb = s[i].Return_b();
					                 sign1 = i; }
	                    if(maxa<s[i].Return_a())
	                {maxa = s[i].Return_a();
					               sign2 = i;}
	            if(maxw<s[i].Return_w())
	              {maxw=s[i].Return_w();
	                               sign3 = i;}
	     if(maxv<s[i].Return_v())
	           { maxv = s[i].Return_v();
			                         sign4=i;}
        }
		}
	cout<<"===========球队数据王==========="<<endl;
	cout<<"*****得分王******"<<endl;
	cout<<"--最高分:"<<s[sign0].Return_s()<<endl;
	s[sign0].print();
	cout<<"*****篮板王******"<<endl;
	cout<<"--最高篮板:"<<s[sign1].Return_b()<<endl;
	s[sign1].print();
	 cout<<"*****助攻王******"<<endl;
	 cout<<"--最高助攻"<<s[sign2].Return_a()<<endl;
	s[sign2].print();
	cout<<"*****老将王******"<<endl;
	cout<<"--最长任职:"<<s[sign3].Return_w()<<endl;
	s[sign3].print();
	return s[sign0];
 }
 
void Out_Print(char name[])//显示部分
{  fstream file;
    int i = 0;
	Per datePer;
	person one;
	person s[10];
      file.open(name,ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
		file.read((char*)&datePer,sizeof(datePer));
		while(!file.eof())
		{
			s[i].Change_Per(datePer);//结构体向类的转
			 file.read((char*)&datePer,sizeof(datePer));
			 i++;
			 if (i>10)  break;//球员最多十五人
		}
	 file.close();
  int t;
     char ch,sign;
	  while(1){   system("cls");
	          	Prin_Snake();
	                 cout<<"               -----------------------------------显示进程------------------------------------------"<<endl;
	             cout<<"                                           1.简介显示 2.数据信息 3.全部信息 4.数据王"<<endl;
	             cout<<"请选择您要显示的类型:";
				 cin>>sign;
	       switch(sign)
	             { case '1' : for(t = 0;t<i;t++)
	                                     s[t].print();
							 s[i].Return_v();  break;//姓名+位置
	   	           case '2': for(t = 0;t<i;t++)
		                     cout<<s[t];   break;
	   	           case '3' :  for(t = 0;t<i;t++)
						    s[t].All_print();  break;
	   	           case '4' : one=Best_date(s,i); break;
	         	   default: cout<<"无法提供这种输出方式\n";break;
	   }
	  cout<<"是否结束显示Y/N:";
		cin>>ch;
		if(ch=='Y'||ch=='y')     break;
		system("cls");
   }
}
//*****************************************************************************************************************
void App_player(char name[])//二.2.1签约球员进程
{  fstream   file;
   Per  P;
   person one;
   system("cls");
   Prin_Snake();
   file.open(name,ios::app|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
		         cout<<"               -----------------------------------签约进程------------------------------------------"<<endl;
		         cin>>one;
		         P=one.Change_person();
		  file.write((char*)&P,sizeof(P));
  file.close();
}
///******************************************************************************************************************
void Fire_Play(char nam[])//二.2.2炒鱿鱼进程
{  fstream file;
   Per  dateP[15];
   char sign;
   int i = 0,count = 0 ;
   string name;
   system("cls");
   Prin_Snake();
   cout<<"               -----------------------------------裁员进程------------------------------------------"<<endl;
    file.open(nam,ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
	 file.read((char*)&dateP[i],sizeof(dateP[i]));
	 cout<<"请输入您要裁去的球员姓名:";
      cin>>name;
            while(!file.eof())
			{
			 if(name==dateP[i].name)  { cout<<"提示:该球员存在！！！"<<endl;
			                                  count = i;}//定位裁员的文件位置
	                 i++;
		    file.read((char*)&dateP[i],sizeof(dateP[i]));
			  if(i==15)    break;
			}
			cout<<"您当前的球队当前存在有"<<i<<"位球员"<<endl;
   file.close();
   int k = 0;
   	file.open(nam,ios::out|ios::binary);
		   file.write((char*)&dateP[k],sizeof(dateP[k]));
			while(k<i-1){  k++;
			               if(k!=count)
			                         file.write((char*)&dateP[k],sizeof(dateP[k]));
			                else  {  cout<<"请再次确认您是否要裁除此球员(Y/N)"<<endl;
			              	           cin>>sign;
			              	               if(sign!='Y'&&sign!='y')
											   {
											      cout<<"恭喜！取消裁员成功，祝愉快！！！"<<endl;
											      file.write((char*)&dateP[k],sizeof(dateP[k]));}
											else cout<<"裁除球员:"<<dateP[k].name<<"    成功！！！"<<endl;
							                  }
			              }
	 file.close();
   
}
//*******************************************************************************************************************
 void Mod_Player(char nam[])//二-3修改球员的特定信息
 { fstream file;
   int i=0;
   Per  dateP;
   string name;
   system("cls");
   Prin_Snake();
    file.open(nam,ios::in|ios::out|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
	 file.read((char*)&dateP,sizeof(dateP));
  cout<<"               -----------------------------------修改进程------------------------------------------"<<endl;
    cout<<"请输入您要修改的球员姓名:";
      cin>>name;
      while(!file.eof())
	   { if(name==dateP.name)
	      {    int sign;  char ch;
			   cout<<"该队员存在.\n";
	           cout<<"(0-姓名 1-出生日期 2-身高 3-体重 4-号码 5-位置 6-得分";
	            cout<<"7-篮板8-助攻 9-伤病 10-在职时间 11-身价)"<<endl;
            while(1)
			  {
   	                cout<<"请输入修改选项的数字:";
                     cin>>sign; 
   	            switch(sign)
			      { 	  
   	                 case 0 :  cout<<"********姓名:";	
   	                              cin>>dateP.name; break;             
   	                 case 1 :  cout<<"********(year-month-day)";
		                             cin>>dateP.birthday.y
		                                 >>dateP.birthday.m
		                                      >>dateP.birthday.d;  break;		        
   	                 case 2 :  cout<<"********身高:";
	                              cin>>dateP.height;  break;	            
   	                 case 3 :  cout<<"********体重:";
		   	                      cin>>dateP.weight; break;		   	    
   	                 case 4 :  cout<<"********号码:";	
	           	                  cin>>dateP.number; break;	         	
   	                 case 5 :  Set_Posit(dateP); break;		        
   	                 case 6 :  cout<<"********得分:";	
		                          cin>>dateP.score; break;
					 case 7 :  cout<<"********篮板:";	
		                          cin>>dateP.board; break;
					 case 8 :  cout<<"********助攻:";	
		                          cin>>dateP.assit; break;			  			  			  		        
	                 case 9 :   cout<<"********伤病:";	
		                           cin>>dateP.ill; break; 				  									   	
	                 case 10 :   cout<<"********在职时间:";
	                              cin>>dateP.wortime; break;
					 case 11 :  cout<<"********身价:";
	                              cin>>dateP.value; break;				  		
	           	     default: cout<<"该数字无法匹配到相关信息."<<endl; 
		           }
		        cout<<"是否继续修改,退出请按*键.";
		               cin>>ch;
		                 if(ch=='*')  break; 
	            }
			       break;			 
	         }   
	     else {
		        i++;
	         	file.read((char*)&dateP,sizeof(dateP));	  }
	   }
    file.close();
	file.open(nam,ios::out|ios::in|ios::binary);
				   file.seekp(i*sizeof(dateP),ios::beg);
			 	file.write((char*)&dateP,sizeof(dateP));
	 file.close();			   
  } 
//*****************************************************************************************************************
bool Search_Player(char name[])//二.4查找球员信息进程
{  fstream file;
	  int i = 0,ker;
	  bool KG=0;//布尔类型 开关用于判断是否查取到球员
	  char firstname[3];
	  Per dateP;
	  person Play;
	  string na,po,poon;
      file.open(name,ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
	  cout<<"请选择查找方式0--姓 1--姓名 2--号码 3--年龄 4--在职时间 5--位置:";
	   char sign;
	   cin>>sign;
	   file.read((char*)&dateP,sizeof(dateP));
	   switch(sign)
	   {
	   	case '0' :   cout<<"请输入球员的姓进行查找:";
		                         cin>>firstname; break;
	   	case '1' :    cout<<"请输入球员的姓名进行查找:";
		                         cin>>na; break;
	   	case '2' :	cout<<"请输入球员的号码进行查找:";
	   	                        cin>>ker;break;
	   	case '3' :	cout<<"请输入球员的年龄进行查找:";
	   	                  cin>>ker; break;
	   	case '4' :	cout<<"请输入球员的在职时间进行查找:";
	                           cin>>ker;break;
	    case '5' :     cout<<"请输入球员的位置进行查找(PG-SG-C-SF-PF-)";
								cin>>po; break;
	   	default:   cout<<"无法提供该查找项目"<<endl;break;
	   }
	   cout<<"搜索结果:"<<endl;
	while(!file.eof()){
	                    Play.Change_Per(dateP);
		if(sign=='0') { for(i = 0;i<strlen(firstname);i++)
		                if(firstname[i]!=dateP.name[i])
						 break;
                            if(i==strlen(firstname))
		                           {  cout<<Play<<endl;
								           KG=1;} }
	     else if(sign=='1'){ if(na==dateP.name)
		                        {cout<<Play<<endl;
										   KG=1;
			                                 break;} }
		   else if(sign=='2') { if(ker==dateP.number)
		                              {
									   cout<<Play<<endl;
											KG=1;
									           break;} }
	   	    else if(sign=='3'){ if(ker==dateP.age)
	   	                          {cout<<Play<<endl;
											KG=1;} }
			  else if(sign=='4'){  if(ker==dateP.wortime)
			                        {cout<<Play<<endl;
									         KG=1;}}
			 else if(sign=='5'){    poon=dateP.position;
			                       if(poon.find(po)==0||poon.find(po)==3)
										  {
										  cout<<Play<<endl;
			                                      KG=1; }}
			 file.read((char*)&dateP,sizeof(dateP));
		}
		if(KG!=true) {
		              cout<<"对不起！！！您查找的内容走丢了！！！\n";
		     return false;}
		else  return true;
	 file.close();
}
//****************************************************************************************************************************
void Wtite_Player(char name[])//二.5录入球队信息
 {
   fstream file;
     char sign, sign1,sign2;
     Per datePer;
     int i = 0;
     Prin_Snake();
     cout<<"请再次确认是否清空.\n";
     cin>>sign;
     if(sign!='y'&&sign!='Y')   return;
	  file.open(name,ios::out|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
  cout<<"               -----------------------------------清空录入进程------------------------------------------"<<endl;
	 cout<<"请在提示下录入球员的个人信息."<<endl;
	 cout<<"系统提示:球员人数上限为15人"<<endl;
	 cout<<"---------------------------------------------------"<<endl;
   while(1)
    { cout<<"球员"<<i+1<<endl;
	   cout<<"-------姓名-------$";
	       cin>>datePer.name;
	   cout<<"-------身高-------$";
	       cin>>datePer.height;
       cout<<"-------出生日期(year-month-day)-------$";
		   cin>>datePer.birthday.y
		       >>datePer.birthday.m
		        >>datePer.birthday.d;
       cout<<"-------体重-------$";
		   cin>>datePer.weight;
		   cout<<"位置:(1-PG-控卫 2-SG-得分后卫 3-C-中锋 4-SF-小前锋 5-PF-大前锋)\n";
	    cin>>sign1;
	  while(sign1>53)
	    {  cout<<"没有对应的位置,请重新输入.\n";
	       cin>>sign1;
           }
	  switch(sign1)
	       {
		    case '1' :  strcpy(datePer.position ,"PG")  ;break;
		    case '2' :  strcpy(datePer.position ,"SG" ) ;break;
		    case '3' :  strcpy(datePer.position ,"C"  ) ;break;
		    case '4' :  strcpy(datePer.position ,"SF" ) ;break;
		    case '5' :  strcpy(datePer.position ,"PF")  ;break;
		   default:   break ;
	       }
	 cout<<"是否担当其他位置?\n";
		 cin>>sign2;
	  switch(sign2)
	       {
		     case '1' :  if(sign1!=sign2) strcat(datePer.position,"/PG");break;
		    case '2' :  if(sign1!=sign2) strcat(datePer.position,"/SG") ;break;
		    case '3' :  if(sign1!=sign2) strcat(datePer.position ,"/C" ) ;break;
		    case '4' :  if(sign1!=sign2) strcat(datePer.position ,"/SF");break;
		    case '5' :  if(sign1!=sign2) strcat(datePer.position ,"/PF") ;break;
		    default:   break ;
	      }
	   cout<<"-------号码-------$";
		 cin>>datePer.number;
	   cout<<"-------在职时间-------$";
		  cin>>datePer.wortime;
	   cout<<"-------得分-------$";
		 cin>>datePer.score;
	   cout<<"-------篮板-------$";
		  cin>>datePer.board;
	   cout<<"-------助攻-------$";
		  cin>>datePer.assit;
	   cout<<"-------伤病-------$";
		  cin>>datePer.ill;
	   cout<<"-------身价-------$";
	      cin>>datePer.value;
 	  file.write((char*)&datePer,sizeof(datePer));
			i++;
			if(i%2==0)  system("cls");
	cout<<"提示:是否结束新建球员信息,您已新建"<<i<<"个球员的信息('Y'键--YES,others--NO)"<<endl;
     sign=getch();
     cout<"\n";
	 if(sign=='y'||sign=='Y')   break;
     }
     file.close();
}
//***************************************************************************************************************************
void DetleCom(int k)//二.6建议墙进程
{
	fstream file,infile;
    char   str[81] ;
    int i=0,len;
	 file.open("comment.txt",ios::out);
	  if(file.fail()){
	  	           cout<<"打开失败comment.txt"<<endl;
	  	           exit(0);
	               }
	  infile.open("com.txt",ios::in);
	  if(infile.fail()){
	  	cout<<"打开失败com.txt"<<endl;
	  	exit(0);
	   }
	  infile.getline(str,81,'\n');
	  while(!infile.eof())
	    {
	  	  while(1)
	    	{    len = strlen(str);
		       if(str[len-1]!='+'&&str[len]=='\0')
				{   if(i!=k) file<<str;
				      infile.getline(str,81,'\n');}
	            else if(str[len-1]=='+'&&str[len]=='\0')
		           {    if(i!=k) {
				               file<<str;
							  file.put('\n');}
				         break;
					}
	             }
	           infile.getline(str,81,'\n');
	        i++;
        }
    file.close();
    infile.close();
         infile.open("com.txt",ios::out);
           if(infile.fail()){
	  	                     cout<<"打开失败com.txt"<<endl;
	  	                     exit(0);
	                         }
         file.open("comment.txt",ios::in);
                if(file.fail()){
	  	                          cout<<"打开失败comment.txt"<<endl;
	  	                      exit(0);
	                         }
  file.getline(str,81,'\n');
	  while(!file.eof())
	  {     infile<<str;
			infile.put('\n');
			file.getline(str,81,'\n');
			  }
	file.close();
   infile.close();
}
//*********************************************************************
void Comment()
{   fstream file;
    char   str[81] ;
    int i=0,len;
	 file.open("comment.txt",ios::in);
	  if(file.fail()){
	  	      cout<<"打开失败"<<endl;
	  	exit(0);}
	Prin_Snake();
	cout<<"	                                 WELCOME   SNAKE   COMMENT  BORAD                         "<<endl;
	cout<<"\n---------------------------------------------------------------------------------------------\n";
	file.getline(str,81,'\n');
	len = strlen(str);
	  while(!file.eof())
	    {
	  	cout<<"匿名"<<i<<":";
	  	while(1)
	    	{    len = strlen(str);
		       if(str[len-1]!='+'&&str[len]=='\0')
				{  cout<<str<<endl;
				      file.getline(str,81,'\n');}
	          else if(str[len-1]=='+'&&str[len]=='\0')
		       {      str[len-1]='\0';
			       cout<<str<<endl;
				       break;
					}
	         }
	       file.getline(str,81,'\n');
	       i++;
        }
        file.close();
        char sign;
        int t;
        cout<<"---------------------------------------------------------------------------------------------"<<endl;
        cout<<"系统提示:您当前是管理员身份,有修改评论的权限！！！\n";
        cout<<"请选择修改模式0----清空 1----删除某一建议 2----不修改\n";
        cin>>sign;
        switch(sign)
		{
		 case '0' :file.open("comment.txt",ios::out);
		                         if(file.fail())
								 cout<<"打开失败"<<endl;
								 file.close();
					file.open("com.txt",ios::out);
		                         if(file.fail())
								 cout<<"打开失败"<<endl;
								 file.close();
								 cout<<"系统提示:建议/评论已经清空!!!"<<endl;break;
		 case '1' :cout<<"请选择要删除第几个评论\n";
		                           cin>>t; DetleCom(t);break;
		 case '2' : break;
		 default:  break;
		}
	file.close();
}
//****************************************************************************************************************************
void  Uers_Note()//二.7使用说明进程
{ fstream file;
char ch;
      Prin_Snake();
      cout<<"               -----------------------------------使用说明进程------------------------------------------"<<endl;
	 file.open("Uer_note.txt",ios::in);
	  if(file.fail()){
	  	             cout<<"打开失败"<<endl;
	  	                  exit(0);}
		  ch=file.get();
	  while(!file.eof())
	    {
	  	 cout<<ch;
          ch=file.get();
	  }
   file.close();
}
//*******************************************************************************************************************************
void DC_Uers(Uers one)//二.8修改密码/注销账号
{   int i = 0,count = 0 ,num=0,t=0;
    char sign,ch;
    Uers  two[10];
	char pass[7], NewPass[7];
    string Test1,Test2,Na1,Na2;
    fstream file;
    Prin_Snake();
    file.open("manager.dat",ios::in|ios::binary);
    if(file.fail()){
        	             cout<<"打开manager.dat失败\n";
    	                     return;}
	       Test1=one.password;
	       Na1=one.manager;
		file.read((char*)&two[count],sizeof(two[count]));
		while(!file.eof())
		{
			Test2=two[count].password;
			Na2=two[count].manager;
			if(Test1==Test2&&Na1==Na2)
					   num=count;
					   count++;
					   if(count==7) break;
			file.read((char*)&two[count],sizeof(two[count]));
	   }
	 file.close();
 cout<<"               -----------------------------------修改或注销进程------------------------------------------"<<endl;
	 cout<<"请输入您要选择的模式(0-修改/1-注销):";
	   cin>>sign;
if(sign=='0')
	{ while(1)
          {  file.open("manager.dat",ios::out|ios::in|ios::binary);
	              if(file.fail()){	cout<<"打开manager.dat失败\n";
    	                   return;
	                }
		  cout<<"当前账号:"<<one.manager<<endl;
		  cout<<"请输入您的原始密码:";
	          i=0;
                               while(i<7)
	                             {  ch = getch();
                                      if(ch==8)
									    {  if(i==0)   continue;
	                                        cout<<'\b'<<" "<<'\b';
	                                                 i--;
	                                                  }
                                      else   {  if(i==6) break;
			                                          pass[i] = ch;
     	                                         cout<<"*";
     	                                      i++;
	                                        }
	                               }
	         pass[6]='\0';
	         cout<<"\n";
	         Test1 = pass;
	         Test2= one.password;
		     if(Test1==Test2)
	                     {
						 cout<<"原始密码正确"<<endl;
						       break; }
		    else { cout<<"输入密码错误,您还有"<<2-t<<"次机会,请重新输入."<<endl;
			      t++;}
			if (t==2) { cout<<"三次输错密码"<<endl;
				          return ;}
	      }
	     i = 0;
	    cout<<"\n请输入您的新密码:";
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
						              one.password[i] = ch;
     	                                  cout<<"*";
     	                                      i++;
	                                          }
	                            }
	   one.password[6]='\0';
	    Test1 = one.password;
		    while(1)
                {cout<<"\n请再次确认您的密码:";
	                               i=0;
                                  while(i<7)
	                                {  ch = getch();
                                        if(ch==8)
										{ if(i==0)   continue;
	                                      cout<<'\b'<<" "<<'\b';
	                                         i--;}
                                        else    {  if(i==6) break;
			                                      pass[i] = ch;
     	                                            cout<<"*";
     	                                             i++;
	                                               }
	                                }
	                                
	                 pass[6]='\0';
	                 Test2=pass;
	              if(Test1==Test2)   {
				                        file.seekp(num*sizeof(one),ios::beg);
			                        file.write((char*)&one,sizeof(one));
	                                 cout<<"\n修改密码成功!"<<endl;
	                              break;
	                               }
	           else            cout<<"\n两次输入的密码不一致,请重新设置"<<endl;
	           }
	   file.close();
	   }
   else if(sign=='1')
   { cout<<"系统提示:注销账号将包括注销账号以及账号对应的球队信息也将删除！！！"<<endl;
	 cout<<"！！！请谨慎操作,并且注销功能不支持撤销！！！"<<endl;
    while(1)
          {   cout<<"请输入您的原始密码:";
	          i=0;
                               while(i<7)
	                             {  ch = getch();
                                      if(ch==8)
									    {  if(i==0)   continue;
	                                        cout<<'\b'<<" "<<'\b';
	                                                 i--;
	                                                  }
                                      else   {  if(i==6) break;
			                                          pass[i] = ch;
     	                                         cout<<"*";
     	                                      i++;
	                                        }
								   }
	         pass[6]='\0';
	         cout<<"\n";
	         Test1 = pass;
	         Test2= one.password;
		     if(Test1==Test2)
	                     {
						 cout<<"原始密码正确~~~"<<endl;
						       break; }
		    else { cout<<"\n输入密码错误,您还有"<<2-t<<"次机会,请重新输入."<<endl;
			      t++;}
			if (t==2) { cout<<"三次输错密码!!!"<<endl;
				          return ;}
	      }
    file.open("manager.dat",ios::out|ios::binary);
	 if(file.fail()){	cout<<"打开manager.dat失败\n";
    	                   return;
	                }
	       cout<<"请再次确定是否注销账号(Y/N):";
			cin>>sign;
			if(sign=='y'||sign=='Y')
	        {int k=0;
				 cout<<"count"<<count<<num;
				 
	                for(k=0;k<count;k++)
				     {  if(k!=num)
				        {
						   file.write((char*)&two[k],sizeof(two[k])); }
					   }
				 file.close();
               cout<<"系统提示:您已注销账号以及相关的球队信息,感谢您的使用！！！"<<endl;
               exit(0);
			 }
            else   {cout<<"不注销账号."<<endl;
                                    return;}

   }
  else cout<<"系统提示:没有这种模式.\n";

}
//--------------------------------------------------------------------------------------------
 void Read_Club()//一.1球队战绩总榜
{ fstream file;
	Uers dateT;
	int i = 0,k,j;
	team t,Te[10];//十支球队的对象数组
	Prin_Snake();
   cout<<"               -----------------------------------球队战绩总榜------------------------------------------"<<endl;
      file.open("manager.dat",ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
		 	          exit(0);
		         }
		file.read((char*)&dateT,sizeof(dateT));
		while(!file.eof())
		{
		   Te[i].Team_Change(dateT.team);
		      i++;
		   file.read((char*)&dateT,sizeof(dateT));
		}
	   file.close();
	cout<<"目前共有球队"<<i<<"支"<<endl;
	  for(j=0;j<i;j++)
	  Te[j].Print();
}
//*******************************************************************************************
void Print_T()//一.3显示某支球队信息
{  fstream file;
   Uers man[10];
   int i=0,k,sign;
   char name[12];
 cout<<"               -----------------------------------显示特定球队进程------------------------------------------"<<endl;
      file.open("manager.dat",ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
	file.read((char*)&man[i],sizeof(man[i]));
	 while(!file.eof())
		{     i++;
		   file.read((char*)&man[i],sizeof(man[i]));
		  }
		file.close();
	for(k=0;k<i;k++)
		cout<<"("<<k<<")"<<man[k].team.ClubName<<"俱乐部--";
		cout<<"请选择打印显示的球队的标号:";
		cin>>sign;//这步回来改成char类型的
		if(sign>=i){cout<<"对不起,显然不存在这支球队."<<endl;
					 return;
             		}
             		
		 else { strcpy(name,man[sign].team.ClubName);
		 	           strcat(name,".dat");
			    Out_Print(name);
			   }
	}
//********************************************************************************************
void SS_player()//一.4查找某个球员信息
{ fstream file;
  char name[12],firstname[3];
  string na,po,poon;
  int  i=0,k,ker,j=0;
  Per dateP;
  person Play;
  Uers man[7];
  char sign;
  bool kg;
  system("cls");
  Prin_Snake();
   cout<<"               -----------------------------------全局查找某球员进程------------------------------------------"<<endl;
      file.open("manager.dat",ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
		file.read((char*)&man[0],sizeof(man[0]));
	while(!file.eof())
		   {      i++;
				  cout<<i;
		        file.read((char*)&man[i],sizeof(man[i]));
		   }
	file.close();
	cout<<"请选择查找方式0--姓 1--姓名 2--号码 3--年龄 4--在职时间 5--位置:";
	   cin>>sign;
	   switch(sign)
	   {
	   	case '0' :   cout<<"请输入球员的姓进行查找:";
		                         cin>>firstname; break;
	   	case '1' :    cout<<"请输入球员的姓名进行查找:";
		                         cin>>na; break;
	   	case '2' :	cout<<"请输入球员的号码进行查找:";
	   	                        cin>>ker;break;
	   	case '3' :	cout<<"请输入球员的年龄进行查找:";
	   	                  cin>>ker; break;
	   	case '4' :	cout<<"请输入球员的在职时间进行查找:";
	                           cin>>ker;break;
	    case '5' :     cout<<"请输入球员的位置进行查找(PG-SG-C-SF-PF-)";
								cin>>po; break;
	   	default:   cout<<"无法提供该查找项目"<<endl;break;
	   }
	   
    for(k=0;k<i;k++)
	 {      kg=0;
		   strcpy(name,man[k].team.ClubName);
		 	strcat(name,".dat");
			file.open(name,ios::in|ios::binary);
          if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
		  file.read((char*)&dateP,sizeof(dateP));
	   while(!file.eof())
	   {
	                     Play.Change_Per(dateP);
		if(sign=='0') { for(j = 0;j<strlen(firstname);j++)
		                if(firstname[j]!=dateP.name[j])
								break;
                            if(j==strlen(firstname))
		                           {  cout<<Play<<endl;
								        kg = true;
								              break;}}
	     else if(sign=='1')  { if(na==dateP.name)
		                        {  cout<<Play<<endl;
								        kg = true;
										     break;}}
		   else if(sign=='2') { if(ker==dateP.number)
		                              {cout<<Play<<endl;
									         kg = true;
									            break;} }
	   	    else if(sign=='3'){ if(ker==dateP.age)
	   	                          {  cout<<Play<<endl;
									    kg = true;
									          break; }}
			  else if(sign=='4'){  if(ker==dateP.wortime)
			                        {   cout<<Play<<endl;
									     kg = true;
									           break;}}
			 else if(sign=='5'){    poon=dateP.position;
			                       if(poon.find(po)==0||poon.find(po)==3)
										 {  cout<<Play<<endl;
										         kg = true;
										               break;}}
			 file.read((char*)&dateP,sizeof(dateP));
		}
	 file.close();
	   if(kg==true)
			  	 cout<<dateP.name<<"在"<<man[k].team.ClubName<<"球队中"<<endl;
	}
}
//*********************************************************************************************
  void Read_Talk()////一.5建议区写入    打印建议
{
 fstream infile;
   char str[81];
   int len;
   system("cls") ;
   Prin_Snake();
   cout<<"               -----------------------------------建议区------------------------------------------"<<endl;
 	infile.open("comment.txt",ios::in);
	   if(infile.fail())
	     {  cout<<"打开评论文件失败\n";
			  exit(0);
	       }
	infile.getline(str,81,'\n');
	  len = strlen(str);
	  while(!infile.eof())
	   {  cout<<"匿名"<<rand()<<":";
	      while(1)
	    	{    len = strlen(str);
		       if(str[len-1]!='+'&&str[len]=='\0')
				  {  cout<<str<<endl;
				      infile.getline(str,81,'\n');}
	           else if(str[len-1]=='+'&&str[len]=='\0')
		           {    str[len-1]='\0';
			             cout<<str<<endl;
				       break;}
	         }
	         infile.getline(str,81,'\n');
        }
}

  void Write_Talk()
{ fstream outfile,infile;
   char ch;
 	outfile.open("comment.txt",ios::out|ios::app);
 	infile.open("com.txt",ios::out|ios::app);
	 if(outfile.fail())
	    {  cout<<"打开评论文件失败\n";
			  exit(0);
	     }
	if(infile.fail())
	    {  cout<<"打开评论文件失败\n";
			  exit(0);
	     }
	  cout<<"\n=========请输入建议/评论内容('+'结束)=========="<<endl;
	   cin.get(ch);
	  while(1)
	  {
   	     cin.get(ch);
	  	    if(ch=='+')  {  outfile.put('+');
							 infile.put('+');
							 cout<<"写入成功"<<endl;
		                      break;}
	    	else         {  outfile.put(ch);
       }                        infile.put(ch);}
     outfile.put('\n');
     infile.put('\n');
 	outfile.close();
 	infile.close();
}
//*******************************************************************************************
void Write_Team(char name[])// 写入俱乐部的信息
{ fstream file;
     Club dateT;
      file.open(name,ios::out|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
	cout<<"俱乐部:";
    cin>>dateT.ClubName;
      cout<<"教练:";
       cin>>dateT.Coach;
        cout<<"战绩:(胜--负)";
          cin>>dateT.win_count>>dateT.fail_count;
	file.write((char*)&dateT,sizeof(dateT));
	cout<<"创建球队成功."<<endl;
	file.close();
}
//**********************************************************************************************
char* Read_Team(char name[],team &s)// 读取俱乐部的信息,返回俱乐部的名字用于创建球队球员信息文件
{ fstream file;
	  Club dateT;
	  char *p;
	  p=&dateT.ClubName[0];
      file.open(name,ios::in|ios::binary);
        if(file.fail())
		        {  cout<<"打开文件失败.";
			          exit(0);
		         }
		file.read((char*)&dateT,sizeof(dateT));
	  	s.Team_Change(dateT);
		  file.close();
		  return p;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void Scan()//一.浏览入口
{ char na[12]="GSW.dat";
  char ch,ker,sign;
  int i = 5;
	while(1){
     system("cls");
	cout<<"*****************************************************************************************************************\n\n\n\n";
	cout<<("                                           ■■■■■■■■■■■■■\n");
	cout<<("                                           ■SNAKE球员信息管理系统 ■\n");
	cout<<("                                           ■■■■■■■■■■■■■\n\n\n\n");
	cout<<"                                              ******主菜单******"<<endl;
	cout<<"                                        *******************************"<<endl;
	cout<<"                                              1.战绩总榜"<<endl;
	cout<<"                                              2.显示某支球队"<<endl;
	cout<<"                                              3.查找某个球员信息"<<endl;
	cout<<"                                              4.建议区"<<endl;
	cout<<"                                              0.退出"<<endl;
	cout<<"请输入选择的模式:";
	cin>>sign;
  switch(sign)
  {
  	case '1' : system("cls");
	                 Read_Club();
	                 break;
	case '2' : Print_T();break;
	case '3' : SS_player();break;
	case '4':Read_Talk();
	            cout<<"是否提出您宝贵的意见:(Y/N)";
	            cin>>ker;
	            if(ker=='Y'||ker=='y')
				         {Write_Talk();
										system("cls");
										 Read_Talk();
										 break;}
				else break;
	case '0' :  cout<<"\n退出成功！！！\n";
	               while(1){
						   Pos(19,26);
                            cout<<"提示:将在0"<<i<<"s后返回主界面.......";
		                            Sleep(950);
		                                i--;
		                                    if(i==0)    break;}
											   return;
	default:    cout<<"数字入口不匹配"<<endl; break;
  }
	 cout<<"\n请按任意键,返回上一层......."<<endl;
     ch=getch();
		  if(ch=='+')  break;
}

}
//-----------------------------------------------------------------------------------------------------------------------------------------
void DL_Ent(Uers man)//二.登录主界面
{   char filename[12];
	  int i=5;
	  bool kg;
	  strcpy(filename,man.team.ClubName);
	  strcat(filename,".dat");
  char ch,ker,sign;
	while(1){
     system("cls");
	cout<<"*****************************************************************************************************************\n";
	cout<<"管理员:"<<man.manager<<"--"<<man.team.ClubName<<endl;
	cout<<"\n\n";
	cout<<("                                           ■■■■■■■■■■■■■\n");
	cout<<("                                           ■SNAKE球员信息管理系统 ■\n");
	cout<<("                                           ■■■■■■■■■■■■■\n\n\n\n");
	cout<<"                                              ******主菜单******"<<endl;
	cout<<"                                        *******************************"<<endl;
	cout<<"                                              1.显示球队信息"<<endl;//多种显示
	cout<<"                                              2.签约/裁除球员"<<endl;
	cout<<"                                              3.修改球员信息"<<endl;
	cout<<"                                              4.查找球员"<<endl;//多种指令查找
	cout<<"                                              5.清空/初始化"<<endl;
	cout<<"                                              6.建议区"<<endl;
	cout<<"                                              7.使用说明书"<<endl;
	cout<<"                                              8.修改密码/注销账号"<<endl;
	cout<<"                                              0.退出登录"<<endl;
	cout<<"请输入选择的模式:";
	cin>>sign;
  switch(sign)
  {
  	case '1' : system("cls");
	                 Out_Print(filename);break;
	case '2' :  cout<<"请选择1.签约球员/2.裁除球员:";
				  cin>>ker;
	            if(ker=='1'){
	                          App_player(filename);
			                           break;}
			  else  if(ker=='2') {
			                       Fire_Play(filename);
			                          break;}
			   else {cout<<"不是1/2,无法提供\n"; break;}
	case '3' : Mod_Player(filename);break;
	case '4':while(1){ 	  system("cls") ;
						  Prin_Snake();
					 cout<<"               -----------------------------------模糊查找进程------------------------------------------"<<endl;
	                 kg=Search_Player(filename);
	                 if(kg==false) cout<<"查无此球员"<<endl;
	                 cout<<"是否结束查找Y/N";
	                   cin>>ker;
	                  if(ker=='y'||ker=='Y')
	                    break;
					  }         break;
	case '5' :system("cls");
	                Wtite_Player(filename);break;
	case '6' : system("cls");
	                       Comment();    break;
	case '7' : system("cls");
	                      Uers_Note();  break;
	case '8' : system("cls");
	                      DC_Uers(man);break;
	case '0' :  cout<<"\n退出登录成功\n";
	while(1){
						   Pos(19,26);
                            cout<<"系统提示:您将在0"<<i<<"s后退出登录界面.......";
		                            Sleep(950);
		                                i--;
		                                    if(i==0)   break;}
				                       return;
	default:    cout<<"数字入口不匹配\n";break;
  }
  cout<<"\n请按任意键,返回上一层......."<<endl;
  ch=getch();
		  if(ch=='+')  break;
}
}
//-----------------------------------------------------------------------------------------------------------------------------------------
Uers Creat_Uers()//零.注册管理员
{    Uers one;
	 fstream file;
     int i=5;
	 char sign;
	 char filename[12];
    system("cls");
	cout<<"*****************************************************************************************************************\n\n\n\n";
	cout<<("                                           ■■■■■■■■■■■■■\n");
	cout<<("                                           ■SNAKE球员信息管理系统 ■\n");
	cout<<("                                           ■■■■■■■■■■■■■\n\n\n");
	cout<<"\n                                         WELCOME TO SNKAE SYSTEM!!!!!!"<<endl;
	cout<<"                                                 《 服务条款 》\n";
	cout<<"                             ---------------------------------------------------------"<<endl;
	cout<<"                             1.您能且仅能使用创建的账户登录,仅对您的球队有效"<<endl;
	cout<<"                             2.球队包括队名简称,教练,胜负场次,球员不少于5人不多于10人"<<endl;
	cout<<"                             3.此系统可以对球迷意见进行审核/删除"<<endl;
	cout<<"                             4.更多使用说明请在注册完成后,于登录界面的选项6详细见解"<<endl;
	cout<<"                             5.账号长度不超过9个字符，密码长度为6个字符，支持数字/字母/符号"<<endl;
	cout<<"                             6.希望系统能帮组您更好的组织球员的数据,合理的安排阵容"<<endl;
	cout<<"                             ---------------------------------------------------------"<<endl;
	cout<<"请仔细阅读,是否同意(Y/N)";
	cin>>sign;
	if(sign!='Y'&&sign!='y')  { cout<<"不同意,自动退出,谢谢！！！走好不送！！！！"<<endl;
	exit(0); }
	system("cls");
	cout<<"*****************************************************************************************************************\n\n\n\n";
	cout<<("                                           ■■■■■■■■■■■■■\n");
	cout<<("                                           ■SNAKE球员信息管理系统 ■\n");
	cout<<("                                           ■■■■■■■■■■■■■\n\n\n\n");
	cout<<"                             ***********************注册模式*********************"<<endl;
	one=New_Manager();
     cout<<"您可选择当前录入球队/球员信息/也可稍后重新创建."<<endl;
     cout<<"请选择是否当前创建(Y/N):";
     cin>>sign;
      if(sign=='Y'||sign=='y')
	                { strcpy(filename,one.team.ClubName);
			                       strcat(filename,".dat");
			                       system("cls");
	                             Wtite_Player(filename);
								 }
	   else   { cout<<"由于您未初始化球队和球员的信息,登陆后的众多功能将无法使用"<<endl;
				cout<<"请在登录后完成初始化."<<endl;
				strcpy(filename,one.team.ClubName);
			                       strcat(filename,".dat");
                   file.open(filename,ios::out|ios::binary);
					if(file.fail()) {
					                   cout<<"创建球队文件失败"<<endl;
                                                 return one;}
					 file.close();
					  while(1){
						   Pos(19,26);
                            cout<<"提示:将在0"<<i<<"s后跳转登录界面.......";
		                            Sleep(950);
		                                i--;
		                                    if(i==0)    break;}
	              }

			 DL_Ent(one);//新注册账号直接跳转登录
	return one;
 }
//-----------------------------------------------------------------------------------------------------------------------------------------
int main()
{   Uers   man;
    team M;
    Date m,n;
    person st[10];//对象数组
	system("title SNAKE球员管理系统");
	    system("mode con cols=114 lines=50");
    while(1){  char ch,sign;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	   cout<<"******************************************************************************************************************\n\n\n";
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
		 cout<<"0--注册账号              1--浏览者                    2--登录                   3--退出\n";
		 cout<<"操纵区:-----------------------------------------------------------------------------------\n";
		  cout<<"选择入口:";
		  cin>>sign;
		  switch(sign)
		  {
		  	case '0':man=Creat_Uers();break;
			case '1':Scan();break;
		  	case '2':
			        man=Get_MG();
					 cout<<man.manager<<man.team.ClubName;
			        if(man.manager[0]=='0')  ;// break;
			         else  {DL_Ent(man);
					               break; }
		  	case '3':exit(0);break;
		   default: cout<<"数字不匹配入口.\n";break;
		  }
		  if(sign!='2'&&sign!='0'&&sign!='1') {
   cout<<"请按任意键,返回上一层"<<endl;
		  ch=getch();
		  if(ch=='+')  break;}
		   system("cls");
   }
}

