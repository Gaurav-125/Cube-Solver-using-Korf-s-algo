//
// Created by KIIT0001 on 01-10-2026.
//

#ifndef RUBIK_S_CUBE_CORNERDBMAKER_H
#define RUBIK_S_CUBE_CORNERDBMAKER_H

#include "CornerPatternDatabase.h"
#include "../GenericsRubiksCube.h"
#include "../RubiksCubeBitboard.cpp"
using namespace std;

class CornerDBMaker {
private:
    string filename;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _filename);
    CornerDBMaker(string _filename,uint8_t init_val);

    bool bfsAndstore();
};

#endif //RUBIK_S_CUBE_CORNERDBMAKER_H
