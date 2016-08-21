#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    QGridLayout *grid = new QGridLayout;//���粼��
    grid->addWidget(createFirstExclusiveGroup(), 0, 0);
    //��Ӹ�ѡ�򵽣�0��0��λ��
    grid->addWidget(createSecondExclusiveGroup(), 1, 0);
    grid->addWidget(createNonExclusiveGroup(), 0, 1);
    grid->addWidget(createPushButtonGroup(), 1, 1);
    setLayout(grid);//ʹ���ֹ�����grid��Ϊ��Ϊ��ǰ�����Ĳ���
    setWindowTitle(tr("Group Boxes"));//���ڱ���
    resize(480, 320);//���ô��ڴ�С
}

Window::~Window()
{
    delete ui;
}

QGroupBox *Window::createFirstExclusiveGroup()
{
    //����һ�����
    QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
    //����������ѡ��ť������ʱ��ֻ��һ����ѡ��
    QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));
    radio1->setChecked(true);// radio1Ĭ��ʹ��

    QVBoxLayout *vbox = new QVBoxLayout;//���򲼾ֹ�����
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    // spacer��Ŀ�����߽С�stretch��������ռ����ť�·��Ŀռ䣬
    //ȷ����Щ��ť�����������ڲ��ֵ��Ϸ���
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}


QGroupBox *Window::createSecondExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("E&xclusive Radio Buttons"));
    groupBox->setCheckable(true);//���ʹ��ѡ��ť����
    //The second group box is itself checkable

    groupBox->setChecked(false);//��ʼ��ʹ��״̬
    //����������ѡ��ť������ʱ��ֻ��һ����ѡ��
    QRadioButton *radio1 = new QRadioButton(tr("Rad&io button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("Radi&o button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Radio &button 3"));
    radio1->setChecked(true); // radio1Ĭ��ʹ��
    QCheckBox *checkBox = new QCheckBox(tr("Ind&ependent checkbox"));
    checkBox->setChecked(true);// ��ѡ��ʹ��


    QVBoxLayout *vbox = new QVBoxLayout; //���򲼾ֹ�����
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(checkBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}


QGroupBox *Window::createNonExclusiveGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("Non-Exclusive Checkboxes"));
    groupBox->setFlat(true);//ƽ�����


    QCheckBox *checkBox1 = new QCheckBox(tr("&Checkbox 1"));
    QCheckBox *checkBox2 = new QCheckBox(tr("C&heckbox 2"));
    checkBox2->setChecked(true);
    QCheckBox *tristateBox = new QCheckBox(tr("Tri-&state button"));
    tristateBox->setTristate(true);//��̬ʹ��
    tristateBox->setCheckState(Qt::PartiallyChecked);
    //partially checked.����Qt::Unchecked��Qt::Checked֮��

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBox1);
    vbox->addWidget(checkBox2);
    vbox->addWidget(tristateBox);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}


QGroupBox *Window::createPushButtonGroup()
{
    QGroupBox *groupBox = new QGroupBox(tr("&Push Buttons"));
    groupBox->setCheckable(true);
    groupBox->setChecked(true);


    QPushButton *pushButton = new QPushButton(tr("&Normal Button"));
    QPushButton *toggleButton = new QPushButton(tr("&Toggle Button"));
    toggleButton->setCheckable(true);//˩����ʹ��,������̬��ť
    toggleButton->setChecked(true);
    QPushButton *flatButton = new QPushButton(tr("&Flat Button"));
    flatButton->setFlat(true);//ƽ�水ť


    QPushButton *popupButton = new QPushButton(tr("Pop&up Button"));
    QMenu *menu = new QMenu(this);
    menu->addAction(tr("&First Item"));
    menu->addAction(tr("&Second Item"));
    menu->addAction(tr("&Third Item"));
    menu->addAction(tr("F&ourth Item"));
    popupButton->setMenu(menu);//��ť�����Ӳ˵�
    QAction *newAction = menu->addAction(tr("Submenu"));
    QMenu *subMenu = new QMenu(tr("Popup Submenu"));
    subMenu->addAction(tr("Item 1"));
    subMenu->addAction(tr("Item 2"));
    subMenu->addAction(tr("Item 3"));
    newAction->setMenu(subMenu);
    //QAction���ṩ��һ������ͬʱ�����ڲ˵��͹������ϵĳ����û��������
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(pushButton);
    vbox->addWidget(toggleButton);
    vbox->addWidget(flatButton);
    vbox->addWidget(popupButton);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}
