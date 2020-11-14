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

    Node* anchor;
    bool isValidPos(Node*) const;

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

    List();
    List(const List<T>&);
    ~List();

    bool isEmpty();
    void insert(Node*, const T&);
    void erase(Node*);

    Node* getFirst() const;
    Node* getLast() const;
    Node* getPrev(Node*) const;
    Node* getNext(Node*) const;

    Node* find(const T&) const;

    T fetch(Node*) const;

    std::string toString() const;

    void deleteAll();

    List<T>& operator = (const List<T>&);
};

template<typename T>
List<T>::Node::Node():next(nullptr) {}

template<typename T>
List<T>::Node::Node(const T &arg):data(arg), next(nullptr) {}

template<typename T>
T List<T>::Node::getData() const {
    return data;
}

template<typename T>
typename List<T>::Node* List<T>::Node::getNext() const {
    return next;
}

template<typename T>
void List<T>::Node::setData(const T &arg) {
    data = arg;
}

template<typename T>
void List<T>::Node::setNext(List<T>::Node* argP) {
    next = argP;
}


#endif //LSLLSE_LIST_H
