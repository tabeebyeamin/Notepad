#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // make textEdit part take up all of the screen
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    // clear the previous file
    currentFile.clear();
    // clear the textEDit widget
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    // open dialog box asking which file to open
    QString fileName = QFileDialog::getOpenFileName(this, "Open the File");
    // object for reading and writing files
    QFile file(fileName);
    currentFile = fileName;
    // open as read-only
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot Open File: " + file.errorString());
        return;
    }
    // otherwise, everything is fine
    setWindowTitle(fileName);
    // create interface for reading text
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    // open dialog box for saving file
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
    QFile file(fileName);

    // open as write-only
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot Save File: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    // create interface for reading text
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    // out to the file
    out << text;
    file.close();



}

void MainWindow::on_actionPrint_triggered()
{
    // allows us to interact with any printer
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if (pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }

    ui->textEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
