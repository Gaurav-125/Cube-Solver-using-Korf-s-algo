cmake_minimum_required(VERSION 4.2)
project(Rubik_s_Cube)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubik_s_Cube main.cpp
        GenericsRubiksCube.cpp
        GenericsRubiksCube.h
        RubiksCube3dArray.cpp
        RubiksCube1dArray.cpp
        RubiksCubeBitboard.cpp
        solver/DFSsolver.h
        solver/IDDFSsolver.h
        solver/BFSsolver.h
        solver/IDAstarSolver.h
        solver/IDAstarSolver2.h
        PatternDatabases/NibbleArray.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/math.h
        PatternDatabases/math.cpp
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/ConerPatterDatabase.cpp
        PatternDatabases/CornerDBMaker.h
        PatternDatabases/CornerDBMaker.cpp)
