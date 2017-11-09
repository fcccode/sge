#pragma once

#include <Windows.h>

namespace sge
{
    class Timer
    {
    public:
        Timer()
        {
            LARGE_INTEGER cpuQPF;
            bool ret = QueryPerformanceFrequency(&cpuQPF);
            if (ret)
            {
                liQPF = (float)cpuQPF.QuadPart;
            }
        }

        // ��λ�룬��ȷ��us
        inline float elapsed()
        {
            LARGE_INTEGER nowTime;
            QueryPerformanceCounter(&nowTime);
            float elapsed = (nowTime.QuadPart - liLastTime) / liQPF;
            liLastTime = nowTime.QuadPart;
            return elapsed;
        }

    private:
        float liQPF;
        LONGLONG liLastTime;
    };

} // !namespace