#include <iostream>
#include "debt.hxx"

void debt::paymentPlan(double pay, double mp_0, double t, int maxiter=100){
    int iter = 0;
    total.push_back(t);
    double i_r = mp_0 / t;
    while(total.back() > 0 && iter < maxiter){
        min_pays.push_back(total.back() * i_r);
        if(iter == 0)
            interests.push_back(min_pays.back());
        else
            interests.push_back(interests.back() + min_pays.back());
        double abono_capital = pay - min_pays.back();
        total.push_back(total.back() - abono_capital);
        if(total.back() <= 0){
            total.back() = 0.0;
            min_pays.push_back(0.0);
        }
        iter++;
    }
    movements = iter;
}
debt::debt(double pay, double mp_0, double total){
    paymentPlan(pay, mp_0, total);
}
debt::debt(double pay, double mp_0, double total, int maxiter){
    paymentPlan(pay, mp_0, total, maxiter);
}
void debt::updatePaymentPlan(double pay, double mp_0, double total, int maxiter=100){
    paymentPlan(pay, mp_0, total, maxiter);
}
void debt::print_debt(){
    std::cout << "Total debt:" << std::endl;
    for(int i = 0; i < movements; i++)
        printf("  %d: $%.2f\n", i, total[i]);
}
void debt::print_minPayments(){
    std::cout << "Total interests:" << std::endl;
    for(int i = 0; i < movements; i++)
        printf("  %d: $%.2f\n", i, min_pays[i]);
}
void debt::print_interests(){
    std::cout << "Total interests:" << std::endl;
    for(int i = 0; i < movements; i++)
        printf("  %d: $%.2f\n", i, interests[i]);
}
double debt::get_total(int month){
    return total[month];
}
double debt::get_min_pays(int month){
    return min_pays[month];
}
double debt::get_interests(int month){
    return interests[month];
}
int debt::get_movements(){
    return movements;
}