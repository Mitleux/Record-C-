#include <iostream>
using namespace std;
struct node { char data; node *link; };  //定义结点类型
node *head;	                //定义链表首指针
void Insert(node *q)		//将结点插入链表首部
{
	//********found********
	q->link=head;  
	head=q;
}
int main()
{
	char ch;
	node *p;
	head=NULL;
	while((ch=cin.get())!='\n')
	{
		//********found********
		p=new node;				//用new为节点p动态分配存储空间
		p->data = ch;			//将ch中的字符赋给结点值域
		//********found********
		Insert(p);				//调用Insert函数把结点p插入到链表首部
	}
	p=head;
	while(p!=NULL)
	{
		cout<<p->data;
		//********found********
		p=p->link;             //使p指向下一个结点
	}
	cout<<endl;
	return 0;
}


