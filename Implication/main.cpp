#include "../header/SimHash.h"
#include "../header/iHash.h"

int main()
{
    IHash* hash = new SimHash;
    vector<double> vec = {0.4, 7.3, 10.234, -100.9, -34.87};
    for(auto x : vec)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    auto a = hash->hash({vec});
    for(auto x : a[0]){
        cout<<x<<" ";
    }
    return 0;
}

