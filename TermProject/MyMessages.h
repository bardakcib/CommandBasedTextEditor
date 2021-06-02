#include <string>
#include "intSLList.h"

#ifndef MYMESSAGES_H
#define MYMESSAGES_H


using namespace std;

class MyMessages {
public:
	string introMessage =
		"\n	   CSE 211 - Term Project"
		"\n		 Fall 2020"
		"\n     Bedirhan Bardakci - 20150702053"
		"\n\n  Please Refer to ReadMe.txt For More Info\n";

	string infoOpenFile = "\n\nPlease Open A.TXT File(ex : open 'Filename.txt'\n";
	string infoUndoComplete = "\nUndo completed for the action taken : ";
	string infoInseretLine = "\nYou Have Deleted All The Lines. Please Undo or Add New Lines\n\n";
	string infoLastPage = "\nYou are already at the last page\n";
	string infoFirstPage = "\nYou are already at the first page\n";
	string infoEnterCommand = "\nEnter Your Command ( to get command list, type help ) :  ";
	string infoCommandListHelper =
		"\n"
		"\n Command List : \n"
		"\n open				- To Open New File		 ( ex : open test.txt )"
		"\n next				- To Go Next Page "
		"\n prev				- To Go Previous Page"
		"\n insert {line no} {new text}	- To Insert A New Line		 ( ex : insert 5 MyNewText )"
		"\n delete {line no}		- To Delete A Line		 ( ex : delete 5 )"
		"\n replace {line no} {new text}	- To Replace A Line Text	 ( ex : replace 5 MyNewText )"
		"\n move {line no1} {line no2}	- To Move A Line To Target Line	 ( ex : move 5 7 )"
		"\n save				- To Save Or Create A New File"						
		"\n undo				- To Undo Last Action"
		"\n\n";

	string errEmptyFile = "\nEmptyFile !!!\n\n";
	string errNoSuchFile = "\nNo Such File Found.Please Enter A Valid File Name !!!\n\n";
	string errNotValidCommand = "\nPlease Enter A Valid Command !!!\n\n";
	string errNotValidOpenCommand = "\nPlease Enter A Valid 'Open File' Command, for ex : open test.txt\n\n";
	string errNotValidPosition = "\nPlease Enter Position Value(s) As Integer, Between 1 and ";
	string errNoUndoActionFound = "\n\nNo Action Found To Undo !!!\n";
};
#endif