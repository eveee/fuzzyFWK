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
    /*vector<float> c = {1, 2, 3, 4, 5};
    Expression<float>* vm[4] = {new ValueModel<float>(1), new ValueModel<float>(2), new ValueModel<float>(3), new ValueModel<float>(4)};
    SugenoConclusion<float> opSg(c);
    cout << opSg.evaluate(vm);

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
*/
    //interprète de cmd
    float s, fo;
    int and_, or_, then, defuzz, agg, cb;
    string poor, good, excellent, rancid, delicious, cheap, average, generous;

    NotMinus1<float> opNot;
    CogDefuzz<float> opDefuzzCog; SugenoDefuzz<float> opDefuzzSugeno;

    Is<float> isp, isgo, ise, isr, isd, isc, isa, isge;

    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    cout << "Application permettant de calculer les pourboires " << endl;
    cout << endl <<  "***** Operateurs *****";
    cout << endl << "AND (1:AndMin, 2:AndMult) -> "; cin >> and_;
    cout << endl << "OR (1:OrMax, 2:OrPlus) -> "; cin >> or_;
    cout << endl << "THEN (1:ThenMin, 2:ThenMult, 3:SugenoThen) -> "; cin >> then;
    if (then == 3)
        defuzz = 2; //sugeno defuzz
    else
        defuzz = 1; //cog defuzz
    cout << endl << "AGG (1:AggMax, 2:AggPlus) -> "; cin >> agg;

        /*ici il faudra decoder les operateurs :

            if(defuzz = 1)
                FuzzyFactory<float> f(&opNot,&decodeAnd(and_),&decodeAnd(or_),&decodeThen(then),&decodeAgg(agg),&opDefuzzCog);
            else
                FuzzyFactory<float> f(&opNot,&decodeAnd(and_),&decodeAnd(or_),&decodeThen(then),&decodeAgg(agg),&opDefuzzSugeno);
        */

    cout << "***** Fonctions membres *****";
    cout << endl << "Répondre par ";
    cout << "isbell min center mid";
    cout << endl << "OU isgauss center sigma";
    cout << endl << "OU istrap min midone midtwo max";
    cout << endl << "OU istrapl min max";
    cout << endl << "OU istrapr min max";
    cout << endl << "OU istriangle min mid max" << endl;

    cout << endl << "poor -> "; cin >> poor;
    cout << endl << "good -> "; cin >> good;
    cout << endl << "excellent -> "; cin >> excellent;
    cout << endl << "rancid -> "; cin >> rancid;
    cout << endl << "delicious -> "; cin >> delicious;
    cout << endl << "cheap -> "; cin >> cheap;
    cout << endl << "average -> "; cin >> average;
    cout << endl << "generous -> "; cin >> generous;

        //il faudra decoder les fonctions membres avec une méthode qui se sert de string tokenizer (decodeIs(string))

    Expression<float> *r =
    f.newAgg(
        f.newAgg(
            f.newThen(
                    f.newOr(f.newIs(&decodeIs(poor), &service), f.newIs(&decodeIs(rancid), &food)),
                    f.newIs(&decodeIs(cheap), &tips)
            ),
            f.newThen(
                f.newIs(&decodeIs(good), &service),f.newIs(&decodeIs(average), &tips)
            )
        ),
        f.newThen(
            f.newOr(f.newIs(&decodeIs(excellent), &service), f.newIs(&decodeIs(delicious), &food)),
            f.newIs(&decodeIs(generous), &tips)
        )
    );

    Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

    while(true){
        cout << "service : "; cin >> s;
        service.setValue(s);
        cout << "food : "; cin >> fo;
        food.setValue(fo);
        cout << "tips -> " << system->evaluate() << endl;
    }

    return 0;
}
