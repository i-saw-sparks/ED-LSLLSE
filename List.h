//
// Created by manie on 13/11/2020.
//

#ifndef LSLLSE_LIST_H
#define LSLLSE_LIST_H

template <typename T>
class List {
private:


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
