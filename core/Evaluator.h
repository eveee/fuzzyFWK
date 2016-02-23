#ifndef EVALUATOR_H_INCLUDED
#define EVALUATOR_H_INCLUDED

#include <vector>
using namespace std;

namespace core{
    template <class T>
    class Evaluator{
        public:
            class EvalFunc{
                public:
                    virtual T operator () (const T&)=0;
            };
        typedef pair<vector<T>,vector<T> > Shape;
        static Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc&);
        static ostream& PrintShape(ostream&, const Shape& s);
    };

    template <class T>
    typename Evaluator<T>::Shape Evaluator<T>:: BuildShape(const T& min, const T& max, const T& step, EvalFunc& f){
        vector<T> x, y;
        for (T i= min ;i <= max ;i += step){
            y.push_back(f(i));
            x.push_back(i);
        } return Shape(x,y);
    }

    template<class T>
    ostream& Evaluator<T>::PrintShape(ostream& os, const Shape& s){
        os << '[';
        typename vector<T>::const_iterator it= s.first.begin();
        for(; it!=s.first.end(); ++it)
            os << *it << ' ';
        os << ']';
        os << endl;
        os << '[';
        it = s.second.begin();
        for(; it!=s.second.end(); ++it)
            os << *it << ' ';
        os << ']';
        return os;
    }

}


#endif // EVALUATOR_H_INCLUDED
