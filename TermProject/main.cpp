#include <stack> 
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "intSLList.h"
#include "MyMessages.h"
#include "MyFunctions.h"

using namespace std;

MyMessages msg;
IntSLList mainList;
string* splittedCommand;
stack<string> undoStack;
MyFunctions myFunctions;
string nameOfFile, command, userNewTextInput, userNewFileNameToSave, deletedText, undoAction, originalTextOfNode, originalFileName;

int currentPage = 1, cur = 0, pageSize = 10, totalLinesAdded = 0, totalPageCount = 0, totalLineCount = 0, userPositionInput1 = 0, userPositionInput2 = 0;

bool readFile(string filename)
{
	ifstream testFile(filename);

	if (testFile.good())
	{
		originalFileName = filename;

		//init list,stack and file details
		mainList.deleteAll();

		while (!undoStack.empty())
			undoStack.pop();

		string line;
		currentPage = 1;
		totalPageCount = 0;
		totalLineCount = 0;

		// fill list with the lines read from txt
		while (getline(testFile, line)) {
			mainList.addToTail(line);
			totalLineCount++;
		}

		if (totalLineCount > 0)
			return true;
		else
			cout << msg.errEmptyFile;
	}

	cout << msg.errNoSuchFile;
	return false;
}

bool openMyFile(string fileName)
{
	fileName = myFunctions.ToLowerCase(fileName);

	if (readFile(fileName))
	{
		totalPageCount = myFunctions.PageCountCalculator(totalLineCount, pageSize);
		mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
		return true;
	}

	cout << msg.errNotValidOpenCommand;
	return false;
}

void updatePageToNavigate()
{
	currentPage = userPositionInput1 / pageSize;

	if (currentPage == 0)
		currentPage = 1;
	else if ((userPositionInput1 % pageSize) != 0)
		currentPage++;
}

