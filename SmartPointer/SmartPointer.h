/*
 * @name: SmartPointer.h
 * @description:
 *
 */

#include <iostream>

using namespace std;

template <class T>
class SmartPointer {
  public:
    SmartPointer(T* ptr) {
        ref = ptr;
        ref_count = new unsigned long; 
        *ref_count = 1;
    }

    SmartPointer(SmartPointer<T> &ptr) {
        ref = ptr.ref;
        ref_count = ptr.ref_count;
        ++*ref_count;
    }

    SmartPointer<T>& operator=(SmartPointer<T> &ptr) {
        if (this != &ptr) {
            if (--*ref_count == 0) {
                clear();
                cout << "operator= clear" << endl;
            }
        }
        ref = ptr.ref;
        ref_count = ptr.ref_count;
        ++*ref_count;
        return *this;
    }

    ~SmartPointer() {
        if (--*ref_count == 0) {
            clear();
            cout << "destructor clear" << endl;
        }
    }

    T getValue() {
        return *ref;
    }

  private:
    void clear() {
        delete ref;
        delete ref_count;
        ref = NULL;
        ref_count = NULL;
    }

  protected:
    T* ref;
    unsigned long* ref_count;
};
