#pragma once
#include <bitset>

#define KEYMAX 256
#define KEY cKeyManager::GetInstance()

using namespace std;

class cKeyManager
{
	SINGLETONE(cKeyManager)
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	HRESULT init();
	void release();

	//Ű�� �ѹ��� ���ǳ�?
	bool isOnceKeyDown(int key);
	//Ű�� �ѹ� ������ �����?
	bool isOnceKeyUp(int key);
	//Ű�� ��� �����ֳ�?
	bool isStayKeyDown(int key);
	//���Ű��?(ĸ����,�ѹ���)
	bool isToggleKey(int key);
};

