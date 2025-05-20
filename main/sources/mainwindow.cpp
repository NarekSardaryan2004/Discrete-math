#include "mainwindow.h"

MainWindow::MainWindow(int m, int n) {
    this->n = n;
    this->m = m;
}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
    graphh(&qp);
}

void MainWindow::graphh(QPainter *qp) const {
    int yOffset = 80, count_for_j = 0, count_for_i = 0;

    bool case1 = (m % 3 == 0 && n % 3 == 0);
    bool case2 = (m % 3 == 1 && n % 3 == 1);
    bool ok_for_j = true, ok_for_i = true;

    QColor color;

    for (int i = 0; i < n; ++i) {
        int xOffset = 80;
        for (int j = 0; j < m; ++j) {
            QPen pen(Qt::black);
            qp->setPen(pen);
            qp->drawEllipse(xOffset, yOffset, 20, 20);

            // Horizontal Lines
            if (j < m - 1) {
                QPen pen;
                if (case1) {
                    if (i < n - 1) {
                        if (m == 3) {
                            if (count_for_j < 2)
                                pen.setColor(Qt::red);
                            else
                                pen.setColor(Qt::blue);

                            ++count_for_j;
                            if (count_for_j == 4)
                                count_for_j = 0;

                            color = pen.color();
                        }
                        else {
                            if (j == 0) {
                                count_for_j = 0;
                            }

                            if (count_for_j < 3)
                                pen.setColor(Qt::red);
                            else
                                pen.setColor(Qt::blue);

                            ++count_for_j;
                            if (count_for_j == 6)
                                count_for_j = 0;

                            if (j == m - 2) {
                                color = pen.color();
                            }

                            if (i % 2 == 1 && j > m - 4) {
                                pen.setColor(Qt::cyan);
                            }
                        }
                    }
                    else {
                        if ((n / 3) % 2 == 0) {
                            if (!ok_for_j) {
                                pen.setColor(Qt::green);
                            }
                            else {
                                pen.setColor(Qt::magenta);
                            }

                            ok_for_j = !ok_for_j;
                        }
                        else {
                            if (ok_for_j) {
                                pen.setColor(Qt::green);
                                ok_for_j = false;
                            }
                            else {
                                pen.setColor(Qt::magenta);
                                ok_for_j = true;
                            }
                        }
                    }
                }
                else if (case2) {
                    if (count_for_j < 3)
                        pen.setColor(Qt::red);
                    else
                        pen.setColor(Qt::blue);

                    ++count_for_j;
                    if (count_for_j == 6)
                        count_for_j = 0;
                }

                qp->setPen(pen);
                qp->drawLine(30 + xOffset, 10 + yOffset, 40 + xOffset, 10 + yOffset);
            }

            // Vertical Lines
            if (i < n - 1) {
                QPen pen;
                if (case1) {
                    if (j < m - 1) {
                        if (j == 0) {
                            if (count_for_i < 3) {
                                ok_for_i = true;
                            }
                            else {
                                ok_for_i = false;
                            }

                            ++count_for_i;
                            if (count_for_i == 6) {
                                count_for_i = 0;
                            }
                        }

                        if (ok_for_i) {
                            pen.setColor(Qt::green);
                            ok_for_i = false;
                        }
                        else {
                            pen.setColor(Qt::magenta);
                            ok_for_i = true;
                        }
                    }
                    else {
                        if (i % 2 == 1 && m != 3)
                            pen.setColor(Qt::cyan);
                        else {
                            pen.setColor(color);
                        }
                    }
                }
                else if (case2) {
                    if (j == 0) {
                        ok_for_i = (count_for_i < 3);
                        ++count_for_i;
                        if (count_for_i == 6)
                            count_for_i = 0;
                    }

                    pen.setColor(ok_for_i ? Qt::green : Qt::magenta);
                }

                qp->setPen(pen);
                qp->drawLine(10 + xOffset, 30 + yOffset, 10 + xOffset, 40 + yOffset);
            }
            xOffset += 50;
        }
        yOffset += 50;
    }
}
