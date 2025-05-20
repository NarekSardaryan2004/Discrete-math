#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QPainter>

class MainWindow : public QMainWindow {
public:
    MainWindow(int n,int m);
    ~MainWindow();
private:
    void graphh(QPainter *qp) const;

    void paintEvent(QPaintEvent *event);

private:
    QWidget* wid;
    int n, m;
};
#endif // MAINWINDOW_H
