#ifndef TEXTBASED_OPENPATHSSIGNATURE_H
#define TEXTBASED_OPENPATHSSIGNATURE_H

#include <bitset>
class OpenPathsSignature{
    std::bitset<4> signature;

public:
    void set(int pos, bool flag){
        signature.set(pos, flag);
    }

    void setAll(bool flag){
        for (int x=0; x<signature.size(); x++){
            signature.set(x, flag);
        }
    }

    bool operator[](Direction direction){
        return signature[direction];
    }

};

#endif //TEXTBASED_OPENPATHSSIGNATURE_H
