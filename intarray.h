#pragma once
#include <iostream>
#include <exception>

using namespace std;

class IntegerArray{
    private:
        int *_arr;
        size_t _size;
    public:
         
        IntegerArray(){
            _arr = nullptr;
            _size = 0;
        };
        
        IntegerArray(size_t size) : _size(size){
            try{
                _arr = arraloc(size);
            }
            catch (BadExcept &exc){
                cout << exc.what() << endl;
                _arr = nullptr;
            }
        };

        ~IntegerArray(){
           try{
                if (_arr == nullptr)
                    throw DoubleFree();
                   arrdel(_arr);
            }
            catch(DoubleFree &exc){
                cout << exc.what() << endl;;
            }
        };

        class DoubleFree: public exception{
            public:
                const char *what() const throw() override{
                    return("Oups, Double Free");
                }
        };

        class BadExcept: public exception{
            public:
                const char *what() const throw () override{
                    return( "Something Wrong!");
                }
        };

        class BadAlloc: public bad_alloc{
            public:
                const char *what() const throw() override{
                    return("Allocation wrong");
                }
        };


        int getnum(size_t size);
        int  *arrdel(int *arr);
        int  *arraloc(size_t size);
        void setnum(int num, size_t size);
        void erase();
        void reallocate(size_t newsize);
        int  *arrncpy(size_t newsize, int *arr);
        int *arrset(size_t newsize, int *arr, int num, int l);
        void resize(size_t newsize);
        void setback(int num);
        void setfront(int num);
        size_t ShowSize();
        int *getArr();
        size_t search(int num);
        void SetNum(int num, size_t size);
};
