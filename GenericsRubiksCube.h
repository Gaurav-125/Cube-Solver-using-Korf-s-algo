//
// Created by KIIT0001 on 11-06-2026.
//

#ifndef RUBIK_S_CUBE_GENERICSRUBIKSCUBE_H
#define RUBIK_S_CUBE_GENERICSRUBIKSCUBE_H

#include "bits/stdc++.h"
using namespace std;

class GenericsRubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2,
    };

    virtual COLOR getColor(FACE face,unsigned row,unsigned col) const = 0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const = 0;

    static string getMove(MOVE ind);

    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);

    /*
     * Perform moves on Rubiks Cube
     */
    GenericsRubiksCube &move(MOVE ind);

    /*
     * Perform invert move on Rubiks Cube
     */
    GenericsRubiksCube &invert(MOVE ind);

    virtual GenericsRubiksCube &f() = 0;
    virtual GenericsRubiksCube &fPrime() = 0;
    virtual GenericsRubiksCube &f2() = 0;

    virtual GenericsRubiksCube &u() = 0;
    virtual GenericsRubiksCube &uPrime() = 0;
    virtual GenericsRubiksCube &u2() = 0;

    virtual GenericsRubiksCube &l() = 0;
    virtual GenericsRubiksCube &lPrime() = 0;
    virtual GenericsRubiksCube &l2() = 0;

    virtual GenericsRubiksCube &r() = 0;
    virtual GenericsRubiksCube &rPrime() = 0;
    virtual GenericsRubiksCube &r2() = 0;

    virtual GenericsRubiksCube &d() = 0;
    virtual GenericsRubiksCube &dPrime() = 0;
    virtual GenericsRubiksCube &d2() = 0;

    virtual GenericsRubiksCube &b() = 0;
    virtual GenericsRubiksCube &bPrime() = 0;
    virtual GenericsRubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;
    uint8_t getCornerIndex(uint8_t ind) const;
    uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif //RUBIK_S_CUBE_GENERICSRUBIKSCUBE_H
