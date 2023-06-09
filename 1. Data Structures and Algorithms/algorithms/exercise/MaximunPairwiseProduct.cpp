#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;

int MaxPairwiseProduct(const vector<int>& numbers){
    int product = 0;
    int n = numbers.size();
    for (int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            product = max(product, numbers[i] * numbers[j]);
        }
    }
    return product;
}


int main(int argc, const char* argv[]){
    cout << "argv[1]: " << argv[1] << endl;
    int n = atoi(argv[1]);
    // int n;
    // cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    int product = MaxPairwiseProduct(numbers);
    cout << "The maximun pairwise product: " << product << "\n";
    return 0;
}