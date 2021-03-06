#include "dialogsettings.h"
#include "ui_dialogsettings.h"

DialogSettings::DialogSettings(QWidget *parent, CIniFile* ini) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    ui->setupUi(this);
    m_settings = ini;
    FromIni();
}

DialogSettings::~DialogSettings()
{
    delete ui;
}

void DialogSettings::ToIni()
{
    m_settings->setString("fill_method", ui->cmbFillMethod->currentText());
    m_settings->setString("color_theme", ui->cmbThemes->currentText());

}

void DialogSettings::FromIni()
{
    ui->cmbFillMethod->setCurrentText(m_settings->getString("fill_method"));
    ui->cmbThemes->setCurrentText(m_settings->getString("color_theme"));
}

void DialogSettings::on_pushButton_clicked()
{
    ToIni();
    m_settings->Save();
    close();
}
