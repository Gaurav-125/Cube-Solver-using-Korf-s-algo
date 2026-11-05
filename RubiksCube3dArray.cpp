//
// Created by KIIT0001 on 14-09-2026.
//

#include "GenericsRubiksCube.h"

class RubiksCube3dArray:public GenericsRubiksCube {
private:
    void rotateFace(int ind) {  // this function is rotating a 3X3 face clockwise
        char temp_arr[3][3]{};
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                temp_arr[i][j]=cube[ind][i][j];
            }
        }

        for (int i=0;i<3;i++) cube[ind][0][i]=temp_arr[2-i][0];
        for (int i=0;i<3;i++) cube[ind][i][2]=temp_arr[0][i];
        for (int i=0;i<3;i++) cube[ind][2][2-i]=temp_arr[i][2];
        for (int i=0;i<3;i++) cube[ind][2-i][0]=temp_arr[2][2-i];
    }
public:
    char cube[6][3][3]{};

    RubiksCube3dArray() {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(COLOR(i));
                    // cout<<cube[i][j][k]<<" ";
                }
                // cout<<"\n";
            }
            // cout<<"\n";
        }
    }

    RubiksCube3dArray(char _cube[6][3][3]) {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k]=_cube[i][j][k];
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color=cube[(int)face][row][col];

        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    GenericsRubiksCube &u() override{
        this->rotateFace(0);

        char temp_arr[3]={};
        for (int i=0;i<3;i++) temp_arr[i]=cube[4][0][2-i];  // Moving the corresponding edge stickers of adjacent faces.
        for (int i=0;i<3;i++) cube[4][0][2-i]=cube[1][0][2-i];
        for (int i=0;i<3;i++) cube[1][0][2-i]=cube[2][0][2-i];
        for (int i=0;i<3;i++) cube[2][0][2-i]=cube[3][0][2-i];
        for (int i=0;i<3;i++) cube[3][0][2-i]=temp_arr[i];

        return *this;
    }

    GenericsRubiksCube &uPrime() {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    GenericsRubiksCube &u2() {
        this->u();
        this->u();

        return  *this;
    }

    GenericsRubiksCube &l() {
        this->rotateFace(1);

        char temp_arr[3]={};
        for (int i=0;i<3;i++) temp_arr[i]=cube[0][i][0];
        for (int i=0;i<3;i++) cube[0][i][0]=cube[4][2-i][2];
        for (int i=0;i<3;i++) cube[4][2-i][2]=cube[5][i][0];
        for (int i=0;i<3;i++) cube[5][i][0]=cube[2][i][0];
        for (int i=0;i<3;i++) cube[2][i][0]=temp_arr[i];

        return *this;
    }

    GenericsRubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    GenericsRubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    GenericsRubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3]={};
        for (int i=0;i<3;i++) temp_arr[i]=cube[0][2][i];
        for (int i=0;i<3;i++) cube[0][2][i]=cube[1][2-i][2];
        for (int i=0;i<3;i++) cube[1][2-i][2]=cube[5][0][2-i];
        for (int i=0;i<3;i++) cube[5][0][2-i]=cube[3][i][0];
        for (int i=0;i<3;i++) cube[3][i][0]=temp_arr[i];

        return *this;
    }

    GenericsRubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    GenericsRubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    GenericsRubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3]={};
        for (int i=0;i<3;i++) temp_arr[i]=cube[0][2-i][2];
        for (int i=0;i<3;i++) cube[0][2-i][2]=cube[2][2-i][2];
        for (int i=0;i<3;i++) cube[2][2-i][2]=cube[5][2-i][2];
        for (int i=0;i<3;i++) cube[5][2-i][2]=cube[4][i][0];
        for (int i=0;i<3;i++) cube[4][i][0]=temp_arr[i];

        return *this;
    }

    GenericsRubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    GenericsRubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    GenericsRubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3]={};
        for (int i=0;i<3;i++) temp_arr[i]=cube[0][0][2-i];
        for (int i=0;i<3;i++) cube[0][0][2-i]=cube[3][2-i][2];
        for (int i=0;i<3;i++) cube[3][2-i][2]=cube[5][2][i];
        for (int i=0;i<3;i++) cube[5][2][i]=cube[1][i][0];
        for (int i=0;i<3;i++) cube[1][i][0]=temp_arr[i];

        return *this;
    }

    GenericsRubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    GenericsRubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    GenericsRubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3]={};
        for (int i=0;i<3;i++) temp_arr[i]=cube[2][2][i];
        for (int i=0;i<3;i++) cube[2][2][i]=cube[1][2][i];
        for (int i=0;i<3;i++) cube[1][2][i]=cube[4][2][i];
        for (int i=0;i<3;i++) cube[4][2][i]=cube[3][2][i];
        for (int i=0;i<3;i++) cube[3][2][i]=temp_arr[i];

        return *this;
    }

    GenericsRubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    GenericsRubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCube3dArray& r1) const{
        for (int i=1;i<6;i++) {
            for (int j=1;j<3;j++) {
                for (int k=1;k<3;k++) {
                    if (cube[i][j][k]!=r1.cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray& r1) {
        for (int i=1;i<6;i++) {
            for (int j=1;j<3;j++) {
                for (int k=1;k<3;k++) {
                    cube[i][j][k]=r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }

};

struct hash3d { // it is used to convert a rubikscube state to a hash value
    size_t operator()(const RubiksCube3dArray& r1) const { // return a number hash value
        string str="";
        for (int i=0;i<6;i++) {   // used in solver to prevent visiting same state again & again
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    str+=r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};