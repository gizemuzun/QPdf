#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include <qfile.h>
#include <QtPrintSupport/QPrinter>
#include <QDir>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QApplication>
#include <QtWidgets>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_write_txt_clicked(){
    //QDir a;
    //a.setCurrent("");
    QString reportPath = "reports";
    QDir d;
    d.mkdir(reportPath);
    //QFile file("reports/myfile.txt");
    QFile file("/home/gizem/reports/myfile.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "file not open");
    }

    //Burası olmadan text dosyasına yazma işlemi gerçekleşmiyor.
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text ;
    file.flush();
    file.close();

}

void MainWindow::on_pushButton_write_pdf_clicked()
{
    QTextDocument *dost = new QTextDocument;

    dost->setDocumentMargin(100);
    QTextCursor cursor(dost);

    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::End);
    cursor.insertBlock();

    cursor.insertText("Gizem");
    cursor.movePosition(QTextCursor::End);


    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("gizem_pdf.pdf");
    dost->print(&printer);

    //14 Ekim 2019




    //Burası olmadan da pdf 'e yazdırıyor
/*
    return;
    QFile file("/home/gizem/Workspace/Qt/hello_world/QFile/myfile.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){

        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.flush();

*/
}

void MainWindow::on_exportpdf_clicked()

{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;

    //doc.setHtml("<p align='center'><img src=':/home/gizem/Masaüstü/desktop bilkon/icons/newton.png'></p>");

    const char* s1 = "<html><head><style>body { font-family: sans-serif;}.note-atomic { background: rgb(242,242,242); width: 1000px; margin: 5px auto; border: 1px solid grey; border-radius: 8px;padding: 5px;}</style></head><body><div class = 'note-atomic'>"
                     "GIZEM UZUN Hacettepe Üniversitesi</div><img src='/home/gizem/Masaüstü/newton.png' width='400' height='300' /></body></html>";
    doc.setHtml(QString::fromStdString(s1));




    doc.setPageSize(printer.pageRect().size()); // Sayfa Numarasını gizlemek için gerekli!
    doc.print(&printer);

}
