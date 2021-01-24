#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class clientClass{
public:
    int code;
    int jour;
    int jour2;
    int importance;
    int date;
    int duree;
};

class Node {
public:
    clientClass * client;
    Node* next;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void TableWidgetDisplay();
    Node* a = NULL;

private slots:

    void on_submit_clicked();

    void on_AddClient_clicked();

private:
    Ui::MainWindow *ui;
};
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef);
void push(Node** , int , int , int , int , int );


#endif // MAINWINDOW_H
