// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.

#pragma once
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#include <vector>
#include <d3dx9.h>

// ���� ������ �ڵ�
extern HWND g_hWnd;

// SingleTone Base
#define SINGLETONE(class_name)\
private:\
	class_name();\
	~class_name();\
public:\
	static class_name* GetInstance()\
	{\
		static class_name instance;\
		return &instance;\
	}

// GET,SET 
#define SYNTHSIZE(varType, varName, funcName)\
	protected: varType varName;\
	public: varType Get##funcName(void) const { return varName; }\
	public: void Set##funcName(varType var) { varName = var; }

// Delete, Release
#define SAFE_DELETE(p) { if(p) delete p; p = NULL; }
#define SAFE_RELEASE(p) { if(p) p->Release(); p = NULL; }

// VerTex Pos
struct ST_PC_VERTEXT
{
	D3DXVECTOR3 p;
	D3DCOLOR c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

// TexTure VerTex Pos
struct ST_PC_TEXTURE_VERTEXT
{
	D3DXVECTOR3 p;
	D3DXVECTOR2 T;
	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

#define DEGREE D3DX_PI/180

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include "cDeviceManager.h"
#include "cState.h"
#include "cCamera.h"
#include "cKeyManager.h"
#include "cLight.h"