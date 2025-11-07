#include <iostream>
#include <exception>


class Number {
private:
    int x;

public:
    void setX(int x){
        this->x = x;
    }

    int getX(){
        return x;
    }

    class Low : public std::exception {
        const char *what() const throw(){
            return "Low";
        }
    };

    class Hight : public std::exception {
        const char *what() const throw(){
            return "Hight";
        }
    };

};

int main(){

    Number n;

    n.setX(10);
    std::cout << "N: " << n.getX() << std::endl;

    try{
        if (n.getX() < 10)
           throw Number::Low();
        else if (n.getX() > 10)
            throw Number::Hight();
        else 
            std::cout << "Valid value" << std::endl;
    }catch (std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}