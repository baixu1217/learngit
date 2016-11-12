#include"SList.h"
#include<assert.h>

void InitSlist(pNode *pHead)
{
	*pHead = NULL;
}

pNode BuyNode(DataType data)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void PushBack(pNode *pHead,DataType data)
{
	/*assert(*pHead);*/
	if(*pHead == NULL)
	{
		*pHead = BuyNode(data);
		(*pHead)->next = NULL;
	}
	else
	{
		pNode pCur = *pHead;
		while(pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = BuyNode(data);
	}
}

void PopBack(pNode *pHead)
{
	if(*pHead == NULL)
		return;
	if((*pHead)->next == NULL)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		pNode pCur = *pHead;
		pNode pPrev = NULL;
		while(pCur->next)
		{
			pPrev = pCur;
			pCur = pCur->next;
		}
		free(pCur);
		pPrev->next = NULL;
	}
}

void PushFront(pNode *pHead,DataType data)
{
	if(*pHead == NULL)
		*pHead = BuyNode(data);
	else
	{
		pNode cur = BuyNode(data);
		cur->next = *pHead;
		*pHead = cur;
	}
}

void PopFront(pNode *pHead)
{
	if(*pHead == NULL)
		return;
	else
	{
		pNode pDel = *pHead;
		*pHead = (*pHead)->next;
		free(pDel);
	}
}

pNode Find(pNode pHead, DataType data)
{
		pNode pCur = pHead;
		while(pCur)
		{
			if(pCur->data == data)
			{
				return pCur;
			}
			pCur = pCur->next;
		}
		return NULL;
}

void Insert(pNode pos, DataType data)
{
	pNode newNode = BuyNode(data);
	if(pos == NULL)
		return;
	newNode->next = pos->next;
	pos->next = newNode;
}

void Erase(pNode* pHead, pNode pos)
{
	pNode pCur = *pHead;
	if(*pHead == pos && (*pHead)->next == NULL)
	{
		free(pos);
		*pHead = NULL;
		return;
	}
	while(pCur)
	{
		pNode pPrev = pCur;
		while(pPrev->next == pos)
		{
			pNode pDel = pos;
			pPrev->next = pos->next;
			free(pDel);
			return;
		}
		pCur = pCur->next;
	}
	return;
}

void Remove(pNode* pHead, DataType data)
{
	pNode pos = Find(*pHead,data);
	Erase(pHead,pos);
}

void Destroy(pNode* pHead)
{
	while(*pHead)
	{
		pNode pDel = *pHead;
		*pHead = (*pHead)->next;
		free(pDel);
	}
	return;
}

int Empty(pNode pHead)
{
	return pHead == NULL;
}

int Size(pNode pHead)
{
	pNode pCur = pHead;
	int count = 0;
	if(pHead == NULL)
		return 0;
	while(pCur)
	{
		count++;
		pCur = pCur->next;
	}
	return count;
}


void Print(pNode pHead)
{
	pNode pCur = pHead;
	while(pCur)
	{
		cout<<pCur->data<<"->";
		pCur = pCur->next;
	}
	cout<<"NULL"<<endl;
}

void Reverse(pNode pHead)
{
	if(pHead)
	{
		Reverse(pHead->next);
		cout<<pHead->data<<"->";	
	}
}

void DeleteListNotTail(pNode *pHead,pNode pos)
{
	assert(pHead);
	if(*pHead == NULL || pos->next == NULL)
		return;
	pNode pDel = pos->next;
	pos->next = pDel->next;
	pos->data = pDel->data;
	free(pDel);
}

void InsertNotHead(pNode *pHead,pNode pos,DataType data)
{
	if(*pHead == NULL || pos == *pHead)
		return;
	pNode newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;
	pos->data = data;
}

