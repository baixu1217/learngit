#pragma once
#include<iostream>
using namespace std;
typedef int DataType;
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*pNode;

void InitSlist(pNode *pHead);

void PushBack(pNode *pHead,DataType data);
void PopBack(pNode *pHead);

void PushFront(pNode *pHead,DataType data);
void PopFront(pNode *pHead);
pNode BuyNode(DataType data);
pNode Find(pNode pHead, DataType data);
void Insert(pNode pos, DataType data);                //某个位置插入data

void Erase(pNode* pHead, pNode pos);        //删除位置节点
void Remove(pNode* pHead, DataType data);     //删除某个数据的节点
void RemoveAll(pNode* pHead, DataType data);      //删除所有数据为data的节点
void Destroy(pNode* pHead);                 //销毁
int Empty(pNode pHead);                       //判空
int Size(pNode pHead);                          //节点数目

void Reverse(pNode pHead);          //倒序打印
void DeleteListNotTail(pNode *pHead,pNode pos);       //删除链表非尾节点
void InsertNotHead(pNode *pHead,pNode pos,DataType data);     //插入链表非头节点前插入节点
pNode FindLastK(pNode pHead,int k);  //查找倒数第k个节点
pNode FindMidNode(pNode pHead);        //查找中间节点
pNode JosephCircle(pNode *pHead,int M);     //约瑟夫环
pNode BubbleSort(pNode pHead);    //冒泡排序
pNode Back(pNode pHead);   //求尾节点

void ReverseList(pNode *pHead);      //逆置
pNode MergeList(pNode List1,pNode List2); //合并
int IsCross(pNode pHead1,pNode pHead2); //是否相交
pNode CrossNum(pNode pHead1,pNode pHead2); //求交点
pNode IsWithCircle(pNode pHead);     //是否带环,返回环的相遇点
int LengthWithCircle(pNode pHead);   //求环的长度
pNode Entry(pNode pHead,pNode pMeetNode);   //求入口点
int IsCrossWithCircle(pNode pHead1,pNode pHead2);  //带环的是否相交
pNode CrossNumWithCircle(pNode pHead1,pNode pHead2);  //两个带环的相交的交点

