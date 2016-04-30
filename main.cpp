#include <iostream>
#include <cstdlib>

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

Is<float>* decodeIs(string in){
    int pos1 = in.find(" ", 0);
    int pos2 = in.find(" ", pos1 + 1);
    int pos3 = in.find(" ", pos2 + 1);
    int pos4 = in.find(" ", pos3 + 1);

    string cmd = in.substr(0, pos1);

    if(cmd.compare("isbell") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string center = in.substr(pos2 + 1, pos3 - (pos2 + 1));
        string mid = in.substr(pos3 + 1, in.size() - (pos3 + 1));
        return new IsBell<float>(atof(min_.c_str()), atof(mid.c_str()), atof(center.c_str()));
    }

    else if(cmd.compare("isgauss") == 0){
        string center = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string sigma = in.substr(pos2 + 1, in.size() - (pos2 + 1));
        return new IsGaussian<float>(atof(center.c_str()), atof(sigma.c_str()));
    }

    else if(cmd.compare("istrap") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string mid1 = in.substr(pos2 + 1, pos3 - (pos2 + 1));
        string mid2 = in.substr(pos3 + 1, pos4 - (pos3 + 1));
        string max_ = in.substr(pos4 + 1, in.size() - (pos4 + 1));
        return new IsTrapeze<float>(atof(min_.c_str()), atof(mid1.c_str()), atof(mid2.c_str()), atof(max_.c_str()));
    }

    else if(cmd.compare("istrapl") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string max_ = in.substr(pos2 + 1, in.size() - (pos2 + 1));
        return new IsTrapezeLeft<float>(atof(min_.c_str()), atof(max_.c_str()));
    }

    else if(cmd.compare("istrapr") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string max_ = in.substr(pos2 + 1, in.size() - (pos2 + 1));
        return new IsTrapezeRight<float>(atof(min_.c_str()), atof(max_.c_str()));
    }

    else {
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string mid = in.substr(pos2 + 1, pos3 - (pos2 + 1));
        string max_ = in.substr(pos3 + 1, in.size() - (pos3 + 1));
        return new IsTriangle<float>(atof(min_.c_str()), atof(mid.c_str()), atof(max_.c_str()));
    }

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
    int and_, or_, then, agg;
    string poor, good, excellent, rancid, delicious, cheap, average, generous;

    NotMinus1<float> opNot;
    CogDefuzz<float> opDefuzzCog; NaryExpression<float>* opDefuzzSugeno = new SugenoDefuzz<float>() ;

    vector<float>* coeff = new vector<float>();
	coeff->push_back(1.0);
	coeff->push_back(1.0);
	coeff->push_back(1.0);
    NaryExpression<float>* opSugenoConclusion = new SugenoConclusion<float>(coeff);

    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    cout << "Application permettant de calculer les pourboires " << endl;
    cout << endl <<  "***** Operateurs *****";
    cout << endl << "AND (1:AndMin, 2:AndMult) -> "; cin >> and_;
    cout << endl << "OR (1:OrMax, 2:OrPlus) -> "; cin >> or_;
    cout << endl << "THEN (1:ThenMin, 2:ThenMult, 3:SugenoThen) -> "; cin >> then;
    cout << endl << "AGG (1:AggMax, 2:AggPlus) -> "; cin >> agg;

    if(then == 3){
        FuzzyFactory<float> f(&opNot,decodeAnd(and_),decodeOr(or_),decodeThen(then),decodeAgg(agg),opDefuzzSugeno,opSugenoConclusion);
        cout << endl << endl << "***** Fonctions membres *****";
        cout << endl << "Repondre par ";
        cout << endl << "isbell min center mid";
        cout << endl << "OU isgauss center sigma";
        cout << endl << "OU istrap min midone midtwo max";
        cout << endl << "OU istrapl min max";
        cout << endl << "OU istrapr min max";
        cout << endl << "OU istriangle min mid max" << endl;

        cin.ignore();
        cout << endl << "poor -> "; getline(cin, poor);
        cout << endl << "good -> "; getline(cin, good);
        cout << endl << "excellent -> "; getline(cin, excellent);
        cout << endl << "rancid -> "; getline(cin, rancid);
        cout << endl << "delicious -> "; getline(cin, delicious);
        cout << endl << "cheap -> "; getline(cin, cheap);
        cout << endl << "average -> "; getline(cin, average);
        cout << endl << "generous -> "; getline(cin, generous);

        Expression<float> *r =
        f.newAgg(
            f.newAgg(
                f.newThen(
                        f.newOr(f.newIs(decodeIs(poor), &service), f.newIs(decodeIs(rancid), &food)),
                        f.newIs(decodeIs(cheap), &tips)
                ),
                f.newThen(
                    f.newIs(decodeIs(good), &service),f.newIs(decodeIs(average), &tips)
                )
            ),
            f.newThen(
                f.newOr(f.newIs(decodeIs(excellent), &service), f.newIs(decodeIs(delicious), &food)),
                f.newIs(decodeIs(generous), &tips)
            )
        );  Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

        while(true){
            cout << "service : "; cin >> s;
            service.setValue(s);
            cout << "food : "; cin >> fo;
            food.setValue(fo);
            cout << "tips -> " << system->evaluate() << endl;
        }

    }
    else{
        FuzzyFactory<float> f(&opNot,decodeAnd(and_),decodeOr(or_),decodeThen(then),decodeAgg(agg),&opDefuzzCog);
        cout << endl << endl << "***** Fonctions membres *****";
        cout << endl << "Repondre par ";
        cout << endl << "isbell min center mid";
        cout << endl << "OU isgauss center sigma";
        cout << endl << "OU istrap min midone midtwo max";
        cout << endl << "OU istrapl min max";
        cout << endl << "OU istrapr min max";
        cout << endl << "OU istriangle min mid max" << endl;

        cout << endl << "poor -> "; getline(cin, poor);
        cout << endl << "good -> "; getline(cin, good);
        cout << endl << "excellent -> "; getline(cin, excellent);
        cout << endl << "rancid -> "; getline(cin, rancid);
        cout << endl << "delicious -> "; getline(cin, delicious);
        cout << endl << "cheap -> "; getline(cin, cheap);
        cout << endl << "average -> "; getline(cin, average);
        cout << endl << "generous -> "; getline(cin, generous);

        std::vector<core::Expression<float>*> rules;

        std::vector<core::Expression<float>*> SC_service_food;
        SC_service_food.push_back(&service);
        SC_service_food.push_back(&food);

        std::vector<core::Expression<float>*> SC_service;
        SC_service.push_back(&service);

        rules.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(decodeIs(poor), &service),
                    f.newIs(decodeIs(rancid), &food)
                ),
                f.newSugenoConclusion(&SC_service_food)
            ));

        rules.push_back(
            f.newThen(
                f.newIs(decodeIs(good), &service),
                f.newSugenoConclusion(&SC_service)
            ));

        rules.push_back(
            f.newThen(
                f.newOr(
                    f.newIs(decodeIs(excellent), &service),
                    f.newIs(decodeIs(delicious), &food)
                ),
                f.newSugenoConclusion(&SC_service_food)
            )); core::Expression<float> *system = f.newSugenoDefuzz(&rules);

            while(true){
                cout << "service : "; cin >> s;
                service.setValue(s);
                cout << "food : "; cin >> fo;
                food.setValue(fo);
                cout << "tips -> " << system->evaluate() << endl;
            }
    }



    return 0;
}
