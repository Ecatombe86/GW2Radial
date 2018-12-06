#pragma once

#include <Main.h>
#include <Singleton.h>
#include <d3dx9.h>

namespace GW2Addons
{

class UnitQuad;

class Core : public Singleton<Core>
{
public:
	static void Init(HMODULE dll);
	static void Shutdown();

	~Core();

	HWND gameWindow() const { return gameWindow_; }
	HMODULE dllModule() const { return dllModule_; }
	WNDPROC baseWndProc() const { return baseWndProc_; }
	uint screenWidth() const { return screenWidth_; }
	uint screenHeight() const { return screenHeight_; }
	const std::unique_ptr<UnitQuad>& quad() const { return quad_; }
	ID3DXEffect* mainEffect() const { return mainEffect_; }

protected:
	void InternalInit();
	HWND gameWindow_ = nullptr;
	HMODULE dllModule_ = nullptr;
	WNDPROC baseWndProc_ = nullptr;

	uint screenWidth_ = 0, screenHeight_ = 0;

	std::unique_ptr<UnitQuad> quad_;
	ID3DXEffect* mainEffect_ = nullptr;
};
}
