//
// Created by KIIT0001 on 27-09-2026.
//

#ifndef RUBIK_S_CUBE_IDASTARSOLVER2_H
#define RUBIK_S_CUBE_IDASTARSOLVER2_H

#include "bits/stdc++.h"
#include "../GenericsRubiksCube.h"
#include "../PatternDatabases/CornerPatternDatabase.h"

template<typename T,typename H>
class IDAstarSolver2 {
private:
    CornerPatternDatabase cornerdb;
    vector<GenericsRubiksCube::MOVE> moves;
    unordered_map<T,GenericsRubiksCube::MOVE,H> move_done;
    unordered_map<T, bool, H> visited;

    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube, int _depth, int _estimate):cube(_cube), depth(_depth), estimate(_estimate) {};
    };

    struct compareCube {
        bool operator()(pair<Node, int> const &p1, pair<Node,int> const &p2) const {
            auto n1 = p1.first, n2 = p2.first;
            if (n1.depth + n1.estimate == n2.depth + n2.estimate)
                return n1.estimate>n2.estimate;
            else return n1.depth + n1.estimate > n2.depth + n2.estimate;
        }
    };

    void resetStructure(){
        moves.clear();
        move_done.clear();
        visited.clear();
    }

    pair<T ,int> IDAstar(int bound) {
        priority_queue<pair<Node, int>, vector<pair<Node,int>>, compareCube> pq;
        Node start = Node(rubiksCube,0,cornerdb.getNumMoves(rubiksCube));
        pq.push(make_pair(start,0)); // start-> starting node/state   0->move used to reach this cube, for starting node no move is made, so 0 is taken as dummy move
        int next_bound=100;
        int count=0;
        while (!pq.empty()) {
            count++;
            auto p = pq.top();
            Node node=p.first;
            pq.pop();

            if (visited[node.cube]) continue;

            visited[node.cube]=true;
            move_done[node.cube] = GenericsRubiksCube::MOVE(p.second);

            if (node.cube.isSolved()) {
                cout<<"final Nodes explored: "<<count<<'\n';
                return make_pair(node.cube,bound);
            }
            node.depth++;
            // if (node.depth==9) break;
            for (int i=0;i<18;i++) {
                auto curr_move=GenericsRubiksCube::MOVE(i);
                node.cube.move(curr_move);
                if (!visited[node.cube]) {
                    node.estimate=cornerdb.getNumMoves(node.cube);
                    // if (node.estimate) count++;
                    // cout<<node.estimate<<'\n';
                    if (node.estimate + node.depth > bound) {
                            next_bound=min(next_bound,node.estimate+node.depth);
                    }else {
                        pq.push(make_pair(node,i));
                    }
                }
                node.cube.invert(curr_move);
            }
        }
        cout<<"Nodes explored: "<<count<<'\n';
        return make_pair(rubiksCube,next_bound);
    }

public:
    T rubiksCube;

    IDAstarSolver2(T& _rubiksCube, string fileName):rubiksCube(_rubiksCube) {
        cornerdb.fromFile(fileName);
    }

    vector<GenericsRubiksCube::MOVE> solve() {
        int bound=1;
        auto p=IDAstar(bound);
        while (p.second!=bound) {
            resetStructure();
            bound=p.second;
            p=IDAstar(bound);
        }
        T solved_cube = p.first;
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube==rubiksCube)) {
            GenericsRubiksCube::MOVE curr_move=move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube=solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};

#endif //RUBIK_S_CUBE_IDASTARSOLVER2_H
