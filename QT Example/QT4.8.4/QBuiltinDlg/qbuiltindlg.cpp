#include "qbuiltindlg.h"
#include "ui_qbuiltindlg.h"

QBuiltinDlg::QBuiltinDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QBuiltinDlg)
{
    displayTextEdit = new QTextEdit(tr("The standard text edit of QT"));
    QGridLayout* gridLayout = new QGridLayout;
/*
 *����һ�����񲼾ֹ�����QGridLayout����gridLayout���ֹ��������������Ų����еĴ��ڲ�����
 *������������7��QPushButton������Щ����ֱ�����������ɫ�Ի��򡢴�����Ϣ���ļ��Ի�������Ի�������Ի� ��ҳ���öԻ��򡢽��ȶԻ���ʹ�ӡ�Ի���Ĵ�������ʾ��
 *Ȼ�����QGridLayout::addWidget()�����������е�QPushButton�Լ�QTextEdit���ڲ����Ų������񲼾ֹ�����gridLayout�С�
 *��󣬺���QDialog::setLayout()�����񲼾ֹ�����gridLayout����Ϊ�ڽ��Ի���CBuiltinDlg����Ķ��㲼�ֹ�������
 */
    colorPushBtn	= new QPushButton(tr("Color Dialog"));
    errorPushBtn	= new QPushButton(tr("Error Message"));
    filePushBtn	= new QPushButton(tr("File Dialog"));
    fontPushBtn	= new QPushButton(tr("Front Dialog"));
    inputPushBtn	= new QPushButton(tr("Input Dialog"));
    pagePushBtn	= new QPushButton(tr("PageSet Dialog"));
    progressPushBtn = new QPushButton(tr("Process Dialog"));
    printPushBtn	= new QPushButton(tr("Printer Dialog"));
    gridLayout->addWidget(colorPushBtn, 0, 0, 1, 1);
    gridLayout->addWidget(errorPushBtn, 0, 1, 1, 1);
    gridLayout->addWidget(filePushBtn, 0, 2, 1, 1);
    gridLayout->addWidget(fontPushBtn, 1, 0, 1, 1);
    gridLayout->addWidget(inputPushBtn, 1, 1, 1, 1);
    gridLayout->addWidget(pagePushBtn, 1, 2, 1, 1);
    gridLayout->addWidget(progressPushBtn, 2, 0, 1, 1);
    gridLayout->addWidget(printPushBtn, 2, 1, 1, 1);
    gridLayout->addWidget(displayTextEdit, 3, 0, 3, 3);

/*
 *�����е�QPushButton�����clicked()�źŹ������ڽ��Ի�����CBuiltinDlg�Ĳۺ���doPushButton()��
 *������QPushButton����� ������������ͳһ�Ĳۺ���doPushButton()������
*/
    connect(colorPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(errorPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(filePushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(fontPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(inputPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(pagePushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(progressPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
    connect(printPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));

    setWindowTitle(tr("Builtin"));
    resize(400, 300);
    setLayout(gridLayout);
}

QBuiltinDlg::~QBuiltinDlg()
{
    delete ui;
}

void QBuiltinDlg::doPushBtn()
{
    /*
     *�ۺ����Ŀ�ͷ�������ǻ�ȡ�����źŵ�QPushButton�����ָ�롣����QOjbect::sender()���ط����źŵĶ����ָ�룬�������� ΪQObject*��
     *ģ�庯�� T qobject_cast(QObject* object)
     *������͵�ת������<QOjbect*>���͵Ķ���ָ��ת��Ϊ����Ϊ<T   *>�Ķ���ָ�룬���ת���ɹ���������ȷ�Ķ���ָ�룬���� ����0��
     *����T������ֱ�ӻ��Ӽ̳���QOjbect���࣬�����ڸ���Ķ�������Q_OBJECT�����������qobject_cast()�����ķ���ֵ��δ����ģ���
     *���⣬������Ϊһ����̳���������qobject_cast()ģ�庯�������������ڱ�׼C++��
     *dynamic_cast()ģ�庯��������qobject_cast()����Ҫ����ʱ������Ϣ��Run-Time Type Information, RTTI����֧�֡�
*/
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    /*
     *if()�����ж���䣬�жϷ����źŵĶ����Ƿ�����Ӧ��QPushButton����colorBtn��errorPushBtn�ȣ���������򴴽� ��Ӧ��Qt�ڽ��Ի��򲢽�����ʾ��
     *���򽫻������öδ��룬ֱ���ҵ�����Ϊtrue��if()������䡣
     */
    if(btn == colorPushBtn)
    {// ��ɫ�Ի���.
        QPalette palette = displayTextEdit->palette();
        const QColor& color = QColorDialog::getColor(palette.color(QPalette::Base), this);
        if(color.isValid())
        {
            palette.setColor(QPalette::Base, color);
            displayTextEdit->setPalette(palette);

        }
    }
    /*
     *������δ�������ɫ�Ի�������ӣ����Ĺ���������Qt�ڽ�����ɫ�Ի���QColorDialog���ȡ�û�ѡ�����ɫ��Ȼ�������ı� �༭��ı���ɫ��
     *����QTextEdit::palette()��ȡ�ı��༭�����displayTextEdit�ĵ�ɫ�塣
     *������������ QColorDialog::getColor()������������ʾһ��ģ̬����ɫ�Ի��򣬲������û�ѡ�����ɫ����ĳ������ã���ʱ�������������Ч�ģ�����ʹ�ó������ã���������color��
     *����û�������ȡ������ť����ɫ�Ի��򽫷���һ����Ч����ɫ��
     *��ɫ�Ի������ɫ��ʼ��Ϊpalette.color  (QPalette::Base)�����ı��༭��ı���ɫ�������ڲ���Ϊthis��
     *QColor::isValid() �����ж���ɫ�Ի��򷵻ص���ɫ�Ƿ���Ч�������ɫ�Ի��򷵻ص���ɫ����Ч�ģ�����QPalette::setColor() �� �õ�ɫ��ı�����ɫΪ��ɫ�Ի��򷵻ص���ɫ��
     *�˴���QPalette:: setColor() ��������2����������1������QPalette::Baseָ���˵�ɫ��Ľ�ɫ��
     *���߳���Ӧ�����õ�ɫ�������������ɫ���е���һ����ɫ����ɫ���ú�������Ӱ�쵽���е�������ɫ�飩��
     *��2������  color ָ��Ӧ�����õ���ɫ����󣬺���QtextEdit::setPalette()���������ı��༭��ĵ�ɫ�塣
*/
    else if(btn == errorPushBtn)
    {// ������Ϣ��.
        QErrorMessage box(this);
        box.setWindowTitle(tr("Error Message"));
        box.showMessage(tr("Error 1"));
        box.showMessage(tr("Error 2"));
        box.showMessage(tr("Error 3"));
        box.showMessage(tr("Error 4"));
        box.showMessage(tr("Error 5"));
        box.exec();
    }
    /*
     *�öδ�����һ��������Ϣ������ӡ�����������У���ε�����QErrorMessage::showMessage()�������ú����Ĺ������ڴ����� Ϣ������ʾ������Ϣ��
     *��ε��øú�������Ϊ����ʾ��ʾ��ͬ������Ϣ�������ͬ������Ϣ�Լ�������Ϣ��ġ��ٴ���ʾ�����Ϣ����ѡ��ѡ������Ч����
     *���ִ��QErrorMessage::exec()��ʾ�Ի���
     *��Ϊ���������Եġ�API����
     */
    else if(btn == filePushBtn)
    {// �ļ��Ի���.
        QString fileName = QFileDialog::getOpenFileName(this,tr("open the file"),"/home/czm",
                                                        tr("All files(*.*)"";;text files(*.txt)"";;XML files(*.xml)"));
        displayTextEdit->setText(fileName);
    }
    /*
     *�öδ����һ���ļ��Ի��򣬻�ȡ�û�ѡ����ļ�������ʾ���ı��༭���С��˴�������QFileDialog::getOpenFileName()����4��������
     *���У�ʵ�� this ָ���ļ��Ի���ĸ����ڲ�����ʵ�� tr("���ļ�") ָ���ļ��Ի���ı��⣻
     *ʵ�Ρ�/home/czm��ָ �����ļ��Ի����Ĭ��·�������һ�������Ƚϸ��ӣ���ָ�����ļ��Ի���Ķ���ļ���������������֮��ͨ�������� �š�;;�������
     *����û�ѡ�����ļ�����������ȷ������ť����ô���ļ��Ի��򽫷����û�ѡ����ļ�����������û�������ȡ������ ť���öԻ��򽫷���һ��NULL �ַ�����
     */
    else if(btn == fontPushBtn)
    {// ����Ի���.
        bool ok;
        const QFont& font = QFontDialog::getFont(&ok, displayTextEdit->font(),this,tr("����Ի���"));
        if(ok)
        {// ���<ȷ��>,��������.
            displayTextEdit->setFont(font);
        }
    }
    /*
     *QFontDialog::getFont()   ������������ʾһ������Ի��򡣴˴����ú��������ĸ�������
     *��1��������һ��������������ڱ�ʶ�� ����ѡ��״̬������û�������ȷ������ť��������Ի��򽫻�����ok����Ϊtrue��������û�������ȡ������ť��ok���ᱻ���� Ϊfalse��
     *��2������ָ���˶Ի���ĳ�ʼ��ɫ�����û�ȡ����ɫ��ѡ��ʱ������Ի��򽫳�ʼ��ɫ��Ϊ����ֵ��
     *this����ָ���˸����ڲ��������һ������ָ��������Ի���ı��⡣
     */
    else if(btn == inputPushBtn)
    {// ����Ի���.
        bool ok;
        QString text = QInputDialog::getText(this,tr("InputDialog"),tr("Please Input text"),
                                            QLineEdit::Normal,QDir::home().dirName(),&ok);
        if(ok && !text.isEmpty())
        {
            displayTextEdit->setText(text);
        }
    }
    /*
     *QInputDialog::getText()������������ʾһ���ı�����Ի���
     *ǰ2�������ֱ�ָ��������Ի���ĸ����ڲ����ͶԻ���ı��⣻
     *��3������ָ���˱�ǩ����ʾ�ı���
     *��4������ָ�����б༭��QLineEdit�������ݵ���ʾģʽ���˴� ΪQLineEdit::Normal�������û������ʵ��������ʾ��
     *��5������ָ�����б༭��Ĭ����ʾ�����ݣ�����QDir::home()  ������ ����home·����QDir::dirName()����·�������֣�
     *���һ��������QFontDialog::getFont()�����ĵ�1��������������ͬ��
     */
    else if(btn == pagePushBtn)
    {// ҳ���öԻ���.
        QPrinter printer;
        QPageSetupDialog dlg(&printer, this);
        dlg.setWindowTitle(tr("PageSet Dialog"));
        if (dlg.exec() == QDialog::Accepted)
        {
            // ������һ���Ĵ���
        }
    }
    /*
     *���ȣ�������һ����ӡ��QPrinter����printer��
     *Ȼ�󴴽���һ��ҳ���öԻ���QPageSetupDialog���󣬲����öԻ���ı��⡣
     *����������У�ֻ�Ǽ򵥵ش�������ʾһ��ҳ���öԻ��򣬸öԻ��򷵻غ�û�н�����һ���Ĵ���
     */
    else if(btn == progressPushBtn)
    {// ���ȶԻ���.
        QProgressDialog progress(tr("Coping..."), tr("Cancel"),0,10000,this);
        progress.setWindowModality(Qt::WindowModal);
        progress.setWindowTitle(tr("Process Dialog"));
        progress.show();
        for(int i=0; i<10000; i++)
        {
            progress.setValue(i);
            qApp->processEvents();
            if(progress.wasCanceled())
                break;
            //... �����ļ�����
            qDebug() << i;
        }
        progress.setValue(10000);
    }
    /*
     *��һ�δ��봴����һ�����ȶԻ��򣬲�ģ������ʾһ����ʱ������Ĺ������̡�
     *���ȣ�������QProgressDialog�Ĺ��캯����������һ�����ȶԻ����ջ���󡣹��캯����5��������
     *��1��������һ���ַ�������ָ������ʾ���û�����ʾ��Ϣ��������ǰ���ڽ��еĹ�����
     *��2������ָ���ˡ�ȡ������ť����ʾ�ı�������ò���Ϊ0�Ļ������ȶԻ���û�С�ȡ������ť�����������ȶԻ���Ĵ���ΪQProgressDialog progress(tr("Coping..."), 0 , 0, 10000, this)
     *��������2�������ֱ�ָ���˲����Ĳ�����������������У����Լٶ����ȶԻ�����ʾ����10 000���ļ��Ľ�չ�����
     *��3���� ���趨Ϊ0����4�������趨Ϊ10 000���������������Ĳ�ֵ������������Ʋ����Ĳ���Ϊ10 000����
     *��5������ָ���˽��ȶԻ���ĸ����ڲ�����
     *������������setWindowModality()���ý��ȶԻ��������ΪQt::WindowModal����Ϊģ̬�Ի���
     *�����ַ�ʽʹ�ý��ȶԻ���QProgressDialog��ģ̬�Ի���ʽ��
     *ʹ��һ��ģ̬���ȶԻ�����ʾ��ʱ������Ĺ������ȶ��ڱ���ǱȽϼ򵥵ģ�
         *���Ǳ������QApplication::processEvents()��������QEventLoop::processEvents(QEventLoop::ExcludeUserInputEvents)�����Ա�֤�¼�ѭ�������Դ��������¼���
         *�Է�ֹӦ�ó�����Ϊ��ʱ��Ĳ���������û�з�Ӧ��
         *���Զ���Ի���������У�ʹ����ģ̬���ȶԻ���ͨ��QProgressDialog::setValue()�����ƽ���ʾ�Ľ��ȣ�
         *ͨ��QProgressDialog::wasCancled()�����ж��û��Ƿ���;ѡ�� �ˡ�ȡ������ť������ǣ����жϸ����ļ�������
         *���⣬����ʹ����qDebug()������ӡfor()�������н��ȣ�ģ�⸴�Ʋ�����
     *��ģ̬�Ի���ʽ����ģ̬���ȶԻ�����������ʾ�ں�̨���еĳ�ʱ������Ĺ������ȣ������Ļ����û����ܹ���Ӧ�ó��� ���������ڽ��н�����
     */
    else if(btn == printPushBtn)
    {// ��ӡ�Ի���.
        QPrinter printer;
        QPrintDialog dlg(&printer, this);
        dlg.setWindowTitle(tr("Printer Dialog"));
        if (dlg.exec() == QDialog::Accepted)
        {
            // ������һ���Ĵ���
        }
    }

}

