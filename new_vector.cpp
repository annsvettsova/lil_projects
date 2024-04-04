#include <iostream>

class vector{
    private:
        int dim;
        int *v;
        int number;
    public:
        static int count;
        vector();
        vector(int d);
        //vector(int d, int* v); перекладываем из одного вектора в другой
        //vector(vector & vect);
        vector& operator = (const vector &vect);
        vector operator + (const vector vect);
        vector& operator - ();
};

int vector::count = 0;

vector::vector(){
    number = count;
    count++;
    std::cout<<"Constructor vector() made vector #" << number << std::endl;
    dim = 0;
    v = new int[dim];
}

vector::vector(int d){
    number = count;
    count++;
    std::cout<<"Constructor vector(int dim) made vector #" << number << std::endl;
    dim = d;
    v = new int[dim];
    for (int i = 0; i < dim; i++){
        v[i] = 0;
    }
}

vector& vector::operator = (const vector &vect){
    std::cout << "Equating vector №" << number << " with vector #" << vect.number << std::endl;
    dim = vect.dim;
    for (int i = 0; i < dim; i++){
        v[i] = vect.v[i];
    }
    return *this;
}

vector vector::operator + (const vector vect){
    std::cout << "Summing vector #" << number << " with vector #" << vect.number << std::endl;
    vector tmp(dim);
    for (int i = 0; i < dim; i++){
        tmp.v[i] = v[i] + vect.v[i];
    }
    return tmp;
}

int main(){
    int d = 10;
    vector vect1(d);
    vector vect2(d);
    vector vect_res; // конструктор без параметров создается без ()
    
    vect_res = vect1 + vect2;
    
    return 0;
}
