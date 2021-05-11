class SevenOpMock: public Base {
    public:
        SevenOpMock() { };

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
}

class FifteenOpMock: public Base {
    public:
        FifteenOpMock() { };

        virtual double evaluate() { return 15.5; }
        virtual string stringify() { return "15.5"; }
}

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { };
        virtual double evaluate() { return 0.0; }
        virtual string stringify() { return "0.0"; }
}


class NegativeFourOpMock: public Base {
    public:
        NegativeFourOpMock() { };

        virtual double evaluate() { return -4.0; }
        virtual string stringify() { return "-4.0"; }
}

class NegativeTwelveOpMock: public Base {
    public:
       NegativeTwelveOpMock() { };

        virtual double evaluate() { return -12.0; }
        virtual string stringify() { return "-12.0"; }
}

