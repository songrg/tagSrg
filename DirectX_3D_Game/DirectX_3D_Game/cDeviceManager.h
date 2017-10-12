#pragma once
// 싱글톤으로 만들어진 DirectX Device

#define g_pDeviceManager cDeviceManager::GetInstance()
#define g_pD3DDevice	 cDeviceManager::GetInstance()->GetDevice()

class cDeviceManager
{
SINGLETONE(cDeviceManager)

private:
	LPDIRECT3D9		  m_pD3D;				// DirectX 3D 디바이스를 생성할 d3d객체 변수
	LPDIRECT3DDEVICE9 m_pD3DDevice; // 그래픽 카드를 사용하기 위한 오브젝트 (포인터 변수)

public:
	LPDIRECT3DDEVICE9 GetDevice();
	void Destroy();
};