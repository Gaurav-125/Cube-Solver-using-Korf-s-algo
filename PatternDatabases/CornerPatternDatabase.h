//
// Created by KIIT0001 on 01-10-2026.
//

#ifndef RUBIK_S_CUBE_CORNERPATTERNDATABASE_H
#define RUBIK_S_CUBE_CORNERPATTERNDATABASE_H

#include "../GenericsRubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase:public PatternDatabase{

    typedef GenericsRubiksCube::FACE F;
    PermutationIndexer<8> permIndexer;
public:

    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const GenericsRubiksCube &cube) const override;
};

#endif //RUBIK_S_CUBE_CORNERPATTERNDATABASE_H
