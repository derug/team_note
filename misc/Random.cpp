struct Random{
    mt19937 gen;
    Random(){ gen.seed(chrono::steady_clock::now().time_since_epoch().count()); }
    int get(int l, int r){ return uniform_int_distribution<int>(l,r)(gen); }
    template<typename T>
    void shuffle(vector<T>& v){ std::shuffle(v.begin(), v.end(), gen); }
} rnd;
