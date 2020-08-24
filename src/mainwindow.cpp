#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "debt.hxx"
#include <sstream>
#include <QString>

void plotPaymentPlan(double pay, double mp_0, double total, Ui::MainWindow* ui){
    // Define the series to be plotted.
    QtCharts::QLineSeries *series_debt = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *series_min_pays = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *series_interests = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *series_payments = new QtCharts::QLineSeries();

    // Set the names for the series.
    series_debt->setName("Debt");
    series_min_pays->setName("Minimun Payments");
    series_interests->setName("Interests");
    series_payments->setName("Payments");

    // Instantiate the debt and compute the plan.
    debt bbva = debt(pay, mp_0, total);

    // Get the number of movements.
    int m = bbva.get_movements();

    // Fill the series with data.
    for(int i = 0; i <= m; i++){
        series_debt->append(i, bbva.get_total(i));
        series_min_pays->append(i, bbva.get_min_pays(i));
        /*
            If `i = m` then we are 1 movement after the debt was fulfilled.
            This way the last value for the cumulative interest is in `m-1`.
            Also the last payment would be `m-1`.
        */
        if(i != m){
            series_interests->append(i, bbva.get_interests(i));
            series_payments->append(i, pay);
        }
    }

    // Create the chart.
    QtCharts::QChart *chart = new QtCharts::QChart();

    // Add the series to the chart.
    chart->addSeries(series_debt);
    chart->addSeries(series_min_pays);
    chart->addSeries(series_interests);
    chart->addSeries(series_payments);

    // Create the default axes.
    chart->createDefaultAxes();

    // Set the range for the x-axis.
    chart->axes(Qt::Horizontal).first()->setRange(0, m);

    // Change the ticks on the x axis.
    QtCharts::QValueAxis *axisX = qobject_cast<QtCharts::QValueAxis*>(chart->axes(Qt::Horizontal).first());
    Q_ASSERT(axisX);
    axisX->setTickCount(m+1);
    axisX->setLabelFormat("%d");

    // Set the title for the plot.
    std::stringstream ss_title;
    ss_title << "Debt paying plan for montly " << m << " payments of $" << pay << std::endl;
    chart->setTitle(QString::fromStdString(ss_title.str()));

    // Create the chartView to visualize the plot.
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);

    // Set the chartView to use *Antialising*.
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add the chartView on the desired position on the gridLayout.
    ui->gridLayout->addWidget(chartView, 1, 0);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow){
    ui->setupUi(this);
    plotPaymentPlan(15000, 6057.84, 76289.39, ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

