#include <iostream>
#include "PathDepOption.h"
#include "GmtrAsianCall.h"

using namespace std;
using namespace fre;

int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    MCModel Model(S0,r,sigma);

    double T =1.0/12.0, K=100.0;
    int m=30;

    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall  CVOption(T,K,m);

    long N=30000;
    double epsilon =0.001;
    
    Option.PriceByVarRedMC(Model,N,CVOption,epsilon);
    cout << "Arithmetic call price = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl << endl
        << "delta = " << Option.GetDelta() << endl;
    
    
    // cout << "delta = " << Option.DeltaByVarRedMC(Model,N,CVOption,epsilon) << endl;

    Option.PriceByMC(Model,N,epsilon);
    cout << "Price by direct MC = " << Option.GetPrice() << endl
        << "Error = " << Option.GetPricingError() << endl << endl
        << "delta = " << Option.GetDelta() << endl;
    
    return 0;
}
/*
Arithmetic call price = 1.42614
Error = 0.000138385
delta = 0.519884

Price by direct MC = 1.42126
Error = 0.0120034
delta = 0.524658

*/

