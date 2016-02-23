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

using namespace std;
using namespace core;
using namespace fuzzy;

int main()
{
    ValueModel<int>* v = new ValueModel<int>();
    cout << v->evaluate();
    int *i = new int(4);
    ValueModel<int>* va = new ValueModel<int>(i);
    cout << va->evaluate();
   //operators
    NotMinus1<int> opNot;
    AndMin<int> opAnd;
    OrMax<int> opOr;
    ThenMin<int> opThen;

    BinaryExpressionModel<int> *b = new BinaryExpressionModel<int>(&opThen, v, va);
    cout << b->evaluate();

    UnaryExpressionModel<int> *u = new UnaryExpressionModel<int>(&opNot, va);
    cout << u->evaluate();

    /*
    CogDefuzz opDefuzz;
    //fuzzy expession factory
    FuzzyExpressionFactory f(&opNot,&opAnd,&opOr,&opThen,&opOr,&opDefuzz);
    //membership function
    IsTriangle poor(-5,0,5);
    IsTriangle good(0,5,10);
    IsTriangle excellent(5,10,15);
    IsTriangle cheap(0,5,10);
    IsTriangle average(10,15,20);
    IsTriangle generous(20,25,30);
    //values
    Value service(0);
    Value food(0);
    Value tips(0);

    Expression *r =
    f.NewAgg(
        f.NewAgg(
            f.NewThen(
                f.NewIs(&service,&poor),f.NewIs(&tips,&cheap)
            ),
            f.NewThen(
                f.NewIs(&service,&good),f.NewIs(&tips,&average)
            )
        ),
        f.NewThen(
            f.NewIs(&service,&excellent),f.NewIs(&tips,&generous)
        )
    );
    //defuzzification
    Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);
    //apply input
    float s;
    while(true){
        cout << "service : ";cin >> s;
        service.SetValue(s);
        cout << "tips -> " << system->Evaluate() << endl;
    }*/
    return 0;
}
