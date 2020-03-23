//#
//# Copyright (C) 2018-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef MINIGMP_GLOBAL_H
#define MINIGMP_GLOBAL_H

#ifdef _WIN32
#  define MINIGMPSHARED_EXPORT __declspec(dllexport)
#endif

#if defined (linux) || defined (__APPLE__)
#  define MINIGMPSHARED_EXPORT __attribute__((visibility("default")))
#endif



#endif //MINIGMP_GLOBAL_H
