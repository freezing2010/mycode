#include "mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_messageBox(new QMessageBox(this))
    , m_centerWidget(new QWidget(this))
    , m_verticalLayout(new QVBoxLayout(this))
    , m_label(new QLabel(this))
{
    this->move(800,600);

    this->resize(400,300);


    m_label->setText("empty");
    m_label->resize(40,30);

    m_verticalLayout->addWidget(m_label);

    m_centerWidget->setLayout(m_verticalLayout);

    this->setCentralWidget(m_centerWidget);

//    connect(this, &MainWindow::temperatureChanged, [&](double temperature){
//        this->m_label->setText(QString::number(temperature));
//    });
}

MainWindow::~MainWindow()
{

}

void MainWindow::showResult(bool value)
{
    if(value){
        m_label->setText(QString::fromLocal8Bit("放行！"));
    }else {
        m_label->setText(QString::fromLocal8Bit("隔离！"));
    }
}

bool MainWindow::passed() const
{
    return m_passed;
}

void MainWindow::setPassed(bool passedValue)
{
    qDebug() << "13123123123" << Q_FUNC_INFO << passedValue;
    this->m_passed = passedValue;
    Q_EMIT passedChanged(passedValue);//
    Q_EMIT signalPass(passedValue);
}

double MainWindow::temperature() const
{
    return m_temperature;
}

void MainWindow::setTemperature(double tempValue)
{
    this->m_temperature = tempValue;
    Q_EMIT temperatureChanged(tempValue);
}

bool MainWindow::methodPass(double temperature)
{
    qDebug() << "1233333333333";
    if(temperature > 37.2){
//        emit signalPass(false);
        this->setPassed(false);
//        Q_EMIT passedChanged(false);
//        m_messageBox->setText(QString::fromLocal8Bit("隔离"));
        m_messageBox->information(this,"Tips:",QString::fromLocal8Bit("%1度,隔离!").arg(QString::number(temperature,'f',1)));

        return false;
    }else {
//        emit signalPass(true);
        this->setPassed(true);
//        Q_EMIT passedChanged(true);
//        m_messageBox->setText(QString::fromLocal8Bit("放行"));
        m_messageBox->information(this,"Tips:",QString::fromLocal8Bit("%1度,放行!").arg(QString::number(temperature,'f',1)));

        return true;
    }

//    m_messageBox->show();

}
