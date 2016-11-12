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
void Insert(pNode pos, DataType data);                //ĳ��λ�ò���data

void Erase(pNode* pHead, pNode pos);        //ɾ��λ�ýڵ�
void Remove(pNode* pHead, DataType data);     //ɾ��ĳ�����ݵĽڵ�
void RemoveAll(pNode* pHead, DataType data);      //ɾ����������Ϊdata�Ľڵ�
void Destroy(pNode* pHead);                 //����
int Empty(pNode pHead);                       //�п�
int Size(pNode pHead);                          //�ڵ���Ŀ

void Reverse(pNode pHead);          //�����ӡ
void DeleteListNotTail(pNode *pHead,pNode pos);       //ɾ�������β�ڵ�
void InsertNotHead(pNode *pHead,pNode pos,DataType data);     //���������ͷ�ڵ�ǰ����ڵ�
pNode FindLastK(pNode pHead,int k);  //���ҵ�����k���ڵ�
pNode FindMidNode(pNode pHead);        //�����м�ڵ�
pNode JosephCircle(pNode *pHead,int M);     //Լɪ��
pNode BubbleSort(pNode pHead);    //ð������
pNode Back(pNode pHead);   //��β�ڵ�

void ReverseList(pNode *pHead);      //����
pNode MergeList(pNode List1,pNode List2); //�ϲ�
int IsCross(pNode pHead1,pNode pHead2); //�Ƿ��ཻ
pNode CrossNum(pNode pHead1,pNode pHead2); //�󽻵�
pNode IsWithCircle(pNode pHead);     //�Ƿ����,���ػ���������
int LengthWithCircle(pNode pHead);   //�󻷵ĳ���
pNode Entry(pNode pHead,pNode pMeetNode);   //����ڵ�
int IsCrossWithCircle(pNode pHead1,pNode pHead2);  //�������Ƿ��ཻ
pNode CrossNumWithCircle(pNode pHead1,pNode pHead2);  //�����������ཻ�Ľ���

