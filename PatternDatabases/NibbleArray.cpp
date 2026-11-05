//
// Created by KIIT0001 on 27-09-2026.
//

#include "NibbleArray.h"

NibbleArray::NibbleArray(const size_t size, const uint8_t val):size(size), arr((size+1)/2,val) { }

uint8_t NibbleArray::get(const size_t pos)const {
    size_t i=pos/2;
    assert(i < this->size);

    uint8_t val = this->arr.at(i);

    // if odd position return 4 bits from right
    if (pos%2) {
        return val & 0x0F;   // 0x0F=15 or 0000 1111
    }
    // even position return 4 bits from left
    else {
        return val>>4;
    }
}

void NibbleArray::set(const size_t pos,const uint8_t val) {
    size_t i=pos/2;
    uint8_t currval=this->arr.at(i);
    assert(i <= this->size);

    if (pos%2) {  // odd position set 4 bits from right
        this->arr.at(i) = (currval & 0XF0) | (val & 0X0F); // 0XF0=240 or 1111 0000 and 0x0F=15 or 0000 1111
    }else { // even position set 4 bits from left
        this->arr.at(i) = (currval & 0X0F) | (val << 4);
    }
}

uint8_t *NibbleArray::data() {
    return this->arr.data();
}

const uint8_t *NibbleArray::data() const {
    return this->arr.data();
}

size_t NibbleArray::storageSize() const {
    return this->arr.size();
}

void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.clear();
    dest.reserve(this->size);

    for (unsigned i=0;i<this->size;++i) {
        dest.push_back(this->get(i));
    }
}

void NibbleArray::reset(const uint8_t val) {
    fill(this->arr.begin(),this->arr.end(),val);
}


