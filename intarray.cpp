#pragma once
#include "intarray.h"
using namespace std;


        int  IntegerArray::getnum(size_t size){
            return(_arr[size]);
        }    

        int *IntegerArray::arrdel(int *arr){
            delete []arr;
            arr = nullptr;
            return (arr);
        }

        int *IntegerArray::arraloc(size_t size){
            int *arr = nullptr;
            if (size == 0)
                throw BadExcept(); 
            try{
                try{
                arr = new int[size];
                }
                catch (bad_alloc &er){
                    throw BadAlloc();
                }
            }
            catch (BadAlloc &exc){
                cout << exc.what() << endl;
                return (nullptr);
            }
            return (arr);
        }
        
        void IntegerArray::setnum(int num, size_t size){
            try{
            if (size >= _size)
                throw BadExcept();
            }
            catch(BadExcept &exc){
                cout << exc.what() << endl;
            }
                _arr[size] = num;
        }

        void IntegerArray::erase(){
            if (_arr == nullptr)
                throw BadExcept();
            delete []_arr;
            _arr = nullptr;
            _size = 0;
        }

        void IntegerArray::reallocate(size_t newsize){
            int *arr;
            try{
                arr = arraloc(newsize);
                erase();
            }
            catch(BadExcept &exc)
            {
                cout << exc.what() << endl;
            }
            _size = newsize;
            _arr = arr;
        }

        int *IntegerArray::arrncpy(size_t newsize, int *arr){
            try{
                if (newsize == 0)
                throw BadExcept{};
            }
            catch(BadExcept &exc){
                cout << exc.what() << endl;
                return (arr);
            }
            int *newarr = arraloc(newsize);
            if (newarr == nullptr)
                return (arr);
            if (newsize >= _size){
                while (_size-- > 0)
                    newarr[_size] = arr[_size];
                _size = newsize;
                arrdel(_arr);
                return(newarr);
            }
            _size = newsize;
            while (newsize-- > 0)
                newarr[newsize] = arr[newsize];
            arrdel(_arr);
            return (newarr);
        }

        int *IntegerArray::arrset(size_t newsize, int *arr, int num, int l){
            try{
                if (newsize == 0)
                throw BadExcept{};
            }
            catch(BadExcept &exc){
                cout << exc.what() << endl;
                return (arr);
            }
            int *newarr = arraloc(newsize);
            if (newarr == nullptr)
                return (arr);
            while (_size-- > 0)
                newarr[_size + l] = arr[_size];
            _size = newsize;
            arrdel(_arr);           
            switch (l){
                case 0:
                    newarr[_size - 1] = num;
                    break;
                case 1:
                    newarr[0] = num;
                    break;
            }
            return (newarr);
        }
        void IntegerArray::resize(size_t newsize){
                _arr = arrncpy(newsize, _arr);
        }

        void IntegerArray::setback(int num){
            _arr = arrset(_size + 1, _arr, num, 0);
        }
        void IntegerArray::setfront(int num){
            _arr = arrset(_size + 1, _arr, num, 1);
        }
        size_t IntegerArray::ShowSize(){
            return(_size);
        }
        
        int *IntegerArray::getArr(){
            return(_arr);
        }

        size_t IntegerArray::search(int num){
            size_t i = 0;
            while(i<_size){
            if(_arr[i] == num)
                return (i);
            i++;
            }
            try{
            if (i == _size)
                throw BadExcept();
            }
            catch (BadExcept &exc){
            cout << "Object cannot be find" << endl;
            }
            return (0);
        }

        void IntegerArray::SetNum(int num, size_t size){
            try{
                if (size >= _size)
                    throw BadExcept();
                _arr[size] = num;
            }
            catch (BadExcept &exc){
                cout << exc.what() << endl;
            }
        }