int main()
{
	// Please first read the ReadMe.txt
	cout << msg.introMessage << endl;

	bool anyFileOpened = false;

	while (!anyFileOpened)	// open file
	{
		cout << msg.infoOpenFile;
		getline(cin, command);

		string* userInputSplittedBySpace = myFunctions.SplitStringBySpaceToArray(command);

		command = userInputSplittedBySpace[0];
		nameOfFile = userInputSplittedBySpace[1];

		command = myFunctions.ToLowerCase(command);

		anyFileOpened = openMyFile(nameOfFile);
	}

	while (true)	// operations on file opened
	{
		cout << msg.infoEnterCommand;
		getline(cin, command);

		// Splitting user commands into an array of string to parse user request
		splittedCommand = myFunctions.SplitStringBySpaceToArray(command);

		command = splittedCommand[0];
		command = myFunctions.ToLowerCase(command);

		if (command == "help")
		{
			cout << msg.infoCommandListHelper;
		}

		else if (command == "undo")
		{
			// We will feed stack with a unique combination using #
			// for example if user will enter insert 5 asd  we will store this in stack as
			// insert#5#asd
			// then when we will need undo, we will split this string to array by '#'
			if (undoStack.empty())
				cout << msg.errNoUndoActionFound;
			else
			{
				undoAction = undoStack.top();

				// if any action found, split it by '#'
				string* splittedAction = myFunctions.SplitStringByDelimiterToArray(undoAction, "#");

				// After split, we will get the action details
				string command = splittedAction[0]; // this will be always the command details
				string undoParam1 = splittedAction[1]; // sometime this will be int, some times text
				string undoParam2 = splittedAction[2]; // sometime this will be int, some times text

				if (command == "delete") // if user deleted then we should insert it again
				{
					userPositionInput1 = stoi(undoParam1);
					originalTextOfNode = undoParam2;

					mainList.insertNode(userPositionInput1, originalTextOfNode);

					totalLineCount++;
					updatePageToNavigate();
				}

				else if (command == "insert") // if user inserted then we should delete it / them again
				{
					userPositionInput1 = stoi(undoParam1);
					totalLinesAdded = stoi(undoParam2);

					if (totalLinesAdded != 1) // if multiple lines added with some of them spaces
					{
						for (int i = 0; i < totalLinesAdded; i++)
						{
							mainList.deleteFromTail(); // delete all the lines one by one from tail
							totalLineCount--;
						}
						currentPage = (userPositionInput1 - totalLinesAdded) / pageSize;

						if (currentPage == 0)
							currentPage = 1;
						else if (((userPositionInput1 - totalLinesAdded) % pageSize) != 0)
							currentPage++;
					}
					else // if just 1 line added then delete that specific line
					{
						if (userPositionInput1 > 0 && userPositionInput1 <= totalLineCount)
						{
							mainList.deleteNode(userPositionInput1);
							totalLineCount--;
						}
						else
							cout << msg.errNotValidPosition << totalLineCount << " !!!\n";
					}
				}

				else if (command == "move") // reverse the move action
				{
					userPositionInput1 = stoi(undoParam1);
					userPositionInput2 = stoi(undoParam2);

					mainList.moveNode(userPositionInput2, userPositionInput1);

					// after move request, we may need to move to the related page to see the result
					updatePageToNavigate();
				}

				else if (command == "replace") // reverse the line to its original text value 
				{
					userPositionInput1 = stoi(undoParam1);
					originalTextOfNode = undoParam2;

					mainList.replaceNode(userPositionInput1, originalTextOfNode);

					// after replace request, we may need to move to the related page to see the result
					updatePageToNavigate();
				}

				else if (command == "next") // go back to the page user commands next
				{
					// turn back to the page where user enters next
					currentPage = stoi(undoParam1);

					// if you want to trigger oposite of next (prev) then uncomment below code
					//if (currentPage > 1)
					//	currentPage--;
				}

				else if (command == "prev") // go back to the page user commands next
				{
					// turn back to the page where user enters prev
					currentPage = stoi(undoParam1);

					// if you want to trigger oposite of prev (next) then uncomment below code
					//if (currentPage < totalPageCount)
					//	currentPage++;
				}

				totalPageCount = myFunctions.PageCountCalculator(totalLineCount, pageSize);
				mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
				undoStack.pop();

				cout << msg.infoUndoComplete << command << " " << undoParam1 << endl;
			}
		}

		else if (command == "insert")
		{
			try
			{
				userNewTextInput = splittedCommand[2];
				userPositionInput1 = stoi(splittedCommand[1]);

				// input position must be greater than 0 
				if (userPositionInput1 > 0 && userPositionInput1 <= 2147483647) // int max, not sugested :)
				{
					// lines added with spaces + 1 (the last line added)
					// if totalLinesAdded is 1 then we understand that just 1 line added
					// if it is more than 1 then we understand that some lines added with spaces
					totalLinesAdded = userPositionInput1 - totalLineCount;

					if (totalLinesAdded <= 1)
					{
						totalLinesAdded = 1; // only 1 line added
						mainList.insertNode(userPositionInput1, userNewTextInput);
						totalLineCount++; // due to insertion, line count increases
					}
					else
					{
						string tempText = " ";
						for (int i = 1; i <= totalLinesAdded; i++) // (count of diff) so multiple lines added
						{
							totalLineCount++; // due to insertion, line count increases
							if (i == totalLinesAdded)
								tempText = userNewTextInput; // just the very last line will have text value
															 // middle lines will be added with spaces
							mainList.insertNode(totalLineCount, tempText);
						}
					}
					totalPageCount = myFunctions.PageCountCalculator(totalLineCount, pageSize);

					// after insertions, we may need to move next pages
					// if new pages added, then we will navigate user to the page at position he/she inserted 
					// so currentpage recalculated
					updatePageToNavigate();

					mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
					undoStack.push(command + "#" + to_string(userPositionInput1) + "#" + to_string(totalLinesAdded));
				}
				else
					cout << msg.errNotValidPosition << "2147483647 !!!\n";
			}
			catch (exception ex)
			{
				cout << msg.errNotValidPosition << totalLineCount << "!!!\n";
			}
		}

		else if (totalLineCount == 0)
		{
			cout << msg.infoInseretLine;
		}

		else if (command == "open")
		{
			nameOfFile = splittedCommand[1];
			openMyFile(nameOfFile);
		}

		else if (command == "next")
		{
			cur = currentPage;
			currentPage++;

			// if we are already at the last page
			if (currentPage > totalPageCount)
			{
				currentPage = totalPageCount;
				cout << msg.infoLastPage;
			}

			mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
			undoStack.push(command + "#" + to_string(cur));
		}

		else if (command == "prev")
		{
			cur = currentPage;
			currentPage--;
			// check if we are already at the first page
			if (currentPage < 1)
			{
				currentPage = 1;
				cout << msg.infoFirstPage;
			}

			mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
			undoStack.push(command + "#" + to_string(cur));
		}

		else if (command == "delete")
		{
			try
			{
				userPositionInput1 = stoi(splittedCommand[1]);

				// input position must be between 1 and total line count
				if (userPositionInput1 > 0 && userPositionInput1 <= totalLineCount)
				{
					deletedText = mainList.deleteNode(userPositionInput1);

					totalLineCount--; // if any node deleted, this means lines are decreasing

					// maybe too many lines deleted, so we need to update the total page count
					totalPageCount = myFunctions.PageCountCalculator(totalLineCount, pageSize);

					// after deletions, we may need to move that pages to see the action result.
					// if pages deleted, then we will navigate user to the page to the 1 previous page 
					// so currentpage recalculated
					updatePageToNavigate();

					// if too many lines are deleted, and user is at that last page 
					// which does not exists anymore, we will navigate user the last page.
					if (currentPage > totalPageCount)
						currentPage = totalPageCount;

					mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
					cout << "\nLine " << userPositionInput1 << " is deleted." << endl;
					undoStack.push(command + "#" + to_string(userPositionInput1) + "#" + deletedText);
				}
				else
					cout << msg.errNotValidPosition << totalLineCount << " !!!\n";
			}
			catch (exception ex)
			{
				cout << msg.errNotValidPosition << totalLineCount << " !!!\n";
			}
		}

		else if (command == "replace") {
			try
			{
				userNewTextInput = splittedCommand[2];
				userPositionInput1 = stoi(splittedCommand[1]);

				// input values must be between 1 and total line count
				if (userPositionInput1 > 0 && userPositionInput1 <= totalLineCount)
				{
					originalTextOfNode = mainList.replaceNode(userPositionInput1, userNewTextInput);

					// after replace request, we may need to move to the related page to see the result
					updatePageToNavigate();

					mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
					undoStack.push(command + "#" + to_string(userPositionInput1) + "#" + originalTextOfNode);
				}
				else
					cout << msg.errNotValidPosition << totalLineCount << " !!!\n";
			}
			catch (exception ex)
			{
				cout << msg.errNotValidPosition << totalLineCount << "!!!\n";
			}
		}

		else if (command == "move")
		{
			try
			{
				userPositionInput1 = stoi(splittedCommand[1]);
				userPositionInput2 = stoi(splittedCommand[2]);

				// input values must be between 1 and total line count
				if (userPositionInput2 > totalLineCount || userPositionInput1 > totalLineCount || userPositionInput1 < 1 || userPositionInput2 < 1)
				{
					cout << msg.errNotValidPosition << totalLineCount << "!!!\n";
				}
				else
				{
					mainList.moveNode(userPositionInput1, userPositionInput2);

					// after move request, we may need to move to the related page to see the result
					currentPage = userPositionInput2 / pageSize;

					if (currentPage == 0)
						currentPage = 1;
					else if ((userPositionInput2 % pageSize) != 0)
						currentPage++;
					mainList.printAll(currentPage, pageSize, totalPageCount, totalLineCount);
					undoStack.push(command + "#" + to_string(userPositionInput1) + "#" + to_string(userPositionInput2));
				}
			}
			catch (exception ex)
			{
				cout << msg.errNotValidPosition << totalLineCount << "!!!\n";
			}
		}

		else if (command == "save")
		{
			// If any name given by user, a new file will be created and filled with data
			// If just save comment sent by the user, current file will be overwritten

			userNewFileNameToSave = splittedCommand[1];

			if (userNewFileNameToSave == "")
				userNewFileNameToSave = originalFileName;

			mainList.save(userNewFileNameToSave);
			cout << userNewFileNameToSave << " created / modified." << endl;
		}

		else
		{
			cout << msg.errNotValidCommand;
		}
	}
}


