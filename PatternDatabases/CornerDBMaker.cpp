//
// Created by KIIT0001 on 01-10-2026.
//

#include "CornerDBMaker.h"
using namespace std;

CornerDBMaker::CornerDBMaker(string _filename) {
    filename=_filename;
}

CornerDBMaker::CornerDBMaker(string _filename, uint8_t init_val) {
    filename=_filename;
    cornerDB=CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndstore() {
    RubiksCubeBitboard cube;
    queue<RubiksCubeBitboard> q;
    q.push(cube);
    cornerDB.setNumMoves(cube,0);
    int currDepth=0;
    while (!q.empty()) {
        int n=q.size();
        currDepth++;
        cout<<currDepth<<'\n';
        if (currDepth==7) break;
        for (int c=0;c<n;c++) {
            RubiksCubeBitboard node=q.front();
            q.pop();
            for (int i=0;i<18;i++) {
                auto curr_move=GenericsRubiksCube::MOVE(i);
                node.move(curr_move);
                if ((int)cornerDB.getNumMoves(node) > currDepth) {
                    cornerDB.setNumMoves(node,currDepth);
                    // cout<<"push: "<<currDepth<<'\n';
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }
    // cornerDB.toFile(filename);
    return true;
}
