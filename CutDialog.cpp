#include "CutDialog.h"
#include "ui_CutDialog.h"

CutDialog::CutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CutDialog)
{
    ui->setupUi(this);

	ui->mediaCombo->setCurrentIndex(2);
}

CutDialog::~CutDialog()
{
    delete ui;
}

void CutDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int CutDialog::media() const
{
	int idx = ui->mediaCombo->currentIndex();

	int medias[] = {
		100, 101, 102, 106, 111, 112, 113, 120, 121, 122, 123, 124, 125,
		126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138
	};

	if (idx < 0 || idx >= 26)
		idx = 0;
	return medias[idx];
}
int CutDialog::speed() const
{
	return ui->speedSlider->value();
}
int CutDialog::pressure() const
{
	return ui->pressureSlider->value();
}
bool CutDialog::trackEnhancing() const
{
	return ui->trackEnhancingCheckbox->isChecked();
}
void CutDialog::onMediaChanged(int idx)
{

	if (idx < 0 || idx >= 26)
		idx = 0;

	int pressures[] = {
		27, 27, 10, 14, 27, 2, 10, 30, 30, 30, 30, 1, 1,
		1, 30, 20, 27, 30, 30, 5, 25, 20, 20, 30, 30, 30
	};

	int newspeed = idx == 17 ? 3 : 10;
	int newpressure = pressures[idx];

	ui->speedSlider->setValue(newspeed);
	ui->pressureSlider->setValue(newpressure);
}