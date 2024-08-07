#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <string>
#include <vector>
#include <map>
#include <filesystem>
//#include <pybind11/pybind11.h>

class ProcessInfo {
public:
    int pid;
    std::string user;
    std::string name;
    std::string status;
    long memory;
    double cpu_usage;

    ProcessInfo(int pid, std::string user, std::string name, std::string status, long memory, double cpu_usage);

    //std::map<std::string, pybind11::object> to_dict() const;
};

class ProcessMonitor {
public:
    std::vector<ProcessInfo> getProcesses();
    void monitorProcesses(int interval_seconds);

private:
    bool is_number(const std::string& s);
    std::string getProcessUser(int pid);
    std::string getProcessName(int pid);
    std::string getProcessStatus(int pid);
    long getProcessMemory(int pid);
    double getProcessCpuUsage(int pid);
};

bool compareByCpuUsage(const ProcessInfo& a, const ProcessInfo& b);
bool compareByMemory(const ProcessInfo& a, const ProcessInfo& b);

#endif // PROCESS_MONITOR_H
