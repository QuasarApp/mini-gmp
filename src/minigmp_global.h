//#
//# Copyright (C) 2018-2021 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef MINIGMP_GLOBAL_H
#define MINIGMP_GLOBAL_H

#ifdef _WIN32
#  define MINIGMPSHARED_EXPORT __declspec(dllexport)
#elif (linux) || defined (__linux__) || defined (__APPLE__)
#  define MINIGMPSHARED_EXPORT __attribute__((visibility("default")))
#else
#  define MINIGMPSHARED_EXPORT
#endif



#endif //MINIGMP_GLOBAL_H
