#pragma once
#ifndef SELECTOR_RESOLUCIONES_H
#define SELECTOR_RESOLUCIONES_H

#include "../initialicer/MINELLAX.H"

using namespace std;

extern vector<pair<int, int>> resolutions;
extern int currentResolutionIndex;

void changeResolution(int width, int height);
void render();
void keyboard(int key, int action);

#endif 