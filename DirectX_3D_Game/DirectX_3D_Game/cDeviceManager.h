#pragma once
// �̱������� ������� DirectX Device

#define g_pDeviceManager cDeviceManager::GetInstance()
#define g_pD3DDevice	 cDeviceManager::GetInstance()->GetDevice()

class cDeviceManager
{
SINGLETONE(cDeviceManager)

private:
	LPDIRECT3D9		  m_pD3D;				// DirectX 3D ����̽��� ������ d3d��ü ����
	LPDIRECT3DDEVICE9 m_pD3DDevice; // �׷��� ī�带 ����ϱ� ���� ������Ʈ (������ ����)

public:
	LPDIRECT3DDEVICE9 GetDevice();
	void Destroy();
};