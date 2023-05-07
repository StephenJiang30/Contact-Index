#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
struct Sign{
		char name[8];
		char sex[4];
		char birthday[12];
		char phone[11];
		char postcode[7];
		char addr[30];
		struct Sign *next;
	}pe;  
	char PhoneCop[4] ;
 
//结构体 
struct Sign *p1,*p2,*head;
FILE *fp;
void ShowMenu(){
	system("color 0E");
	printf("                                                                    \n");
	printf("                           通讯录管理系统                           \n");
	printf("                   Address book management system\n");
	printf("                                                                    \n");
	printf("            1-----------------信息录入-------------------           \n");
	printf("                         Information input                          \n");
	printf("            2-----------------信息查询-------------------           \n");
	printf("                         Information query                          \n");
	printf("            3-----------------信息显示-------------------           \n");
	printf("                        Information display                         \n");
	printf("            4-----------------信息修改-------------------           \n");
	printf("                       Modify the information                       \n");
	printf("            5-----------------信息统计-------------------           \n");
	printf("                       Statistical information                      \n");
	printf("            6-----------------退出系统-------------------           \n");
	printf("                              Log out                               \n");
	printf("                                                                    \n");
    printf("             HUNAN INSTITUTE OF ENGINEERING     202101              \n");
	printf("                                                                    \n");
	printf("Please Input the Number You Need to Operate: ");
};
void HeadShow()
{
	printf("                           通讯录管理系统          \n");
	printf("---------------------------------------------------------------------\n");
 
} 
void FileLoading()
{
		if((fp=fopen("txl.dat","rb"))==NULL)
	{
		printf("文件操作错误，请检查是否有权限操作文件！");
		Sleep(3000);
		exit(1);
	}
	p1=(struct Sign*)malloc(sizeof(struct Sign)); 
	p1->next=NULL;
	head=p1;
	while(!feof(fp))
	{
		if(fread(p1,sizeof(struct Sign),1,fp)!=1)
			break;
		p2=(struct Sign*)malloc(sizeof(struct Sign));
		p2->next=NULL;
		p1->next=p2;
		p1=p2;
	}
	fclose(fp);
}
void add()
{	
	char ch; 
	if((fp==fopen("txl.dat","ab+"))!=1)
	{
		printf("文件打开失败");
		exit(1);
	}
	while(1)
	{	system("cls");
		printf("请输入__\n");
		p2=(struct Sign*)malloc(sizeof(struct Sign));
		p2->next=NULL; 
		printf("姓名：");scanf("%s",pe.name);
		printf("性别：");scanf("%s",pe.sex);
		printf("生日：");scanf("%s",pe.birthday);
		printf("电话号码：");scanf("%s",pe.phone);
		printf("邮编：");scanf("%s",pe.postcode);
		printf("地址：");scanf("%s",pe.addr);
		strcpy(p1->name,pe.name);
		strcpy(p1->sex,pe.sex);
		strcpy(p1->birthday,pe.birthday);
		strcpy(p1->phone,pe.phone);
		strcpy(p1->postcode,pe.postcode);
		strcpy(p1->addr,pe.addr);
		p1->next=p2;
		p1=p2;        
		if(fwrite(&pe,sizeof(struct Sign),1,fp)!=1)
			printf("写入错误");
		printf("输入E或e来结束输入？");
		getchar();
		ch=getchar();
		if(ch=='e'||ch=='E')
			break;
 
	}
	fclose(fp);
}
void SaveChange()
{	
	if((fp==fopen("txl.dat","w"))!=1)
	{
		printf("文件打开失败");
		exit(1);
	}
	p1=head;
	while(p1->next!=NULL)
	{
		if(fwrite(p1,sizeof(struct Sign),1,fp)!=1)
			printf("写入错误");
		p1=p1->next;
		
	} 
	fclose(fp);
}
void AllShow()
{
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","姓名","性别","生日","电话","邮编","地址");	
	printf("*********************************************************************\n");
	p1=head;
	while(p1->next!=NULL)
	{
		printf("%10.8s %6.6s %10.12s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		p1=p1->next;
		
	} 
	
}
 
void AllNum()
{	int i=0; 
	HeadShow();
	printf("          共有记录条数为：    \n");	
	printf("---------------------------------------------------------------------\n");
	p1=head;
		while(p1->next!=NULL)
	{
		i++;
		p1=p1->next;
		
	} 
	printf("          %d                  \n",i);
	printf("---------------------------------------------------------------------\n");
	
	printf("          共有联通用户为：    \n");	
	printf("---------------------------------------------------------------------\n");
	p1=head;
	i=0;
		while(p1->next!=NULL)
	{
		strncpy(PhoneCop,p1->phone,3);
		if(strcmp(PhoneCop,"130")==0||strcmp(PhoneCop,"131")==0||strcmp(PhoneCop,"132")==0||strcmp(PhoneCop,"155")==0||strcmp(PhoneCop,"156")==0||strcmp(PhoneCop,"185")==0||strcmp(PhoneCop,"186")==0)
			i++;
		p1=p1->next;
		
	} 
	printf("          %d                  \n",i);
	printf("---------------------------------------------------------------------\n");
	printf("          共有移动用户为：    \n");	
	printf("---------------------------------------------------------------------\n");
	p1=head;
	i=0;
		while(p1->next!=NULL)
	{
		strncpy(PhoneCop,p1->phone,3);
		if(strcmp(PhoneCop,"134")==0||strcmp(PhoneCop,"135")==0||strcmp(PhoneCop,"136")==0||strcmp(PhoneCop,"137")==0||strcmp(PhoneCop,"138")==0||strcmp(PhoneCop,"139")==0||strcmp(PhoneCop,"150")==0||strcmp(PhoneCop,"151")==0||strcmp(PhoneCop,"152")==0||strcmp(PhoneCop,"157")==0||strcmp(PhoneCop,"158")==0||strcmp(PhoneCop,"159")==0||strcmp(PhoneCop,"187")==0||strcmp(PhoneCop,"188")==0||strcmp(PhoneCop,"147")==0)
			i++;
		p1=p1->next;
		
	} 
	printf("          %d                  \n",i);
	printf("---------------------------------------------------------------------\n");
		printf("          共有电信用户为：    \n");	
	printf("---------------------------------------------------------------------\n");
	p1=head;
	i=0;
		while(p1->next!=NULL)
	{
		strncpy(PhoneCop,p1->phone,3);
		if(strcmp(PhoneCop,"180")==0||strcmp(PhoneCop,"189")==0||strcmp(PhoneCop,"133")==0||strcmp(PhoneCop,"153")==0||strcmp(PhoneCop,"199")==0)
			i++;
		p1=p1->next;
		
	} 
	printf("          %d                  \n",i);
	printf("---------------------------------------------------------------------\n");
}
void CheckFace()
{	int Check_key; 
	printf("                      通讯录管理系统                        \n");
	printf("              Address book management system\n");
	printf("                                                          \n");
	printf("                 1------按姓名查询                        \n");
	printf("                        Query by name                     \n");
	printf("                 2------按电话号码查询                    \n");
	printf("                        Phone Number Enquiry              \n");
	printf("                 3------综合查询                          \n");
	printf("                        Integrated query                  \n");
	printf("                 4------退出查询模块                      \n");
	printf("                        Exit Query Module                 \n");
	printf("                                                          \n");
    printf("        HUNAN INSTITUTE OF ENGINEERING     202101         \n");
	printf("                                                          \n");
	printf("Please Input the Number You Need to Operate: ");
    
}
void Selelctname()
{	system("cls"); 
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","姓名","性别","生日","电话","邮编","地址");	
	printf("*********************************************************************\n");
	p1=head;
	char FindName[8];
	int i=0; 
	printf("请输入要查询的姓名：");
	scanf("%s",&FindName);
	while(p1->next!=NULL)
	{
		if(strcmp(p1->name,FindName)==0) 
		    {printf("%10.8s %6.6s %10.10s %11.14s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		    i++;
			}
		p1=p1->next;
		
	} 
	printf("共  %d  条\n",i);
	system("pause"); 
} 
 
void Selelctphone()
{	system("cls"); 
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","姓名","性别","生日","电话","邮编","地址");	
	printf("*********************************************************************\n");
	p1=head;
	char phone[11];
	int i=0; 
	printf("请输入要查询的电话号码：");
	scanf("%s",&phone);
	while(p1->next!=NULL)
	{
		if(strcmp(p1->phone,phone)==0) 
		    {printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		    i++;
			}
		p1=p1->next;
		
	} 
	printf("共  %d  条\n",i);
	system("pause"); 
} 
void Selelctall()
{	system("cls"); 
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","姓名","性别","生日","电话","邮编","地址");	
	printf("*********************************************************************\n");
	p1=head;
	char all[30];
	int i=0; 
	printf("请输入任意一项要查询的内容：");
	scanf("%s",&all);
	while(p1->next!=NULL)
	{
		if(strcmp(p1->name,all)==0||strcmp(p1->sex,all)==0||strcmp(p1->birthday,all)==0||strcmp(p1->phone,all)==0||strcmp(p1->postcode,all)==0||strcmp(p1->addr,all)==0) 
		    {printf("%10.8s %6.6s %10.10s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		    i++;
			}
		p1=p1->next;
		
	} 
	printf("共  %d  条\n",i);
	system("pause"); 
} 
void Change()
{	char ChangeName[8]; 
	int changekey;
	system("cls");
	HeadShow();
	int i,y=0;				
    p1=p2=head;		
	printf("请输入你要修改的对象的姓名：");
	scanf("%s",&ChangeName);
		getchar();	
	while(p1!=NULL)
	{	
	if(strcmp(p1->name,ChangeName)==0)	
	   {	printf("%10.8s %6.6s %10.10s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
			printf("您要修改的是这条记录吗？1-是||2-否\n");
			scanf("%d",&i);
			if(i==1)
			{ y=1;
			printf("你要修改的通讯录为:\n");
	   		printf("%10.8s %6.6s %10.10s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
        	printf("请选择您的操作      1-删除||2-修改\n");
        	scanf("%d",&changekey);	
        	if(changekey==1) 
       		 {
          		if(p1==head)		 
             	 {head=p1->next;	 
          		  free(p1);
			 	 }
				  else
            	 {
             	p2->next=p1->next;
                free(p1);	
		  		SaveChange();	
             	
             }
				
		} 
		else if(changekey==2)
		{
			printf("姓名:");scanf("%s",p1->name);
			printf("性别:");scanf("%s",p1->sex);
			printf("生日:");scanf("%s",p1->birthday);
			printf("电话:");scanf("%s",p1->phone);
			printf("邮编:");scanf("%s",p1->postcode);
			printf("地址:");scanf("%s",p1->addr);	
			SaveChange();
			printf("\n  OK!    \n");
		} 	
			}			
		
	   }
	else if(strcmp(p1->name,ChangeName)&&(p1->next)==NULL)
	   {
			i=0;			 
		
	   }
   		p2=p1;		
	    p1=p1->next;  
	}
 
     if(y==0)	
	{
        printf("对不起，没有找到要修改的通讯名单，请检查你要修改的姓名是否正确\n");
		printf("Sorry, we can't find the address list you want to change, please check whether the name you want to change is correct\n");
    }
    
	
	system("pause");
}
void ExirShow()
{
	system("color 0F");
 	printf("                      通讯录管理系统                      \n");
	printf("             Address book management system\n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                         谢谢使用！                       \n");
	printf("                          Tnanks!                         \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
    printf("          HUNAN INSTITUTE OF ENGINEERING     202101       \n");
	
}
void ErrorShow()
{   int errortime=3;
	system("color 4E");
	for(errortime=3;errortime>0;errortime--)
		{
       	 printf("\rTyping error! Please check carefully! Will return after %d seconds!",errortime);
		 Sleep(1000);
		}
	
}
int main()
{	int key;
	int Ex_key; 
	int Check_key;
	char a[10];
	if((fp=fopen("txl.dat","ab"))==NULL)
	{
		printf("文件操作错误，请检查是否有权限操作文件！");
		Sleep(3000);
		exit(1);
	}
	fclose(fp);	
	FileLoading();
	while(1){
	ShowMenu();
	gets(a);
	key=atoi(a);
	if(key==1)
	   {system("cls");
		add();
		}
	else if(key==2)
		{	system("cls");
			
			system("color 0E");
		while(1)
     		 {
			system("color 0E");  
			CheckFace();
     		printf("请输入你的选择:\n");
	  		gets(a);
	  		Check_key=atoi(a);
    		if(Check_key==1)
    			Selelctname()
    		;
    		else if(Check_key==2)
    			Selelctphone()
    		;
    		else if(Check_key==3)
    			Selelctall()
    		;
    		else if(Check_key==4)
    	
    		break;
    		else
    		ErrorShow();
			system("cls");
			system("color 1F");	
			getchar();
    		
    	} 	
		
		
		}
 	
 	else if(key==3)      
 	{	system("color 0E"); 
	 	system("cls"); 
	 	AllShow();
 		system("pause");
 	}
	else if(key==4)
		{
			system("color 0A"); 
			Change();
		
		
		} 
 	else if(key==5)
	 	{
 		system("color 5F"); 
	 	system("cls"); 
 		AllNum();
 		system("pause");
		 }
 	else if(key==6) 
	 	{
 		system("cls");
	 	ExirShow();	
	 	Sleep(1000);
		exit(0);
		}
 		
	else 
	
		ErrorShow();
		system("cls");
		system("color 1F");	
		getchar();
	}
 	
 
}

