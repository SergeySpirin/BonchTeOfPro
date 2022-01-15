#include "myapp.h"

MyApp::MyApp(QWidget *parent)
: QWidget(parent)
{
    init();

    initDataBase();

    setDefaultFilterAndSorting();

    setLayout(mainLayout);
}

//UI Inicialising

void MyApp::initStyles()
{
    styles["primaryColor"] = "#1F2023";
    styles["accentColor"] = "#27292D";
    styles["thirdColor"] = "#383B40";
    styles["buttonColor"] = "#0071DF";
    styles["frame"] = "border: 1px solid " + styles["accentColor"] + "; "
                      "border-radius: 7px; "
                      "background-color: " + styles["accentColor"] + ";";
    styles["label"] = "border: none; "
                      "font-weight: 700;";
    styles["lineEdit"] = "color: gray; "
                         "border-radius: 10px; "
                         "border: 2px solid #383B40; "
                         "background-color: " + styles["thirdColor"] + ";";
    styles["errorLineEdit"] = "color: gray; "
                              "border-radius: 10px; "
                              "border: 2px solid red; "
                              "background-color: " + styles["thirdColor"] + ";";
    styles["button"] = "min-width: 100px; "
                       "color: #fff; "
                       "border-radius: 5px; "
                       "border: 2px solid #324456; "
                       "background-color: " + styles["buttonColor"] + ";";
    styles["selectedButton"] = "min-width: 100px; "
                               "color: #fff; "
                               "border-radius: 5px; "
                               "border: 2px solid #6dcf38; "
                               "background-color: " + styles["buttonColor"] + ";";
    styles["table"] = "border-radius: 10px;";
}

void MyApp::initTableFrame()
{
    tableView = new QTableView();


    tableView->setStyleSheet(styles["table"]);

    tableView->verticalHeader()->hide();

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);;

    int tableViewWidth = tableView->rect().width();

    tableView->setColumnWidth(0, tableViewWidth * 0.05);
    tableView->setColumnWidth(1, tableViewWidth * 0.4);
    tableView->setColumnWidth(2, tableViewWidth * 0.4);
    tableView->setColumnWidth(3, tableViewWidth * 0.15);

    tableViewLayout = new QVBoxLayout();

    tableViewLayout->addWidget(tableView);

    tableFrame = new QFrame();
    tableFrame->setStyleSheet(styles["frame"]);
    tableFrame->setFixedSize(650, 550);

    tableFrame->setLayout(tableViewLayout);
}

void MyApp::initAddingFrame()
{
    addItemLbl = new QLabel("Add File");
    addItemLbl->setStyleSheet(styles["label"]);

    newCatalogLbl = new QLabel("Catalog: ");
    newFileLbl = new QLabel("File: ");
    newSizeLbl = new QLabel("Size: ");

    newCatalogLine = new QLineEdit();
    newFileLine = new QLineEdit();
    newSizeLine = new QLineEdit();

    newCatalogLine->setPlaceholderText("Catalog");
    newFileLine->setPlaceholderText("File");
    newSizeLine->setPlaceholderText("Size");

    newCatalogLine->setStyleSheet(styles["lineEdit"]);
    newFileLine->setStyleSheet(styles["lineEdit"]);
    newSizeLine->setStyleSheet(styles["lineEdit"]);

    newCatalogLine->setAlignment(Qt::AlignCenter);
    newFileLine->setAlignment(Qt::AlignCenter);
    newSizeLine->setAlignment(Qt::AlignCenter);

    connect(newCatalogLine, &QLineEdit::textEdited, this, &MyApp::catalogLineEdited);
    connect(newFileLine, &QLineEdit::textEdited, this, &MyApp::fileLineEdited);
    connect(newSizeLine, &QLineEdit::textEdited, this, &MyApp::sizeLineEdited);

    addItemBtn = new QPushButton(" Add Item ");
    addItemBtn->setStyleSheet(styles["button"]);

    connect(addItemBtn, &QPushButton::clicked, this, &MyApp::addItmBtnOnClicked);

    //Layout Options

    addingPanelLayout = new QGridLayout();
    addingPanelLayout->setSpacing(8);

    //Widgets Options

    addingPanelLayout->addWidget(addItemLbl, 0, 0, 1, 4, Qt::AlignJustify);

    addingPanelLayout->addWidget(newCatalogLbl, 1, 0, 1, 1, Qt::AlignLeft);
    addingPanelLayout->addWidget(newFileLbl, 2, 0, 1, 1, Qt::AlignLeft);
    addingPanelLayout->addWidget(newSizeLbl, 3, 0, 1, 1, Qt::AlignLeft);

    addingPanelLayout->addWidget(newCatalogLine, 1, 1, 1, 3);
    addingPanelLayout->addWidget(newFileLine, 2, 1, 1, 3);
    addingPanelLayout->addWidget(newSizeLine, 3, 1, 1, 3);

    addingPanelLayout->addWidget(addItemBtn, 4, 0, 1, 4, Qt::AlignJustify);

    //Frame Options

    addingPanelFrame = new QFrame();
    addingPanelFrame->setStyleSheet(styles["frame"]);
    addingPanelFrame->setMinimumWidth(kitPanelLayoutWidth);

    addingPanelFrame->setLayout(addingPanelLayout);
}

