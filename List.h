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
List<T>::List():anchor(nullptr) {}

template<typename T>
List<T>::List(const List<T> &):anchor(nullptr) {

}

template<typename T>
List<T>::~List() {

}

template<typename T>
bool List<T>::isEmpty() {
    return anchor == nullptr;
}

template<typename T>
void List<T>::insert(List::Node *pos, const T &arg) {
    if(pos != nullptr && !isValidPos(pos))
        throw Exception("Invalid position");

    Node* aux(new Node(arg));

    if(aux == nullptr)
        throw Exception("Memory not available");

    if(pos == nullptr){
        aux->setNext(pos->getNext());
        pos->getNext(aux);
    }else{
        aux->setNext(pos->getNext());
        pos->setNext(aux);
    }
}

template<typename T>
void List<T>::erase(List::Node* pos) {
    if(!isValidPos(pos))
        throw Exception("Invalid position");

    if(pos == anchor->getNext())
        anchor = anchor->getNext();
    else
        getPrev(pos)->setNext(pos->getNext());

    delete pos;
}

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
