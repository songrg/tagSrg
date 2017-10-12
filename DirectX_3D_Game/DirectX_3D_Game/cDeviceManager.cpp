#include "stdafx.h"
#include "cDeviceManager.h"

cDeviceManager::cDeviceManager()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);	// DirectX 3D 객체 생성 (레퍼런스 카운트 1 증가)

	// 그래픽 카드 제원 파악
	D3DCAPS9 d3dCaps;
	int nVertexProcessing;

	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);

	if (d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	// 렌더링에 필요한 정보
	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(D3DPRESENT_PARAMETERS));
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;	// 더블 버퍼링 사용
	d3dPP.Windowed = TRUE;						// 윈도우 모드 사용 여부
	d3dPP.BackBufferFormat = D3DFMT_UNKNOWN;	// 백 버퍼 사이즈 지정
	d3dPP.EnableAutoDepthStencil = TRUE;		// 스탠실 버퍼 사용 여부.
	d3dPP.AutoDepthStencilFormat = D3DFMT_D16;	// 스탠실 버퍼 크기 지정

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,	// 디바이스 생성
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&d3dPP,
		&m_pD3DDevice);
}

cDeviceManager::~cDeviceManager()
{

}

LPDIRECT3DDEVICE9 cDeviceManager::GetDevice()
{
	return m_pD3DDevice;
}

void cDeviceManager::Destroy()
{
	SAFE_RELEASE(m_pD3D);
	ULONG ul = m_pD3DDevice->Release();

	//assert(ul == 0 && "디바이스를 이용해 생성된 객체 중 해제되지 않은 객체가 있습니다");
}