void MyApp::initRemoveFrame()
{
    removeItemLbl = new QLabel("Remove File");
    removeItemLbl->setStyleSheet(styles["label"]);

    removeIdLine = new QLineEdit();
    removeIdLine->setPlaceholderText("ID");
    removeIdLine->setAlignment(Qt::AlignCenter);
    removeIdLine->setStyleSheet(styles["lineEdit"]);

    connect(removeIdLine, &QLineEdit::textEdited, this, &MyApp::removeIdLineEdited);

    removeBtn = new QPushButton(" Remove Item ");
    removeBtn->setStyleSheet(styles["button"]);

    //Layout Options

    removePanelLayout = new QGridLayout();
    removePanelLayout->setSpacing(8);

    //Widgets Options

    removePanelLayout->addWidget(removeItemLbl, 0, 0, 1, 4, Qt::AlignJustify);
    removePanelLayout->addWidget(removeIdLine, 1, 1, 1, 2, Qt::AlignJustify);
    removePanelLayout->addWidget(removeBtn, 2, 0, 1, 4, Qt::AlignJustify);

    connect(removeBtn, &QPushButton::clicked, this, &MyApp::removeItmBtnOnClicked);


    //Frame Options

    removePanelFrame = new QFrame();
    removePanelFrame->setStyleSheet(styles["frame"]);
    removePanelFrame->setMinimumWidth(kitPanelLayoutWidth);

    removePanelFrame->setLayout(removePanelLayout);
}

void MyApp::initFilterFrame()
{
    filterLbl = new QLabel("Set Filter");
    filterLbl->setStyleSheet(styles["label"]);

    biggerFilterBtn = new QPushButton(" Size > 1GB ");
    smallerFilterBtn = new QPushButton(" Size < 1GB ");
    clearFilterBtn = new QPushButton(" Clear Filter ");

    biggerFilterBtn->setStyleSheet(styles["button"]);
    smallerFilterBtn->setStyleSheet(styles["button"]);
    clearFilterBtn->setStyleSheet(styles["button"]);

    connect(biggerFilterBtn, &QPushButton::clicked, this, &MyApp::biggerFilterBtnOnClicked);
    connect(smallerFilterBtn, &QPushButton::clicked, this, &MyApp::smallerFilterBtnOnClicked);
    connect(clearFilterBtn, &QPushButton::clicked, this, &MyApp::clearFilterBtnOnClicked);

    //Layout Options

    filterLayout = new QGridLayout();
    filterLayout->setSpacing(8);

    //Widgets Options

    filterLayout->addWidget(filterLbl, 0, 0, 1, 4, Qt::AlignJustify);
    filterLayout->addWidget(biggerFilterBtn, 1, 0, 1, 2);
    filterLayout->addWidget(smallerFilterBtn, 1, 2, 1, 2);
    filterLayout->addWidget(clearFilterBtn, 2, 0, 1, 4);

    //Frame Options

    filterFrame = new QFrame();
    filterFrame->setStyleSheet(styles["frame"]);
    filterFrame->setMinimumWidth(kitPanelLayoutWidth);

    filterFrame->setLayout(filterLayout);
}

