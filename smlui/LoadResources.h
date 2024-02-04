//==--------------------------------------------------==
//   Samm's Markup Language for C++ UI
//   (c) 2024 Samm
//   Read LICENSE file
//==--------------------------------------------------==
#ifndef SMLUI_LOAD_RESOURCES_H
#define SMLUI_LOAD_RESOURCES_H
#include <iostream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <resource.h>

namespace SML_UI {
#ifdef _WIN32
    HMODULE GCM()
    {
        HMODULE hModule = NULL;
        GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)GCM, &hModule);
        return hModule;
    }
#endif

    std::string Load_TXT_Res(int res, int res_type)
    {
        std::string result;
#ifdef _WIN32
        HRSRC hRes = FindResource(GCM(), MAKEINTRESOURCE(resource), MAKEINTRESOURCE(TXT));
        if (hRes != 0)
        {
            HGLOBAL hData = LoadResource(GCM(), hRes);
            DWORD hSize = SizeofResource(GCM(), hRes);

            char* hFinal = (char*)LockResource(hData);
            result.assign(hFinal, hSize);

            return result;
        }
#elif __linux__

#elif __ANDROID__

#elif __APPLE__
#elif __unix__

#endif

        return "";
    }
};

#endif
