#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_write_txt_clicked();

    void on_pushButton_write_pdf_clicked();    


    void on_exportpdf_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
