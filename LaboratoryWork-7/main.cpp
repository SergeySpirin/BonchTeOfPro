#include "myapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
QApplication app(argc, argv);

MyApp window;

window.setWindowTitle("Data Base App");
window.show();

return app.exec();
}
