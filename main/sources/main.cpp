#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool ok;
    int n = QInputDialog::getInt(nullptr, "Enter Value", "Enter the value of n:", 1, 1, 100, 1, &ok);

    if (!ok) return 0;

    int m = QInputDialog::getInt(nullptr, "Enter Value", "Enter the value of m:", 1, 1, 100, 1, &ok);

    if (!ok) return 0;

    if ((m == 1 && n == 1) || !((m % 3 == 0 && n % 3 == 0) || (m % 3 == 1 && n % 3 == 1))) {
        QMessageBox::critical(nullptr, "Error", "Can't cover");

        return 0;
    } else {
        MainWindow w(m, n);
        w.resize(m * 110, n * 110);
        w.show();

        return a.exec();
    }

    return 0;
}
