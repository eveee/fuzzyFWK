#include <iostream>

#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"
#include "core/BinaryExpressionModel.h"
#include "core/UnaryShadowExpression.h"
#include "core/BinaryShadowExpression.h"
#include "fuzzy/NotMinus1.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/IsTrapeze.h"
#include "fuzzy/IsTrapezeLeft.h"
#include "fuzzy/IsTrapezeRight.h"
#include "fuzzy/IsBell.h"
#include "fuzzy/IsGaussian.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/OrPlus.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/ThenMult.h"
#include "fuzzy/AggMax.h"
#include "fuzzy/AggPlus.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/SugenoDefuzz.h"
#include "fuzzy/SugenoConclusion.h"
#include "core/FuzzyFactory.h"

using namespace std;
using namespace core;
using namespace fuzzy;

int main()
{/*
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

    //operators
    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    OrMax<float> opOr;
    ThenMin<float> opThen;
    CogDefuzz<float> opDefuzz;
    AggPlus<float> opAgg;

    //fuzzy expression factory
    FuzzyFactory<float> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

    //membership function
    IsTriangle<float> poor(-5,0,5);
    IsTriangle<float> good(0,5,10);
    IsTriangle<float> excellent(5,10,15);
    IsTriangle<float> rancid(-5,0,5);
    IsTriangle<float> delicious(5,10,15);
    IsTriangle<float> cheap(0,5,10);
    IsTriangle<float> average(10,15,20);
    IsTriangle<float> generous(20,25,30);

    //values
    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    Expression<float> *r =
    f.newAgg(
        f.newAgg(
            f.newThen(
                    f.newAgg(f.newIs(&poor, &service), f.newIs(&rancid, &food)),
                    f.newIs(&cheap, &tips)
            ),
            f.newThen(
                f.newIs(&good, &service),f.newIs(&average, &tips)
            )
        ),
        f.newThen(
            f.newAgg(f.newIs(&excellent, &service), f.newIs(&delicious, &food)),
            f.newIs(&generous, &tips)
        )
    );


    //defuzzification
    Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

    //apply input
    float s, fo;
    while(true){
        cout << "service : "; cin >> s;
        service.setValue(s);
        cout << "food : "; cin >> fo;
        food.setValue(fo);
        cout << "tips -> " << system->evaluate() << endl;
    }
*/

    /*vector<float> c = {1, 2, 3, 4, 5};
    Expression<float>* vm[4] = {new ValueModel<float>(1), new ValueModel<float>(2), new ValueModel<float>(3), new ValueModel<float>(4)};
    SugenoConclusion<float> opSg(c);
    cout << opSg.evaluate(vm);
    */

    //Mettre SugenoThen dans la factory pour que ça soit appelé avec newThen

     //operators
    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    OrMax<float> opOr;
    ThenMin<float> opThen;
    CogDefuzz<float> opDefuzz;
    AggPlus<float> opAgg;

    //fuzzy expression factory
    FuzzyFactory<float> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

    //membership function
    IsTriangle<float> poor(-5,0,5);
    IsTriangle<float> good(0,5,10);
    IsTriangle<float> excellent(5,10,15);
    IsTriangle<float> rancid(-5,0,5);
    IsTriangle<float> delicious(5,10,15);
    IsTriangle<float> cheap(0,5,10);
    IsTriangle<float> average(10,15,20);
    IsTriangle<float> generous(20,25,30);

    //values
    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    Expression<float> *r =
    f.newAgg(
        f.newAgg(
            f.newThen(
                    f.newOr(f.newIs(&poor, &service), f.newIs(&rancid, &food)),
                    f.newIs(&cheap, &tips)
            ),
            f.newThen(
                f.newIs(&good, &service),f.newIs(&average, &tips)
            )
        ),
        f.newThen(
            f.newOr(f.newIs(&excellent, &service), f.newIs(&delicious, &food)),
            f.newIs(&generous, &tips)
        )
    );

    //defuzzification
    Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

    return 0;
}
