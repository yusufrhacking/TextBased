#ifndef TEXTBASED_POOL_H
#define TEXTBASED_POOL_H
#include <vector>
#include <cstdlib>

class GenericPool{
public:
    virtual ~GenericPool() = default;
};

template <typename T>
class Pool: public GenericPool {
private:
    std::vector<T> elements;

public:
    explicit Pool(int size = 100){
        elements.resize(size);
    }

    ~Pool() override = default;

    bool isEmpty() const{
        return elements.empty();
    }

    int getSize() const{
        return elements.size();
    }

    void resize(int n){
        elements.resize(n);
    }

    void clear() {
        elements.clear();
    }

    void add(T element){
        elements.push_back(element);
    }

    void set(int index, T element){
        elements[index] = element;
    }

    T& get(int index){
        return static_cast<T&>(elements[index]);
    }

    T operator [] (unsigned int index) {
        return elements[index];
    }
};


#endif //TEXTBASED_POOL_H
