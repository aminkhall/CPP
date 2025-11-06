#include <iostream>
#include <exception>


class Number {
    private:
        int x;
    public:
        void setX(int x){
            this->x = x;
        }
        int getX();

    class Low : public std::exception {
        const char *what() const noexcept{
            return "Low";
        }
    };

    class Hight : public std::exception {
        const char *what() const noexcept {
            return "Hight";
        }
    };

    void check(){
        try{
            if (x < 10){
                throw Low();
            }
            else    
                throw Hight();
        }catch (std::exception &e){
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
};

int main(){
    Number x;
    x.setX(2);
    x.check();
}