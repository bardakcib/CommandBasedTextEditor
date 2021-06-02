-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

                                             CSE 211 - Term Project
                                                   Fall 2020
                                        Bedirhan Bardakci - 20150702053

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

    Command List : 
    open				            - To Open New File		        ( ex : open test.txt )
    next				            - To Go Next Page 
    prev				            - To Go Previous Page
    insert {line no} {new text}	    - To Insert A New Line		    ( ex : insert 5 MyNewText )
    delete {line no}		        - To Delete A Line		        ( ex : delete 5 )
    replace {line no} {new text}	- To Replace A Line Text	    ( ex : replace 5 MyNewText )
    move {line no1} {line no2}	    - To Move A Line To Target Line	( ex : move 5 7 )
    undo				            - To Undo Last Action
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------


    Project Developer and test with Visual Studio 2019

    Test files are added under Resource File on VS FolderBase

    MyFunctions.cpp, MyFunctions.h and MyMessages.h are created to optimize code re-usage and clean code

    intsllist.cpp nad intsllist.h are from our LabWorks, I have modified them in order to use.


-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
    References :
    I got some help from stackoverflow but not directly copy paste
    I understand them and modified them


1-  SplitStringByDelimiterToArray

    I have used # char in my undoStack.
    Then I use this function to split the commands easily into an array
    https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c


2-  LeftTrim    RightTrim   LeftAndRightTrimSpaces

    To Left and Right Trim Spaces in case of user may enter spaces between commands
    if so I don't want to interrupt the code and try to go on
    https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring


3-  SplitStringBySpaceToArray

    I want to split the users command by spaces 
    to not to opearte hardcoded by using substr functions
    this is much more dynamic
    https://stackoverflow.com/questions/16029324/splitting-a-string-into-an-array-in-c-without-using-vector


4-  replace method in SplitStringBySpaceToArray
    I can manually itterate over string's chars but I want to implement a clean single line of code
    So For the string replace method I got help from stackoverflow
    https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string