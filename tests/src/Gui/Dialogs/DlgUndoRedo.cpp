
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
			//This creates the application which inits the MDIView, the Document
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
		//Get pointer to active view and get active document
		MDIView* mdi = getMainWindow()->activeWindow();
		Document test = mdi->getGuiDocument();
		UndoDialog undo = new UndoDialog(mdi);
		//adds command to transaction list
		test::openCommand("Mock");
		//Act 
		//call onFetchInfo to add the actions to the MDI undoActions list
		undo::onFetchInfo();
		//get the list from the mdi
		QStringList vecUndos = mdi->undoActions();
		//Assert
		//There should only be one item in the list 
		Q_ASSERT(vecUndos.size() == 1);
	}
	void testUndoNoActiveWindow() // NOLINT
	{
		//Arrange
		//Get pointer to active view
		MDIView* mdi = getMainWindow()->activeWindow();
		UndoDialog undo = new UndoDialog(mdi);
		//Act 
		//close the active view
		mdi::deleteSelf();
		//Assert
		//QT Test will catch an exception if a crash occurs for having no active view to undo
		QVERIFY_THROWS_EXCEPTION(std::exception, undo::onFetchInfo());
	}
	void testUndoSelectedActsExcludesA() // NOLINT
	{
		//Arrange
		MDIView* mdi = getMainWindow()->activeWindow();
		UndoDialog undo = new UndoDialog(mdi);
		//adds commands to transaction list
		std::vector<std::string> undoStringBefore = test::getUndoVector();
		test::openCommand("Mock 1");
		test::openCommand("Mock 2");
		test::openCommand("Mock 3");
		test::openCommand("Mock 4");
		//Act 
		//Undoing all the mock commands
		undo::onSelected();
		undo::onSelected();
		undo::onSelected();
		undo::onSelected();
		//checks the available undos after clearing the commands
		std::vector<std::string> undoStringAfter = test::getUndoVector();
		//Assert
		//The availble undo actions before and after the test should be the same
		Q_ASSERT(undoStringAfter == undoStringBefore);
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
		//Get pointer to active view and get active document
		MDIView* mdi = getMainWindow()->activeWindow();
		UndoDialog undo = new UndoDialog(mdi);
		Document test = mdi->getGuiDocument();
		//Act 
		//Saving but not closing the file
		test::save();
		//Assert
		//Test will catch an exception if the onFetchInfo() causes an exception for undoing after saving
		QVERIFY_THROWS_EXCEPTION(std::exception, undo::onFetchInfo());
	}
	void testCloseClearsHistory() // NOLINT
	{
		//Arrange
		//Get pointer to active view and get active document
		MDIView* mdi = getMainWindow()->activeWindow();
		UndoDialog undo = new UndoDialog(mdi);
		Document test = mdi->getGuiDocument();
		//adds command to transaction list
		test::openCommand("Mock");
		//Act 
		//checks to see it can undo last command
		std::vector<std::string> undoStringBefore = test::getUndoVector();
		//saves then closes and reopens the document object
		test::save();
		test::close();
		test::restore();
		//checks the undo list expecting empty transaction list
		std::vector<std::string> undoStringAfter = test::getUndoVector();
		//Assert
		//Tests if closing will maintain the same undo list
		Q_ASSERT(undoStringBefore != undoStringAfter);
	} 
	void testNewActionClearsRedo() // NOLINT
	{
		//Arrange
		//Get pointer to active view and get active document
		MDIView* mdi = getMainWindow()->activeWindow();
		RedoDialog redo = new RedoDialog(mdi);
		UndoDialog undo = new UndoDialog(mdi);
		Document test = mdi->getGuiDocument();
		//adds command to transaction list
		test::openCommand("Mock");
		//undoes the action
		undo::onSelected();
		//Act 
		//checks the redo
		std::vector<std::string> redoStringBefore = test::getRedoVector();
		//overwrites redo list by adding new command to transaction list
		test::openCommand("Mock 2");
		//checks for empty redo list
		std::vector<std::string> redoStringAfter = test::getRedoVector();
		//Assert
		//Tests that new actions clear the redo queue
		Q_ASSERT(redoStringBefore != redoStringAfter);
	} 
};

QTEST_MAIN(testDlgUndoRedo)

#include "DlgUndoRedo.moc"

