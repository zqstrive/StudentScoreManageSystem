#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h> 
typedef struct student /*����ѧ����Ϣ�ṹ��*/ 
{
	char num[15];		/*ѧ��*/ 
	char name[15];		/*����*/ 
	int cgrade;			/*C���Գɼ�*/ 
	int mgrade;			/*��ѧ�ɼ�*/ 
	int egrade;			/*Ӣ��ɼ�*/ 			
	int total;			/*�ܷ�*/ 
	float ave;			/*ƽ����*/ 
	int mingci;			/*����*/ 
}Stu;
typedef struct link		/*����ڵ�*/
{
	Stu data;				/*������*/ 
	struct link *next;		/*ָ����*/ 
}NODE,*PNODE;
int Menu();          	/*ѡ��˵�*/ 
NODE *Create(); 	/*����������*/ 
void DeleteRecord(NODE *head);		/*ɾ��������*/ 
void SearchRecord(NODE *head);		/*��ѯ����*/ 
void ModifyRecord(NODE *head);		/*�޸ĺ���*/ 
void InsertRecord(NODE *head);		/*���뺯��*/ 
void CountRecord(NODE *head);		/*ͳ�ƺ���*/ 
void SortRecord(NODE *head);		/*������*/ 
void SaveRecord(NODE *head);		/*���浽�ļ�����*/ 
void DisplayRecord(NODE *head);		/*��Ļ��ʾ����*/ 
void QuitSystem();					/*�˳�������*/ 
int main()
{
	int i;		/*ѡ���������*/ 
	char m;  	/*�ж�ִ�����*/ 
	NODE *head=NULL;  
	while(1)
	{
		i=Menu();
		switch(i)			/*ѡ����Ļ��ʾ����*/ 
		{
			case 1:
					printf("����������¼ѧ����Ϣ\n");
					head=Create();
					printf("�����ɹ�\n"); 
					break;
			case 2:
					printf("Are you sure to delete record?(Y/N)\n");
					scanf(" %c",&m);	/*ע�⣺%cǰ��һ���ո�*/ 
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
					printf("Now count stdents�� grades and others information\n");
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
					printf("���浽�ı��ĵ��ɹ���\n");
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
	system("cls");  /*����*/
	return i;
} 
NODE *Create()			/*��������*/ 
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
		printf("�������%d��ѧ������Ϣ:\n",i+1);
		printf("�������ѧ����ѧ��:");
		scanf("%s",p->data.num);
		printf("�������ѧ��������:");
		scanf("%s",p->data.name);
		printf("�������ѧ����C���Գɼ�:");
		scanf("%d",&p->data.cgrade);
		printf("�������ѧ������ѧ�ɼ�:");
		scanf("%d",&p->data.mgrade);
		printf("�������ѧ����Ӣ��ɼ���");
		scanf("%d",&p->data.egrade); 
		p->data.total=0;
		p->data.ave=0;
		p->data.total=p->data.cgrade+p->data.mgrade+p->data.egrade;
		p->data.ave=p->data.total/(3.0);
		printf("�ܷ�Ϊ%d,ƽ����Ϊ%5.2f\n",p->data.total,p->data.ave);
		p->next=NULL;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	return head;	 
}
void DeleteRecord(NODE *head)		/*ɾ����¼������ɾ��֮ǰ��ʾѧ����Ϣ*/ 
{									/*��ѧ��ɾ���Ͱ�����ɾ������*/	
	NODE *p,*q;
	int i;
	char dname[15],dnum[15];
	if(head==NULL)
	{
		printf("�����ݣ�������������Ϣ\n"); 
	}
	else
	{
		p=head;
		q=p->next;
		printf("1.��ѧ��ɾ��\n2.������ɾ��\nѡ�����ɾ��;����");
		scanf("%d",&i);
		if(i==1)
		{
			printf("������ѧ�ţ�\n");
			scanf("%s",dnum);
			while(stricmp(q->data.num,dnum)!=0&&q->next!=NULL)
			{
				p=q;
				q=q->next; 
			}
			if(stricmp(q->data.num,dnum)==0)
			{
				printf("��ɾ����ѧ����Ϣ���£�\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				p->next=q->next;
				free(q); 
			}
		} 
		else if(i==2)
		{
			printf("������������\n");
			scanf("%s",dname);
			while(stricmp(q->data.name,dname)!=0&&q->next!=NULL)
			{
				p=q;
				q=q->next;
			} 
			if(stricmp(q->data.name,dname)==0)
			{
				p->next=q->next;
				printf("��ɾ����ѧ����Ϣ���£�\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				free(q); 
			}
		}
		else
			printf("������������������\n"); 
	}
}
void SearchRecord(NODE *head)			/*��ѯѧ����Ϣ����ѧ�ż�����������*/ 
{
	NODE *p,*q;
	int i;
	char sname[15],snum[15];
	if(head==NULL)
	{
		printf("�����ݣ�������������Ϣ\n");
	}
	else
	{
		p=head;
		q=p->next;
		printf("1.��ѧ�Ų�ѯ\n2.��������ѯ\nѡ����ֲ�ѯ;����");
		scanf("%d",&i);
		if(i==1)
		{
			printf("������ѧ��:\n");
			scanf("%s",snum);
			while(stricmp(q->data.num,snum)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next;
			}
			if(stricmp(q->data.num,snum)==0)
			{
				printf("��ѧ����Ϣ����:\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("δ�ҵ���ѧ��\n"); 
			}
		}
		else if(i==2)
		{
			printf("����������:\n");
			scanf("%s",sname);
			while(stricmp(q->data.name,sname)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next; 
			} 
			if(stricmp(q->data.name,sname)==0)
			{
				printf("��ѧ����Ϣ����:\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("δ�ҵ���ѧ��\n"); 
			}
		}
		else
		{
			printf("������������������\n");
		}
	}
}
void ModifyRecord(NODE *head)		/*�޸�ѧ����Ϣ����ѧ�ż�������*/ 
{									/*��һ���޸�������Ϣ����Ҫ����������Ϣ*/ 
	NODE *p,*q;
	int i,newcgrade,newmgrade,newegrade;
	char mname[15],mnum[10],newname[15],newnum[15];
	if(head==NULL)
	{
		printf("�����ݣ�������������Ϣ\n"); 
	} 
	else
	{
		p=head;
		q=p->next;
		printf("1.��ѧ���޸�\n2.�������޸�\nѡ������޸�;��");
		scanf("%d",&i) ;
		if(i==1)
		{
			printf("������ѧ��:\n");
			scanf("%s",mnum);
			while(stricmp(q->data.num,mnum)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next;
			} 
			if(stricmp(q->data.num,mnum)==0)
			{
				printf("��ѧ��ԭ��Ϣ����:\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				printf("�������㽫�޸ĸ�ѧ������Ϣ\n");
				printf("������Ҫ�޸ĵ�ѧ��:\n");
				scanf("%s",newnum);
				printf("������Ҫ�޸ĵ�����:\n");
				scanf("%s",newname);
				printf("������Ҫ�޸ĵ�C���Գɼ�:\n");
				scanf("%d",&newcgrade);
				printf("������Ҫ�޸ĵ���ѧ�ɼ�:\n");
				scanf("%d",&newmgrade);
				printf("������Ҫ�޸ĵ�Ӣ��ɼ�:\n");
				scanf("%d",&newegrade);
				strcpy(q->data.num,newnum);strcpy(q->data.name,newname);q->data.cgrade=newcgrade;q->data.mgrade=newmgrade;q->data.egrade=newegrade;q->data.total=q->data.cgrade+q->data.mgrade+q->data.egrade;q->data.ave=q->data.total/(3.0); 
				printf("�޸Ĺ����ѧ����Ϣ����:\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("δ�ҵ���ѧ��\n"); 
			}
		}
		else if(i==2)
		{
			printf("����������:\n");
			scanf("%s",mname);
			while(stricmp(q->data.name,mname)!=0&&p->next!=NULL)
			{
				p=q;
				q=q->next;
			} 
			if(stricmp(q->data.name,mname)==0)
			{
				printf("��ѧ��ԭ��Ϣ����:\n");
				printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
				printf("�������㽫�޸ĸ�ѧ������Ϣ\n");
				printf("������Ҫ�޸ĵ�ѧ��:\n");
				scanf("%s",newnum);
				printf("������Ҫ�޸ĵ�����:\n");
				scanf("%s",newname);
				printf("������Ҫ�޸ĵ�C���Գɼ�:\n");
				scanf("%d",&newcgrade);
				printf("������Ҫ�޸ĵ���ѧ�ɼ�:\n");
				scanf("%d",&newmgrade);
				printf("������Ҫ�޸ĵ�Ӣ��ɼ�:\n");
				scanf("%d",&newegrade);
				strcpy(q->data.num,newnum);strcpy(q->data.name,newname);q->data.cgrade=newcgrade;q->data.mgrade=newmgrade;q->data.egrade=newegrade;q->data.total=q->data.cgrade+q->data.mgrade+q->data.egrade;q->data.ave=q->data.total/(3.0); 
				printf("�޸Ĺ����ѧ����Ϣ����:\n");
				printf("\tѧ��\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
				printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",q->data.num,q->data.name,q->data.total,q->data.ave,q->data.cgrade,q->data.mgrade,q->data.egrade);
			}
			else
			{
				printf("δ�ҵ���ѧ��\n"); 
			} 
		}
		else
		{
			printf("������������������\n");
		}
	}
}
void InsertRecord(NODE *head)			/*������Ϣ����ѧ�ż�������*/ 
{
	NODE *p,*r;
	int i;
	char iname[15],inum[15];
	if(head==NULL)
	{
		printf("�����ݣ�����������\n");
	}
	else
	{
		p=head;
		printf("1.��ѧ�Ų���\n2.����������\nѡ����ֲ���;��");
		scanf("%d",&i);
		if(i==1)
		{
			printf("���������λ�ø�����ѧ��:\n");
			scanf("%s",inum);		
			r=(NODE*)malloc(sizeof(NODE));		
			printf("�������ѧ����ѧ��:");
			scanf("%s",r->data.num);
			printf("�������ѧ��������:");
			scanf("%s",r->data.name);
			printf("�������ѧ����C���Գɼ�:");
			scanf("%d",&r->data.cgrade);
			printf("�������ѧ������ѧ�ɼ�:");
			scanf("%d",&r->data.mgrade);
			printf("�������ѧ����Ӣ��ɼ���");
			scanf("%d",&r->data.egrade); 
			r->data.total=0;
			r->data.ave=0;
			r->data.total=r->data.cgrade+r->data.mgrade+r->data.egrade;
			r->data.ave=r->data.total/(3.0);
			printf("�ܷ�Ϊ%d,ƽ����Ϊ%5.2f\n",r->data.total,r->data.ave); r->next=NULL;	
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
			printf("��������븽��������:\n");
			scanf("%s",iname);
			r=(NODE*)malloc(sizeof(NODE));
			printf("�������ѧ����ѧ��:");
			scanf("%s",r->data.num);
			printf("�������ѧ��������:");
			scanf("%s",r->data.name);
			printf("�������ѧ����C���Գɼ�:");
			scanf("%d",&r->data.cgrade);
			printf("�������ѧ������ѧ�ɼ�:");
			scanf("%d",&r->data.mgrade);
			printf("�������ѧ����Ӣ��ɼ���");
			scanf("%d",&r->data.egrade); 
			r->data.total=0;
			r->data.ave=0;
			r->data.total=r->data.cgrade+r->data.mgrade+r->data.egrade;
			r->data.ave=r->data.total/(3.0);
			printf("�ܷ�Ϊ%d,ƽ����Ϊ%5.2f\n",r->data.total,r->data.ave);
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
void CountRecord(NODE *head)   			/*ͳ�Ƹ�����߷֣�������������*/ 
{
	NODE *p;
	int maxc=0,maxm=0,maxe=0,failc=0,failm=0,faile=0;
	p=head->next;
	if(head==NULL)
	{
		printf("�����ݣ�������������Ϣ\n"); 
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
		printf("C������߷�Ϊ%d,��ѧ��߷�Ϊ%d,Ӣ����߷�Ϊ%d,C���Բ���������Ϊ%d,��ѧ����������Ϊ%d,Ӣ�ﲻ��������Ϊ%d\n",maxc,maxm,maxe,failc,failm,faile);
	}
}
void SortRecord(NODE *head)			/*����������Ϊ����ͽ�������*/ 
{									/*��Ϊ��ѧ�ţ�����������C���Գɼ�������ѧ�ɼ�����Ӣ��ɼ������ܳɼ�6�ַ�ʽ*/ 
	NODE *p=NULL,*q=NULL;
	int i,j,tempc,tempm,tempe,temps;
	float tempa;
	char tempnum[15],tempname[15];
	if(head==NULL)
	{
		printf("�����ݣ�������������Ϣ\n");
	}
	else
	{
		printf("1.��������  2.��������\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("1.��ѧ������ 2.���������� 3.��C���Գɼ����� 4.����ѧ�ɼ����� 5.��Ӣ��ɼ����� 6.���ܳɼ�����\n");
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
							printf("\tѧ��\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;							
			}
		}
		else if(i==2)
		{
			printf("1.��ѧ������ 2.���������� 3.��C���Գɼ����� 4.����ѧ�ɼ����� 5.��Ӣ��ɼ����� 6.���ܳɼ�����\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
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
							printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
							printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
							p=p->next;							
						} 
						break;							
			}
		}
	} 
}
void SaveRecord(NODE *head)			/*��ѧ����Ϣ���浽�ļ��У�������ѧ���ܳɼ���������*/ 
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
	fprintf(fp,"\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t\t��ѧ�ɼ�\t\tӢ��ɼ�\n");
	while(p!=NULL)
	{
		fprintf(fp,"    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
		p=p->next;
	} 
	fclose(fp);
}
void DisplayRecord(NODE *head)		/*��Ļ��ʾ��������ѧ���ɼ���������*/ 
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
		printf("\tѧ��\t\t����\t�ܷ�\tƽ����\t\tC���Գɼ�\t��ѧ�ɼ�\tӢ��ɼ�\n");
		printf("    %10s\t\t%s\t%d\t%5.2f\t\t%d\t\t%d\t\t%d\n",p->data.num,p->data.name,p->data.total,p->data.ave,p->data.cgrade,p->data.mgrade,p->data.egrade);
		p=p->next;	
	}
}
void QuitSystem()			/*��������*/ 
{
	printf("Quit system,thanks for your using \n");
	exit(0);
}
