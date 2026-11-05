#include <bits/stdc++.h>
#include "GenericsRubiksCube.h"
#include "./solver/DFSsolver.h"
#include "./solver/IDDFSsolver.h"
#include "./RubiksCube3dArray.cpp"
#include "./RubiksCube1dArray.cpp"
#include "./RubiksCubeBitboard.cpp"
#include "PatternDatabases/CornerDBMaker.h"
#include "solver/BFSsolver.h"
#include "solver/IDAstarSolver.h"
#include "solver/IDAstarSolver2.h"

#include "chrono"
#include<fstream>
using namespace std;

int getindex(int i,int j,int k){
    return i*9 + j*3 + k;
}

int main(){
    // Taking input from a text file
    char arr[54];
    string line;
    ifstream myfile;
    // cout<<"File\n";
    myfile.open("file_path",ios::in);
    if(!myfile.is_open())
        throw runtime_error("Problem in opening file");
    // cout<<"File open\n";
    int i=0;
    while(getline(myfile,line)){
        // cout<<line<<'\n';
        for(auto l:line){
            if(l>=65 && l<=90){
                arr[i]=l;
                i++;
            }
        }
    }
    myfile.close();
    // cout<<"file closed";
    char arr1[6][3][3];


    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                arr1[i][j][k]=arr[getindex(i,j,k)];
            }
        }
    }

    // for(int i=0;i<6;i++){
    //     for(int j=0;j<3;j++){
    //         for(int k=0;k<3;k++){
    //             cout<<arr1[i][j][k]<<' ';
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }

    // RubiksCube3dArray cube(arr1);
    // cube.print();

    // RubiksCube1dArray cube(arr);
    // cube.print();

    // RubiksCubeBitboard cube(arr1);
    // cube.print();

