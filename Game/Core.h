#pragma once

#include "stdio.h"

// a macro
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
