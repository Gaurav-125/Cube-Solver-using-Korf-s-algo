//
// Created by KIIT0001 on 22-09-2026.
//

#ifndef RUBIK_S_CUBE_BFSSOLVER_H
#define RUBIK_S_CUBE_BFSSOLVER_H

#include <bits/stdc++.h>
#include "../GenericsRubiksCube.h"

template<typename T,typename H>
class BFSsolver {
private:
    vector<GenericsRubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T,GenericsRubiksCube::MOVE,H> moves_done;
    // int count=0;
    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube]=true;
        while (!q.empty()) {
            T node=q.front();
            q.pop();
            if (node.isSolved()) return node;

            for (int i=0;i<18;i++) {
                auto curr_move=GenericsRubiksCube::MOVE(i);
                node.move(curr_move);
                if (!visited[node]) {
                    q.push(node);
                    moves_done[node]=curr_move;
                    visited[node]=true;
                }
                node.invert(GenericsRubiksCube::MOVE(i));
            }
        }
        // cout<<"RubiksCube\n";
        // rubiksCube.print();
        return rubiksCube;
    }
public:
    T rubiksCube;
    BFSsolver(T& _rubiksCube): rubiksCube(_rubiksCube) {
        // cout<<"Constructor";
        // rubiksCube.print();
    }

    vector<GenericsRubiksCube::MOVE> solve() {
        T solved_cube=bfs();
        // cout<<"Solve\n";
        // solved_cube.print();
        assert(solved_cube.isSolved());
        T curr_cube=solved_cube;
        while (!(curr_cube==rubiksCube)) {

            auto curr_move=moves_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube=solved_cube;
        // solved_cube.print();
        reverse(moves.begin(),moves.end());

        return moves;
    }
};


#endif //RUBIK_S_CUBE_BFSSOLVER_H
