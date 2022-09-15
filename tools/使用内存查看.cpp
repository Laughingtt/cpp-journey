#include <iostream>
#include <iomanip>

#include <vector>

// #include <windows.h>
// #include <psapi.h>
#pragma comment(lib,"psapi.lib")

void ShowProcessMemoryUsageInfo()
{
    HANDLE handle = GetCurrentProcess();
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
    float memoryUsage_M = pmc.WorkingSetSize / (1024.0 *1024.0);
    float memoryUsage_K = pmc.WorkingSetSize / 1024.0 ;

    std::cout << std::fixed << std::setprecision(2) << "内存使用:" << memoryUsage_K<<"K " << memoryUsage_M << "M" << std::endl;
}


int main()
{
    ShowProcessMemoryUsageInfo();
    std::vector<int> t_TempIntVec;

    for (int i=0;i<100000;++i)
    {
        t_TempIntVec.push_back(i);
    }
    ShowProcessMemoryUsageInfo();

    std::vector<int> emptyVec;
    t_TempIntVec.swap(emptyVec);

    EmptyWorkingSet(GetCurrentProcess());

    ShowProcessMemoryUsageInfo();


    getchar();
    return 0;
}