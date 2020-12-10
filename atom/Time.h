#ifndef __ATOM_ENGINE_TIME_LIBRARY_H__
#define __ATOM_ENGINE_TIME_LIBRARY_H__

/* Connected to Atom Engine library header */

#pragma region Comments
//
// This section is all about Time related stuff
// Time declaration for this section is found at Time.cpp
//
#pragma endregion

#include "glut.h"

namespace TimeLib {
	namespace Library {
		class Time {
		public:
			Time();
			~Time();

			void LocalObserve();
			float LocalDeltaTime();
			float LocalTimeElapsed();
			void LocalReset();
		
			static void Observe();
			static float DeltaTime();
			static float TimeElapsed();
			static void Reset();
			static float GetFPS();
		private:
			float prevTime;
			float presTime;
			float startTime;

			float dt;
			float time_elapsed;
		protected:
		};
	}
}

#endif