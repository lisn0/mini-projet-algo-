#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <bits/stdc++.h>
using namespace std;



void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->client->jour <= b->client->jour) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else if ((a->client->jour == b->client->jour) and (a->client->date <= b->client->date)){
         result = a;
         result->next = SortedMerge(a->next, b);
   }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->client->code << " ";
        cout << node->client->jour << " ";
        cout << node->client->importance << " ";
        cout << node->client->date << " ";
        cout << node->client->duree << " ";
        cout << endl;
        node = node->next;
    }
}

void push(Node** head_ref, int new_code, int new_jour, int new_importance, int new_date, int new_duree)
{
    Node* new_node = new Node();
    clientClass * new_client = new clientClass();
    new_client->code = new_code;
    new_client->jour = new_jour;
    new_client->importance = new_importance;
    new_client->date = new_date;
    new_client->duree = new_duree;
    new_node->client = new_client;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

Node add_client(QTableWidget t, Node a){

}


void MainWindow::TableWidgetDisplay()
{
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(0);
    table->setColumnCount(5);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("code"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("jour"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("importance"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("date"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("duree"));
    this->setCentralWidget(table);
    MergeSort(&a);
    while(a){
     table->insertRow(table->rowCount());
     auto code = new QTableWidgetItem;
     code->setData(Qt::EditRole,a->client->code);
     auto jour = new QTableWidgetItem;
     jour->setData(Qt::EditRole,a->client->jour);
     auto importance = new QTableWidgetItem;
     importance->setData(Qt::EditRole,a->client->importance);
     auto date = new QTableWidgetItem;
     date->setData(Qt::EditRole,a->client->date);
     auto duree = new QTableWidgetItem;
     duree->setData(Qt::EditRole,a->client->duree);
     table->setItem(table->rowCount()-1,0,code);
     table->setItem( table->rowCount()-1,1,jour);
     table->setItem( table->rowCount()-1,2,importance);
     table->setItem( table->rowCount()-1,3,date);
     table->setItem( table->rowCount()-1,4,duree);
     a = a->next;
//     printList(a);
    }
}


void MainWindow::on_submit_clicked()
{
    TableWidgetDisplay();
}


void MainWindow::on_AddClient_clicked()
{
    int intcode,intjour,intimportance,intduree,intdate;
    intcode = ui->textEdit_2->toPlainText().toInt();
    intjour = ui->textEdit_3->toPlainText().toInt();
    intimportance = ui->textEdit_4->toPlainText().toInt();
    intduree = ui->textEdit_6->toPlainText().toInt();
    intdate = ui->textEdit_5->toPlainText().toInt();
    auto code = new QTableWidgetItem;
    code->setData(Qt::EditRole,intcode);
    auto jour = new QTableWidgetItem;
    jour->setData(Qt::EditRole,intjour);
    auto importance = new QTableWidgetItem;
    importance->setData(Qt::EditRole,intimportance);
    auto date = new QTableWidgetItem;
    date->setData(Qt::EditRole,intdate);
    auto duree = new QTableWidgetItem;
    duree->setData(Qt::EditRole,intduree);
    push(&a, intcode,intjour,intimportance,intdate,intduree);
    ui->tableWidget_2->insertRow (ui->tableWidget_2->rowCount());
    ui->tableWidget_2->setItem   (ui->tableWidget_2->rowCount()-1,0,code);
    ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1,1,jour);
    ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1,2,importance);
    ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1,3,date);
    ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1,4,duree);
    ui->tableWidget_2->sortByColumn(0,Qt::AscendingOrder);
    if(a->client->importance==1)
    a->client->jour2=a->client->jour-2;
    if(a->client->importance==2)
    a->client->jour2=a->client->jour-6;
    if(a->client->importance==3)
    a->client->jour2=a->client->jour-10;
//    printList(a);

}
