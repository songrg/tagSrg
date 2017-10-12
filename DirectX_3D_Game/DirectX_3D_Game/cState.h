#pragma once

#define g_eSTATE	cState::GetInstance()

enum STATE
{
	STAND, RUN, BACK,
	NONE,
	FINGHER5, FINGHER4, FINGHER3, FINGHER2, FINGHER1, ALL
};

class cState
{
	SINGLETONE(cState)

private:
	STATE m_eState;

public:
	STATE GetState() { return m_eState; }
	void SetState(STATE state) { m_eState = state; }
};

