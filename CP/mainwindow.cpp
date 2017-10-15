#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help.h"

#include <QMenu>
#include <QAction>
#include <QStackedWidget>
#include <QLabel>
#include <QLayout>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1024, 768);
    listOfSystems = new QStackedWidget(this);
    //QLabel *labelWelcome = new QLabel("<p><span style=\" font-size:72pt;\">WELCOME ОТСЮДА</span></p>");
    //QLabel *labelGoodbye = new QLabel("<p><span style=\" font-size:72pt;\">GGGGGUUUUUU</span></p>");
    //listOfSystems->setCurrentIndex(1);
    setCentralWidget(listOfSystems);
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//определяем действия при выборе пунктов меню

void MainWindow::actionShowTheory()
{listOfSystems->setCurrentIndex(1);}

void MainWindow::actionStartDemo()
{listOfSystems->setCurrentIndex(2);}

void MainWindow::actionStartTest()
{listOfSystems->setCurrentIndex(3);}

void MainWindow::actionShowHelp()
{
    Help *window = new Help();
    window->show();
}

//-------------------------------------------

void MainWindow::createMenus()
{
    //-------------------Пункт меню ТЕОРИЯ-------------------------------//
    QMenu * mnTheory = new QMenu("Теория"); // создаём меню Теория
    QAction *showTheory = new QAction("Просмотреть теорию", this);
    connect(showTheory, SIGNAL(triggered()), this, SLOT(actionShowTheory()));\
    mnTheory->addAction(showTheory);
    //-------------------------------------------------------------------//
    //----------------Пункт меню ДЕМОНСТРАЦИЯ----------------------------//
    QMenu * mnDemo = new QMenu("Демонстрация"); // создаём меню Демонстрация
    QAction *startDemo = new QAction("Перейти к демонстрации", this);
    connect(startDemo, SIGNAL(triggered()), this, SLOT(actionStartDemo()));
    mnDemo->addAction(startDemo);
    //-------------------------------------------------------------------//
    //----------------Пункт меню ТЕСТИРОВАНИЕ----------------------------//
    QMenu * mnTest = new QMenu("Тестирование"); // создаем меню Тестирование
    QAction *startTest = new QAction("Начать тестирование", this);
    connect(startTest, SIGNAL(triggered()), this, SLOT(actionStartTest()));
    mnTest->addAction(startTest);
    //-------------------------------------------------------------------//
    //------------------Пункт меню СПРАВКА-------------------------------//
    QMenu * mnHelp = new QMenu("Справка"); // создаем меню Справка
    QAction *showHelp = new QAction("Показать справку", this);
    connect(showHelp, SIGNAL(triggered()), this, SLOT(actionShowHelp()));
    mnHelp->addAction(showHelp);
    //-------------------------------------------------------------------//
    ui->menuBar->addMenu(mnTheory); // Добавляем пункты меню в menuBar, т.е. те, которые будут отображаться в гл. окне
    ui->menuBar->addMenu(mnDemo);
    ui->menuBar->addMenu(mnTest);
    ui->menuBar->addMenu(mnHelp);
}
