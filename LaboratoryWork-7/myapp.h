#ifndef MYAPP_H
#define MYAPP_H

#include <QDebug>
#include <QMessageBox>

#include <QTableView>
#include <QHeaderView>

#include <QWidget>
#include <QFrame>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

#include <QString>
#include <QMap>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

class MyApp : public QWidget
{

public:
    MyApp(QWidget *parent = 0);

private:

    //UI Instances

    void test();

    QTableView *tableView;
    QVBoxLayout *tableViewLayout;

    QFrame *tableFrame, *addingPanelFrame, *removePanelFrame, *filterFrame, *sortingFrame;
    QGridLayout *mainLayout, *addingPanelLayout, *removePanelLayout, *filterLayout, *sortingLayout;
    QVBoxLayout *kitPanelLayout;

    QLabel *addItemLbl, *removeItemLbl, *filterLbl, *sortingLbl;
    QLabel *newCatalogLbl, *newFileLbl, *newSizeLbl;
    QLineEdit *newCatalogLine, *newFileLine, *newSizeLine;
    QPushButton *addItemBtn;

    QLineEdit *removeIdLine;
    QPushButton *removeBtn;

    QPushButton *biggerFilterBtn, *smallerFilterBtn, *clearFilterBtn;

    QPushButton *sortingByIdBtn, *sortingByCatalogBtn, *sortingByFileBtn, *sortingBySizeBtn;

    QMap<QString, QString> styles;
    const int kitPanelLayoutWidth = 220;

    //UI Methods

    void init();

    void initStyles();

    void initTableFrame();

    void initKitPanelLayout();
    void initAddingFrame();
    void initRemoveFrame();
    void initFilterFrame();
    void initSortingFrame();

    void clearFilterButtonSelection();
    void clearSortingButtonSelection();

    //Data Instances

    enum Filter{sizeBigger, sizeSmaller, none};

    bool sortingOrderUp;
    enum SortingField{id, catalog, file, size};

    Filter *filter;
    SortingField *sortingField;

    //Data Base Instances

    QSqlDatabase database;
    QSqlQuery *sqlQuery;
    QSqlTableModel *sqlTableModel;

    //Data Base Methods

    void initDataBase();

    //Slots

    void setDefaultFilterAndSorting();

    void changeFilter();

    void addItmBtnOnClicked();
    void removeItmBtnOnClicked();

    void biggerFilterBtnOnClicked();
    void smallerFilterBtnOnClicked();
    void clearFilterBtnOnClicked();

    void sortingByIdBtnOnClicked();
    void sortingByCatalogBtnOnClicked();
    void sortingByFileBtnOnClicked();
    void sortingBySizeBtnOnClicked();

    //Data Methods

    void changeSorting();

    //Signals

    void catalogLineEdited();
    void fileLineEdited();
    void sizeLineEdited();
    void removeIdLineEdited();

};

#endif // MYAPP_H
