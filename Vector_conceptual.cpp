#include<bits/stdc++.h> // or #include<vector>
using namespace std;

// Iterators -> begin() , end(), rbegin(),rend();
// Capacity -> size(), max_size(), capacity(),empty(),resize(),shrink_to_fit()
// Element access -> [], at(),front(),back()
// Modifiers-> assign(), push_back(), pop_back(), insert(),erase(),clear(),swap()

void print_vector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> v;

    vector<int>:: iterator it;

    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    //v[0]=50;
    v.push_back(400);
    v.push_back(500);

    it=v.begin();
    cout<<*it<<endl;
    it=v.end()-1;
    cout<<*it<<endl;

    vector<int> ::reverse_iterator it2;
    it2=v.rbegin();
    cout<<*it2<<endl;
    it2=v.rend()-1;
    cout<<*it2<<endl;

    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;


//    v.resize(3);
//    v.shrink_to_fit();

//    cout<<v.size()<<endl;
//    cout<<v.capacity()<<endl;   //capacity increase by 2.
//   // cout<<v.max_size()<<endl;

    print_vector(v);


    return 0;
}
