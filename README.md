# Command Based Text Editor

Our goal in this project is to write a command-based text editor in cpp using [linked lists](https://www.geeksforgeeks.org/data-structures/linked-list/) and [stack](https://www.geeksforgeeks.org/stack-in-cpp-stl/).

This text editor will print the contents of a file to the screen, page by page.

Each page consists of 10 lines. An example image is given below.

![](https://raw.githubusercontent.com/bardakcib/CommandBasedTextEditor/master/res/commandList.png)

I have implemented a stack to keep track of all actions carried out, so you can undo actions if needed.

Sample txt files are included to the &quot;Resource Files&quot; folder of the project

![](RackMultipart20210602-4-y9nfnl_html_3591410863e2fd4d.png)

## Main Commands:

![](RackMultipart20210602-4-y9nfnl_html_72b267963f418752.png)

- **open filename:** The program should open the file whose name is provided in the field `filename` and loads its contents. For example, if the user enters &quot;_open test.txt_&quot;, your program should open test.txt and load each line in the file to the linked list.

- **save filename:** The program should write the contents of the linked list to the file whose name is provided in the `filename` field.

- **insert n text:** The program should insert a new line with the &quot;text&quot; area user entered to the n_th_ line. For example, if the user enters &quot;insert 5 hello my friend&quot;, your program should insert a new line at line position 5 and put &quot;hello my friend&quot; in that line.

If the .txt file already contains more than n lines, it should insert thin new line between lines n-1 and n, putting the newly inserted text at line n. If the file contains less than n lines, it should fill the gap with blank lines until the newly inserted line becomes at position n.

- **delete n:** The program should delete the line at position n.

- **move n m:** The program should move the line at position n to new position m.

- **replace n text:** The program should replace the text at line n with the string provided within `text` area.

- **next:** Previous contents of the file should not change, but the program should display the next page.

- **prev:** Previous contents of the file should not change, but the program should display the previous page.

- **undo:** Reverts the last action taken. User should be able to call as many undo commands as s/he likes, and should be able to revert back to the initial state of the file after calling undo action enough times