pNode FindMidNode(pNode pHead)
{
	assert(pHead);
	pNode pFast = pHead;
	pNode pSlow = pHead;
	while(pFast && pFast->next)            //偶数个节点时，中间节点返回后一个
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	while(pFast->next && pFast->next->next)  //偶数个节点时，中间节点返回前一个
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

pNode FindLastK(pNode pHead,int k)
{
	assert(pHead);
	int count = k;
	pNode pFast = pHead;
	pNode pSlow = pHead;
	if(pHead == NULL || k <= 0)
		return NULL;
	/*while(count--)            //pFast移动k次
	{
		if(pFast == NULL)
			return NULL;
		pFast = pFast->next;	
	}

	while(pFast)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}*/

	while(--count)                 //pFast移动k-1次
	{
		if(pFast == NULL)
			return NULL;
		pFast = pFast->next;	
	}

	while(pFast->next)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

pNode JosephCircle(pNode *pHead,int M)
{
	assert(pHead);
	pNode pCur = *pHead;
	pNode pPcur = *pHead;
	int count = M;
	if(*pHead == NULL || M <= 0)
		return NULL;
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	pCur->next = *pHead;
	while(pPcur->next != pPcur)
	{
		int count = M;
		while(--count)
		{
			pPcur = pPcur->next;
		}
		if(pPcur == *pHead)
		{
			*pHead = (*pHead)->next;
		}
		DeleteListNotTail(pHead,pPcur);
	}
	return pPcur;
}


void ReverseList(pNode pHead)      //逆置
{
	assert(pHead);
	if(pHead == NULL || pHead->next == NULL)
		return;
	pNode pPre = pHead;
	pNode pCur = pPre->next;
	pNode pNext = pCur->next;

	while(pNext)
	{
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
		pNext = pNext->next;
	}
	pCur->next = pPre;
	pHead->next = NULL;
}

pNode MergeList(pNode List1,pNode List2){	if(List1 == NULL)		return List2;	if(List2 == NULL)		return List1;	pNode List = NULL;	pNode pNode1 = List1;	pNode pNode2 = List2;	if(pNode1->data <= pNode2->data)	{		List = pNode1;		pNode1 = pNode1->next;	}			else	{		List = pNode2;		pNode2 = pNode2->next;	}			pNode pList = List;	while(pNode1 && pNode2)	{		if(pNode1->data <= pNode2->data)		{			pList->next = pNode1;			pList = pNode1;			pNode1 = pNode1->next;		}			else		{			pList->next = pNode2;			pList = pNode2;			pNode2 = pNode2->next;		}	}	if(pNode1 == NULL)		pList->next = pNode2;	else		pList->next = pNode1;	return List;}
int IsCross(pNode pHead1,pNode pHead2){	if(pHead1 == NULL || pHead2 == NULL)		return -1;	pNode pCur1 = pHead1;	pNode pCur2 = pHead2;	while(pCur1->next)		pCur1 = pCur1->next;	while(pCur2->next)		pCur2 = pCur2->next;	if(pCur1 == pCur2)		return 1;	else		return -1;}


pNode BubbleSort(pNode pHead)
{
	if(pHead == NULL || pHead->next == NULL)
		return pHead;
	pNode pCur = pHead;
	pNode pNext = pCur->next;
	pNode pTail = NULL;
	while(pCur != pTail)
	{
		pNext = pCur->next;
		while(pCur->next != pTail)
		{
			if(pCur->data > pNext->data)
			{
				DataType tmp = pCur->data;
				pCur->data = pNext->data;
				pNext->data = tmp;
			}
			pCur = pNext;
			pNext = pNext->next;
		}
		pTail = pCur;
		pCur = pHead;
	}
	return pHead;
}

pNode CrossNum(pNode pHead1,pNode pHead2){	if(IsCross(pHead1,pHead2) != 1)	{		return NULL;	}	pNode pNode1 = pHead1;	pNode pNode2 = pHead2;	int count1 = 0;	int count2 = 0;	int step = 0;	while(pNode1)	{		pNode1 = pNode1->next;		count1++;	}	while(pNode2)	{		pNode2 = pNode2->next;		count2++;	}	step = count1-count2;	pNode1 = pHead1;	pNode2 = pHead2;	if(step >= 0)	{		while(step--)			pNode1 = pNode1->next;	}	else	{		step = 0 - step;		while(step--)			pNode2 = pNode2->next;	}	while(pNode1 && pNode2)	{		if(pNode1 == pNode2)			return pNode1;		pNode1 = pNode1->next;		pNode2 = pNode2->next;	}}
int LengthWithCircle(pNode pHead){	pNode pMeetNode = IsWithCircle(pHead);	pNode pCur = pMeetNode;	if(pMeetNode == NULL)		return 0;	int count = 1;	while(pCur->next != pMeetNode)	{		pCur = pCur->next;		count++;	}	return count;}
pNode IsWithCircle(pNode pHead){	pNode pFast = pHead;	pNode pSlow = pHead;	while(pFast && pFast->next)	{		pFast = pFast->next->next;		pSlow = pSlow->next;		if(pFast == pSlow)			return pFast;	}	return NULL;}


pNode Back(pNode pHead){	pNode pCur = pHead;	if(pHead == NULL)		return pHead;	while(pCur->next)	{		pCur = pCur->next;	}	return pCur;}

pNode Entry(pNode pHead,pNode pMeetNode){	pNode pCur = pHead;	while(pCur != pMeetNode)	{		pCur = pCur->next;		pMeetNode = pMeetNode->next;	}	return pCur;}
int IsCrossWithCircle(pNode pHead1,pNode pHead2){	pNode pNode1 = IsWithCircle(pHead1);	pNode pNode2 = IsWithCircle(pHead2);	if(pNode1 == NULL || pNode2 == NULL)		return 0;	while(pNode2->next != pNode1)	{		pNode2 = pNode2->next;	}	return 1;}

pNode CrossNumWithCircle(pNode pHead1,pNode pHead2)
{
	pNode pTail = Entry(pHead1,IsWithCircle(pHead1));
	pTail->next = NULL;
	return CrossNum(pHead1,pHead2);
}

void Test1()
{
	pNode pHead;
	InitSlist(&pHead);
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	Print(pHead);
}
void Test2()
{
	pNode pHead;
	InitSlist(&pHead);
	PushFront(&pHead,1);
	PushFront(&pHead,2);
	PushFront(&pHead,3);
	PushFront(&pHead,4);
	PopFront(&pHead);
	PopFront(&pHead);
	PopFront(&pHead);
	PopFront(&pHead);
	PopFront(&pHead);
	Print(pHead);
}
void Test3()
{
	pNode pHead;
	InitSlist(&pHead);
	PushFront(&pHead,1);
	PushFront(&pHead,2);
	PushFront(&pHead,3);
	PushFront(&pHead,4);
	PushFront(&pHead,2);
	PushFront(&pHead,4);
	PushFront(&pHead,2);
	Insert(Find(pHead,3),6);
	Erase(&pHead,Find(pHead,3));
	Remove(&pHead,6);
	Print(pHead);
	cout<<endl<<Empty(pHead)<<endl;
	cout<<Size(pHead)<<endl;
	Destroy(&pHead);
}

void Test4()
{
	pNode pHead;
	InitSlist(&pHead);
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	Reverse(pHead);
	DeleteListNotTail(&pHead,Find(pHead,2));
	cout<<endl;
	Print(pHead);
	InsertNotHead(&pHead,Find(pHead,3),2);
	Print(pHead);
	cout<<FindMidNode(pHead)->data<<endl;
	pHead = JosephCircle(&pHead,3);
	cout<<pHead->data<<endl;
	pHead->next = NULL;
	cout<<FindMidNode(pHead)->data<<endl;
}

void Test5()
{
	pNode pHead;
	InitSlist(&pHead);
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	Print(pHead);
	cout<<FindLastK(pHead,3)->data<<endl;
	cout<<FindLastK(pHead,1)->data<<endl;
	cout<<FindLastK(pHead,4)->data<<endl;

}
void Test6()
{
	pNode pHead;
	InitSlist(&pHead);
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	Print(pHead);
	ReverseList(pHead);
	Print(pHead);

}
void Test7()
{
	pNode pHead1;
	InitSlist(&pHead1);
	PushBack(&pHead1,1);
	PushBack(&pHead1,3);
	PushBack(&pHead1,5);
	PushBack(&pHead1,7);
	pNode pHead2;
	InitSlist(&pHead2);
	PushBack(&pHead2,1);
	PushBack(&pHead2,2);
	PushBack(&pHead2,4);
	PushBack(&pHead2,6);
	//pHead1 = MergeList(pHead1,pHead2);
	//Print(pHead1);
	cout<<endl<<IsCross(pHead1,pHead2)<<endl;

}
void Test8()
{
	pNode pHead1;
	InitSlist(&pHead1);
	PushBack(&pHead1,4);
	PushBack(&pHead1,3);
	PushBack(&pHead1,8);
	PushBack(&pHead1,7);
	BubbleSort(pHead1);
	Print(pHead1);
}

void Test9()
{
	pNode pHead1;
	InitSlist(&pHead1);
	PushBack(&pHead1,4);
	PushBack(&pHead1,3);
	PushBack(&pHead1,8);
	PushBack(&pHead1,7);
	BubbleSort(pHead1);
	pNode newNode = Find(pHead1,7);
	pNode pHead2;
	InitSlist(&pHead2);
	PushBack(&pHead2,1);
	PushBack(&pHead2,2);
	PushBack(&pHead2,6);
	pNode pNewNode = Back(pHead2);
	pNewNode->next = newNode;
	cout<<IsCross(pHead1,pHead2)<<endl;
	cout<<CrossNum(pHead1,pHead2)->data<<endl;
}
void Test10()
{
	pNode pHead1;
	InitSlist(&pHead1);
	PushBack(&pHead1,4);
	PushBack(&pHead1,3);
	PushBack(&pHead1,8);
	PushBack(&pHead1,7);
	PushBack(&pHead1,6);
	pNode pHead2;
	InitSlist(&pHead2);
	PushBack(&pHead2,1);
	PushBack(&pHead2,2);
	PushBack(&pHead2,6);
	pNode NewNode = Find(pHead1,7);
	pNode pNewNode = Back(pHead1);
	pNewNode->next = NewNode;
	pNode ppNode = Back(pHead2);
	pNode ppNewNode = Find(pHead1,8);
	ppNode->next = ppNewNode;
	//Print(pHead1);
	cout<<IsCrossWithCircle(pHead1,pHead2)<<endl;
	cout<<CrossNumWithCircle(pHead1,pHead2)->data<<endl;
}

int main()
{
	Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	getchar();
	return 0;
}

//#include"SList.h"
//void InitSeqList(pSeqList seq)
//{
//	seq->data = NULL;
//	seq->size = 0;
//	seq->capacity = 0;
//
//}
//void Test()
//{
//	SeqList seq;
//	InitSeqList(&seq);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}o # learngit
