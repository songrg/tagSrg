// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.

#pragma once
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#include <vector>
#include <d3dx9.h>

// 전역 윈도우 핸들
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

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include "cDeviceManager.h"
#include "cState.h"
#include "cCamera.h"
#include "cKeyManager.h"
#include "cLight.h"