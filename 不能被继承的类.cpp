template <typename T> class MakeSealed{
    friend T;
private:
    MakeSealed() {}
    ~MakeSealed() {}
};

class SealedClass1 : virtual public MakeSealed<SealedClass1> {
public:
    SealedClass1() {}
    ~SealedClass1() {}
};

class ErrorClass1 : public SealedClass1 {
};



int main(){
    SealedClass1 a;
    // ErrorClass1 e; error
    return 0;
}