void MyApp::initSortingFrame()
{
    sortingLbl = new QLabel("Set Sorting");
    sortingLbl->setStyleSheet(styles["label"]);

    sortingByIdBtn = new QPushButton(" Sort By Id ");
    sortingByCatalogBtn = new QPushButton(" Sort By Catalog ");
    sortingByFileBtn = new QPushButton(" Sort By File ");
    sortingBySizeBtn = new QPushButton(" Sort By Size ");

    sortingByIdBtn->setStyleSheet(styles["button"]);
    sortingByCatalogBtn->setStyleSheet(styles["button"]);
    sortingByFileBtn->setStyleSheet(styles["button"]);
    sortingBySizeBtn->setStyleSheet(styles["button"]);

    connect(sortingByIdBtn, &QPushButton::clicked, this, &MyApp::sortingByIdBtnOnClicked);
    connect(sortingByCatalogBtn, &QPushButton::clicked, this, &MyApp::sortingByCatalogBtnOnClicked);
    connect(sortingByFileBtn, &QPushButton::clicked, this, &MyApp::sortingByFileBtnOnClicked);
    connect(sortingBySizeBtn, &QPushButton::clicked, this, &MyApp::sortingBySizeBtnOnClicked);

    //Layout Options

    sortingLayout = new QGridLayout();
    sortingLayout->setSpacing(8);

    //Widgets Options

    sortingLayout->addWidget(sortingLbl, 0, 3, 1, 2, Qt::AlignJustify);

    sortingLayout->addWidget(sortingByIdBtn, 1, 0, 1, 4);
    sortingLayout->addWidget(sortingByCatalogBtn, 1, 4, 1, 4);
    sortingLayout->addWidget(sortingByFileBtn, 2, 0, 1, 4);
    sortingLayout->addWidget(sortingBySizeBtn, 2, 4, 1, 4);

    //Frame Options

    sortingFrame = new QFrame();
    sortingFrame->setStyleSheet(styles["frame"]);
    sortingFrame->setMinimumWidth(kitPanelLayoutWidth);

    sortingFrame->setLayout(sortingLayout);
}

void MyApp::initKitPanelLayout()
{
    initAddingFrame();
    initRemoveFrame();
    initFilterFrame();
    initSortingFrame();

    kitPanelLayout = new QVBoxLayout();

    kitPanelLayout->addWidget(addingPanelFrame, 9);
    kitPanelLayout->addWidget(removePanelFrame, 6);
    kitPanelLayout->addWidget(filterFrame, 6);
    kitPanelLayout->addWidget(sortingFrame, 6);
}

//Database Inicialisation

void MyApp::initDataBase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("MainDateBase");

    if(database.open())
    {
        qDebug("Database opened.");
    }
    else
    {
        qDebug("Error opening database.");
    }

    sqlQuery = new QSqlQuery(database);

    if(!database.tables().contains("Explorer"))
    {
        sqlQuery->clear();
        sqlQuery->exec("CREATE TABLE Explorer(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, Catalog VARCHAR, File VARCHAR, Size INTEGER);");
        sqlQuery->clear();
        sqlQuery->exec("INSERT INTO Explorer(Catalog, File, Size) VALUES ('Catalog-1', 'File-1', 299);");
    };

    sqlTableModel = new QSqlTableModel(this, database);
    sqlTableModel->setTable("Explorer");
    sqlTableModel->select();
    sqlTableModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    tableView->setModel(sqlTableModel);

};

