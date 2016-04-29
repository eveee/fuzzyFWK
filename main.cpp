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

And<float>* decodeAnd(int and_){
    AndMin<float> opAndMin;
    AndMult<float> opAndMult;
    if (and_ == 1)
        return &opAndMin;
    else
        return &opAndMult;
}

Or<float>* decodeOr(int or_){
    OrMax<float> opOrMax;
    OrPlus<float> opOrPlus;
    if (or_ == 1)
        return &opOrMax;
    else
        return &opOrPlus;
}

Then<float>* decodeThen(int then){
    ThenMin<float> opThenMin;
    ThenMult<float> opThenMult;
    SugenoThen<float> opSugenoThen;
    if (then == 1)
        return &opThenMin;
    else if (then == 2)
        return &opThenMult;
    else
        return &opSugenoThen;
}

Agg<float>* decodeAgg(int agg){
    AggMax<float> opAggMax;
    AggPlus<float> opAggPlus;
    AggMax<float> opAggMin;
    if (agg == 1)
        return &opAggMax;
    else if (agg == 2)
        return &opAggPlus;
    else
        return &opAggMin;
}

Is<float>* decodeIs(string is){

}

int main()
{/*
    ValueModel<float> v(2);
    cout << v.evaluate() << endl;
    ValueModel<float> va(4);
    cout << va.evaluate() << endl;

*/
    //interprète de cmd
    float s, fo;
    int and_, or_, then, defuzz, agg, cb;
    string poor, good, excellent, rancid, delicious, cheap, average, generous;

    NotMinus1<float> opNot;
    CogDefuzz<float> opDefuzzCog; SugenoDefuzz<float> opDefuzzSugeno;

    std::vector<float>* coeff;
	coeff->push_back(1);
	coeff->push_back(1);
	coeff->push_back(1);
    SugenoConclusion<float> opSugenoConclusion(coeff);

    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    cout << "Application permettant de calculer les pourboires " << endl;
    cout << endl <<  "***** Operateurs *****";
    cout << endl << "AND (1:AndMin, 2:AndMult) -> "; cin >> and_;
    cout << endl << "OR (1:OrMax, 2:OrPlus) -> "; cin >> or_;
    cout << endl << "THEN (1:ThenMin, 2:ThenMult, 3:SugenoThen) -> "; cin >> then;
    cout << endl << "AGG (1:AggMax, 2:AggPlus) -> "; cin >> agg;

    if(then == 3)
        FuzzyFactory<float> f(&opNot,decodeAnd(and_),decodeOr(or_),decodeThen(then),decodeAgg(agg),opDefuzzSugeno,opSugenoConclusion);
    else
        FuzzyFactory<float> f(&opNot,decodeAnd(and_),decodeOr(or_),decodeThen(then),decodeAgg(agg),&opDefuzzCog);

    cout << endl << endl << "***** Fonctions membres *****";
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

    if(defuzz = 1){
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
        );  Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);
    }

    else{
        std::vector<const core::Expression<float>*> rules;

        std::vector<const core::Expression<float>*> SC_service_food;
        SC_service_food.push_back(&service);
        SC_service_food.push_back(&food);

        std::vector<const core::Expression<float>*> SC_service;
        SC_service.push_back(&service);

        rules.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(&poor, &service),
                    f.newIs(&rancid, &food)
                ),
                f.newSugenoConclusion(&SC_service_food)
            ));

        rules.push_back(
            f.newThen(
                f.newIs(&good, &service),
                f.newSugenoConclusion(&SC_service)
            ));

        rules.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(&excellent, &service),
                    f.newIs(&delicious, &food)
                ),
                f.newSugenoConclusion(&SC_service_food)
            ));
            core::Expression<float> *system = f.newSugenoDefuzz(&rules);
        }

    while(true){
        cout << "service : "; cin >> s;
        service.setValue(s);
        cout << "food : "; cin >> fo;
        food.setValue(fo);
        cout << "tips -> " << system->evaluate() << endl;
    }

    return 0;
}
