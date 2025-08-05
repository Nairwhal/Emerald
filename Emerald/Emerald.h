#pragma once

#include <iostream>
#include <fstream>
#include "Context.h"
#include "Content.h"

int main();
char* fileToBuffer(const char*, int*);
void createCNC(std::vector<Context*>*, std::vector<Content*>*, char*, int*);