void MyApp::setDefaultFilterAndSorting()
{
    filter = new Filter(Filter::none);

    sortingOrderUp = true;
    sortingField = new SortingField(id);

    clearFilterBtn->setStyleSheet(styles["selectedButton"]);
    sortingByIdBtn->setStyleSheet(styles["selectedButton"]);
};

void MyApp::clearFilterButtonSelection()
{
    biggerFilterBtn->setStyleSheet(styles["button"]);
    smallerFilterBtn->setStyleSheet(styles["button"]);
    clearFilterBtn->setStyleSheet(styles["button"]);
};

void MyApp::changeFilter()
{
    switch (*filter)
    {
        case (Filter::sizeBigger):
            sqlTableModel->setFilter("Size>1024");
        break;
        case (Filter::sizeSmaller):
            sqlTableModel->setFilter("Size<1024");
        break;
        case (Filter::none):
            sqlTableModel->setFilter("");
        break;
    };
    sqlTableModel->select();
    tableView->setModel(sqlTableModel);
};

void MyApp::addItmBtnOnClicked()
{
    QString catalog = newCatalogLine->text();
    QString file = newFileLine->text();
    QString size = newSizeLine->text();

    if(size == "")
    {
        newSizeLine->setStyleSheet(styles["errorLineEdit"]);
    }
    else if(size.toInt() < 0)
    {
        newSizeLine->setStyleSheet(styles["errorLineEdit"]);
        newSizeLine->clear();

        QMessageBox::warning(0, "Error", "Size of the file is less than 0!");
    }
    else
    {
        newSizeLine->setStyleSheet(styles["lineEdit"]);
    };

    if(size.toInt() > 0 && catalog != "" && file != "")
    {
        newCatalogLine->clear();
        newFileLine->clear();
        newSizeLine->clear();

        newCatalogLine->setStyleSheet(styles["lineEdit"]);
        newFileLine->setStyleSheet(styles["lineEdit"]);
        newSizeLine->setStyleSheet(styles["lineEdit"]);

        sqlQuery->clear();
        sqlQuery->exec("INSERT INTO Explorer (Catalog, File, Size) VALUES ('" + catalog + "','" + file + "'," + size + ");");

        sqlTableModel->select();

        catalog = "";
        file = "";
        size = "";
    }
    else if(catalog == "" || file == "")
    {
        if(size == "")
        {
            newSizeLine->setStyleSheet(styles["errorLineEdit"]);
        };
        if(catalog == "")
        {
            newCatalogLine->setStyleSheet(styles["errorLineEdit"]);
        }
        else
        {
            newCatalogLine->setStyleSheet(styles["lineEdit"]);
        };
        if(file == "")
        {
            newFileLine->setStyleSheet(styles["errorLineEdit"]);
        }
        else
        {
            newFileLine->setStyleSheet(styles["lineEdit"]);
        };

        QMessageBox::warning(0, "Error", "Some fields are empty!");
    };
};

void MyApp::removeItmBtnOnClicked()
{
    QString id;
    id = removeIdLine->text();

    if(id.toInt() > 0)
    {
        sqlQuery->clear();
        sqlQuery->exec("DELETE FROM Explorer WHERE ID=" + id);

        removeIdLine->setStyleSheet(styles["lineEdit"]);
        removeIdLine->clear();

        sqlTableModel->select();
    }
    else if(id == "" || id.toInt() < 0)
    {
        removeIdLine->setStyleSheet(styles["errorLineEdit"]);
        removeIdLine->clear();

        QMessageBox::warning(0, "Error", "Incorrect ID!");
    };
};

void MyApp::clearSortingButtonSelection()
{
    sortingByIdBtn->setStyleSheet(styles["button"]);
    sortingByCatalogBtn->setStyleSheet(styles["button"]);
    sortingByFileBtn->setStyleSheet(styles["button"]);
    sortingBySizeBtn->setStyleSheet(styles["button"]);
};

void MyApp::biggerFilterBtnOnClicked()
{
    clearFilterButtonSelection();
    biggerFilterBtn->setStyleSheet(styles["selectedButton"]);

    *filter = Filter::sizeBigger;

    changeFilter();
};

