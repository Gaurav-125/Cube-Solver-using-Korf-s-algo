//
// Created by KIIT0001 on 27-09-2026.
//

// this solution is just like IDDFS
// f(n) = g(n) + h(n), here we have take h(n) = 0;


#ifndef RUBIK_S_CUBE_IDASTARSOLVER_H
#define RUBIK_S_CUBE_IDASTARSOLVER_H

#include <bits/stdc++.h>
#include "../GenericsRubiksCube.h"

template<typename T,typename H>
class IDAstarSolver {   // this implementation is just like IDDFS, h(n) = 0;
private:
    vector<GenericsRubiksCube::MOVE> moves;
    int threashold=0;

    bool search(int depth) {
        if (rubiksCube.isSolved()) {
            // cout<<"RubiksCube is Solved";
            return true;
        }

        // f(n)=g(n)+h(n)
        // currently h(n)=0;
        int f=depth;
        // if f exceeds threadhold don't explore this node
        if (f>threashold) return false;

        for (int i=0;i<18;i++) {
            rubiksCube.move(GenericsRubiksCube::MOVE(i));
            moves.push_back(GenericsRubiksCube::MOVE(i));

            if (search(depth+1)) return true;

            moves.pop_back();
            rubiksCube.invert(GenericsRubiksCube::MOVE(i));
        }
        return false;
    }
public:
    T rubiksCube;
    IDAstarSolver(T& _rubiksCube): rubiksCube(_rubiksCube) { }

    vector<GenericsRubiksCube::MOVE> solve() {
        while (true) {
            if (search(0)) {
                // if (rubiksCube.isSolved()) cout<<"RubiksCube is solved\n";
                return moves;
            }
            threashold++;         //Unlike IDDFS there is no fixed max_value of threashold, it will kept increasing till any depth to find solution
        }


    }
};

#endif //RUBIK_S_CUBE_IDASTARSOLVER_H
