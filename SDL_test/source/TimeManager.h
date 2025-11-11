#pragma once
#include <SDL3/SDL_timer.h>
#include<math.h>


#define TIME TimeManager::GetInstance()


class TimeManager
{
private:
	//time control
	float _deltaTime;
	float _elapseTime;
	float _priviosElapseTime;

	//FPS
	const int _FPS = 60;
	float _frameTime;
	

public:

	static TimeManager* GetInstance() {
		static TimeManager instance;
		return &instance;
	}

	float GetDeltaTime() { return _deltaTime; }
	float GetElapseTime() { return _elapseTime; }
	bool ShouldUpdateGame() const { return _deltaTime >= _frameTime; }
													     //calcula es frames que t'as pasat      //quan de temps tarda un frame
	void RestartDeltaTime() { _deltaTime = _deltaTime - (float)(floor(_deltaTime / _frameTime) * _frameTime); }


	void Update() {
		_elapseTime = (double)SDL_GetTicks() / 1000.0;
		_deltaTime += _elapseTime - _priviosElapseTime;
		_priviosElapseTime = _elapseTime;
	}

private:
	TimeManager() {
		_deltaTime = 0.0f;
		_elapseTime = 0.0f;
		_priviosElapseTime = (double)SDL_GetTicks() / 1000.f;
	
		_frameTime = 1.0f / (float)_FPS;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager& t) = delete;
	TimeManager& operator=(const TimeManager& t) = delete;



};
