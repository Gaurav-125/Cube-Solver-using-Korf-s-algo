//
// Created by KIIT0001 on 20-09-2026.
//

#include<bits/stdc++.h>
#include "../GenericsRubiksCube.h"

#ifndef RUBIK_S_CUBE_SOLVER_DFSSOLVER_H
#define RUBIK_S_CUBE_SOLVER_DFSSOLVER_H

template<typename T,typename H>

class DFSsolver {
private:
    vector<GenericsRubiksCube::MOVE> moves;
    int max_search_depth;

    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep>max_search_depth) {
            return false;
        }
        for (int i=0;i<18;i++) {
        rubiksCube.move(GenericsRubiksCube::MOVE(i));
        moves.push_back(GenericsRubiksCube::MOVE(i));
        if (dfs(dep+1)) return true;
        moves.pop_back();
        rubiksCube.invert(GenericsRubiksCube::MOVE(i));
        }
        return false;
    }
public:
    T rubiksCube;
    DFSsolver(const T &_rubiksCube,int _max_depth=8): rubiksCube(_rubiksCube),max_search_depth(_max_depth){
        // rubiksCube=_rubiksCube;
        // max_search_depth=_max_depth;
        // cout<<"\n"<<"constructor:\n";
        // rubiksCube.print();
        // _rubiksCube.print();
    }

    vector<GenericsRubiksCube::MOVE> solve() {

        // cout<<"\nDFS CUBE\n";
        // rubiksCube.print();
        dfs(1);

        // if (rubiksCube.isSolved())cout<<"\nSolved\n";
        // rubiksCube.print();
        return moves;
    }

};

#endif
