//
// Created by KIIT0001 on 22-09-2026.
//

#ifndef RUBIK_S_CUBE_IDDFSSOLVER_H
#define RUBIK_S_CUBE_IDDFSSOLVER_H

#include<bits/stdc++.h>
#include "../GenericsRubiksCube.h"
#include "DFSsolver.h"

template<typename T,typename H>
class IDDFSsolver {
private:
    vector<GenericsRubiksCube::MOVE> moves;
    int max_depth;
public:
    T rubiksCube;

    IDDFSsolver(T &_rubiksCube,int max_search_depth): rubiksCube(_rubiksCube){
        // rubiksCube=_rubiksCube;
        max_depth=max_search_depth;
        // cout<<"constructor:"<<max_depth<<" ";
        // rubiksCube.print();
        // cout<<(rubiksCube==_rubiksCube)<<"\n";
    }

    vector<GenericsRubiksCube::MOVE> solve() {
        for (int i=1;i<=max_depth;i++) {
            DFSsolver<T,H> dfsSolver(rubiksCube,i);
            moves=dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube=dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif //RUBIK_S_CUBE_IDDFSSOLVER_H
