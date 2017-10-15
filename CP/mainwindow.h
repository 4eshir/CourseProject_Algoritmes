#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStackedWidget *listOfSystems;

private:
    Ui::MainWindow *ui;
    void createMenus();

private slots:
    void actionShowTheory();
    void actionStartDemo();
    void actionStartTest();
    void actionShowHelp();

};

#endif // MAINWINDOW_H
