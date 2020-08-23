#include <iostream>
#include <string>
#include <vector>

class debt{
    private:
    std::vector<double> total;
    std::vector<double> min_pays;
    std::vector<double> interests;
    int movements;
    void paymentPlan(double pay, double mp_0, double t, int maxiter=100){
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
    public:
    debt(double pay, double mp_0, double total, int maxiter=100){
        paymentPlan(pay, mp_0, total, maxiter);
    }
    void updatePaymentPlan(double pay, double mp_0, double total, int maxiter=100){
        paymentPlan(pay, mp_0, total, maxiter);
    }
    void print_debt(){
        std::cout << "Total debt:" << std::endl;
        for(int i = 0; i < movements; i++)
            printf("  %d: $%.2f\n", i, total[i]);
    }
    void print_minPayments(){
        std::cout << "Total interests:" << std::endl;
        for(int i = 0; i < movements; i++)
            printf("  %d: $%.2f\n", i, min_pays[i]);
    }
    void print_interests(){
        std::cout << "Total interests:" << std::endl;
        for(int i = 0; i < movements; i++)
            printf("  %d: $%.2f\n", i, interests[i]);
    }
};
