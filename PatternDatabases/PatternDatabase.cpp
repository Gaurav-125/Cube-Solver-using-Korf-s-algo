//
// Created by KIIT0001 on 30-09-2026.
//

#include "PatternDatabase.h"
using namespace std;

PatternDatabase::PatternDatabase(const size_t size) : database(size,0xFF),size(size),numItems(0){ }

PatternDatabase::PatternDatabase(const size_t size, uint8_t init_val) : database(size,init_val), size(size), numItems(0) { }

bool PatternDatabase::setNumMoves(const uint32_t ind, const uint8_t numMoves) {
    uint8_t oldMoves = this->getNumMoves(ind);

    if (oldMoves==0XF) {
        ++this->numItems;
    }

    if (oldMoves>numMoves) {
        this->database.set(ind,static_cast<int>(numMoves));
        // cout<<"set: "<<static_cast<int>(numMoves)<<'\n';
        return true;
    }

    return false;
}

bool PatternDatabase::setNumMoves(const GenericsRubiksCube &cube, const uint8_t numMoves) {
    return this->setNumMoves(this->getDatabaseIndex(cube), numMoves);
}

uint8_t PatternDatabase::getNumMoves(const uint32_t ind) const {
    return this->database.get(ind);
}

uint8_t PatternDatabase::getNumMoves(const GenericsRubiksCube &cube) const {
    return this->getNumMoves(this->getDatabaseIndex(cube));
}

size_t PatternDatabase::getSize() const {
    return this->size;
}

size_t PatternDatabase::getNumItems() const {
    return this->numItems;
}

bool PatternDatabase::isFull() const {
    return this->numItems==this->size;
}

void PatternDatabase::toFile(const string &filePath) const {
    ofstream writer(filePath, ios::out | ios::binary | ios::trunc);

    if (!writer.is_open())
        throw "Faild to open the file to write";

    writer.write(
        reinterpret_cast<const char*>(this->database.data()),
        this->database.storageSize()
    );

    writer.close();
}

bool PatternDatabase::fromFile(const string &filePath) {
    ifstream reader(filePath, ios::in | ios::ate);

    if (!reader.is_open())
        return false;

    size_t filesize=reader.tellg();

    if (filesize != this->database.storageSize()) {
        reader.close();
        throw "Database Corrupt! Failed to open file to read";
    }

    reader.seekg(0,ios::beg);
    reader.read(
        reinterpret_cast<char*>(this->database.data()),
        this->database.storageSize()
    );
    reader.close();
    this->numItems=this->size;
    cout<<"\n"<<"Database loaded\n";
    cout<<this->database.storageSize()<<'\n';
    return true;
}

vector<uint8_t> PatternDatabase::inflate() const {
    vector<uint8_t> inflated;
    this->database.inflate(inflated);
    return inflated;
}

void PatternDatabase::reset() {
    if (this->numItems!=0) {
        this->database.reset(0XFF);
        this->numItems=0;
    }
}
