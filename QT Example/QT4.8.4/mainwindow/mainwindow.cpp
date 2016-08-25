#include "mainwindow.h"  

#include <QtGui>

// ������ʵ��
MainWindow::MainWindow()
{
    setWindowTitle(tr("myMainWindow"));
    text = new QTextEdit(this);
    setCentralWidget(text);
   
    createActions();
    createMenus();
    createToolBars();
}

void MainWindow::createActions()
{
	
    // file open action
    fileOpenAction = new QAction(QIcon(":/images/open.png"),tr("Open"),this);	// ���ļ�
    fileOpenAction->setShortcut(tr("Ctrl+O"));
//    fileOpenAction->setShortcut(QKeySequence::Open);      ��Щ��ݼ��Ķ���������ƽ̨�й�
//    fileOpenAction->setShortcut(QKeySequence(tr("Ctrl+O")));  �����ִ�Сд
    fileOpenAction->setStatusTip(tr("open a file"));
//  text��accel�������ڹ�����ʾ��״̬��ʾ��������ʹ��setToolTip()��setStatusTip()Ϊ�����ṩ�ض��ı���
    connect(fileOpenAction,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

    
    // file new action
    fileNewAction = new QAction(QIcon(":/images/new.png"),tr("New"),this);	// �½��ļ�
    fileNewAction->setShortcut(tr("Ctrl+N"));
    fileNewAction->setStatusTip(tr("new file"));
    connect(fileNewAction,SIGNAL(triggered()),this,SLOT(slotNewFile()));

    // save file action
    fileSaveAction = new QAction(QPixmap(":/images/save.png"),tr("Save"),this);	// �����ļ� 
    fileSaveAction->setShortcut(tr("Ctrl+S"));
    fileSaveAction->setStatusTip(tr("save file"));
    connect(fileSaveAction,SIGNAL(activated()),this,SLOT(slotSaveFile()));
   /*
    *buttonû�� triggered��activated�ġ�
    *clicked һ��ָ���������
    *triggered һ����QAction�ȱ�����
    *activated һ��ָ�ؼ�������ȣ�����ԭ������кࣩܶ
*/

    // exit action
    exitAction = new QAction(tr("Exit"), this);	// �˳�
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("exit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    cutAction = new QAction(QIcon(":/images/cut.png"), tr("Cut"), this);		// ����
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("cut to clipboard"));
    connect(cutAction, SIGNAL(triggered()), text, SLOT(cut()));

    copyAction = new QAction(QIcon(":/images/copy.png"), tr("Copy"), this);		// ����
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("copy to clipboard"));
    connect(copyAction, SIGNAL(triggered()), text, SLOT(copy()));

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("Paste"), this);		// ճ��
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("paste clipboard to selection"));
    connect(pasteAction, SIGNAL(triggered()), text, SLOT(paste()));

    aboutAction = new QAction(tr("About"), this);		// ����
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(slotAbout()));
}

void
MainWindow::createMenus()
{
	
    fileMenu = menuBar()->addMenu(tr("File"));
    editMenu = menuBar()->addMenu(tr("Edit"));
    aboutMenu = menuBar()->addMenu(tr("Help"));
/*
 *û�и����ڵĲ˵���
 *QMenuBar *menuBar = new QMenuBar(0);
 *menuFile = menuBar->addMenu(tr("File"));
 *����
 *menuFile = new QMenu(tr("File"),this);
 *QMenuBar *menuBar = menuBar();
 *menuBar->addMenu(menuFile);
 */
    
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileSaveAction);
    fileMenu->addAction(exitAction);
    
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);
    
    aboutMenu->addAction(aboutAction);
}


void
MainWindow::createToolBars()
{
	
    fileTool = addToolBar(tr("File"));
    fileTool->setMovable(true);             //�Ƿ������ƶ�
    addToolBar(Qt::TopToolBarArea,fileTool);//��ʼλ��
    fileTool->setAllowedAreas(Qt::AllToolBarAreas);//��ͣ���ؼ���������

    fileTool->addAction(fileNewAction);
    fileTool->addAction(fileOpenAction);
    fileTool->addAction(fileSaveAction);
    fileTool->setFloatable(false);           //�Ƿ�������

    editTool = addToolBar(tr("Edit"));
    addToolBar(Qt::RightToolBarArea,editTool);//��ʼλ��
    editTool->setMovable(true);
    editTool->setAllowedAreas(Qt::RightToolBarArea|Qt::TopToolBarArea);
    editTool->setFloatable(true);           //�Ƿ�������

    QSize size(16,15);
    editTool->setIconSize(size);

    editTool->addAction(copyAction);
    editTool->addAction(cutAction);
    editTool->addAction(pasteAction);
   
}

void
MainWindow::slotNewFile()
{
}


void
MainWindow::slotOpenFile()
{
}

void
MainWindow::slotSaveFile()
{
}

void
MainWindow::slotCopy()
{
}

void
MainWindow::slotCut()
{
}

void
MainWindow::slotPaste()
{
}

void
MainWindow::slotAbout()
{
}


