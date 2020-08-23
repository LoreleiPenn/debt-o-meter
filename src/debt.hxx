#ifndef DEBT_SIM
#define DEBT_SIM
#include <vector>
class debt{
    private:
    std::vector<double> total;
    std::vector<double> min_pays;
    std::vector<double> interests;
    int movements;
    void paymentPlan(double, double, double, int);
    public:
    debt(double, double, double, int);
    void updatePaymentPlan(double, double, double, int);
    void print_debt();
    void print_minPayments();
    void print_interests();
};
#endif
