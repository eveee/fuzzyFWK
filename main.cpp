#include <iostream>

#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"
#include "core/BinaryExpressionModel.h"
#include "core/UnaryShadowExpression.h"
#include "core/BinaryShadowExpression.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/ThenMult.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"
#include "fuzzy/CogDefuzz.h"
#include "core/FuzzyFactory.h"

using namespace std;
using namespace core;
using namespace fuzzy;

int main()
{
    ValueModel<float> v(2);
    cout << v.evaluate() << endl;
    ValueModel<float> va(4);
    cout << va.evaluate() << endl;

    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    AndMult<float> opAnd2;
    OrMax<float> opOr;
    ThenMin<float> opThen;
    CogDefuzz<float> opDefuzz;
    AggPlus<float> opAgg;

    IsTriangle<float> poor(-5,0,5);

    UnaryExpressionModel<float> *b = new UnaryExpressionModel<float>(&poor, &va);
    cout << b->evaluate() << endl;

    //UnaryExpressionModel<int> *u = new UnaryExpressionModel<int>(&opNot, va);
    //cout << u->evaluate();

    FuzzyFactory<float> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);
    cout << f.newAnd(&v,&va)->evaluate() << endl;
    f.changeAnd(&opAnd2);
    cout << f.newAnd(&v,&va)->evaluate() << endl;
/*
    //operators
    NotMinus1<int> opNot;
    AndMin<int> opAnd;
    OrMax<int> opOr;
    ThenMin<int> opThen;
    CogDefuzz<int> opDefuzz;
    AggPlus<int> opAgg;

    //fuzzy expression factory
    FuzzyFactory<int> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);


    //membership function
    IsTriangle<int> poor(-5,0,5);
    IsTriangle<int> good(0,5,10);
    IsTriangle<int> excellent(5,10,15);
    IsTriangle<int> cheap(0,5,10);
    IsTriangle<int> average(10,15,20);
    IsTriangle<int> generous(20,25,30);


    //values
    ValueModel<int> service(0);
    ValueModel<int> food(0);
    ValueModel<int> tips(0);


    Expression<int> *r =
    f.newAgg(
        f.newAgg(
            f.newThen(
                f.newIs(&poor ,&service),f.newIs(&cheap, &tips)
            ),
            f.newThen(
                f.newIs(&good, &service),f.newIs(&average, &tips)
            )
        ),
        f.newThen(
            f.newIs(&excellent, &service),f.newIs(&generous, &tips)
        )
    );


    //defuzzification
    Expression<int> *system = f.newDefuzz(&tips, r, 0, 25, 1);

    /*
    //apply input
    float s;
    while(true){
        cout << "service : ";cin >> s;
        service.setValue(s);
        cout << "tips -> " << system->evaluate() << endl;
    }*/
    return 0;
}
