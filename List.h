//
// Created by manie on 13/11/2020.
//

#ifndef LSLLSE_LIST_H
#define LSLLSE_LIST_H

#include <exception>
#include <string>

template <typename T>
class List {
private:
    class Node{
    private:
        T data;
        Node* next;
    public:
        Node();
        Node(const T&);
        T getData() const;
        Node* getNext() const;

        void setData(const T&);
        void setNext(Node*);
    };

public:
    class Exception:public std::exception{
    private:
        std::string msg;
    public:
        explicit  Exception(const char* message):msg(message){}
        explicit Exception(const std::string& message):msg(message){}
        virtual  ~Exception() throw (){}
        virtual const char* what() const throw (){
            return msg.c_str();
        }
    };
};


#endif //LSLLSE_LIST_H
