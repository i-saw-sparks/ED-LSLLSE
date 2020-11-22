//
// Created by manie on 13/11/2020.
//

#ifndef LSLLSE_LIST_H
#define LSLLSE_LIST_H

#include <exception>
#include <string>
#include <functional>

template <typename T>
class List {
private:
    class Node{
    private:
        T data;
        Node *next, *prev;
    public:
        Node();
        Node(const T&);
        T getData() const;
        Node* getNext() const;
        Node* getPrev() const;

        void setData(const T&);
        void setNext(Node*);
        void setPrev(Node*);
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

    typedef Node* Position;

    List();
    List(const List<T>&);
    ~List();

    bool isEmpty() const;
    void insert(Node*, const T&);
    void erase(Node*);

    Node* getFirstPos() const;
    Node* getLastPos() const;
    Node* getPrevPos(Node*) const;
    Node* getNextPos(Node*) const;

    Node* find(const T&, std::function<int(T, T)> comp) const;

    T fetch(Node*) const;
    std::string toString() const;
    void deleteAll();
    List<T>& operator = (const List<T>&);
};

template<typename T>
List<T>::List():anchor(nullptr) {}

template<typename T>
List<T>::List(const List<T> &arg):anchor(nullptr) {
    Node* aux(arg.anchor);
    Node* last(nullptr);
    Node* newNode;

    while(aux != nullptr){
        newNode = new Node(aux->getData());
        if(newNode == nullptr)
            throw Exception("Memory not available");

        if(last == nullptr)
            anchor = newNode;
        else
            last->setNext(newNode);

        last = newNode;
        aux= aux->getNext();
    }
}

template<typename T>
List<T>::~List() {
    deleteAll();
}

template<typename T>
bool List<T>::isEmpty() const{
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
        aux->setNext(anchor);

        if(anchor != nullptr)
            anchor->setPrev(aux);

        anchor = aux;
    }else{
        aux->setPrev(pos);
        aux->setNext(pos->getNext());

        if(pos->getNext() != nullptr)
            pos->getNext()->setPrev(aux);

        pos->setNext(aux);
    }
}

template<typename T>
void List<T>::erase(List::Node* pos) {
    if(!isValidPos(pos))
        throw Exception("Invalid position");

    if(pos == anchor)
        anchor = anchor->getNext();

    if(pos->getPrev() != nullptr)
        pos->getPrev()->setNext(pos->getNext());

    if(pos->getNext() != nullptr)
        pos->getNext()->setPrev(pos->getPrev());

    delete pos;
}

template<typename T>
typename List<T>::Node *List<T>::getFirstPos() const {
    return anchor;
}

template<typename T>
typename List<T>::Node *List<T>::getLastPos() const {
    if(isEmpty())
        return nullptr;

    Node* aux(anchor);

    while (aux->getNext() != nullptr)
        aux = aux->getNext();

    return aux;
}

template<typename T>
typename List<T>::Node *List<T>::getPrevPos(List::Node *pos) const {
    if(!isValidPos(pos))
        return nullptr;

    return pos->getPrev();
}

template<typename T>
typename List<T>::Node *List<T>::getNextPos(List::Node *pos) const {
    if(!isValidPos(pos))
        return nullptr;

    return pos->getNext();
}

template<typename T>
typename List<T>::Node *List<T>::find(const T &arg, std::function<int(T, T)> comp) const {
    Node* aux(anchor);

    while (aux != nullptr && comp(aux->getData(), arg) != 0)
        aux = aux->getNext();

    return aux;
}

template<typename T>
T List<T>::fetch(List::Node *pos) const {
    if(!isValidPos(pos))
        throw Exception("Invalid position");

    return  pos->getData();
}

template<typename T>
std::string List<T>::toString() const {
    Node* aux(anchor);
    std::string ret;

    while (aux != nullptr){
        ret += aux->getData().toString() + "\n";
        aux = aux->getNext();
    }

    return ret;
}

template<typename T>
void List<T>::deleteAll() {
    Node* aux;

    while (anchor != nullptr){
        aux = anchor;
        anchor = anchor ->getNext();

        delete aux;
    }
}

template<typename T>
bool List<T>::isValidPos(List::Node *pos) const {
    Node* aux(anchor);

    while (aux != nullptr){
        if(aux == pos)
            return true;

        aux = aux->getNext();
    }

    return false;
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &arg) {
    deleteAll();

    this = List(arg);

    return *this;
}

template<typename T>
List<T>::Node::Node():next(nullptr), prev(nullptr) {}

template<typename T>
List<T>::Node::Node(const T &arg):data(arg), next(nullptr), prev(nullptr) {}

template<typename T>
T List<T>::Node::getData() const {
    return data;
}

template<typename T>
typename List<T>::Node* List<T>::Node::getNext() const {
    return next;
}

template<typename T>
typename List<T>::Node *List<T>::Node::getPrev() const{
    return prev;
}

template<typename T>
void List<T>::Node::setData(const T &arg) {
    data = arg;
}

template<typename T>
void List<T>::Node::setNext(List<T>::Node* argP) {
    next = argP;
}

template<typename T>
void List<T>::Node::setPrev(List::Node *argP) {
    prev = argP;
}


#endif //LSLLSE_LIST_H
