#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.dbus.demo")
    Q_PROPERTY(bool passed READ passed WRITE setPassed NOTIFY passedChanged)
    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    bool methodPass(double temperature);
    void showResult(bool value);

    bool passed() const;
    void setPassed(bool passedValue);

    double temperature() const;
    void setTemperature(double tempValue);

Q_SIGNALS:
    void signalPass(bool pass);

    void passedChanged(bool passed);
    void temperatureChanged(double temperature);

private:
    QMessageBox *m_messageBox;
    QWidget *m_centerWidget;
    QVBoxLayout *m_verticalLayout;
    QLabel *m_label;

    bool m_passed;
    double m_temperature;

};

#endif // MAINWINDOW_H
