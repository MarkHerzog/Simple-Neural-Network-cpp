#include <iostream>
#include <vector>
double predict(double i, double w, double b){
    double value = (w * i) + b;
    return value;
};
double sum(std::vector<double> list){
    double value = 0;
    for(int i = 0; i < list.size(); i++){value += list[i];};
    return value;
};
std::vector<int> inputs = {1, 2, 3, 4};
std::vector<int> targets = {3, 5, 7, 9};
int main(){
    double w = 0.1;
    double b = 0.1;
    double learning_rate = 0.1;
    int epochs = 100;
    for(int i = 0; i < epochs; i ++){
        std::vector<double> pred;
        std::vector<double> errors_d;
        std::vector<double> weight_d;
        std::vector<double> bias_d;
        for(int a = 0; a < 4; a++){pred.push_back(predict(inputs[a], w, b));};
        std::cout << i << '\n';

        for(int t = 0; t < 4; t++){errors_d.push_back(2 * (pred[t] - targets[t]));};
        for(int c = 0; c < 4; c++){weight_d.push_back(errors_d[c] * inputs[c]);};
        for(int d = 0; d < 4; d++){bias_d.push_back(errors_d[d]);};
        w -= learning_rate * (sum(weight_d) / (weight_d.size()));
        b -= learning_rate * (sum(bias_d) / (bias_d.size()));

    };
    std::cout << predict(100, w, b) << '\n';
    std::cin >> epochs;
    return 0;
}