void MyApp::smallerFilterBtnOnClicked()
{
    clearFilterButtonSelection();
    smallerFilterBtn->setStyleSheet(styles["selectedButton"]);

    *filter = Filter::sizeSmaller;

    changeFilter();
};

void MyApp::clearFilterBtnOnClicked()
{
    clearFilterButtonSelection();
    clearFilterBtn->setStyleSheet(styles["selectedButton"]);

    *filter = Filter::none;

    changeFilter();
};

void MyApp::sortingByIdBtnOnClicked()
{
    clearSortingButtonSelection();
    sortingByIdBtn->setStyleSheet(styles["selectedButton"]);

    sortingOrderUp = *sortingField == SortingField::id ? !sortingOrderUp : true;
    *sortingField = SortingField::id;

    changeSorting();
};

void MyApp::sortingByCatalogBtnOnClicked()
{
    clearSortingButtonSelection();
    sortingByCatalogBtn->setStyleSheet(styles["selectedButton"]);

    sortingOrderUp = *sortingField == SortingField::catalog ? !sortingOrderUp : true;
    *sortingField = SortingField::catalog;

    changeSorting();
};

void MyApp::sortingByFileBtnOnClicked()
{
    clearSortingButtonSelection();
    sortingByFileBtn->setStyleSheet(styles["selectedButton"]);

    sortingOrderUp = *sortingField == SortingField::file ? !sortingOrderUp : true;
    *sortingField = SortingField::file;

    changeSorting();
};

void MyApp::sortingBySizeBtnOnClicked()
{
    clearSortingButtonSelection();
    sortingBySizeBtn->setStyleSheet(styles["selectedButton"]);

    sortingOrderUp = *sortingField == SortingField::size ? !sortingOrderUp : true;
    *sortingField = SortingField::size;

    changeSorting();
};

void MyApp::changeSorting()
{
    switch (*sortingField)
    {
        case (SortingField::id):
            if(sortingOrderUp)
            {
                sqlTableModel->setSort(0, Qt::AscendingOrder);
            }
            else if(!sortingOrderUp)
            {
                sqlTableModel->setSort(0, Qt::DescendingOrder);
            }
        break;
        case (SortingField::catalog):
            if(sortingOrderUp)
            {
                sqlTableModel->setSort(1, Qt::AscendingOrder);
            }
            else if(!sortingOrderUp)
            {
                sqlTableModel->setSort(1, Qt::DescendingOrder);
            }
        break;
        case (SortingField::file):
            if(sortingOrderUp)
            {
                sqlTableModel->setSort(2, Qt::AscendingOrder);
            }
            else if(!sortingOrderUp)
            {
                sqlTableModel->setSort(2, Qt::DescendingOrder);
            }
        break;
        case (SortingField::size):
            if(sortingOrderUp)
            {
                sqlTableModel->setSort(3, Qt::AscendingOrder);
            }
            else if(!sortingOrderUp)
            {
                sqlTableModel->setSort(3, Qt::DescendingOrder);
            }
        break;
    };
    sqlTableModel->select();
};

void MyApp::catalogLineEdited()
{
    newCatalogLine->setStyleSheet(styles["lineEdit"]);
}

void MyApp::fileLineEdited()
{
    newFileLine->setStyleSheet(styles["lineEdit"]);
}

void MyApp::sizeLineEdited()
{
    newSizeLine->setStyleSheet(styles["lineEdit"]);
}

void MyApp::removeIdLineEdited()
{
    removeIdLine->setStyleSheet(styles["lineEdit"]);
}

void MyApp::init()
{
    initStyles();
    initTableFrame();
    initKitPanelLayout();

    mainLayout = new QGridLayout(this);
    setStyleSheet("background-color: " + styles["primaryColor"] + ";");
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(10, 10, 10, 10);

    mainLayout->addWidget(tableFrame, 0, 0);
    mainLayout->addLayout(kitPanelLayout, 0, 1);
}
