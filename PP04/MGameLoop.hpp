#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{		}
		void Release()
		{		}

		void Input()
		{		}
		void Update()
		{		}
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);


			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			cout << "FPS speed : " << 1.0/renderDuration.count()<< endl;

		int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		if (remainingFrameTime > 0)
			this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		}
	};
}
