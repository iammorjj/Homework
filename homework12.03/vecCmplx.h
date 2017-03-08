#ifndef VECCMPLX_H
#define VECCMPLX_H

#include "cmplx.h"

class VectorCmpx {
    CmpxNum* v;
    size_t SIZE;
public:
    VectorCmpx(size_t sz = 0);
    VectorCmpx(const VectorCmpx& obj);
    ~VectorCmpx();
    VectorCmpx& operator=(const VectorCmpx& obj);
    VectorCmpx(VectorCmpx&& obj);
    VectorCmpx& operator=(VectorCmpx&& obj);
    friend void swap(VectorCmpx& obj1, VectorCmpx& obj2);
};

VectorCmpx::VectorCmpx(size_t sz) {
    v = nullptr, SIZE = sz;
    if(SIZE)
        v = new CmpxNum[SIZE];
}
VectorCmpx::VectorCmpx(const VectorCmpx& obj) {
    v = nullptr, SIZE = obj.SIZE;
    if(obj.v != nullptr) {
        SIZE = obj.SIZE;
        v = new CmpxNum[SIZE];
    }
}
VectorCmpx::~VectorCmpx() {
    if(v != nullptr)
        delete[] v;
}
VectorCmpx& VectorCmpx::operator=(const VectorCmpx& obj) {
    if(v != nullptr)
        delete[] v;
    SIZE = obj.SIZE;
    v = new CmpxNum[SIZE];
    for(size_t i = 0; i < SIZE; i++)
        v[i] = obj.v[i];
    return *this;
}
VectorCmpx::VectorCmpx(VectorCmpx&& obj): v(nullptr), SIZE(0) {
    v = obj.v; SIZE = obj.SIZE;
    obj.v = nullptr; obj.SIZE = 0;
}
VectorCmpx& VectorCmpx::operator=(VectorCmpx&& obj) {
    if(this != &obj) {
        if(v != nullptr)
            delete[] v;
        v = obj.v; SIZE = obj.SIZE;
        obj.v = nullptr; obj.SIZE = 0;
    }
    return *this;
}
void swap(VectorCmpx& obj1, VectorCmpx& obj2) {
    swap(obj1.SIZE, obj2.SIZE);
    swap(obj1.v, obj2.v);
}

#endif
