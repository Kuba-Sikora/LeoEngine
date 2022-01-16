#pragma once

#include "Leo/Core/Base.h"

namespace Leo {

	class LEO_API FPSTimer
	{

	public:
		FPSTimer()
		{
			m_CurrentCount = 0;
			m_Interval = NULL;
			m_CycleStartTime = 0;
		}

		inline int getCount() { return m_CurrentCount; }
		inline void incrementCount() { m_CurrentCount++; }

		void setInterval(unsigned int interval) { m_Interval = interval; }

		void resetCycle() {
			m_CurrentCount = 0;
			m_CycleStartTime = clock();
		}

		unsigned long getElapsedTime() {
			return ((unsigned long) clock() - m_CycleStartTime) / CLOCKS_PER_SEC;
		}

		void update()
		{
			incrementCount();

			if (m_Interval && getElapsedTime() >= m_Interval)
			{
				onInterval();
				resetCycle();
			}
		}

		void onInterval();


	private:
		unsigned int m_CurrentCount;
		unsigned int m_Interval;
		unsigned long m_CycleStartTime;

	};

}