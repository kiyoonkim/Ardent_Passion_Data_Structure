#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("���� �Ұ�");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int removePos = plist->curPosition;
	int lastPos = plist->numOfData - 1;
	LData removeData = plist->arr[removePos];

	for (int i = removePos; i < lastPos; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->curPosition)--;	// ������ ���� �ʾұ� ������ 1��ŭ ������ �̵�
	(plist->numOfData)--;
	return removeData;
}

int LCount(List* plist)
{
	return (plist->numOfData);
}