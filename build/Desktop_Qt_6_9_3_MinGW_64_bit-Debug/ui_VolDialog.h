/********************************************************************************
** Form generated from reading UI file 'VolDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLDIALOG_H
#define UI_VOLDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VolDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineCode;
    QLineEdit *lineDestination;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QLineEdit *lineCompagnie;
    QDoubleSpinBox *spinPrix;
    QHBoxLayout *buttonBox;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *VolDialog)
    {
        if (VolDialog->objectName().isEmpty())
            VolDialog->setObjectName("VolDialog");
        verticalLayout = new QVBoxLayout(VolDialog);
        verticalLayout->setObjectName("verticalLayout");
        lineCode = new QLineEdit(VolDialog);
        lineCode->setObjectName("lineCode");

        verticalLayout->addWidget(lineCode);

        lineDestination = new QLineEdit(VolDialog);
        lineDestination->setObjectName("lineDestination");

        verticalLayout->addWidget(lineDestination);

        dateEdit = new QDateEdit(VolDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(0, 0, 0));

        verticalLayout->addWidget(dateEdit);

        timeEdit = new QTimeEdit(VolDialog);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setTime(QTime(0, 0, 0));

        verticalLayout->addWidget(timeEdit);

        lineCompagnie = new QLineEdit(VolDialog);
        lineCompagnie->setObjectName("lineCompagnie");

        verticalLayout->addWidget(lineCompagnie);

        spinPrix = new QDoubleSpinBox(VolDialog);
        spinPrix->setObjectName("spinPrix");
        spinPrix->setMaximum(100000.000000000000000);
        spinPrix->setDecimals(2);
        spinPrix->setValue(0.000000000000000);

        verticalLayout->addWidget(spinPrix);

        buttonBox = new QHBoxLayout();
        buttonBox->setObjectName("buttonBox");
        btnCancel = new QPushButton(VolDialog);
        btnCancel->setObjectName("btnCancel");

        buttonBox->addWidget(btnCancel);

        btnSave = new QPushButton(VolDialog);
        btnSave->setObjectName("btnSave");

        buttonBox->addWidget(btnSave);


        verticalLayout->addLayout(buttonBox);


        retranslateUi(VolDialog);

        QMetaObject::connectSlotsByName(VolDialog);
    } // setupUi

    void retranslateUi(QDialog *VolDialog)
    {
        VolDialog->setWindowTitle(QCoreApplication::translate("VolDialog", "Vol", nullptr));
        lineCode->setPlaceholderText(QCoreApplication::translate("VolDialog", "Code vol", nullptr));
        lineDestination->setPlaceholderText(QCoreApplication::translate("VolDialog", "Destination", nullptr));
        lineCompagnie->setPlaceholderText(QCoreApplication::translate("VolDialog", "Compagnie", nullptr));
        btnCancel->setText(QCoreApplication::translate("VolDialog", "Annuler", nullptr));
        btnSave->setText(QCoreApplication::translate("VolDialog", "Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolDialog: public Ui_VolDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLDIALOG_H
