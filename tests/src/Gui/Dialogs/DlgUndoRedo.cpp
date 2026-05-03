
#include <QDebug>
#include <QTest>
#include <fstream>
#include <iostream>

#include <QAction>
#include <QList>


#include <App/Application.h>

#include "Gui/Dialogs/DlgVersionMigrator.h"

#include "App/ApplicationDirectories.h"

#include <src/App/InitApplication.h>
#include "Dialogs/DlgUndoRedo.h"
#include "Application.h"
#include "MainWindow.h"
#include "MDIView.h"


class testDlgUndoRedo final: public QObject
{
	Q_OBJECT

	public:
		testDlgUndoRedo()
		{
			tests::initApplication();
		}
        
private Q_SLOTS:

	// These two are default in most test files
	void init()  // NOLINT
	{}

	void cleanup()  // NOLINT
	{}

	void testUndoAddAllActions() // NOLINT
	{
		//Arrange
		MDIView* mdi =  getMainWindow()->activeWindow();
		Gui::UndoDialog dialog = new UndoDialog(mockMdi);
		//Act 
		//Assert
		Q_ASSERT();
	}

	void testUndoNoActiveWindow() // NOLINT
	{
		//Arrange
		//Creates a new UndoDialog using the nullpointer mdi we created.
		//This constructor also calls the UndoDialog::OnFetchInfo which executes the code that checks the mdi
		MDIView* mdi =  getMainWindow()->activeWindow();
		Gui::UndoDialog dialog =  new UndoDialog(mdi);
		//Act 
        dialog.onFetchInfo();
		//Assert
		Q_ASSERT();
	}
	void testUndoSelectedActsExcludesA() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testUndoSelectedActsIncludesA() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testSelectUndoandRedoEmpty() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testSelectUndoandRedo() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testSelectUndo() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testSelectRedo() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testSelectEarlierUndoandRedo() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	} 
	void testUndoLaterRedo() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testSavingThenUndo() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	}
	void testCloseClearsHistory() // NOLINT
	{
		//Arrange
		//Act 
		//Assert
		//Q_ASSERT();
	} 

	
    
};

QTEST_MAIN(testDlgUndoRedo)

#include "DlgUndoRedo.moc"

