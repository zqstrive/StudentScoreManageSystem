#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h> 
typedef struct student /*定义学生信息结构体*/ 
{
	char num[15];		/*学号*/ 
	char name[15];		/*姓名*/ 
	int cgrade;			/*C语言成绩*/ 
	int mgrade;			/*数学成绩*/ 
	int egrade;			/*英语成绩*/ 			
	int total;			/*总分*/ 
	float ave;			/*平均分*/ 
	int mingci;			/*名次*/ 
}Stu;
typedef struct link		/*定义节点*/
{
	Stu data;				/*数据域*/ 
	struct link *next;		/*指针域*/ 
}NODE,*PNODE;
int Menu();          	/*选择菜单*/ 
NODE *Create(); 	/*创建链表函数*/ 
void DeleteRecord(NODE *head);		/*删除链表函数*/ 
void SearchRecord(NODE *head);		/*查询函数*/ 
void ModifyRecord(NODE *head);		/*修改函数*/ 
void InsertRecord(NODE *head);		/*插入函数*/ 
void CountRecord(NODE *head);		/*统计函数*/ 
void SortRecord(NODE *head);		/*排序函数*/ 
void SaveRecord(NODE *head);		/*保存到文件函数*/ 
void DisplayRecord(NODE *head);		/*屏幕显示函数*/ 
void QuitSystem();					/*退出程序函数*/ 
int main()
{
	int i;		/*选择操作序数*/ 
	char m;  	/*判断执行与否*/ 
	NODE *head=NULL;  
	while(1)
	{
		i=Menu();
		switch(i)			/*选择屏幕显示序数*/ 
		{
			case 1:
					printf("创建链表，记录学生信息\n");
					head=Create();
					printf("创建成功\n"); 
					break;
			case 2:
					printf("Are you sure to delete record?(Y/N)\n");
					scanf(" %c",&m);	/*注意：%c前有一个空格*/ 
					while(m=='Y'||m=='y')
					{
						DeleteRecord(head); 
						printf("Do you want to delete again(Y/N)?");
						scanf(" %c",&m);
					}
					break;
			case 3:
					printf("Are you sure to search record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						SearchRecord(head);
						printf("Do you want to search again(Y/N)?\n");
						scanf(" %c",&m);
					}
					break;		
			case 4:
					printf("Are you sure to modify record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						ModifyRecord(head);
						printf("Do you want to modify again(Y/N)?\n");
						scanf(" %c",&m);
					}
					break;	
			case 5:
					printf("Are you sure to insert record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						InsertRecord(head);
						printf("Do you want to insert record(Y/N)?");
						scanf(" %c",&m);	
					}	
					break;
			case 6:
					printf("Now count stdents’ grades and others information\n");
					CountRecord(head);
					break;		
			case 7:
					printf("Are you sure to sort record?(Y/N)\n");
					scanf(" %c",&m);
					while(m=='Y'||m=='y')
					{
						SortRecord(head);
						printf("Do you want to sort again(Y/N)?\n");
						scanf(" %c",&m);	
					}	
					break;
			case 8:
					printf("Now save record to file\n");
					SaveRecord(head);
					printf("保存到文本文档成功！\n");
					break;
			case 9:
					printf("Now display record\n");
					DisplayRecord(head);
					break;			
			case 0:
					QuitSystem();
					break;		
		}
	}
	return 0; 
}
int Menu()
{
	int i;
	printf("             The Students' Grade Management System            \n");
	printf("**************************Menu**************************************\n");
	printf("*  1 input   record                              2 delete record   *\n");
	printf("*  3 search  record                              4 modify record   *\n");
	printf("*  5 insert  record                              6 count  record   *\n");
    printf("*  7 sort    record                              8 save   record   *\n");
	printf("*  9 display record                              0 quit   system   *\n");
	printf("********************************************************************\n");
	printf("\n");
	printf("           	  Please Enter your choice(0~9): \n ");	  
	scanf("%d",&i);
	system("cls");  /*清屏*/
	return i;
} 
NODE *Create()			/*创建链表*/ 
{
	NODE *head,*p,*q;
	int i,n;
	printf("input the number of student:\n");
	scanf("%d",&n);
	head=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	q=head;
	q->next=NULL; 
	for(i=0;i<n;i++)
	{	
		p=(NODE*)malloc(sizeof(NODE));
		printf("请输入第%d个学生的信息:\n",i+1);
		printf("请输入该学生的学号:");
		scanf("%s",p->data.num);
		printf("请输入该学生的姓名:");
		scanf("%s",p->data.name);
		printf("请输入该学生的C语言成绩:");
		scanf("%d",&p->data.cgrade);
		printf("请输入该学生的数学成绩:");
		scanf("%d",&p->data.mgrade);
		printf("请输入该学生的英语成绩：");
		scanf("%d",&p->data.egrade); 
		p->data.total=0;
		p->data.ave=0;
		p->data.total=p->data.cgrade+p->data.mgrade+p->data.egrade;
		p->data.ave=p->data.total/(3.0);
		printf("总分为%d,平均分为%5.2f\n",p->data.total,p->data.ave);
		p->next=NULL;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return head;	 
}
void DeleteRecord(NODE *head)		/*删除记录，并在删除之前显示学生信息*/ 
{									/*按学号删除和按姓名删除两种*/	
	NODE *p,*q;
	int i;
	char dname[15],dnum[15];
	if(head==NULL)
	{
		printf("空数据，请重新输入信息\n"); 
	}
	else
	{
		p=head;
		q=p->next;
		printf("1.按学号删除\n2.按姓名删除\n选择何种删除途径：");
		scanf("%d",&i);
		if(i==1)
		{
			printf("请输入学号：\n");
			scanf("%s",dnum);
			while(stricmp(q->data.num,dnum)!=0&&q->next!=NULL)
			{
				p=q;
				q=q->next; 
			}
			if(stricmp(q->data.num,dnum)==0)
			{
				printf("被删除的学生信息如下：\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				p->next=q->next;
				free(q); 
			}
		} 
		else if(i==2)
		{
			printf("请输入姓名：\n");
			scanf("%s",dname);
			while(stricmp(q->data.name,dname)!=0&&q->next!=NULL)
			{
				p=q;
				q=q->next;
			} 
			if(stricmp(q->data.name,dname)==0)
			{
				p->next=q->next;
				printf("被删除的学生信息如下：\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				free(q); 
			}
		}
		else
			printf("输入有误，请重新输入\n"); 
	}
}
void SearchRecord(NODE *head)			/*查询学生信息，按学号及按姓名查找*/ 
{
	NODE *p,*q;
	int i;
	char sname[15],snum[15];
	if(head==NULL)
	{
		printf("空数据，请重新输入信息\n");
	}
	else
	{
		p=head;
		q=p->next;
		printf("1.按学号查询\n2.按姓名查询\n选择何种查询途径：");
		scanf("%d",&i);
		if(i==1)
		{
			printf("请输入学号:\n");
			scanf("%s",snum);
			while(stricmp(q->data.num,snum)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next;
			}
			if(stricmp(q->data.num,snum)==0)
			{
				printf("该学生信息如下:\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("未找到该学生\n"); 
			}
		}
		else if(i==2)
		{
			printf("请输入姓名:\n");
			scanf("%s",sname);
			while(stricmp(q->data.name,sname)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next; 
			} 
			if(stricmp(q->data.name,sname)==0)
			{
				printf("该学生信息如下:\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("未找到该学生\n"); 
			}
		}
		else
		{
			printf("输入有误，请重新输入\n");
		}
	}
}
void ModifyRecord(NODE *head)		/*修改学生信息，按学号及按姓名*/ 
{									/*且一次修改所有信息，需要重新输入信息*/ 
	NODE *p,*q;
	int i,newcgrade,newmgrade,newegrade;
	char mname[15],mnum[10],newname[15],newnum[15];
	if(head==NULL)
	{
		printf("空数据，请重新输入信息\n"); 
	} 
	else
	{
		p=head;
		q=p->next;
		printf("1.按学号修改\n2.按姓名修改\n选择何种修改途径");
		scanf("%d",&i) ;
		if(i==1)
		{
			printf("请输入学号:\n");
			scanf("%s",mnum);
			while(stricmp(q->data.num,mnum)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next;
			} 
			if(stricmp(q->data.num,mnum)==0)
			{
				printf("该学生原信息如下:\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				printf("接下来你将修改该学生的信息\n");
				printf("请输入要修改的学号:\n");
				scanf("%s",newnum);
				printf("请输入要修改的姓名:\n");
				scanf("%s",newname);
				printf("请输入要修改的C语言成绩:\n");
				scanf("%d",&newcgrade);
				printf("请输入要修改的数学成绩:\n");
				scanf("%d",&newmgrade);
				printf("请输入要修改的英语成绩:\n");
				scanf("%d",&newegrade);
				strcpy(q->data.num,newnum);strcpy(q->data.name,newname);q->data.cgrade=newcgrade;q->data.mgrade=newmgrade;q->data.egrade=newegrade;q->data.total=q->data.cgrade+q->data.mgrade+q->data.egrade;q->data.ave=q->data.total/(3.0); 
				printf("修改过后的学生信息如下:\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("未找到该学生\n"); 
			}
		}
		else if(i==2)
		{
			printf("请输入姓名:\n");
			scanf("%s",mname);
			while(stricmp(q->data.name,mname)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next;
			} 
			if(stricmp(q->data.name,mname)==0)
			{
				printf("该学生原信息如下:\n");
				printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				printf("接下来你将修改该学生的信息\n");
				printf("请输入要修改的学号:\n");
				scanf("%s",newnum);
				printf("请输入要修改的姓名:\n");
				scanf("%s",newname);
				printf("请输入要修改的C语言成绩:\n");
				scanf("%d",&newcgrade);
				printf("请输入要修改的数学成绩:\n");
				scanf("%d",&newmgrade);
				printf("请输入要修改的英语成绩:\n");
				scanf("%d",&newegrade);
				strcpy(q->data.num,newnum);strcpy(q->data.name,newname);q->data.cgrade=newcgrade;q->data.mgrade=newmgrade;q->data.egrade=newegrade;q->data.total=q->data.cgrade+q->data.mgrade+q->data.egrade;q->data.ave=q->data.total/(3.0); 
				printf("修改过后的学生信息如下:\n");
				printf("\t学号\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("未找到该学生\n"); 
			} 
		}
		else
		{
			printf("输入有误，请重新输入\n");
		}
	}
}
void InsertRecord(NODE *head)			/*插入信息，按学号及按姓名*/ 
{
	NODE *p,*r;
	int i;
	char iname[15],inum[15];
	if(head==NULL)
	{
		printf("空数据，请重新输入\n");
	}
	else
	{
		p=head;
		printf("1.按学号插入\n2.按姓名插入\n选择何种插入途径");
		scanf("%d",&i);
		if(i==1)
		{
			printf("请输入插入位置附近的学号:\n");
			scanf("%s",inum);		
			r=(NODE*)malloc(sizeof(NODE));		
			printf("请输入该学生的学号:");
			scanf("%s",r->data.num);
			printf("请输入该学生的姓名:");
			scanf("%s",r->data.name);
			printf("请输入该学生的C语言成绩:");
			scanf("%d",&r->data.cgrade);
			printf("请输入该学生的数学成绩:");
			scanf("%d",&r->data.mgrade);
			printf("请输入该学生的英语成绩：");
			scanf("%d",&r->data.egrade); 
			r->data.total=0;
			r->data.ave=0;
			r->data.total=r->data.cgrade+r->data.mgrade+r->data.egrade;
			r->data.ave=r->data.total/(3.0);
			printf("总分为%d,平均分为%5.2f\n",r->data.total,r->data.ave); r->next=NULL;	
			while(stricmp(p->data.num,inum)!=0&&p->next!=NULL)
			{
				p=p->next;
			} 
			if(stricmp(p->data.num,inum)==0)
			{
				if(p==head)
				{
					r->next=head;
					head=r;
				}
				else
				{
					r->next=p->next;
					p->next=r;
				}
			}
			else
			{
				p->next=r;
			}
		}	
		else if(i==2)
		{
			printf("请输入插入附近的姓名:\n");
			scanf("%s",iname);
			r=(NODE*)malloc(sizeof(NODE));
			printf("请输入该学生的学号:");
			scanf("%s",r->data.num);
			printf("请输入该学生的姓名:");
			scanf("%s",r->data.name);
			printf("请输入该学生的C语言成绩:");
			scanf("%d",&r->data.cgrade);
			printf("请输入该学生的数学成绩:");
			scanf("%d",&r->data.mgrade);
			printf("请输入该学生的英语成绩：");
			scanf("%d",&r->data.egrade); 
			r->data.total=0;
			r->data.ave=0;
			r->data.total=r->data.cgrade+r->data.mgrade+r->data.egrade;
			r->data.ave=r->data.total/(3.0);
			printf("总分为%d,平均分为%5.2f\n",r->data.total,r->data.ave);
			while(stricmp(p->data.num,inum)!=0&&p->next!=NULL)
			{
				p=p->next;
			} 
			if(stricmp(p->data.num,inum)==0)
			{
				if(p==head)
				{
					r->next=head;
					head=r;
				}
				else
				{
					r->next=p->next;
					p->next=r;
				}
			}
			else
			{
				p->next=r;
			}
		}	
	} 
}
void CountRecord(NODE *head)   			/*统计各科最高分，及不及格人数*/ 
{
	NODE *p;
	int maxc=0,maxm=0,maxe=0,failc=0,failm=0,faile=0;
	p=head->next;
	if(head==NULL)
	{
		printf("空数据，请重新输入信息\n"); 
	} 
	else
	{

		while(p!=NULL)
		{	
			if(p->data.cgrade>=maxc)
			{
				maxc=p->data.cgrade;
			}
			if(p->data.mgrade>=maxm)
			{
				maxm=p->data.mgrade;
			}
			if(p->data.egrade>=maxe)
			{
				maxe=p->data.egrade;
			}
			if(p->data.cgrade<60)
			{
				failc++;
			}
			if(p->data.mgrade<60)
			{
				failm++;
			}
			if(p->data.egrade<60)
			{
				faile++;
			}
			p=p->next;
		} 
		printf("C语言最高分为%d,数学最高分为%d,英语最高分为%d,C语言不及格人数为%d,数学不及格人数为%d,英语不及格人数为%d\n",maxc,maxm,maxe,failc,failm,faile);
	}
}
void SortRecord(NODE *head)			/*排序函数，分为升序和降序两种*/ 
{									/*分为按学号，按姓名，按C语言成绩，按数学成绩，按英语成绩，按总成绩6种方式*/ 
	NODE *p=NULL,*q=NULL;
	int i,j,tempc,tempm,tempe,temps;
	float tempa;
	char tempnum[15],tempname[15];
	if(head==NULL)
	{
		printf("空数据，请重新输入信息\n");
	}
	else
	{
		printf("1.升序排列  2.降序排列\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("1.按学号排列 2.按姓名排列 3.按C语言成绩排列 4.按数学成绩排列 5.按英语成绩排列 6.按总成绩排列\n");
			scanf("%d",&j);
			switch(j)
			{
				case 1:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(stricmp(p->data.num,q->data.num)>0)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;
				case 2:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(stricmp(p->data.name,q->data.name)>0)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;	
				case 3:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.cgrade>q->data.cgrade)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;
				case 4:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.mgrade>q->data.mgrade)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;		
				case 5:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.egrade>q->data.egrade)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;
				case 6:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.total>q->data.total)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;							
			}
		}
		else if(i==2)
		{
			printf("1.按学号排列 2.按姓名排列 3.按C语言成绩排列 4.按数学成绩排列 5.按英语成绩排列 6.按总成绩排列\n");
			scanf("%d",&j);
			switch(j)
			{
				case 1:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(stricmp(p->data.num,q->data.num)<0)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;
				case 2:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(stricmp(p->data.name,q->data.name)<0)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;	
				case 3:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.cgrade<q->data.cgrade)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;
				case 4:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.mgrade<q->data.mgrade)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;		
				case 5:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.egrade<q->data.egrade)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;
				case 6:
						for(p=head->next;p!=NULL;p=p->next)
						{
							for(q=p->next;q!=NULL;q=q->next)
							{
								if(p->data.total<q->data.total)
								{
									strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
									strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
									tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
									tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
									tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
									temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
									tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
								}
							}
						}
						p=head->next;
						while(p!=NULL)
						{
							printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;							
			}
		}
	} 
}
void SaveRecord(NODE *head)			/*将学生信息保存到文件中，并按照学生总成绩降序排列*/ 
{
	NODE *p=NULL,*q=NULL;
	int i,j,tempc,tempm,tempe,temps;
	float tempa;
	char tempnum[15],tempname[15];
	FILE *fp;
	fp=fopen("student.txt","w+");
	if(fp==NULL)
	{
		printf("Fail to open student.txt\n");
		return; 
	}
	for(p=head->next;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data.total<q->data.total)
			{
				strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
				strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
				tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
				tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
				tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
				temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
				tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
			}
		}
	}
	p=head->next;
	fprintf(fp,"\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t\t数学成绩\t\t英语成绩\n");
	while(p!=NULL)
	{
		fprintf(fp,"    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
		p=p->next;
	} 
	fclose(fp);
}
void DisplayRecord(NODE *head)		/*屏幕显示，并按照学生成绩降序排列*/ 
{
	NODE *p=NULL,*q=NULL;
	int i,j,tempc,tempm,tempe,temps,k;
	float tempa;
	char tempnum[15],tempname[15];
	for(p=head->next;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data.total<q->data.total)
			{
				strcpy(tempnum,p->data.num);strcpy(p->data.num,q->data.num);strcpy(q->data.num,tempnum);
				strcpy(tempname,p->data.name);strcpy(p->data.name,q->data.name);strcpy(q->data.name,tempname);
				tempc=p->data.cgrade;p->data.cgrade=q->data.cgrade;q->data.cgrade=tempc;
				tempm=p->data.mgrade;p->data.mgrade=q->data.mgrade;q->data.mgrade=tempm;
				tempe=p->data.egrade;p->data.egrade=q->data.egrade;q->data.egrade=tempe;
				temps=p->data.total;p->data.total=q->data.total;q->data.total=temps;
				tempa=p->data.ave;p->data.ave=q->data.ave;q->data.ave=tempa;		
			}
		}
	}
	p=head->next;
	while(p!=NULL)
	{	
		printf("\t学号\t\t姓名\t总分\t平均分\t\tC语言成绩\t数学成绩\t英语成绩\n");
		printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
		p=p->next;	
	}
}
void QuitSystem()			/*结束程序*/ 
{
	printf("Quit system,thanks for your using \n");
	exit(0);
}
