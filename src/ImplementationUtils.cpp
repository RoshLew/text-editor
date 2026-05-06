#include "ImplementationUtils.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

std::string ImplementationUtils::getWorkingDirectory(const std::string &argvZero) {
#if defined(_WIN32) || defined(_WIN64)
    char path[MAX_PATH] = {0};
    DWORD length = GetModuleFileNameA(NULL, path, MAX_PATH);
    if (length == 0 || length == MAX_PATH) {
        return std::string();
    }

    std::string fullPath(path, length);
    std::size_t pos = fullPath.find_last_of("\\/");
    return (pos == std::string::npos) ? std::string() : fullPath.substr(0, pos + 1);
#else
    int i = argvZero.find_last_of('/');
    return argvZero.substr(0, i + 1);
#endif
}
