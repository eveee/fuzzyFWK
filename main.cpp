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
    if (and_ == 1)
        return new AndMin<float>();
    else
        return new AndMult<float>();
}

Or<float>* decodeOr(int or_){
    if (or_ == 1)
        return new OrMax<float>();
    else
        return new OrPlus<float>();
}

Then<float>* decodeThen(int then){
    if (then == 1)
        return new ThenMin<float>();
    else if (then == 2)
        return new ThenMult<float>();
    else
        return new SugenoThen<float>();
}

Agg<float>* decodeAgg(int agg){
    if (agg == 1)
        return new AggMax<float>();
    else
        return new AggPlus<float>();
}

Is<float>* decodeIs(string in){
    int pos1 = in.find(" ", 0);
    int pos2 = in.find(" ", pos1 + 1);
    int pos3 = in.find(" ", pos2 + 1);
    int pos4 = in.find(" ", pos3 + 1);

    string cmd = in.substr(0, pos1);

    if(cmd.compare("isbell") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string mid = in.substr(pos2 + 1, pos3 - (pos2 + 1));
        string center = in.substr(pos3 + 1, in.size() - (pos3 + 1));
        return new IsBell<float>(strtof(min_.c_str(), NULL), strtof(mid.c_str(), NULL), strtof(center.c_str(), NULL));
    }

    else if(cmd.compare("isgauss") == 0){
        string center = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string sigma = in.substr(pos2 + 1, in.size() - (pos2 + 1));
        return new IsGaussian<float>(strtof(center.c_str(), NULL), strtof(sigma.c_str(), NULL));
    }

    else if(cmd.compare("istrap") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string mid1 = in.substr(pos2 + 1, pos3 - (pos2 + 1));
        string mid2 = in.substr(pos3 + 1, pos4 - (pos3 + 1));
        string max_ = in.substr(pos4 + 1, in.size() - (pos4 + 1));
        return new IsTrapeze<float>(strtof(min_.c_str(), NULL), strtof(mid1.c_str(), NULL), strtof(mid2.c_str(), NULL), strtof(max_.c_str(), NULL));
    }

    else if(cmd.compare("istrapl") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string max_ = in.substr(pos2 + 1, in.size() - (pos2 + 1));
        return new IsTrapezeLeft<float>(strtof(min_.c_str(), NULL), strtof(max_.c_str(), NULL));
    }

    else if(cmd.compare("istrapr") == 0){
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string max_ = in.substr(pos2 + 1, in.size() - (pos2 + 1));
        return new IsTrapezeRight<float>(strtof(min_.c_str(), NULL), strtof(max_.c_str(), NULL));
    }

    else {
        string min_ = in.substr(pos1 + 1, pos2 - (pos1 + 1));
        string mid = in.substr(pos2 + 1, pos3 - (pos2 + 1));
        string max_ = in.substr(pos3 + 1, in.size() - (pos3 + 1));
        return new IsTriangle<float>(strtof(min_.c_str(), NULL), strtof(mid.c_str(), NULL), strtof(max_.c_str(), NULL));
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
	/*coeff->push_back(1.0);
	coeff->push_back(1.0);
	coeff->push_back(1.0);
    NaryExpression<float>* opSugenoConclusion = new SugenoConclusion<float>(coeff);*/

    ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);

    cout << "\t Application permettant de calculer les pourboires ";
    cout << endl << "\t -------------------------------------------------" << endl << endl;
    cout << endl <<  "\t *****%% Operateurs %%*****" << endl;
    cout << endl << "\t AND (1:AndMin, 2:AndMult): "; cin >> and_;
    cout << "\t OR (1:OrMax, 2:OrPlus): "; cin >> or_;
    cout << "\t THEN (1:ThenMin, 2:ThenMult, 3:SugenoThen): "; cin >> then;
    cout << "\t AGG (1:AggMax, 2:AggPlus): "; cin >> agg;

    if(then == 3){
        float c1, c2;

        cout << endl << endl << "\t Rentrez deux coefficients (SugenoConclusion): "; cin >> c1; cin >> c2;

        coeff->push_back(c1); coeff->push_back(c2); coeff->push_back(1.0);

        NaryExpression<float>* opSugenoConclusion = new SugenoConclusion<float>(coeff);
        FuzzyFactory<float> f(&opNot,decodeAnd(and_),decodeOr(or_),decodeThen(then),decodeAgg(agg),opDefuzzSugeno,opSugenoConclusion);

        cout << endl << endl << "\t *****%% Fonctions membres %%*****" << endl;
        cout << endl << "\t Repondre par ";
        cout << endl << "\t\t isbell min mid center";
        cout << endl << "\t\t OU isgauss center sigma";
        cout << endl << "\t\t OU istrap min midone midtwo max";
        cout << endl << "\t\t OU istrapl min max";
        cout << endl << "\t\t OU istrapr min max";
        cout << endl << "\t\t OU istriangle min mid max" << endl;

        cin.ignore();
        cout << endl << "\t poor: "; getline(cin, poor);
        cout << "\t good: "; getline(cin, good);
        cout << "\t excellent: "; getline(cin, excellent);
        cout << "\t rancid: "; getline(cin, rancid);
        cout << "\t delicious: "; getline(cin, delicious);
        cout << "\t cheap: "; getline(cin, cheap);
        cout << "\t average: "; getline(cin, average);
        cout << "\t generous: "; getline(cin, generous);

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
            ));

            core::Expression<float> *system = f.newSugenoDefuzz(&rules);

            cout << endl << endl << "\t *****%% Calcul du pourboire %%*****";

            while(true){
                cout << endl << endl << "\t service: "; cin >> s;
                service.setValue(s);
                cout << "\t food: "; cin >> fo;
                food.setValue(fo);
                cout << "\t tips -> " << system->evaluate() << endl;
            }
    }
    else{
        AndMin<float> opAnd;
        OrMax<float> opOr;
        ThenMin<float> opThen;
        AggPlus<float> opAgg;

        /*IsTriangle<float> poor(-5,0,5);
        IsTriangle<float> good(0,5,10);
        IsTriangle<float> excellent(5,10,15);
        IsTriangle<float> rancid(-5,0,5);
        IsTriangle<float> delicious(5,10,15);
        IsTriangle<float> cheap(0,5,10);
        IsTriangle<float> average(10,15,20);
        IsTriangle<float> generous(20,25,30);*/

        FuzzyFactory<float> f(&opNot,decodeAnd(and_),decodeOr(or_),decodeThen(then),decodeAgg(agg),&opDefuzzCog);
        cout << endl << endl << "\t *****%% Fonctions membres %%*****" << endl;
        cout << endl << "\t Repondre par ";
        cout << endl << "\t\t isbell min mid center";
        cout << endl << "\t\t OU isgauss center sigma";
        cout << endl << "\t\t OU istrap min midone midtwo max";
        cout << endl << "\t\t OU istrapl min max";
        cout << endl << "\t\t OU istrapr min max";
        cout << endl << "\t\t OU istriangle min mid max" << endl;

        cin.ignore();
        cout << endl << "\t poor: "; getline(cin, poor);
        cout << "\t good: "; getline(cin, good);
        cout << "\t excellent: "; getline(cin, excellent);
        cout << "\t rancid: "; getline(cin, rancid);
        cout << "\t delicious: "; getline(cin, delicious);
        cout << "\t cheap: "; getline(cin, cheap);
        cout << "\t average: "; getline(cin, average);
        cout << "\t generous: "; getline(cin, generous);

        Expression<float> *r =
        f.newAgg(
            f.newAgg(
                f.newThen(
                        f.newOr(f.newIs(decodeIs(poor), &service), f.newIs(decodeIs(rancid), &food)),
                        f.newIs(decodeIs(rancid), &tips)
                ),
                f.newThen(
                    f.newIs(decodeIs(good), &service),f.newIs(decodeIs(average), &tips)
                )
            ),
            f.newThen(
                f.newOr(f.newIs(decodeIs(excellent), &service), f.newIs(decodeIs(delicious), &food)),
                f.newIs(decodeIs(generous), &tips)
            )
        );

        Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

        cout << endl << endl << "\t *****%% Calcul du pourboire %%*****";

        while(true){
                cout << endl << endl << "\t service: "; cin >> s;
                service.setValue(s);
                cout << "\t food: "; cin >> fo;
                food.setValue(fo);
                cout << "\t tips -> " << system->evaluate() << endl;
        }

    }



    return 0;
}