// cube successfully loaded from text file and printed





    // DFS solver testing
    // keep randomshuffle less than max_depth
    // 3d array representation testing
    // RubiksCube3dArray cube;
    // // if (cube.isSolved()) cout<<"Solved\n";
    // cube.print();
    // // cout<<"\n";
    // // cube.move(GenericsRubiksCube::MOVE(1));
    // // cube.move(GenericsRubiksCube::MOVE(7));
    // // if (!cube.isSolved())cout<<"Not Solved\n";
    // // cube.print();
    // // cube.invert(GenericsRubiksCube::MOVE(2));
    // // cube.invert(GenericsRubiksCube::MOVE(1));
    // // cube.print();
    //
    // vector<GenericsRubiksCube::MOVE> shuffle_moves=cube.randomShuffleCube(5);
    // cout<<"Shuffled Cube: \n";
    // for (auto move:shuffle_moves) cout<<cube.getMove(move)<<' ';
    // cout<<'\n';
    // cube.print();
    //
    // DFSsolver<RubiksCube3dArray,hash3d> dfsolver(cube,5);
    //
    // cout<<"Solved Cube\n";
    // vector<GenericsRubiksCube::MOVE> solve_moves=dfsolver.solve();
    //
    // for (auto mov:solve_moves) {
    //     cout<<cube.getMove(mov)<<' ';
    //     cube.move(mov);
    // }
    // cout<<'\n';
    //
    // // cout<<solve_moves.size()<<"\n";
    // cube.print();
    // 3d array representation testing end; perfectly working


    // 1d array representation testing
    // RubiksCube1dArray cube;
    // cube.print();
    // // cube.move(GenericsRubiksCube::MOVE(1));
    // // cube.move(GenericsRubiksCube::MOVE(7));
    // // cube.print();
    // // cube.invert(GenericsRubiksCube::MOVE(7));
    // // cube.invert(GenericsRubiksCube::MOVE(1));
    // // // cube.invert(GenericsRubiksCube::MOVE(5));
    // // cube.print();
    //
    // vector<GenericsRubiksCube::MOVE> shuffled_moves=cube.randomShuffleCube(6);
    // cout<<"Shuffled Cube:\n";
    // for (auto mov:shuffled_moves) cout<<cube.getMove(mov)<<" ";
    // cout<<"\n";
    // cube.print();
    //
    // DFSsolver<RubiksCube1dArray,hash1d> dfsSolver(cube,5);
    // vector<GenericsRubiksCube::MOVE> solved_move=dfsSolver.solve();
    // cout<<"Solved Cube:\n";
    // for (auto mov:solved_move) {
    //     cout<<cube.getMove(mov)<<" ";
    //     cube.move(mov);
    // }
    // cout<<"\n";
    // if (cube.isSolved()) cube.print();
    // else cout<<"Not Solved";
    // 1d array representation testing end; perfectly working


    // bitboard representation testing
    // RubiksCubeBitboard cube;
    // cube.print();
    // // cube.move(GenericsRubiksCube::MOVE(3));
    // // cube.move(GenericsRubiksCube::MOVE(8));
    // // cube.print();
    // // cube.invert(GenericsRubiksCube::MOVE(8));
    // // cube.invert(GenericsRubiksCube::MOVE(3));
    // // cube.invert(GenericsRubiksCube::MOVE(12));
    // // cube.print();
    //
    // // cube.move(GenericsRubiksCube::MOVE(15));
    // // cube.invert(GenericsRubiksCube::MOVE(15));
    // // cout<<cube.getMove(GenericsRubiksCube::MOVE(15));
    //
    // vector<GenericsRubiksCube::MOVE> shuffled_move=cube.randomShuffleCube(2);
    // cout<<"Shuffled cube\n";
    // for (auto mov:shuffled_move) {
    //     cout<<cube.getMove(mov)<<" ";
    // }
    // cout<<"\n";
    // cube.print();
    //
    // DFSsolver<RubiksCubeBitboard,HashBitBoard> dfsSolver(cube,4);
    // vector<GenericsRubiksCube::MOVE> solved_move=dfsSolver.solve();
    // cout<<"Solved Cube:\n";
    // for (auto mov:solved_move) {
    //     cout<<cube.getMove(mov)<<" ";
    //     cube.move(mov);
    // }
    // cout<<"\n";
    // if (cube.isSolved())cube.print();
    // else cout<<"Not Solved";
    // bitboard representatio testing done; working fine

    // DFS solver testing ended; 3d and 1d are working perfectly; bitboard is working fine, implementation is correct sometime not producing solution due to depth limit


    // IDDFS solver testing
    // RubiksCube3dArray cube;
    // RubiksCube1dArray cube;
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<GenericsRubiksCube::MOVE> shuffled_move=cube.randomShuffleCube(1);
    // cout<<"Shuffled cube\n";
    // for (auto mov:shuffled_move) cout<<cube.getMove(mov)<<" ";
    // cout<<"\n";
    // cube.print();

    // IDDFSsolver<RubiksCubeBitboard,HashBitBoard> solver(cube,5);
    // vector<GenericsRubiksCube::MOVE> solved_move=solver.solve();
    // cout<<"Solved cube:\n";
    // for (auto mov:solved_move) {
    //     cout<<cube.getMove(mov)<<" ";
    //     cube.move(mov); // // or just equate with rubikscube object of IDDFS
    // }
    // cout<<"\n";
    // if (cube.isSolved()) {
    //     // cube=solver.rubiksCube;
    //     cube.print();
    // }
    // else cout<<"NOT solved";
    // IDDFS solver testing done; working perfectly fine with all the representations



    // BFS Solver
    // RubiksCube3dArray cube;
    // // RubiksCube1dArray cube;
    // // cout<<"BFS Solver\n";
    // // RubiksCubeBitboard cube;
    // cube.print();
    // //
    // vector<GenericsRubiksCube::MOVE> shuffled_moves=cube.randomShuffleCube(4);
    // cout<<"Shuffled Cube:\n";
    // for (auto mov:shuffled_moves) cout<<cube.getMove(mov)<<" ";
    // cout<<"\n";
    // cube.print();
    // //
    // BFSsolver<RubiksCube3dArray,hash3d> bfsSolver(cube);
    // vector<GenericsRubiksCube::MOVE> solved_move=bfsSolver.solve();
    // cout<<"Solved Cube:\n";
    // for (auto mov:solved_move) {
    //     cout<<cube.getMove(mov)<<" ";
    //     cube.move(mov);
    // }
    // cout<<"\n";
    //
    // // if (bfsSolver.rubiksCube.isSolved()) {
    // //     cube=bfsSolver.rubiksCube;
    // //     cube.print();
    // // }else {
    // //     cout<<"Not Solved";
    // // }
    //
    // if (cube.isSolved()) cube.print();
    // else cout<<"Not Solved";

    // BFS implementation ended, working perfectly



    // IDAstar solver without pattern database
    // RubiksCube3dArray cube;
    // RubiksCube1dArray cube;
    // RubiksCubeBitboard cube;
    // cube.print();
    // vector<GenericsRubiksCube::MOVE> shuffled_moves=cube.randomShuffleCube(8);
    // cout<<"Shuffled Moves: ";
    // for (auto mov:shuffled_moves) {
    //     cout<<cube.getMove(mov)<<" ";
    // }
    // cout<<"\n";
    // cube.print();
    // IDAstarSolver<RubiksCubeBitboard,HashBitBoard> solver(cube);
    // vector<GenericsRubiksCube::MOVE> solved_moves=solver.solve();
    //
    // if (solver.rubiksCube.isSolved()) {
    //     cout<<"Solved Rubik's Cube: ";
    //     for (auto mov:solved_moves) {
    //         cube.move(mov);
    //         cout<<cube.getMove(mov)<<" ";
    //     }
    //     cout<<"\n";
    //     cube.print();
    // }else cout<<"Cube not solved";

    // IDAstar without pattern database implementation ended, working perfectly



    // IDAstar with pattern database
    string fileName="filepath\\CornerDatabase1.txt";
    // CornerDBMaker dbMaker(fileName,0x99);
    // dbMaker.bfsAndstore();

    // RubiksCubeBitboard cube;
    // CornerPatternDatabase cornerdb;
    // cornerdb.fromFile(fileName);
    //
    // cube.randomShuffleCube(8);
    // cout<<"Heuristic: "<<static_cast<int>(cornerdb.getNumMoves(cube));



    RubiksCubeBitboard cube;
    // RubiksCube1dArray cube;
    // RubiksCube3dArray cube;
    cube.print();
    auto shuffle_moves=cube.randomShuffleCube(4);
    cout<<"Shuffled Moves: ";
    for (auto mov:shuffle_moves) cout<<cube.getMove(mov)<<" ";
    cout<<'\n';
    cube.print();

    IDAstarSolver2<RubiksCubeBitboard,HashBitBoard> Solver(cube,fileName);

    auto start=chrono::high_resolution_clock::now();
    //
    auto solved_moves=Solver.solve();
    //
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<"execution time: "<<duration.count()/1000<<" ms\n";
    if (Solver.rubiksCube.isSolved()) {
    cout<<"Solved Moves: ";
    for (auto mov:solved_moves) cout<<cube.getMove(mov)<<' ';
    cout<<'\n';
    //
    Solver.rubiksCube.print();
    }else {
    cout<<"Not Solved";
    }

    return 0;
}
