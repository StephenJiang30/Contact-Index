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
 
//�ṹ�� 
struct Sign *p1,*p2,*head;
FILE *fp;
void ShowMenu(){
	system("color 0E");
	printf("                                                                    \n");
	printf("                           ͨѶ¼����ϵͳ                           \n");
	printf("                   Address book management system\n");
	printf("                                                                    \n");
	printf("            1-----------------��Ϣ¼��-------------------           \n");
	printf("                         Information input                          \n");
	printf("            2-----------------��Ϣ��ѯ-------------------           \n");
	printf("                         Information query                          \n");
	printf("            3-----------------��Ϣ��ʾ-------------------           \n");
	printf("                        Information display                         \n");
	printf("            4-----------------��Ϣ�޸�-------------------           \n");
	printf("                       Modify the information                       \n");
	printf("            5-----------------��Ϣͳ��-------------------           \n");
	printf("                       Statistical information                      \n");
	printf("            6-----------------�˳�ϵͳ-------------------           \n");
	printf("                              Log out                               \n");
	printf("                                                                    \n");
    printf("             HUNAN INSTITUTE OF ENGINEERING     202101              \n");
	printf("                                                                    \n");
	printf("Please Input the Number You Need to Operate: ");
};
void HeadShow()
{
	printf("                           ͨѶ¼����ϵͳ          \n");
	printf("---------------------------------------------------------------------\n");
 
} 
void FileLoading()
{
		if((fp=fopen("txl.dat","rb"))==NULL)
	{
		printf("�ļ��������������Ƿ���Ȩ�޲����ļ���");
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
		printf("�ļ���ʧ��");
		exit(1);
	}
	while(1)
	{	system("cls");
		printf("������__\n");
		p2=(struct Sign*)malloc(sizeof(struct Sign));
		p2->next=NULL; 
		printf("������");scanf("%s",pe.name);
		printf("�Ա�");scanf("%s",pe.sex);
		printf("���գ�");scanf("%s",pe.birthday);
		printf("�绰���룺");scanf("%s",pe.phone);
		printf("�ʱࣺ");scanf("%s",pe.postcode);
		printf("��ַ��");scanf("%s",pe.addr);
		strcpy(p1->name,pe.name);
		strcpy(p1->sex,pe.sex);
		strcpy(p1->birthday,pe.birthday);
		strcpy(p1->phone,pe.phone);
		strcpy(p1->postcode,pe.postcode);
		strcpy(p1->addr,pe.addr);
		p1->next=p2;
		p1=p2;        
		if(fwrite(&pe,sizeof(struct Sign),1,fp)!=1)
			printf("д�����");
		printf("����E��e���������룿");
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
		printf("�ļ���ʧ��");
		exit(1);
	}
	p1=head;
	while(p1->next!=NULL)
	{
		if(fwrite(p1,sizeof(struct Sign),1,fp)!=1)
			printf("д�����");
		p1=p1->next;
		
	} 
	fclose(fp);
}
void AllShow()
{
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","����","�Ա�","����","�绰","�ʱ�","��ַ");	
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
	printf("          ���м�¼����Ϊ��    \n");	
	printf("---------------------------------------------------------------------\n");
	p1=head;
		while(p1->next!=NULL)
	{
		i++;
		p1=p1->next;
		
	} 
	printf("          %d                  \n",i);
	printf("---------------------------------------------------------------------\n");
	
	printf("          ������ͨ�û�Ϊ��    \n");	
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
	printf("          �����ƶ��û�Ϊ��    \n");	
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
		printf("          ���е����û�Ϊ��    \n");	
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
	printf("                      ͨѶ¼����ϵͳ                        \n");
	printf("              Address book management system\n");
	printf("                                                          \n");
	printf("                 1------��������ѯ                        \n");
	printf("                        Query by name                     \n");
	printf("                 2------���绰�����ѯ                    \n");
	printf("                        Phone Number Enquiry              \n");
	printf("                 3------�ۺϲ�ѯ                          \n");
	printf("                        Integrated query                  \n");
	printf("                 4------�˳���ѯģ��                      \n");
	printf("                        Exit Query Module                 \n");
	printf("                                                          \n");
    printf("        HUNAN INSTITUTE OF ENGINEERING     202101         \n");
	printf("                                                          \n");
	printf("Please Input the Number You Need to Operate: ");
    
}
void Selelctname()
{	system("cls"); 
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","����","�Ա�","����","�绰","�ʱ�","��ַ");	
	printf("*********************************************************************\n");
	p1=head;
	char FindName[8];
	int i=0; 
	printf("������Ҫ��ѯ��������");
	scanf("%s",&FindName);
	while(p1->next!=NULL)
	{
		if(strcmp(p1->name,FindName)==0) 
		    {printf("%10.8s %6.6s %10.10s %11.14s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		    i++;
			}
		p1=p1->next;
		
	} 
	printf("��  %d  ��\n",i);
	system("pause"); 
} 
 
void Selelctphone()
{	system("cls"); 
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","����","�Ա�","����","�绰","�ʱ�","��ַ");	
	printf("*********************************************************************\n");
	p1=head;
	char phone[11];
	int i=0; 
	printf("������Ҫ��ѯ�ĵ绰���룺");
	scanf("%s",&phone);
	while(p1->next!=NULL)
	{
		if(strcmp(p1->phone,phone)==0) 
		    {printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		    i++;
			}
		p1=p1->next;
		
	} 
	printf("��  %d  ��\n",i);
	system("pause"); 
} 
void Selelctall()
{	system("cls"); 
	HeadShow();
	printf("%10.8s %6.6s %10.10s %11.4s %9.7s %16.6s \n","����","�Ա�","����","�绰","�ʱ�","��ַ");	
	printf("*********************************************************************\n");
	p1=head;
	char all[30];
	int i=0; 
	printf("����������һ��Ҫ��ѯ�����ݣ�");
	scanf("%s",&all);
	while(p1->next!=NULL)
	{
		if(strcmp(p1->name,all)==0||strcmp(p1->sex,all)==0||strcmp(p1->birthday,all)==0||strcmp(p1->phone,all)==0||strcmp(p1->postcode,all)==0||strcmp(p1->addr,all)==0) 
		    {printf("%10.8s %6.6s %10.10s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
		    i++;
			}
		p1=p1->next;
		
	} 
	printf("��  %d  ��\n",i);
	system("pause"); 
} 
void Change()
{	char ChangeName[8]; 
	int changekey;
	system("cls");
	HeadShow();
	int i,y=0;				
    p1=p2=head;		
	printf("��������Ҫ�޸ĵĶ����������");
	scanf("%s",&ChangeName);
		getchar();	
	while(p1!=NULL)
	{	
	if(strcmp(p1->name,ChangeName)==0)	
	   {	printf("%10.8s %6.6s %10.10s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
			printf("��Ҫ�޸ĵ���������¼��1-��||2-��\n");
			scanf("%d",&i);
			if(i==1)
			{ y=1;
			printf("��Ҫ�޸ĵ�ͨѶ¼Ϊ:\n");
	   		printf("%10.8s %6.6s %10.10s %11.11s %9.7s %16.16s \n",p1->name,p1->sex,p1->birthday,p1->phone,p1->postcode,p1->addr);
        	printf("��ѡ�����Ĳ���      1-ɾ��||2-�޸�\n");
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
			printf("����:");scanf("%s",p1->name);
			printf("�Ա�:");scanf("%s",p1->sex);
			printf("����:");scanf("%s",p1->birthday);
			printf("�绰:");scanf("%s",p1->phone);
			printf("�ʱ�:");scanf("%s",p1->postcode);
			printf("��ַ:");scanf("%s",p1->addr);	
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
        printf("�Բ���û���ҵ�Ҫ�޸ĵ�ͨѶ������������Ҫ�޸ĵ������Ƿ���ȷ\n");
		printf("Sorry, we can't find the address list you want to change, please check whether the name you want to change is correct\n");
    }
    
	
	system("pause");
}
void ExirShow()
{
	system("color 0F");
 	printf("                      ͨѶ¼����ϵͳ                      \n");
	printf("             Address book management system\n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                                                          \n");
	printf("                         ллʹ�ã�                       \n");
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
		printf("�ļ��������������Ƿ���Ȩ�޲����ļ���");
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
     		printf("���������ѡ��:\n");
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

