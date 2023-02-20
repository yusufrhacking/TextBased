#ifndef TEXTBASED_GROUP_H
#define TEXTBASED_GROUP_H
#include <vector>
#include <cstdlib>

class GenericGroup{
public:
    virtual ~GenericGroup() { }
};

template <typename T>
class Group: GenericGroup {
private:
    std::vector<T> elements;

public:
    explicit Group(int size = 100){
        elements.resize(size);
    }

    virtual ~Group() = default;

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


#endif //TEXTBASED_GROUP_H
